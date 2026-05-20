#!/usr/bin/env python3
"""
Creates a fixed-layout cartridge binary from the ELF file.
Respects all absolute addresses defined in the linker script.
"""
import sys
import subprocess
from pathlib import Path

from python.config import constants


def main():
    elf_path = Path("../build-cartridge-code/src/GameCartridge/code/GameCartridgeCode")
    output_bin = Path("../build-cartridge-code/src/GameCartridge/code/cartridge_code.bin")
    # rom_size = 0x1000000  # 16MB
    rom_size = 0x0400000  # 4MB

    if not elf_path.exists():
        print(f"Error: ELF file not found: {elf_path}")
        sys.exit(1)

    # Create blank ROM filled with 0xFF (standard for flash cartridges)

    # Define sections and their exact addresses
    defines_pos = []
    defines_size = []

    sections = [
        # code
        ".core",
        ".splash",
        ".map",
        ".map_gen",
        ".battle",

    ]
    print("Building cartridge...")

    header_size = (len(sections) * 8) + 1
    rom = bytearray(b'\xFF')  # * (rom_size - (header_size - 4)))

    addr = 0
    p = 0x0
    rom[p:0x4] = addr.to_bytes(4, byteorder='little')
    p = 0x4
    addr += 0x4

    rom[p:0x1] = len(sections).to_bytes(1, byteorder='little')
    p = p + 0x1

    addr += header_size
    # build header
    for section_name in sections:
        tmp_file = Path(f"{section_name}.tmp")

        # Extract section from ELF
        result = subprocess.run([
            "arm-none-eabi-objcopy",
            "--dump-section", f"{section_name}={tmp_file}",
            str(elf_path)
        ], capture_output=True)

        if result.returncode == 0 and tmp_file.exists():
            data = tmp_file.read_bytes()

            rom[p:0x4] = addr.to_bytes(4, byteorder='little')
            p = p + 0x4
            defines_pos.append(addr)

            l = len(data)
            defines_size.append(l)
            rom[p:0x4] = l.to_bytes(4, byteorder='little')
            p = p + 0x4

            addr = addr + l
            tmp_file.unlink()
        else:
            print(f"  No data for {section_name}")

    rom[0:0x4] = addr.to_bytes(4, byteorder='little')

    # Generate .ld file

    # build cartridge
    i = 0
    for section_name in sections:
        tmp_file = Path(f"{section_name}.tmp")

        # Extract section from ELF
        result = subprocess.run([
            "arm-none-eabi-objcopy",
            "--dump-section", f"{section_name}={tmp_file}",
            str(elf_path)
        ], capture_output=True)

        if result.returncode == 0 and tmp_file.exists():
            data = tmp_file.read_bytes()
            rom[p:p + len(data)] = data
            p = p + len(data)
            print(f"✓ Placed {section_name:<20} at {defines_pos[i]}  ({len(data):,} bytes)")
            tmp_file.unlink()
            i+=1
        else:
            print(f"  No data for {section_name}")

    # Write final binary
    output_bin.write_bytes(rom)

    print(f"\nSuccess! Created {output_bin.name} {len(rom)} ({rom_size // 1024 // 1024} MB) ({rom_size // 1024} KB) ({rom_size} B)")


if __name__ == "__main__":
    main()
