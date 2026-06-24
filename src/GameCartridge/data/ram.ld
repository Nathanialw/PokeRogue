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
    .strings_entity_effects          0x1860000 : { KEEP(*(.strings_entity_effects))  . = ALIGN(4); }

    /* ========================================== */
    /*     BATTLER SPRITES                        */
    /* ========================================== */
    .sprite_battler_layout_back_64               0x3860000 : { KEEP(*(.sprite_battler_layout_back_64))  . = ALIGN(4); }
    .sprite_battler_layout_front_64              0x48700000 : { KEEP(*(.sprite_battler_layout_front_64))  . = ALIGN(4); }
    .sprite_battler_back_64                      0x58800000 : { KEEP(*(.sprite_battler_back_64))  . = ALIGN(4); }
    .sprite_battler_front_64                     0x69500000 : { KEEP(*(.sprite_battler_front_64))  . = ALIGN(4); }
    .sprite_trainers_layout_front_64             0x76090000 : { KEEP(*(.sprite_trainers_layout_front_64))  . = ALIGN(4); }
    .sprite_trainers_layout_back_64              0x86090000 : { KEEP(*(.sprite_trainers_layout_back_64))  . = ALIGN(4); }
    .sprite_trainers_front_64                    0x96000000 : { KEEP(*(.sprite_trainers_front_64))  . = ALIGN(4); }
    .sprite_trainers_back_64                    0x106000000 : { KEEP(*(.sprite_trainers_back_64))  . = ALIGN(4); }

    .sprite_items_layout_64                     0x121000000 : { KEEP(*(.sprite_items_layout_64))  . = ALIGN(4); }
    .sprite_spells_layout_64                    0x140600000 : { KEEP(*(.sprite_spells_layout_64))  . = ALIGN(4); }
    .sprite_skills_layout_64                    0x180000000 : { KEEP(*(.sprite_skills_layout_64))  . = ALIGN(4); }
    .sprite_objects_layout_64                   0x220800000 : { KEEP(*(.sprite_objects_layout_64))  . = ALIGN(4); }
    .sprite_trainers_layout_64                  0x260900000 : { KEEP(*(.sprite_trainers_layout_64))  . = ALIGN(4); }
    .sprite_environment_objects_layout_64       0x300000000 : { KEEP(*(.sprite_environment_objects_layout_64))  . = ALIGN(4); }
    .sprite_items_64                            0x342000000 : { KEEP(*(.sprite_items_64))  . = ALIGN(4); }
    .sprite_spells_64                           0x383000000 : { KEEP(*(.sprite_spells_64))  . = ALIGN(4); }
    .sprite_skills_64                           0x424000000 : { KEEP(*(.sprite_skills_64))  . = ALIGN(4); }
    .sprite_objects_64                          0x465000000 : { KEEP(*(.sprite_objects_64))  . = ALIGN(4); }
    .sprite_environment_objects_64              0x540000000 : { KEEP(*(.sprite_environment_objects_64))  . = ALIGN(4); }

    .sprite_64x64_creature                      0x900000000 : { KEEP(*(.sprite_64x64_creature))  . = ALIGN(4); }
    .sprite_64x64_item                          0x910000000 : { KEEP(*(.sprite_64x64_item))  . = ALIGN(4); }
    .sprite_64x64_object                        0x920000000 : { KEEP(*(.sprite_64x64_object))  . = ALIGN(4); }
    .sprite_64x64_trainer                       0x930000000 : { KEEP(*(.sprite_64x64_trainer))  . = ALIGN(4); }
    .sprite_64x64_tile                          0x940000000 : { KEEP(*(.sprite_64x64_tile))  . = ALIGN(4); }
    .sprite_64x64_environment_object            0x950000000 : { KEEP(*(.sprite_64x64_environment_object))  . = ALIGN(4); }
    .sprite_64x64_creature_metaData             0x960000000 : { KEEP(*(.sprite_64x64_creature_metaData))  . = ALIGN(4); }
    .sprite_64x64_item_metaData                 0x970000000 : { KEEP(*(.sprite_64x64_item_metaData))  . = ALIGN(4); }
    .sprite_64x64_object_metaData               0x980000000 : { KEEP(*(.sprite_64x64_object_metaData))  . = ALIGN(4); }
    .sprite_64x64_trainer_metaData              0x990000000 : { KEEP(*(.sprite_64x64_trainer_metaData))  . = ALIGN(4); }
    .sprite_64x64_tile_metaData                 0x1000000000 : { KEEP(*(.sprite_64x64_tile_metaData))  . = ALIGN(4); }
    .sprite_64x64_environment_object_metaData   0x1100000000 : { KEEP(*(.sprite_64x64_environment_object_metaData))  . = ALIGN(4); }

    /* ========================================== */
    /*     ICONS                                  */
    /* ========================================== */
    .sprite_80x80_skill                         0x1200000000 : { KEEP(*(.sprite_80x80_skill))  . = ALIGN(4); }
    .sprite_80x80_skill_metaData                0x1300000000 : { KEEP(*(.sprite_80x80_skill_metaData))  . = ALIGN(4); }
    .sprite_80x80_spell                         0x1400000000 : { KEEP(*(.sprite_80x80_spell))  . = ALIGN(4); }
    .sprite_80x80_spell_metaData                0x1500000000 : { KEEP(*(.sprite_80x80_spell_metaData))  . = ALIGN(4); }
    .sprite_48x48_creature_buff                 0x1600000000 : { KEEP(*(.sprite_48x48_creature_buff))  . = ALIGN(4); }
    .sprite_48x48_creature_debuff               0x1610000000 : { KEEP(*(.sprite_48x48_creature_debuff))  . = ALIGN(4); }
    .sprite_48x48_trainer_buff                  0x1620000000 : { KEEP(*(.sprite_48x48_trainer_buff))  . = ALIGN(4); }
    .sprite_48x48_creature_buff_metaData        0x1630000000 : { KEEP(*(.sprite_48x48_creature_buff_metaData))  . = ALIGN(4); }
    .sprite_48x48_creature_debuff_metaData      0x1640000000 : { KEEP(*(.sprite_48x48_creature_debuff_metaData))  . = ALIGN(4); }
    .sprite_48x48_trainer_buff_metaData         0x1650000000 : { KEEP(*(.sprite_48x48_trainer_buff_metaData))  . = ALIGN(4); }

    /* ========================================== */
    /*     FONTS                                  */
    /* ========================================== */
    .font_8x8                                   0x1760000000 : { KEEP(*(.font_8x8))  . = ALIGN(4); }
    .font_16x16                                 0x1770000000 : { KEEP(*(.font_16x16))  . = ALIGN(4); }
    .font_20x20                                 0x1780000000 : { KEEP(*(.font_20x20))  . = ALIGN(4); }
    .font_24x24                                 0x1790000000 : { KEEP(*(.font_24x24))  . = ALIGN(4); }
    .font_32x32                                 0x1800000000 : { KEEP(*(.font_32x32))  . = ALIGN(4); }

    /* ========================================== */
    /*      GAME DATA                             */
    /* ========================================== */
    .game_data_type_effects                     0x1850000000 : { KEEP(*(.game_data_type_effects))  . = ALIGN(4); }
    .game_data_creature_types                   0x1860000000 : { KEEP(*(.game_data_creature_types))  . = ALIGN(4); }
    .game_data_creature_stats                   0x1870000000 : { KEEP(*(.game_data_creature_stats))  . = ALIGN(4); }
    .game_data_creature_attributes              0x1880000000 : { KEEP(*(.game_data_creature_attributes))  . = ALIGN(4); }
    .game_data_creature_resists                 0x1890000000 : { KEEP(*(.game_data_creature_resists))  . = ALIGN(4); }
    .game_data_learnable_skills                 0x1900000000 : { KEEP(*(.game_data_learnable_skills))  . = ALIGN(4); }
    .game_data_level_up_skills                  0x1910000000 : { KEEP(*(.game_data_level_up_skills))  . = ALIGN(4); }
    .game_data_ability                          0x1920000000 : { KEEP(*(.game_data_ability))  . = ALIGN(4); }
    .game_data_spell                            0x1930000000 : { KEEP(*(.game_data_spell))  . = ALIGN(4); }
    .game_data_item                             0x1940000000 : { KEEP(*(.game_data_item))  . = ALIGN(4); }
    .game_data_object                           0x1950000000 : { KEEP(*(.game_data_object))  . = ALIGN(4); }
    .game_data_trainer                          0x1960000000 : { KEEP(*(.game_data_trainer))  . = ALIGN(4); }

    /* ========================================== */
    /*      COLORS                                */
    /* ========================================== */
    .colors_16                                  0x2100000000 : { KEEP(*(.colors_16))  . = ALIGN(4); }
    .colors_256                                 0x2210000000 : { KEEP(*(.colors_256))  . = ALIGN(4); }

    /* ========================================== */
    /*      SOUNDS                                */
    /* ========================================== */
    .sounds_music_data                          0x242000000 : { KEEP(*(.sounds_music_data))  . = ALIGN(4); }
    .sounds_music_notes                         0x253000000 : { KEEP(*(.sounds_music_notes))  . = ALIGN(4); }
    .sounds_creatures                           0x264000000 : { KEEP(*(.sounds_creatures))  . = ALIGN(4); }
    .sounds_spells                              0x275000000 : { KEEP(*(.sounds_spells))  . = ALIGN(4); }
    .sounds_skills                              0x286000000 : { KEEP(*(.sounds_skills))  . = ALIGN(4); }
    .sounds_menus                               0x297000000 : { KEEP(*(.sounds_menus))  . = ALIGN(4); }
    .sounds_notes                               0x308000000 : { KEEP(*(.sounds_notes))  . = ALIGN(4); }


    . = 0x10000000000;


    /* This is the critical one */
/*    . = 0x650000;*/
/*    .sprites_objects    0x900000 : { KEEP(*(.sprites_objects))    . = ALIGN(4); }*/

    __rom_end = .;
    end = .;
}
