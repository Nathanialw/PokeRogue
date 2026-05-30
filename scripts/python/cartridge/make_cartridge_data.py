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
    elf_path = Path("../build-cartridge-data/src/GameCartridge/data/GameCartridgeData")
    output_bin = Path("../bin/cartridge_data.bin")
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
        #   DATA
        # char sprite colors
        ".char_sprites_items",
        ".char_sprites_monsters",
        ".char_sprites_objects",
        ".char_sprites_trainers",
        ".char_sprites_biomes",

        # tilesets
        ".tileset_theme",
        ".tileset_creatures",

        # strings
        ".strings_menu_main",
        ".strings_menu_battle",
        ".strings_menu_options",
        ".strings_names_items",
        ".strings_names_creatures",
        ".strings_names_spells",
        ".strings_names_skills",
        ".strings_names_objects",
        ".strings_names_trainers",
        ".strings_descriptions_items",
        ".strings_descriptions_creatures",
        ".strings_descriptions_spells",
        ".strings_descriptions_skills",
        ".strings_descriptions_objects",
        ".strings_descriptions_trainers",
        ".strings_types",

        # sprites
        ".sprite_battler_layout_back",
        ".sprite_battler_layout_front",
        ".sprite_battler_back",
        ".sprite_battler_front",
        ".sprite_items_layout",
        ".sprite_creatures_layout",
        ".sprite_spells_layout",
        ".sprite_skills_layout",
        ".sprite_objects_layout",
        ".sprite_trainers_layout",
        ".sprite_items",
        ".sprite_creatures",
        ".sprite_spells",
        ".sprite_skills",
        ".sprite_objects",
        ".sprite_trainers",

        # map sprites
        ".sprite_16x16_creature",
        ".sprite_16x16_item",
        ".sprite_16x16_object",
        ".sprite_16x16_trainer",
        ".sprite_16x16_tile",
        ".sprite_16x16_creature_metaData",
        ".sprite_16x16_item_metaData",
        ".sprite_16x16_object_metaData",
        ".sprite_16x16_trainer_metaData",
        ".sprite_16x16_tile_metaData",
        ".sprite_20x20_creature",
        ".sprite_20x20_item",
        ".sprite_20x20_object",
        ".sprite_20x20_trainer",
        ".sprite_20x20_tile",
        ".sprite_20x20_creature_metaData",
        ".sprite_20x20_item_metaData",
        ".sprite_20x20_object_metaData",
        ".sprite_20x20_trainer_metaData",
        ".sprite_20x20_tile_metaData",
        ".sprite_24x24_creature",
        ".sprite_24x24_item",
        ".sprite_24x24_object",
        ".sprite_24x24_trainer",
        ".sprite_24x24_tile",
        ".sprite_24x24_creature_metaData",
        ".sprite_24x24_item_metaData",
        ".sprite_24x24_object_metaData",
        ".sprite_24x24_trainer_metaData",
        ".sprite_24x24_tile_metaData",
        ".sprite_32x32_creature",
        ".sprite_32x32_item",
        ".sprite_32x32_object",
        ".sprite_32x32_trainer",
        ".sprite_32x32_tile",
        ".sprite_32x32_creature_metaData",
        ".sprite_32x32_item_metaData",
        ".sprite_32x32_object_metaData",
        ".sprite_32x32_trainer_metaData",
        ".sprite_32x32_tile_metaData",
        ".sprite_64x64_creature",
        ".sprite_64x64_item",
        ".sprite_64x64_object",
        ".sprite_64x64_trainer",
        ".sprite_64x64_tile",
        ".sprite_64x64_creature_metaData",
        ".sprite_64x64_item_metaData",
        ".sprite_64x64_object_metaData",
        ".sprite_64x64_trainer_metaData",
        ".sprite_64x64_tile_metaData",

        # fonts
        ".font_8x8",
        ".font_16x16",
        ".font_20x20",
        ".font_24x24",
        ".font_32x32",

        # game_data
        ".game_data_type_effects",
        ".game_data_creature_types",
        ".game_data_creature_stats",
        ".game_data_learnable_skills",
        ".game_data_level_up_skills",
        ".game_data_ability",
        ".game_data_spell",
        ".game_data_item",
        ".game_data_object",

        # colors
        ".colors_16",
        ".colors_256",

        # sounds
        ".sounds_music_data",
        ".sounds_music_notes",
        ".sounds_creatures",
        ".sounds_spells",
        ".sounds_skills",
        ".sounds_menus",
        ".sounds_notes",
    ]
    print("Building cartridge...")

    # rom = bytearray(b'\xFF' * rom_size)
    rom = bytearray(b'\xFF')  # * rom_size)

    p = 0x4

    addr = p
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
            defines_pos.append(addr)
            l = len(data)
            defines_size.append(l)
            addr = addr + l
            tmp_file.unlink()
        else:
            print(f"  No data for {section_name}")

    rom[0:0x4] = addr.to_bytes(4, byteorder='little')
    print(f"{addr}")
    # Generate .ld file

    # build cartridge
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
            print(f"✓ Placed {section_name:<20} at 0x{p:06X}  ({len(data):,} bytes)")
            p = p + len(data)
            tmp_file.unlink()
        else:
            print(f"  No data for {section_name}")

    # Write final binary
    output_bin.write_bytes(rom)

    print(f"\nSuccess! Created {output_bin.name} {len(rom)} ({rom_size // 1024 // 1024} MB) ({rom_size // 1024} KB) ({rom_size} B)")

    # write defines
    filename = f"{constants.INC_FOLDER}/memory_constants.inc"

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"#pragma once\n\n")
        f.write(f"//  Defines the layout of data in rom\n")
        f.write(f"///   {len(sections)} entries MAX 255\n\n\n")
        for i in range(len(sections)):
            f.write(f"#define {sections[i].upper().lstrip('.')}_POSITION {defines_pos[i]:#x} \n")
            f.write(f"#define {sections[i].upper().lstrip('.')}_SIZE {defines_size[i]:#x} \n")

        f.write("\n\n\n")
        f.write(f"///   {len(defines_pos)} entries MAX 255\n")
        f.write("\n")


if __name__ == "__main__":
    main()
