/*
1MB	    1,048,576	0x00100000	0x0FFFFF (1,048,575)
2MB	    2,097,152	0x00200000	0x1FFFFF
4MB	    4,194,304	0x00400000	0x3FFFFF
8MB	    8,388,608	0x00800000	0x7FFFFF
16MB	16,777,216	0x01000000	0xFFFFFF (16,777,215)
16MB	16,777,216	0x02000000	0xFFFFFF
32MB	16,777,216	0x04000000	0xFFFFFF
64MB	16,777,216	0x08000000	0xFFFFFF
128MB	16,777,216	0x10000000	0xFFFFFF
256MB	16,777,216	0x20000000	0xFFFFFF
*/

/*16MB is used right now 16777216*/
MEMORY
{
    RAM (rwx) : ORIGIN = 0x20010000, LENGTH = 4M
}

SECTIONS
{
    /* Start at address 0 */
    . = 0x000000;

    .core 0x20000000 : AT(0x0000000)   /* example cartridge address */
    {
        KEEP(*(.core))
        . = ALIGN(4);
    }

    .splash 0x20010000 : AT(0x010000)
    {
        KEEP(*(.splash_entry))   /* must come first */
        KEEP(*(.splash))
        . = ALIGN(4);
    } > RAM

    .map 0x20010000 : AT(0x020000)
    {
        KEEP(*(.map_entry))
        KEEP(*(.map))
        . = ALIGN(4);
    } > RAM

    .map_gen 0x20010000 : AT(0x030000)
    {
        KEEP(*(.map_gen_entry))
        KEEP(*(.map_gen))
        . = ALIGN(4);
    } > RAM

    /* Battle / Map Overlays */
    .battle 0x20010000 : AT(0x040000)
    {
        KEEP(*(.battle_entry))
        KEEP(*(.battle))
        . = ALIGN(4);
    } > RAM

    /* ========================================== */
    /*     FORCE ABSOLUTE POSITIONS FROM HERE     */
    /* ========================================== */

    . = 0x05000000;

    /* ========================================== */
    /*     MAP SPRITE DATA                        */
    /* ========================================== */
    .char_sprites_items              0x05000000 : { KEEP(*(.char_sprites_items))      . = ALIGN(4); }
    .char_sprites_monsters           0x05100000 : { KEEP(*(.char_sprites_monsters))      . = ALIGN(4); }
    .char_sprites_objects            0x05200000 : { KEEP(*(.char_sprites_objects))      . = ALIGN(4); }
    .char_sprites_biomes             0x05300000 : { KEEP(*(.char_sprites_biomes))      . = ALIGN(4); }

    /* ========================================== */
    /*     TIELSETS                               */
    /* ========================================== */
    .tileset_theme                   0x06000000 : { KEEP(*(.tileset_theme))      . = ALIGN(4); }
    .tileset_creatures               0x06100000 : { KEEP(*(.tileset_creatures))      . = ALIGN(4); }

    /* ========================================== */
    /*     STRINGS                                */
    /* ========================================== */
    .strings_menu_main               0x07000000 : { KEEP(*(.strings_menu_main))     . = ALIGN(4); }
    .strings_menu_battle             0x07100000 : { KEEP(*(.strings_menu_battle))     . = ALIGN(4); }
    .strings_menu_options            0x07200000 : { KEEP(*(.strings_menu_options))     . = ALIGN(4); }
    .strings_names_items             0x07300000 : { KEEP(*(.strings_names_items))     . = ALIGN(4); }
    .strings_names_creatures         0x07400000 : { KEEP(*(.strings_names_creatures))  . = ALIGN(4); }
    .strings_names_spells            0x07500000 : { KEEP(*(.strings_names_spells))    . = ALIGN(4); }
    .strings_names_skills            0x07600000 : { KEEP(*(.strings_names_skills))   . = ALIGN(4); }
    .strings_names_objects           0x07700000 : { KEEP(*(.strings_names_objects))   . = ALIGN(4); }
    .strings_names_trainers          0x07800000 : { KEEP(*(.strings_names_trainers))  . = ALIGN(4); }
    .strings_descriptions_items      0x07900000 : { KEEP(*(.strings_descriptions_items))     . = ALIGN(4); }
    .strings_descriptions_creatures  0x08000000 : { KEEP(*(.strings_descriptions_creatures))  . = ALIGN(4); }
    .strings_descriptions_spells     0x08100000 : { KEEP(*(.strings_descriptions_spells))    . = ALIGN(4); }
    .strings_descriptions_skills     0x08200000 : { KEEP(*(.strings_descriptions_skills))   . = ALIGN(4); }
    .strings_descriptions_objects    0x08300000 : { KEEP(*(.strings_descriptions_objects))   . = ALIGN(4); }
    .strings_descriptions_trainers   0x08400000 : { KEEP(*(.strings_descriptions_trainers))  . = ALIGN(4); }
    .strings_types                   0x08500000 : { KEEP(*(.strings_types))  . = ALIGN(4); }

    /* ========================================== */
    /*     GRAPHICS                               */
    /* ========================================== */
    .sprite_battler_layout_back      0x09000000 : { KEEP(*(.sprite_battler_layout_back))  . = ALIGN(4); }
    .sprite_battler_layout_front     0x09100000 : { KEEP(*(.sprite_battler_layout_front))  . = ALIGN(4); }
    .sprite_battler_back             0x09200000 : { KEEP(*(.sprite_battler_back))  . = ALIGN(4); }
    .sprite_battler_front            0x09300000 : { KEEP(*(.sprite_battler_front))  . = ALIGN(4); }
    .sprite_items_layout             0x09400000 : { KEEP(*(.sprite_items_layout))  . = ALIGN(4); }
    .sprite_creatures_layout         0x09500000 : { KEEP(*(.sprite_creatures_layout))  . = ALIGN(4); }
    .sprite_spells_layout            0x09600000 : { KEEP(*(.sprite_spells_layout))  . = ALIGN(4); }
    .sprite_skills_layout            0x09700000 : { KEEP(*(.sprite_skills_layout))  . = ALIGN(4); }
    .sprite_objects_layout           0x09800000 : { KEEP(*(.sprite_objects_layout))  . = ALIGN(4); }
    .sprite_trainers_layout          0x09900000 : { KEEP(*(.sprite_trainers_layout))  . = ALIGN(4); }
    .sprite_items                    0x10000000 : { KEEP(*(.sprite_items))  . = ALIGN(4); }
    .sprite_creatures                0x11000000 : { KEEP(*(.sprite_creatures))  . = ALIGN(4); }
    .sprite_spells                   0x12000000 : { KEEP(*(.sprite_spells))  . = ALIGN(4); }
    .sprite_skills                   0x13000000 : { KEEP(*(.sprite_skills))  . = ALIGN(4); }
    .sprite_objects                  0x14000000 : { KEEP(*(.sprite_objects))  . = ALIGN(4); }
    .sprite_trainers                 0x15000000 : { KEEP(*(.sprite_trainers))  . = ALIGN(4); }
    .sprite_map_creature             0x16000000 : { KEEP(*(.sprite_map_creature))  . = ALIGN(4); }
    .sprite_map_item                 0x17000000 : { KEEP(*(.sprite_map_item))  . = ALIGN(4); }
    .sprite_map_object               0x18000000 : { KEEP(*(.sprite_map_object))  . = ALIGN(4); }
    .sprite_map_trainer              0x19000000 : { KEEP(*(.sprite_map_trainer))  . = ALIGN(4); }
    .sprite_map_tile                 0x20000000 : { KEEP(*(.sprite_map_tile))  . = ALIGN(4); }
    .sprite_map_creature_metaData    0x21000000 : { KEEP(*(.sprite_map_creature_metaData))  . = ALIGN(4); }
    .sprite_map_item_metaData        0x22000000 : { KEEP(*(.sprite_map_item_metaData))  . = ALIGN(4); }
    .sprite_map_object_metaData      0x23000000 : { KEEP(*(.sprite_map_object_metaData))  . = ALIGN(4); }
    .sprite_map_trainer_metaData     0x24000000 : { KEEP(*(.sprite_map_trainer_metaData))  . = ALIGN(4); }
    .sprite_map_tile_metaData        0x25000000 : { KEEP(*(.sprite_map_tile_metaData))  . = ALIGN(4); }

    /* ========================================== */
    /*     FONTS                                  */
    /* ========================================== */
    .font_8x8                        0x26000000 : { KEEP(*(.font_8x8))  . = ALIGN(4); }
    .font_16x16                      0x27000000 : { KEEP(*(.font_16x16))  . = ALIGN(4); }

    /* ========================================== */
    /*      SOUNDS                                */
    /* ========================================== */
    .sounds_music_data               0x28000000 : { KEEP(*(.sounds_music_data))  . = ALIGN(4); }
    .sounds_music_notes              0x29000000 : { KEEP(*(.sounds_music_notes))  . = ALIGN(4); }
    .sounds_creatures                0x30000000 : { KEEP(*(.sounds_creatures))  . = ALIGN(4); }
    .sounds_spells                   0x31000000 : { KEEP(*(.sounds_spells))  . = ALIGN(4); }
    .sounds_skills                   0x32000000 : { KEEP(*(.sounds_skills))  . = ALIGN(4); }
    .sounds_menus                    0x33000000 : { KEEP(*(.sounds_menus))  . = ALIGN(4); }
    .sounds_notes                    0x34000000 : { KEEP(*(.sounds_notes))  . = ALIGN(4); }

    /* ========================================== */
    /*      GAME DATA                             */
    /* ========================================== */
    .game_data_type_effects          0x35000000 : { KEEP(*(.game_data_type_effects))  . = ALIGN(4); }
    .game_data_creature_types        0x36000000 : { KEEP(*(.game_data_creature_types))  . = ALIGN(4); }
    .game_data_creature_stats        0x37000000 : { KEEP(*(.game_data_creature_stats))  . = ALIGN(4); }
    .game_data_learnable_skills      0x38000000 : { KEEP(*(.game_data_learnable_skills))  . = ALIGN(4); }
    .game_data_level_up_skills       0x39000000 : { KEEP(*(.game_data_level_up_skills))  . = ALIGN(4); }
    .game_data_ability               0x40000000 : { KEEP(*(.game_data_ability))  . = ALIGN(4); }
    .game_data_spell                 0x41000000 : { KEEP(*(.game_data_spell))  . = ALIGN(4); }
    .game_data_item                  0x42000000 : { KEEP(*(.game_data_item))  . = ALIGN(4); }
    .game_data_object                0x43000000 : { KEEP(*(.game_data_object))  . = ALIGN(4); }

    /* ========================================== */
    /*      COLORS                                */
    /* ========================================== */
    .colors_16                       0x50000000 : { KEEP(*(.colors_16))  . = ALIGN(4); }
    .colors_256                      0x51000000 : { KEEP(*(.colors_256))  . = ALIGN(4); }

    . = 0x60000000;


    /* This is the critical one */
/*    . = 0x650000;*/
/*    .sprites_objects    0x900000 : { KEEP(*(.sprites_objects))    . = ALIGN(4); }*/

    __rom_end = .;
    end = .;
}
