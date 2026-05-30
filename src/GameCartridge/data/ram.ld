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
}

SECTIONS
{
    /* Start at address 0 */
    . = 0x000000;


    /* ========================================== */
    /*     FORCE ABSOLUTE POSITIONS FROM HERE     */
    /* ========================================== */


    /* ========================================== */
    /*     MAP SPRITE DATA                        */
    /* ========================================== */
    .char_sprites_items              0x1500000 : { KEEP(*(.char_sprites_items))      . = ALIGN(4); }
    .char_sprites_monsters           0x1510000 : { KEEP(*(.char_sprites_monsters))      . = ALIGN(4); }
    .char_sprites_objects            0x1520000 : { KEEP(*(.char_sprites_objects))      . = ALIGN(4); }
    .char_sprites_trainers           0x1530000 : { KEEP(*(.char_sprites_trainers))      . = ALIGN(4); }
    .char_sprites_biomes             0x1540000 : { KEEP(*(.char_sprites_biomes))      . = ALIGN(4); }

    /* ========================================== */
    /*     TIELSETS                               */
    /* ========================================== */
    .tileset_theme                   0x1600000 : { KEEP(*(.tileset_theme))      . = ALIGN(4); }
    .tileset_creatures               0x1610000 : { KEEP(*(.tileset_creatures))      . = ALIGN(4); }

    /* ========================================== */
    /*     STRINGS                                */
    /* ========================================== */
    .strings_menu_main               0x1700000 : { KEEP(*(.strings_menu_main))     . = ALIGN(4); }
    .strings_menu_battle             0x1710000 : { KEEP(*(.strings_menu_battle))     . = ALIGN(4); }
    .strings_menu_options            0x1720000 : { KEEP(*(.strings_menu_options))     . = ALIGN(4); }
    .strings_names_items             0x1730000 : { KEEP(*(.strings_names_items))     . = ALIGN(4); }
    .strings_names_creatures         0x1740000 : { KEEP(*(.strings_names_creatures))  . = ALIGN(4); }
    .strings_names_spells            0x1750000 : { KEEP(*(.strings_names_spells))    . = ALIGN(4); }
    .strings_names_skills            0x1760000 : { KEEP(*(.strings_names_skills))   . = ALIGN(4); }
    .strings_names_objects           0x1770000 : { KEEP(*(.strings_names_objects))   . = ALIGN(4); }
    .strings_names_trainers          0x1780000 : { KEEP(*(.strings_names_trainers))  . = ALIGN(4); }
    .strings_descriptions_items      0x1790000 : { KEEP(*(.strings_descriptions_items))     . = ALIGN(4); }
    .strings_descriptions_creatures  0x1800000 : { KEEP(*(.strings_descriptions_creatures))  . = ALIGN(4); }
    .strings_descriptions_spells     0x1810000 : { KEEP(*(.strings_descriptions_spells))    . = ALIGN(4); }
    .strings_descriptions_skills     0x1820000 : { KEEP(*(.strings_descriptions_skills))   . = ALIGN(4); }
    .strings_descriptions_objects    0x1830000 : { KEEP(*(.strings_descriptions_objects))   . = ALIGN(4); }
    .strings_descriptions_trainers   0x1840000 : { KEEP(*(.strings_descriptions_trainers))  . = ALIGN(4); }
    .strings_types                   0x1850000 : { KEEP(*(.strings_types))  . = ALIGN(4); }

    /* ========================================== */
    /*     GRAPHICS                               */
    /* ========================================== */
    .sprite_battler_layout_back      0x1860000 : { KEEP(*(.sprite_battler_layout_back))  . = ALIGN(4); }
    .sprite_battler_layout_front     0x1870000 : { KEEP(*(.sprite_battler_layout_front))  . = ALIGN(4); }
    .sprite_battler_back             0x1880000 : { KEEP(*(.sprite_battler_back))  . = ALIGN(4); }
    .sprite_battler_front            0x19500000 : { KEEP(*(.sprite_battler_front))  . = ALIGN(4); }
    .sprite_items_layout             0x40400000 : { KEEP(*(.sprite_items_layout))  . = ALIGN(4); }
    .sprite_creatures_layout         0x40500000 : { KEEP(*(.sprite_creatures_layout))  . = ALIGN(4); }
    .sprite_spells_layout            0x40600000 : { KEEP(*(.sprite_spells_layout))  . = ALIGN(4); }
    .sprite_skills_layout            0x40700000 : { KEEP(*(.sprite_skills_layout))  . = ALIGN(4); }
    .sprite_objects_layout           0x40800000 : { KEEP(*(.sprite_objects_layout))  . = ALIGN(4); }
    .sprite_trainers_layout          0x40900000 : { KEEP(*(.sprite_trainers_layout))  . = ALIGN(4); }
    .sprite_items                    0x40000000 : { KEEP(*(.sprite_items))  . = ALIGN(4); }
    .sprite_creatures                0x41000000 : { KEEP(*(.sprite_creatures))  . = ALIGN(4); }
    .sprite_spells                   0x42000000 : { KEEP(*(.sprite_spells))  . = ALIGN(4); }
    .sprite_skills                   0x43000000 : { KEEP(*(.sprite_skills))  . = ALIGN(4); }
    .sprite_objects                  0x44000000 : { KEEP(*(.sprite_objects))  . = ALIGN(4); }
    .sprite_trainers                 0x45000000 : { KEEP(*(.sprite_trainers))  . = ALIGN(4); }
    /*     MAP SPRITES                               */
    .sprite_16x16_creature           0x50000000 : { KEEP(*(.sprite_16x16_creature))  . = ALIGN(4); }
    .sprite_16x16_item               0x51000000 : { KEEP(*(.sprite_16x16_item))  . = ALIGN(4); }
    .sprite_16x16_object             0x52000000 : { KEEP(*(.sprite_16x16_object))  . = ALIGN(4); }
    .sprite_16x16_trainer            0x53000000 : { KEEP(*(.sprite_16x16_trainer))  . = ALIGN(4); }
    .sprite_16x16_tile               0x54000000 : { KEEP(*(.sprite_16x16_tile))  . = ALIGN(4); }
    .sprite_16x16_creature_metaData  0x55000000 : { KEEP(*(.sprite_16x16_creature_metaData))  . = ALIGN(4); }
    .sprite_16x16_item_metaData      0x56000000 : { KEEP(*(.sprite_16x16_item_metaData))  . = ALIGN(4); }
    .sprite_16x16_object_metaData    0x57000000 : { KEEP(*(.sprite_16x16_object_metaData))  . = ALIGN(4); }
    .sprite_16x16_trainer_metaData   0x58000000 : { KEEP(*(.sprite_16x16_trainer_metaData))  . = ALIGN(4); }
    .sprite_16x16_tile_metaData      0x59000000 : { KEEP(*(.sprite_16x16_tile_metaData))  . = ALIGN(4); }
    .sprite_20x20_creature           0x60000000 : { KEEP(*(.sprite_20x20_creature))  . = ALIGN(4); }
    .sprite_20x20_item               0x61000000 : { KEEP(*(.sprite_20x20_item))  . = ALIGN(4); }
    .sprite_20x20_object             0x62000000 : { KEEP(*(.sprite_20x20_object))  . = ALIGN(4); }
    .sprite_20x20_trainer            0x63000000 : { KEEP(*(.sprite_20x20_trainer))  . = ALIGN(4); }
    .sprite_20x20_tile               0x64000000 : { KEEP(*(.sprite_20x20_tile))  . = ALIGN(4); }
    .sprite_20x20_creature_metaData  0x65000000 : { KEEP(*(.sprite_20x20_creature_metaData))  . = ALIGN(4); }
    .sprite_20x20_item_metaData      0x66000000 : { KEEP(*(.sprite_20x20_item_metaData))  . = ALIGN(4); }
    .sprite_20x20_object_metaData    0x67000000 : { KEEP(*(.sprite_20x20_object_metaData))  . = ALIGN(4); }
    .sprite_20x20_trainer_metaData   0x68000000 : { KEEP(*(.sprite_20x20_trainer_metaData))  . = ALIGN(4); }
    .sprite_20x20_tile_metaData      0x69000000 : { KEEP(*(.sprite_20x20_tile_metaData))  . = ALIGN(4); }
    .sprite_24x24_creature           0x70000000 : { KEEP(*(.sprite_24x24_creature))  . = ALIGN(4); }
    .sprite_24x24_item               0x71000000 : { KEEP(*(.sprite_24x24_item))  . = ALIGN(4); }
    .sprite_24x24_object             0x72000000 : { KEEP(*(.sprite_24x24_object))  . = ALIGN(4); }
    .sprite_24x24_trainer            0x73000000 : { KEEP(*(.sprite_24x24_trainer))  . = ALIGN(4); }
    .sprite_24x24_tile               0x74000000 : { KEEP(*(.sprite_24x24_tile))  . = ALIGN(4); }
    .sprite_24x24_creature_metaData  0x75000000 : { KEEP(*(.sprite_24x24_creature_metaData))  . = ALIGN(4); }
    .sprite_24x24_item_metaData      0x76000000 : { KEEP(*(.sprite_24x24_item_metaData))  . = ALIGN(4); }
    .sprite_24x24_object_metaData    0x77000000 : { KEEP(*(.sprite_24x24_object_metaData))  . = ALIGN(4); }
    .sprite_24x24_trainer_metaData   0x78000000 : { KEEP(*(.sprite_24x24_trainer_metaData))  . = ALIGN(4); }
    .sprite_24x24_tile_metaData      0x79000000 : { KEEP(*(.sprite_24x24_tile_metaData))  . = ALIGN(4); }
    .sprite_32x32_creature           0x80000000 : { KEEP(*(.sprite_32x32_creature))  . = ALIGN(4); }
    .sprite_32x32_item               0x81000000 : { KEEP(*(.sprite_32x32_item))  . = ALIGN(4); }
    .sprite_32x32_object             0x82000000 : { KEEP(*(.sprite_32x32_object))  . = ALIGN(4); }
    .sprite_32x32_trainer            0x83000000 : { KEEP(*(.sprite_32x32_trainer))  . = ALIGN(4); }
    .sprite_32x32_tile               0x84000000 : { KEEP(*(.sprite_32x32_tile))  . = ALIGN(4); }
    .sprite_32x32_creature_metaData  0x85000000 : { KEEP(*(.sprite_32x32_creature_metaData))  . = ALIGN(4); }
    .sprite_32x32_item_metaData      0x86000000 : { KEEP(*(.sprite_32x32_item_metaData))  . = ALIGN(4); }
    .sprite_32x32_object_metaData    0x87000000 : { KEEP(*(.sprite_32x32_object_metaData))  . = ALIGN(4); }
    .sprite_32x32_trainer_metaData   0x88000000 : { KEEP(*(.sprite_32x32_trainer_metaData))  . = ALIGN(4); }
    .sprite_32x32_tile_metaData      0x89000000 : { KEEP(*(.sprite_32x32_tile_metaData))  . = ALIGN(4); }
    .sprite_64x64_creature           0x90000000 : { KEEP(*(.sprite_64x64_creature))  . = ALIGN(4); }
    .sprite_64x64_item               0x91000000 : { KEEP(*(.sprite_64x64_item))  . = ALIGN(4); }
    .sprite_64x64_object             0x92000000 : { KEEP(*(.sprite_64x64_object))  . = ALIGN(4); }
    .sprite_64x64_trainer            0x93000000 : { KEEP(*(.sprite_64x64_trainer))  . = ALIGN(4); }
    .sprite_64x64_tile               0x94000000 : { KEEP(*(.sprite_64x64_tile))  . = ALIGN(4); }
    .sprite_64x64_creature_metaData  0x95000000 : { KEEP(*(.sprite_64x64_creature_metaData))  . = ALIGN(4); }
    .sprite_64x64_item_metaData      0x96000000 : { KEEP(*(.sprite_64x64_item_metaData))  . = ALIGN(4); }
    .sprite_64x64_object_metaData    0x97000000 : { KEEP(*(.sprite_64x64_object_metaData))  . = ALIGN(4); }
    .sprite_64x64_trainer_metaData   0x98000000 : { KEEP(*(.sprite_64x64_trainer_metaData))  . = ALIGN(4); }
    .sprite_64x64_tile_metaData      0x99000000 : { KEEP(*(.sprite_64x64_tile_metaData))  . = ALIGN(4); }


    /* ========================================== */
    /*     FONTS                                  */
    /* ========================================== */
    .font_8x8                        0x176000000 : { KEEP(*(.font_8x8))  . = ALIGN(4); }
    .font_16x16                      0x177000000 : { KEEP(*(.font_16x16))  . = ALIGN(4); }
    .font_20x20                      0x178000000 : { KEEP(*(.font_20x20))  . = ALIGN(4); }
    .font_24x24                      0x179000000 : { KEEP(*(.font_24x24))  . = ALIGN(4); }
    .font_32x32                      0x180000000 : { KEEP(*(.font_32x32))  . = ALIGN(4); }

    /* ========================================== */
    /*      GAME DATA                             */
    /* ========================================== */
    .game_data_type_effects          0x185000000 : { KEEP(*(.game_data_type_effects))  . = ALIGN(4); }
    .game_data_creature_types        0x186000000 : { KEEP(*(.game_data_creature_types))  . = ALIGN(4); }
    .game_data_creature_stats        0x187000000 : { KEEP(*(.game_data_creature_stats))  . = ALIGN(4); }
    .game_data_learnable_skills      0x188000000 : { KEEP(*(.game_data_learnable_skills))  . = ALIGN(4); }
    .game_data_level_up_skills       0x189000000 : { KEEP(*(.game_data_level_up_skills))  . = ALIGN(4); }
    .game_data_ability               0x190000000 : { KEEP(*(.game_data_ability))  . = ALIGN(4); }
    .game_data_spell                 0x191000000 : { KEEP(*(.game_data_spell))  . = ALIGN(4); }
    .game_data_item                  0x192000000 : { KEEP(*(.game_data_item))  . = ALIGN(4); }
    .game_data_object                0x193000000 : { KEEP(*(.game_data_object))  . = ALIGN(4); }

    /* ========================================== */
    /*      COLORS                                */
    /* ========================================== */
    .colors_16                       0x1900000000 : { KEEP(*(.colors_16))  . = ALIGN(4); }
    .colors_256                      0x1910000000 : { KEEP(*(.colors_256))  . = ALIGN(4); }
    /* ========================================== */
    /*      SOUNDS                                */
    /* ========================================== */
    .sounds_music_data               0x1920000000 : { KEEP(*(.sounds_music_data))  . = ALIGN(4); }
    .sounds_music_notes              0x1930000000 : { KEEP(*(.sounds_music_notes))  . = ALIGN(4); }
    .sounds_creatures                0x1940000000 : { KEEP(*(.sounds_creatures))  . = ALIGN(4); }
    .sounds_spells                   0x1950000000 : { KEEP(*(.sounds_spells))  . = ALIGN(4); }
    .sounds_skills                   0x1960000000 : { KEEP(*(.sounds_skills))  . = ALIGN(4); }
    .sounds_menus                    0x1970000000 : { KEEP(*(.sounds_menus))  . = ALIGN(4); }
    .sounds_notes                    0x1980000000 : { KEEP(*(.sounds_notes))  . = ALIGN(4); }


    . = 0x10000000000;


    /* This is the critical one */
/*    . = 0x650000;*/
/*    .sprites_objects    0x900000 : { KEEP(*(.sprites_objects))    . = ALIGN(4); }*/

    __rom_end = .;
    end = .;
}
