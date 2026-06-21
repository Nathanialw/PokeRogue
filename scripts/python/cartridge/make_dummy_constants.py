#!/usr/bin/env python3
import os

from python.config import constants


def main():
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
        ".sprite_battler_layout_back_64",
        ".sprite_battler_layout_front_64",
        ".sprite_battler_back_64",
        ".sprite_battler_front_64",

        ".sprite_items_layout_64",
        ".sprite_spells_layout_64",
        ".sprite_skills_layout_64",
        ".sprite_objects_layout_64",
        ".sprite_trainers_layout_64",
        ".sprite_items_64",
        ".sprite_spells_64",
        ".sprite_skills_64",
        ".sprite_objects_64",
        ".sprite_trainers_64",

        # ".sprite_battler_layout_back_16",
        # ".sprite_battler_layout_front_16",
        # ".sprite_battler_back_16",
        # ".sprite_battler_front_16",
        # ".sprite_items_layout_16",
        # ".sprite_creatures_layout_16",
        # ".sprite_spells_layout_16",
        # ".sprite_skills_layout_16",
        # ".sprite_objects_layout_16",
        # ".sprite_trainers_layout_16",
        # ".sprite_items_16",
        # ".sprite_creatures_16",
        # ".sprite_spells_16",
        # ".sprite_skills_16",
        # ".sprite_objects_16",
        # ".sprite_trainers_16",

        # ".sprite_16x16_creature",
        # ".sprite_16x16_item",
        # ".sprite_16x16_object",
        # ".sprite_16x16_trainer",
        # ".sprite_16x16_tile",
        # ".sprite_16x16_creature_metaData",
        # ".sprite_16x16_item_metaData",
        # ".sprite_16x16_object_metaData",
        # ".sprite_16x16_trainer_metaData",
        # ".sprite_16x16_tile_metaData",
        #
        # ".sprite_20x20_creature",
        # ".sprite_20x20_item",
        # ".sprite_20x20_object",
        # ".sprite_20x20_trainer",
        # ".sprite_20x20_tile",
        # ".sprite_20x20_creature_metaData",
        # ".sprite_20x20_item_metaData",
        # ".sprite_20x20_object_metaData",
        # ".sprite_20x20_trainer_metaData",
        # ".sprite_20x20_tile_metaData",
        #
        # ".sprite_24x24_creature",
        # ".sprite_24x24_item",
        # ".sprite_24x24_object",
        # ".sprite_24x24_trainer",
        # ".sprite_24x24_tile",
        # ".sprite_24x24_creature_metaData",
        # ".sprite_24x24_item_metaData",
        # ".sprite_24x24_object_metaData",
        # ".sprite_24x24_trainer_metaData",
        # ".sprite_24x24_tile_metaData",
        #
        # ".sprite_32x32_creature",
        # ".sprite_32x32_item",
        # ".sprite_32x32_object",
        # ".sprite_32x32_trainer",
        # ".sprite_32x32_tile",
        # ".sprite_32x32_creature_metaData",
        # ".sprite_32x32_item_metaData",
        # ".sprite_32x32_object_metaData",
        # ".sprite_32x32_trainer_metaData",
        # ".sprite_32x32_tile_metaData",

        ".sprite_64x64_creature",
        ".sprite_64x64_item",
        ".sprite_64x64_object",
        ".sprite_64x64_trainer",
        ".sprite_64x64_tile",
        ".sprite_64x64_environment_object",
        ".sprite_64x64_creature_metaData",
        ".sprite_64x64_item_metaData",
        ".sprite_64x64_object_metaData",
        ".sprite_64x64_trainer_metaData",
        ".sprite_64x64_tile_metaData",
        ".sprite_64x64_environment_object_metaData",

        # icons
        ".sprite_80x80_skill",
        ".sprite_80x80_skill_metaData",
        ".sprite_80x80_spell",
        ".sprite_80x80_spell_metaData",

        ".sprite_48x48_creature_buff",
        ".sprite_48x48_creature_debuff",
        ".sprite_48x48_trainer_buff",
        ".sprite_48x48_creature_buff_metaData",
        ".sprite_48x48_creature_debuff_metaData",
        ".sprite_48x48_trainer_buff_metaData",

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
        ".game_data_creature_attributes",
        ".game_data_creature_resists",
        ".game_data_learnable_skills",
        ".game_data_level_up_skills",
        ".game_data_ability",
        ".game_data_spell",
        ".game_data_item",
        ".game_data_object",
        ".game_data_trainer",

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

    if not os.path.exists(constants.CODE_INC_FOLDER):
        os.mkdir(constants.TYPES_INC_FOLDER)
    filename = f"{constants.TYPES_INC_FOLDER}/data_constants_memory.inc"

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(f"#pragma once\n\n")
        f.write(f"//  Defines the layout of data in rom\n")
        f.write(f"///   {len(sections)} entries MAX 255\n\n\n")
        for i in range(len(sections)):
            f.write(f"#define {sections[i].upper().lstrip('.')}_POSITION 0x0 \n")
            f.write(f"#define {sections[i].upper().lstrip('.')}_SIZE 0x0 \n")

        f.write("\n\n\n")
        # f.write(f"///   {len(defines_pos)} entries MAX 255\n")
        f.write("\n")


if __name__ == "__main__":
    main()
