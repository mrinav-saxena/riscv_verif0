#!/usr/bin/env python3
import argparse
import sys
import os
from pathlib import Path
from utils import run, safe_remove_directory, run_with_logging

def main():

    print()
    
    parser = argparse.ArgumentParser(description="Build RV32I program and run verilator simulation.")
    parser.add_argument("-code", dest="c_file", required=True, help="Path to input C source file")
    parser.add_argument("-tb", dest="tb_dir", required=True, help="Path to testbench directory (contains tb.sv, link.ld, makefile)")
    parser.add_argument("-gcc", default="riscv-none-elf-gcc", help="RISC-V GCC executable name")
    parser.add_argument("-objcopy", default="riscv-none-elf-objcopy", help="RISC-V objcopy executable name")
    parser.add_argument("-objdump", default="riscv-none-elf-objdump", help="RISC-V objdump executable name")
    parser.add_argument("-sim", default="verilator", help="Simulator (default: verilator)")
    parser.add_argument("-top", default="tb", help="Top-level module name (default: tb)")
    parser.add_argument("-extra_make_args", default="", help="Extra args to append to make invocation")
    parser.add_argument("-debug", action="store_true", help="Enable debug output for verilator command")
    parser.add_argument("-skip_hex_build", action="store_true", help="Skip hex file building step")
    args = parser.parse_args()

    c_path = Path(args.c_file).resolve()
    tb_path = Path(args.tb_dir).resolve()
    if not c_path.exists():
        print(f"C file not found: {c_path}", file=sys.stderr)
        sys.exit(1)
    if not tb_path.exists():
        print(f"TB directory not found: {tb_path}", file=sys.stderr)
        sys.exit(1)

    link_ld = tb_path / "link.ld"
    if not link_ld.exists():
        print(f"Linker script not found in TB directory: {link_ld}", file=sys.stderr)
        sys.exit(1)

    # Create run directory: {c_filename}_on_{tb_dirname}
    c_filename = c_path.stem
    tb_dirname = tb_path.name  # Gets the last directory name from the path
    run_dir_name = f"{c_filename}_on_{tb_dirname}"
    run_dir_path = Path("sim/runs") / run_dir_name
    
    # Create the run directory if it doesn't exist
    run_dir_path.mkdir(parents=True, exist_ok=True)
    print(f"Created run directory: {run_dir_path}\n")

    # 1) Handle hex file building/copying
    base = c_path.stem
    hex_source_dir = Path("sim/images") / base
    
    if args.skip_hex_build:
        print("========== [1/4] : SKIPPING HEX BUILD ==========")
        # Check if hex files exist when skipping build
        existing_hex_files = list(hex_source_dir.glob("*.hex"))
        if existing_hex_files:
            print(f"Found {len(existing_hex_files)} existing hex file(s):")
            for hex_file in existing_hex_files:
                print(f"  - {hex_file.name}")
        else:
            print("WARNING: No existing hex files found in {hex_source_dir}")
            print("   Simulation may fail if hex files are required!")
        print("========== HEX BUILD SKIPPED ======================\n")
    else:
        print("========== [1/4] : BUILDING HEX FILES ==========")
        # Build hex files
        build_cmd = [
            sys.executable, str(Path(__file__).parent / "build_hex.py"),
            "-code", str(c_path),
            "-linker", str(link_ld),
            "-gcc", args.gcc,
            "-objcopy", args.objcopy,
            "-objdump", args.objdump,
        ]
        
        # Build hex files with logging
        build_log_path = run_dir_path / "build_hex.log"
        run_with_logging(build_cmd, build_log_path, "Hex file building")
        
        # Copy hex files to run directory
        for hex_file in hex_source_dir.glob("*.hex"):
            hex_dest_run = run_dir_path / hex_file.name
            import shutil
            shutil.copy2(hex_file, hex_dest_run)
            print(f"Copied {hex_file} to run directory: {hex_dest_run}")
        
        # Copy assembly and disassembly files to run directory
        for file_ext in ["*.s", "*.disasm"]:
            for asm_file in hex_source_dir.glob(file_ext):
                asm_dest_run = run_dir_path / asm_file.name
                shutil.copy2(asm_file, asm_dest_run)
                print(f"Copied {asm_file} to run directory: {asm_dest_run}")

        print("========== HEX FILES BUILT AND COPIED ================\n")

    # 2) Verilator compilation
    print("========== [2/4] VERILATOR COMPILATION ==========")
    print("Starting Verilator simulation...")
    
    # Create build directory for intermediate files
    build_dir = Path("sim/build") / run_dir_name
    build_dir.mkdir(parents=True, exist_ok=True)
    print(f"Created build directory: {build_dir}")
    
    # Clean previous build artifacts
    safe_remove_directory(build_dir)
    build_dir.mkdir(parents=True, exist_ok=True)
    
    # Build verilator command with proper include paths (relative to root directory)
    flist_path = Path("sim/scripts/flists/sanity.f")  # Relative to root
    verilator_cmd = [
        "verilator_bin", "-Wall", "--trace", "--trace-fst", "--trace-depth", "4", "--timing",
        "--cc", str((tb_path / "tb.sv").resolve().as_posix()),  # Convert to forward slashes
        "--exe", str((tb_path / "sim_main.cpp").resolve().as_posix()),  # Convert to forward slashes and resolve
        "--Mdir", str(build_dir),  # Use absolute path
        "-f", str(flist_path),  # Include file list
        "-O3", "-Wno-fatal",
        "-CFLAGS", "-IC:/msys64/mingw64/include -DWIN32 -D_WIN32 -D__MINGW64__",
        "-LDFLAGS", "-LC:/msys64/mingw64/lib -lz"
    ]
    
    # Debug output
    if args.debug:
        print(f"\n=== DEBUG MODE ===")
        print(f"Current working directory: {os.getcwd()}")
        print(f"File list path: {flist_path}")
        print(f"File list absolute path: {flist_path.resolve()}")
        print(f"File list exists: {flist_path.exists()}")
        print(f"Testbench path: {tb_path}")
        print(f"Build directory: {build_dir}")
        print(f"Run directory: {run_dir_path}")
        print(f"=== END DEBUG ===\n")
    
    print("Running Verilator...")
    if args.debug:
        print(f"Full command: {' '.join(verilator_cmd)}")
    
    # Run verilator with logging
    verilator_log_path = run_dir_path / "verilator.log"
    os.environ["VERILATOR_ROOT"] = "C:/msys64/mingw64/share/verilator"
    run_with_logging(verilator_cmd, verilator_log_path, "Verilator compilation")
    print("========== VERILATED SUCCESSFULLY =================\n")
    
    # 3) Build with make
    print("========== [3/4] MAKE BUILD ==========")
    print("Building with make...")
    make_cmd = f"mingw32-make -C {build_dir} -f VTb.mk -j8"
    
    # Override PATH to prioritize MinGW64 GCC over Cygwin GCC
    original_path = os.environ.get('PATH', '')
    os.environ['PATH'] = f"C:/msys64/mingw64/bin;{original_path}"
    print("Temporarily overrode PATH to prioritize MinGW64 GCC")
    
    # Build with make and logging
    make_log_path = run_dir_path / "make.log"
    run_with_logging(make_cmd, make_log_path, "Make build")
    
    # Restore original PATH
    os.environ['PATH'] = original_path
    print("Restored original PATH", flush=True)
    
    # Force flush and add a small delay to ensure clean output
    sys.stdout.flush()
    
    print("========== BUILD MADE =====================\n", flush=True)
    sys.stdout.flush()

    # Run simulation
    print("========== [4/4] RUNNING SIMULATION! ==========", flush=True)
    print("Running simulation...", flush=True)
    sim_cmd = str((build_dir/'VTb.exe').resolve().as_posix())  # Convert to forward slashes
    
    # Log simulation command to file
    sim_log_path = run_dir_path / "run_sim.log"
    print(f"Simulation output will be logged to {sim_log_path}", flush=True)
    
    # Debug output for simulation
    if args.debug:
        print(f"\n=== SIMULATION DEBUG ===", flush=True)
        print(f"Simulation command: {sim_cmd}", flush=True)
        print(f"Build directory: {build_dir}", flush=True)
        print(f"Build directory exists: {build_dir.exists()}", flush=True)
        print(f"Executable path: {build_dir/'VTb.exe'}", flush=True)
        print(f"Executable exists: {(build_dir/'VTb.exe').exists()}", flush=True)
        print(f"Run directory: {run_dir_path}", flush=True)
        print(f"Current working directory: {os.getcwd()}", flush=True)
        print(f"=== END SIMULATION DEBUG ===\n", flush=True)
    
    # Run simulation from the run directory so it can find the hex files
    if os.system(f"cd {run_dir_path.as_posix()} && {sim_cmd}") != 0:
        print("Simulation failed", file=sys.stderr)
        sys.exit(1)
    
    # Restore original working directory
    # os.chdir(original_cwd)
    
    print("========== SIMULATION COMPLETE! =================\n", flush=True)

if __name__ == "__main__":
    main()
