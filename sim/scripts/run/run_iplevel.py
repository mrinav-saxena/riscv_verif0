#!/usr/bin/env python3
import argparse
import sys
import os
from pathlib import Path
from utils import run, safe_remove_directory, run_with_logging

def main():

    print()
    
    parser = argparse.ArgumentParser(description="Compile and run SystemVerilog IP-level simulation with Verilator.")
    parser.add_argument("-tb", dest="tb_dir", required=True, help="Path to testbench directory (contains tb.sv, sim_main.cpp)")
    parser.add_argument("-flist", dest="flist_path", required=True, help="Path to file list (.f) file")
    parser.add_argument("-sim", default="verilator", help="Simulator (default: verilator)")
    parser.add_argument("-top_module", default="tb", help="Top-level module name (default: tb)")
    parser.add_argument("-extra_make_args", default="", help="Extra args to append to make invocation")
    parser.add_argument("-debug", action="store_true", help="Enable debug output for verilator command")
    args = parser.parse_args()

    tb_path = Path(args.tb_dir).resolve()
    flist_path = Path(args.flist_path).resolve()
    
    if not tb_path.exists():
        print(f"TB directory not found: {tb_path}", file=sys.stderr)
        sys.exit(1)
    if not flist_path.exists():
        print(f"File list not found: {flist_path}", file=sys.stderr)
        sys.exit(1)

    # Check for required files in testbench directory
    tb_sv = tb_path / "tb.sv"
    sim_main_cpp = tb_path / "sim_main.cpp"
    
    if not tb_sv.exists():
        print(f"tb.sv not found in TB directory: {tb_sv}", file=sys.stderr)
        sys.exit(1)
    if not sim_main_cpp.exists():
        print(f"sim_main.cpp not found in TB directory: {sim_main_cpp}", file=sys.stderr)
        sys.exit(1)

    # Create run directory: ip_level/<tb_dir_name>
    tb_dirname = tb_path.name  # Gets the last directory name from the path
    run_dir_name = tb_dirname
    run_dir_path = Path("runs/ip_level") / run_dir_name
    
    # Create the run directory if it doesn't exist
    run_dir_path.mkdir(parents=True, exist_ok=True)
    print(f"Created run directory: {run_dir_path}\n")

    # 1) Verilator compilation
    print("========== [1/3] VERILATOR COMPILATION ==========")
    print("Starting Verilator simulation...")
    
    # Create build directory for intermediate files
    build_dir = Path("build/ip_level") / run_dir_name
    build_dir.mkdir(parents=True, exist_ok=True)
    print(f"Created build directory: {build_dir}")
    
    # Clean previous build artifacts
    safe_remove_directory(build_dir)
    build_dir.mkdir(parents=True, exist_ok=True)
    
    # Build verilator command with proper include paths (relative to root directory)
    verilator_cmd = [
        "verilator_bin", "-Wall", "--trace", "--trace-fst", "--trace-depth", "4", "--timing",
        "--cc", str(tb_sv.resolve().as_posix()),  # Convert to forward slashes
        "--exe", str(sim_main_cpp.resolve().as_posix()),  # Convert to forward slashes and resolve
        "--Mdir", str(build_dir),  # Use absolute path
        "-f", str(flist_path),  # Include file list
        "-O3", "-Wno-fatal", "--top-module", args.top_module,  # Use the specified top-level module
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
    
    # 2) Build with make
    print("========== [2/3] MAKE BUILD ==========")
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

    # 3) Run simulation
    print("========== [3/3] RUNNING SIMULATION! ==========", flush=True)
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
    
    # Run simulation from the run directory
    if os.system(f"cd {run_dir_path.as_posix()} && {sim_cmd}") != 0:
        print("Simulation failed", file=sys.stderr)
        sys.exit(1)
    
    print("========== SIMULATION COMPLETE! =================\n", flush=True)

if __name__ == "__main__":
    main()
