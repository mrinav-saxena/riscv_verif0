#!/usr/bin/env python3
import argparse
import subprocess
from pathlib import Path
import sys
import struct

def run(cmd: list):
    try:
        subprocess.check_call(cmd)
    except subprocess.CalledProcessError as e:
        print(f"Command failed: {' '.join(cmd)}", file=sys.stderr)
        sys.exit(e.returncode)
    except FileNotFoundError:
        print(f"Tool not found: {cmd[0]} (is it in PATH?)", file=sys.stderr)
        sys.exit(127)


def emit_hex(bin_path: Path, hex_path: Path):
    data = bin_path.read_bytes()
    # pad to 4-byte boundary
    if len(data) % 4 != 0:
        data += b"\x00" * (4 - (len(data) % 4))
    with hex_path.open('w', encoding='ascii') as f:
        for i in range(0, len(data), 4):
            word = int.from_bytes(data[i:i+4], 'little')
            f.write(f"{word:08x}\n")


def extract_sections(elf_path: Path, out_dir: Path):
    """Extract text and data sections from ELF file"""
    # Use objcopy to extract sections
    text_bin = out_dir / "text.bin"
    data_bin = out_dir / "data.bin"
    
    # Extract both .text.startup and .text sections (startup comes first)
    text_cmd = [
        "riscv-none-elf-objcopy",
        "-O", "binary",
        "--only-section=.text.startup",
        "--only-section=.text",
        str(elf_path),
        str(text_bin)
    ]
    run(text_cmd)
    
    # Extract data section
    data_cmd = [
        "riscv-none-elf-objcopy",
        "-O", "binary",
        "--only-section=.data",
        str(elf_path),
        str(data_bin)
    ]
    run(data_cmd)
    
    return text_bin, data_bin


def main():
    
    parser = argparse.ArgumentParser(description="Build RV32I ELF/BIN/HEX from C using a linker script.")
    parser.add_argument("-code", dest="c_file", required=True, help="Path to input C source file (RV32I)")
    parser.add_argument("-linker", dest="linker_script", required=True, help="Path to linker script (link.ld)")
    parser.add_argument("-gcc", default="riscv-none-elf-gcc", help="RISC-V GCC executable name")
    parser.add_argument("-objcopy", default="riscv-none-elf-objcopy", help="RISC-V objcopy executable name")
    parser.add_argument("-objdump", default="riscv-none-elf-objdump", help="RISC-V objdump executable name")
    args = parser.parse_args()

    c_path = Path(args.c_file).resolve()
    ld_path = Path(args.linker_script).resolve()
    
    # Find startup.s file in the same directory as the linker script
    startup_path = ld_path.parent / "startup.s"

    if not c_path.exists():
        print(f"C file not found: {c_path}", file=sys.stderr)
        sys.exit(1)
    if not ld_path.exists():
        print(f"Linker script not found: {ld_path}", file=sys.stderr)
        sys.exit(1)
    if not startup_path.exists():
        print(f"Startup file not found: {startup_path}", file=sys.stderr)
        sys.exit(1)

    # Create output directory structure: sim/images/{c_filename}/
    base = c_path.stem
    out_dir = Path("sim/images") / base
    out_dir.mkdir(parents=True, exist_ok=True)
    
    # Use shorter, more relevant filenames
    elf_path = out_dir / "program.elf"
    bin_path = out_dir / "program.bin"
    imem_hex_path = out_dir / "imem.hex"
    dmem_hex_path = out_dir / "dmem.hex"
    asm_path = out_dir / "program.s"
    disasm_path = out_dir / "program.disasm"

    gcc_cmd = [
        args.gcc,
        "-march=rv32i",
        "-mabi=ilp32",
        "-nostdlib",
        "-nostartfiles",
        "-T", str(ld_path),
        "-Wl,--no-relax",
        "-o", str(elf_path),
        str(startup_path),  # Include startup.s first
        str(c_path),
    ]
    run(gcc_cmd)

    # Generate assembly file
    gcc_asm_cmd = [
        args.gcc,
        "-march=rv32i",
        "-mabi=ilp32",
        "-nostdlib",
        "-nostartfiles",
        "-T", str(ld_path),
        "-Wl,--no-relax",
        "-S",  # Generate assembly
        "-o", str(asm_path),
        str(c_path),
    ]
    run(gcc_asm_cmd)

    # Generate disassembly from ELF
    objdump_cmd = [
        args.objdump,
        "-d",  # Disassemble
        "-M", "no-aliases",  # No instruction aliases for cleaner output
        str(elf_path),
    ]
    
    # Capture objdump output to file
    try:
        result = subprocess.run(objdump_cmd, capture_output=True, text=True, check=True)
        with open(disasm_path, 'w') as f:
            f.write(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"Warning: objdump failed: {e}", file=sys.stderr)
        # Create empty disasm file if objdump fails
        disasm_path.write_text("")

    # Generate complete binary (for backward compatibility)
    objcopy_cmd = [
        args.objcopy,
        "-O", "binary",
        str(elf_path),
        str(bin_path),
    ]
    run(objcopy_cmd)

    # Extract sections and generate separate hex files
    text_bin, data_bin = extract_sections(elf_path, out_dir)
    
    # Generate imem.hex from text section
    emit_hex(text_bin, imem_hex_path)
    
    # Generate dmem.hex from data section
    emit_hex(data_bin, dmem_hex_path)
    
    # Clean up temporary files
    text_bin.unlink(missing_ok=True)
    data_bin.unlink(missing_ok=True)

    print(f"ELF: {elf_path}")
    print(f"BIN: {bin_path}")
    print(f"IMEM HEX: {imem_hex_path}")
    print(f"DMEM HEX: {dmem_hex_path}")
    print(f"ASM: {asm_path}")
    print(f"DISASM: {disasm_path}")

if __name__ == "__main__":
    main()
