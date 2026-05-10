#!/usr/bin/env python3
"""
Creates a fixed-layout cartridge binary from the ELF file.
Respects all absolute addresses defined in the linker script.
"""

import sys
import subprocess
from pathlib import Path

def main():
    if len(sys.argv) < 3:
        print("Usage: make_cartridge.py <ELF file> <output bin>")
        sys.exit(1)

    elf_path = Path(sys.argv[1])
    output_bin = Path(sys.argv[2])
    rom_size = 0x1000000  # 16MB

    if not elf_path.exists():
        print(f"Error: ELF file not found: {elf_path}")
        sys.exit(1)

    # Create blank ROM filled with 0xFF (standard for flash cartridges)
    rom = bytearray(b'\xFF' * rom_size)

    # Define sections and their exact addresses
    sections = [
        (".battle",           0x000000),
        (".map",              0x040000),
        (".strings_items",    0x400000),
        (".strings_creatures",0x410000),
        (".strings_spells",   0x420000),
        (".strings_attacks",  0x430000),
        (".strings_trainers", 0x440000),
        (".strings_objects",  0x450000),
        (".sprites_items",    0x500000),
        (".sprites_creatures",0x510000),
        (".sprites_spells",   0x520000),
        (".sprites_attacks",  0x530000),
        (".sprites_trainers", 0x540000),
        (".sprites_objects",  0x550000),
    ]

    print("Building cartridge with fixed addresses...")

    for section_name, address in sections:
        tmp_file = Path(f"{section_name}.tmp")

        # Extract section from ELF
        result = subprocess.run([
            "arm-none-eabi-objcopy",
            "--dump-section", f"{section_name}={tmp_file}",
            str(elf_path)
        ], capture_output=True)

        if result.returncode == 0 and tmp_file.exists():
            data = tmp_file.read_bytes()
            rom[address:address + len(data)] = data
            print(f"✓ Placed {section_name:<20} at 0x{address:06X}  ({len(data):,} bytes)")
            tmp_file.unlink()
        else:
            print(f"  No data for {section_name}")

    # Write final binary
    output_bin.write_bytes(rom)
    print(f"\nSuccess! Created {output_bin.name} ({rom_size//1024//1024} MB)")
    print(f"   sprites_objects should be at offset 0x550000")

if __name__ == "__main__":
    main()