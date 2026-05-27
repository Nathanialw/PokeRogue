// Created by nathanial on 2/26/26.
//
#include "data_rom.h"

#include "types.h"
#include "enums.h"

#include "lib_memory.h"


#ifdef STANDALONE
const GameFlash g_gameFlash =
{
    /**********************************************************************************************************************/
    /*
    **********************************************************************************************************************/
    .sprites = {
        .items =
        {
#include "inc/map_sprites_items.inc"
        },
        .monsters =
        {
#include "inc/map_sprites_creatures.inc"
        },
        .objects =
        {
#include "inc/map_sprites_objects.inc"
        },
        .biomes =
        {
#include "inc/map_sprite_biome_tiles.inc"
        },
    },

    /**********************************************************************************************************************/
    /*
    **********************************************************************************************************************/
    .tileset = {
        .monsterGroups =
        {
#include "inc/data_tileset_monsterGroups.inc"

        },
        .themeGroups =
        {
#include "inc/data_tileset_themeGroups.inc"
        }
    },

    /**********************************************************************************************************************/
    /*
    **********************************************************************************************************************/
    .text =
    {
        .menus =
        {
#include "inc/text_menus.inc"
        },

        .names =
        {
            .items =
            {
#include "inc/text_names_items.inc"
            },
            .monsters =
            {
#include "inc/text_names_creatures.inc"
            },
            .trainers =
            {
#include "inc/text_names_trainers.inc"
            },
            .spells =
            {
#include "inc/text_names_spells.inc"
            },
            .attacks =
            {
#include "inc/text_names_skills.inc"
            },
            .objects =
            {
#include "inc/text_names_objects.inc"
            },
        },
        /**********************************************************************************************************************/
        /*
        **********************************************************************************************************************/
        .descriptions =
        {
            .items =
            {
#include "inc/text_desc_items.inc"
            },
            .monsters =
            {
#include "inc/text_desc_creatures.inc"
            },
            .trainers =
            {
#include "inc/text_desc_trainers.inc"
            },
            .spells =
            {
#include "inc/text_desc_spells.inc"
            },
            .attacks =
            {
#include "inc/text_desc_skills.inc"
            },
            .objects =
            {
#include "inc/text_desc_objects.inc"
            },
        },

        .types =
        {
#include "inc/text_types.inc"
        }
    },

    /**********************************************************************************************************************/
    /*
    **********************************************************************************************************************/
    .spriteData =
    {
#ifdef INCLUDE_BATTLERS
.battlers = {
     .backLayout =
     {
#include "inc/sprite_creature_back_layout.inc"
     },
     .back =
     {
#include "inc/sprite_creature_back.inc"
     },

     .frontLayout =
     {
#include "inc/sprite_creature_front_layout.inc"
     },
     .front =
     {
#include "inc/sprite_creature_front.inc"
     },
 },

 /**********************************************************************************************************************/
 /*
 **********************************************************************************************************************/
        .itemLayout =
         {
#include "inc/sprite_item_layout.inc"
         },
        .items =
         {
#include "inc/sprite_item.inc"
         },

         /**********************************************************************************************************************/
         /*
         **********************************************************************************************************************/
        .skillLayout =
         {
#include "inc/sprite_skill_layout.inc"
         },
        .skills =
         {
#include "inc/sprite_skill.inc"
         },

         /**********************************************************************************************************************/
         /*
         **********************************************************************************************************************/
        .spellLayout =
         {
#include "inc/sprite_spell_layout.inc"
         },
        .spells =
         {
#include "inc/sprite_spell.inc"
         },

         /**********************************************************************************************************************/
         /*
         **********************************************************************************************************************/
        .objectLayout =
         {
#include "inc/sprite_object_layout.inc"
         },
        .objects =
         {
#include "inc/sprite_object.inc"
         },

         /**********************************************************************************************************************/
         /*
         **********************************************************************************************************************/
        .trainerLayout =
         {
#include "inc/sprite_trainer_layout.inc"
         },
        .trainers =
         {
#include "inc/sprite_trainer.inc"
         },
#endif


/**********************************************************************************************************************/
/*  map Sprites
**********************************************************************************************************************/
.creatureSprites =
 {
#include "inc/sprite_map_creatures.inc"
 },
        .trainerSprites =
         {
#include "inc/sprite_map_trainers.inc"
         },
        .objectSprites =
         {
#include "inc/sprite_map_objects.inc"
         },
        .itemSprites =
         {
#include "inc/sprite_map_items.inc"
         },
        .tileSprites =
         {
#include "inc/sprite_map_tiles.inc"
         },

         /**********************************************************************************************************************/
         /* text font data
         **********************************************************************************************************************/
        .font8x8 =
         {
#include "inc/data_font8x8.inc"

         },
        .font16x16 =
         {
#include "inc/data_font16x16.inc"
         },

        .font20x20 =
         {
#include "inc/data_font20x20.inc"
         },

        .font24x24 =
         {
#include "inc/data_font24x24.inc"
         },

        .font32x32 =
         {
#include "inc/data_font32x32.inc"
         },


         /**********************************************************************************************************************/
         /*
         **********************************************************************************************************************/
    .sounds =
     {
         /**********************************************************************************************************************/
         /*
         **********************************************************************************************************************/
         .music =
         {
             .musicData =
             {
#include "inc/sounds_music_data.inc"
             },
             .songs =
             {
#include "inc/sounds_music.inc"
             },
         },
         /**********************************************************************************************************************/
         /*
         **********************************************************************************************************************/
         .effects =
         {
             .creatures =
             {
#include "inc/sounds_creatures.inc"
             },
             .spells =
             {
#include "inc/sounds_spells.inc"
             },
             .attacks =
             {
#include "inc/sounds_skills.inc"
             },
             .menus =
             {
#include "inc/sounds_menu.inc"
             }
         }
     },
     /**********************************************************************************************************************/
     /*
     **********************************************************************************************************************/
    .gameData =
     {
         .typeEffects =
         {
#include "inc/data_type_effects.inc"

         },
         .creatureTypes =
         {
#include "inc/data_types_creatures.inc"

         },
         .creatureStats =
         {
#include "inc/data_creature_stats.inc"
         },
         .learnableSkills =
         {
#include "inc/data_creature_skills.inc"
         },
         .levelUpSkills =
         {
#include "inc/data_creature_level_up_skills.inc"
         },

         .abilityData =
         {
#include "inc/data_skills.inc"
         },
         .spellData =
         {
#include "inc/data_spells.inc"
         },
         .itemData =
         {
#include "inc/data_items.inc"
         },
         .objectData =
         {
#include "inc/data_objects.inc"
         },
     },
     /**********************************************************************************************************************/
     /*
     **********************************************************************************************************************/
    .animation =
     {
         .itemsAttack =
         {
#include "inc/funcs_animation_items_attack.inc"
         },
         .itemsStruck =
         {
#include "inc/funcs_animation_items_struck.inc"
         },
         .spellsAttack =
         {
#include "inc/funcs_animation_spells_attack.inc"
         },
         .spellsStruck =
         {
#include "inc/funcs_animation_spells_struck.inc"
         },
         .skillsAttack =
         {
#include "inc/funcs_animation_skills_attack.inc"
         },
         .skillsStruck =
         {
#include "inc/funcs_animation_skills_struck.inc"
         },
     },

     /**********************************************************************************************************************/
     /*
     **********************************************************************************************************************/
    .funcs =
     {
         .abilityFunctions =
         {
#include "inc/funcs_skills.inc"
         },
         .spellFunctions =
         {
#include "inc/funcs_spells.inc"
         },
         .itemFunctions =
         {
#include "inc/funcs_items.inc"
         },
         .objectFunctions =
         {
#include "inc/funcs_objects.inc"
         },
     },
     /**********************************************************************************************************************/
     /*
     **********************************************************************************************************************/
    .GetColor =
     {
#include "inc/data_colors16.inc"

     },
    .GetColor256 =
     {
#include "inc/data_colors256.inc"
     },

    .noteFreqFixed =
{
    /** 0 */ 818, 866, 918, 972, 1030, 1091, 1156, 1225, 1298, 1375, 1457, 1543,
    /*12 */ 1635, 1732, 1835, 1945, 2060, 2183, 2312, 2450, 2596, 2750, 2914, 3087,
    /*24 */ 3270, 3465, 3671, 3889, 4120, 4365, 4625, 4900, 5191, 5500, 5827, 6174,
    /*36 */ 6541, 6930, 7342, 7778, 8241, 8731, 9250, 9800, 10383, 11000, 11654, 12347,
    /*48 */ 13081, 13859, 14683, 15556, 16481, 17461, 18500, 19600, 20765, 22000, 23308, 24694,
    /*60 */ 26163, 27718, 29366, 31113, 32963, 34923, 36999, 39200, 41530, 44000, 46616, 49388,
    /*72 */ 52325, 55437, 58733, 62225, 65925, 69846, 73999, 78399, 83061, 88000, 93233, 98777,
    /*84 */ 104650, 110873, 117466, 124451, 131851, 139691, 147998, 156798, 166122, 176000, 186466, 197553,
    /*96 */ 209300, 221746, 234932, 248902, 263702, 279383, 295996, 313596, 332244, 352000, 372931, 395107,
    /*108*/ 418601, 443492, 469863, 497803, 527404, 558765, 591991, 627193, 664488, 704000, 745862, 790213,
    /*120*/ 837202, 886984, 939727, 995606, 1054808, 1117530, 1183982, 1254385
}
};

#else

/**********************************************************************************************************************/
/*      CHAR SPRITES
**********************************************************************************************************************/
SET_MEMORY(".char_sprites_items")
const Sprite char_sprites_items[ITEM_COUNT] = {
#include "inc/map_sprites_items.inc"
};
SET_MEMORY(".char_sprites_monsters")
const Sprite char_sprites_monsters[CREATURE_COUNT] = {
#include "inc/map_sprites_creatures.inc"
};
SET_MEMORY(".char_sprites_objects")
const Sprite char_sprites_objects[OBJECT_COUNT] = {
#include "inc/map_sprites_objects.inc"
};
SET_MEMORY(".char_sprites_trainers")
const Sprite char_sprites_trainers[TRAINER_COUNT] = {
#include "inc/map_sprites_trainers.inc"
};
SET_MEMORY(".char_sprites_biomes")
const Tile char_sprites_biomes[BIOME_COUNT][NUM_TILES] = {
#include "inc/map_sprite_biome_tiles.inc"
};


/**********************************************************************************************************************/
/*      TILESETS
**********************************************************************************************************************/
SET_MEMORY(".tileset_theme")
const Creature monsterGroups[BIOME_COUNT][BIOME_MONSTER_TYPES] = {
#include "inc/data_tileset_monsterGroups.inc"
};
SET_MEMORY(".tileset_creatures")
const Creature themeGroups[BIOME_COUNT][THEME_MONSTER_TYPES] = {
#include "inc/data_tileset_themeGroups.inc"
};


/**********************************************************************************************************************/
/*     STRINGS
**********************************************************************************************************************/
//      menus
SET_MEMORY(".strings_menu_main")
const char Text_Menu_main[MAIN_MENUS_SIZE][SMALL_STRINGS] = {
#include "inc/text_menu_main.inc"
};
SET_MEMORY(".strings_menu_battle")
const char Text_Menu_battleMenu[BATTLE_MENU_SIZE][SMALL_STRINGS] = {
#include "inc/text_menu_battle.inc"
};
SET_MEMORY(".strings_menu_options")
const char Text_Menu_options[OPTIONS_MENU_SIZE][SMALL_STRINGS] = {
#include "inc/text_menu_options.inc"
};


//      names
SET_MEMORY(".strings_names_items")
const SmallStringArray Text_Names_items[ITEM_TEXT_ARRAY_SIZE] = {
#include "inc/text_names_items.inc"
};
SET_MEMORY(".strings_names_creatures")
const SmallStringArray Text_Names_monsters[CREATURE_TEXT_ARRAY_SIZE] = {
#include "inc/text_names_creatures.inc"
};
SET_MEMORY(".strings_names_trainers")
const SmallStringArray Text_Names_trainers[TRAINER_TEXT_ARRAY_SIZE] = {
#include "inc/text_names_trainers.inc"
};
SET_MEMORY(".strings_names_spells")
const SmallStringArray Text_Names_spells[SPELL_TEXT_ARRAY_SIZE] = {
#include "inc/text_names_spells.inc"
};
SET_MEMORY(".strings_names_skills")
const SmallStringArray Text_Names_attacks[ABILITY_TEXT_ARRAY_SIZE] = {
#include "inc/text_names_skills.inc"
};
SET_MEMORY(".strings_names_objects")
const SmallStringArray Text_Names_objects[OBJECT_TEXT_ARRAY_SIZE] = {
#include "inc/text_names_objects.inc"
};

//      descriptiuons
SET_MEMORY(".strings_descriptions_items")
const char Text_Descriptions_items[ITEM_TEXT_ARRAY_SIZE][LARGE_STRINGS] = {
#include "inc/text_desc_items.inc"
};
SET_MEMORY(".strings_descriptions_creatures")
const char Text_Descriptions_monsters[CREATURE_TEXT_ARRAY_SIZE][LARGE_STRINGS] = {
#include "inc/text_desc_creatures.inc"
};
SET_MEMORY(".strings_descriptions_trainers")
const char Text_Descriptions_trainers[TRAINER_TEXT_ARRAY_SIZE][LARGE_STRINGS] = {
#include "inc/text_desc_trainers.inc"
};
SET_MEMORY(".strings_descriptions_spells")
const char Text_Descriptions_spells[SPELL_TEXT_ARRAY_SIZE][LARGE_STRINGS] = {
#include "inc/text_desc_spells.inc"
};
SET_MEMORY(".strings_descriptions_skills")
const char Text_Descriptions_attacks[ABILITY_TEXT_ARRAY_SIZE][LARGE_STRINGS] = {
#include "inc/text_desc_skills.inc"
};
SET_MEMORY(".strings_descriptions_objects")
const char Text_Descriptions_objects[OBJECT_TEXT_ARRAY_SIZE][LARGE_STRINGS] = {
#include "inc/text_desc_objects.inc"
};

//      types
SET_MEMORY(".strings_types")
const char Text_types[TYPE_COUNT][SMALL_STRINGS] = {
#include "inc/text_types.inc"
};

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".sprite_battler_layout_back")
const SpriteLayout battler_back_layout[CREATURE_COUNT] = {
#include "inc/sprite_creature_back_layout.inc"
};
SET_MEMORY(".sprite_battler_layout_front")
const SpriteLayout battler_front_layout[CREATURE_COUNT] = {
#include "inc/sprite_creature_front_layout.inc"
};
SET_MEMORY(".sprite_battler_back")
const uint8_t battler_back[SPRITE_CREATURE_BACK_BYTES] = {
#include "inc/sprite_creature_back.inc"
};
SET_MEMORY(".sprite_battler_front")
const uint8_t battler_front[SPRITE_CREATURE_FRONT_BYTES] = {
#include "inc/sprite_creature_front.inc"
};


SET_MEMORY(".sprite_items_layout")
const SpriteLayout itemLayout[ITEM_COUNT] = {
#include "inc/sprite_item_layout.inc"
};
SET_MEMORY(".sprite_skills_layout")
const SpriteLayout skillLayout[ABILITY_COUNT] = {
#include "inc/sprite_skill_layout.inc"
};
SET_MEMORY(".sprite_spells_layout")
const SpriteLayout spellLayout[SPELL_COUNT] = {
#include "inc/sprite_spell_layout.inc"
};
SET_MEMORY(".sprite_objects_layout")
const SpriteLayout objectLayout[OBJECT_COUNT] = {
#include "inc/sprite_object_layout.inc"
};
SET_MEMORY(".sprite_trainer_layout")
const SpriteLayout trainerLayout[TRAINER_COUNT] = {
#include "inc/sprite_trainer_layout.inc"
};


SET_MEMORY(".sprite_items")
const uint8_t sprites_items[SPRITE_ITEM_BYTES] = {
#include "inc/sprite_item.inc"
};
SET_MEMORY(".sprite_skills")
const uint8_t sprites_skills[SPRITE_SKILL_BYTES] = {
#include "inc/sprite_skill.inc"
};
SET_MEMORY(".sprite_spells")
const uint8_t sprites_spells[SPRITE_SPELL_BYTES] = {
#include "inc/sprite_spell.inc"
};
SET_MEMORY(".sprite_objects")
const uint8_t sprites_objects[SPRITE_OBJECT_BYTES] = {
#include "inc/sprite_object.inc"
};
SET_MEMORY(".sprite_trainers")
const uint8_t sprites_trainers[TRAINER_COUNT] = {
#include "inc/sprite_trainer.inc"
};

/**********************************************************************************************************************/
/*
 *      MAP SPRITES
 *
**********************************************************************************************************************/

#define MAP_SPRITE_CREATURE_LAYOUT_SIZE (sizeof(SpriteFrames) * CREATURE_COUNT)
#define MAP_SPRITE_ITEM_LAYOUT_SIZE (sizeof(SpriteFrames) * ITEM_COUNT)
#define MAP_SPRITE_OBJECT_LAYOUT_SIZE (sizeof(SpriteFrames) * OBJECT_COUNT)
#define MAP_SPRITE_TRAINER_LAYOUT_SIZE (sizeof(SpriteFrames) * TRAINER_COUNT)
#define MAP_SPRITE_TILE_LAYOUT_SIZE (sizeof(SpriteFrames) * TILE_COUNT)

/**********************************************************************************************************************/
/*  16x16 map sprite tiles, may have multiple tiles for idle animations
**********************************************************************************************************************/
SET_MEMORY(".sprite_16x16_creature")
const uint8_t creatureSprites16x16[SPRITE_16x16_CREATURE_BYTES] = {
#include "inc/sprite_16x16_creature.inc"
};
SET_MEMORY(".sprite_16x16_item")
const uint8_t itemSprites16x16[SPRITE_16x16_ITEM_BYTES] = {
#include "inc/sprite_16x16_item.inc"
};
SET_MEMORY(".sprite_16x16_object")
const uint8_t objectSprites16x16[SPRITE_16x16_OBJECT_BYTES] = {
#include "inc/sprite_16x16_object.inc"
};
SET_MEMORY(".sprite_16x16_trainer")
const uint8_t trainerSprites16x16[SPRITE_16x16_TRAINER_BYTES] = {
#include "inc/sprite_16x16_trainer.inc"
};
SET_MEMORY(".sprite_16x16_tile")
const uint8_t tileSprites16x16[SPRITE_16x16_TILE_BYTES] = {
#include "inc/sprite_16x16_tile.inc"
};

SET_MEMORY(".sprite_16x16_creature_metaData")
const SpriteFrames creatureSpritesMetaData16x16[MAP_SPRITE_CREATURE_LAYOUT_SIZE] = {
#include "inc/sprite_16x16_creature_metaData.inc"
};
SET_MEMORY(".sprite_16x16_item_metaData")
const SpriteFrames itemSpritesMetaData16x16[MAP_SPRITE_ITEM_LAYOUT_SIZE] = {
#include "inc/sprite_16x16_item_metaData.inc"
};
SET_MEMORY(".sprite_16x16_object_metaData")
const SpriteFrames objectSpritesMetaData16x16[MAP_SPRITE_OBJECT_LAYOUT_SIZE] = {
#include "inc/sprite_16x16_object_metaData.inc"
};
SET_MEMORY(".sprite_16x16_trainer_metaData")
const SpriteFrames trainerSpritesMetaData16x16[MAP_SPRITE_TRAINER_LAYOUT_SIZE] = {
#include "inc/sprite_16x16_trainer_metaData.inc"
};
SET_MEMORY(".sprite_16x16_tile_metaData")
const SpriteFrames tileSpritesMetaData16x16[MAP_SPRITE_TILE_LAYOUT_SIZE] = {
#include "inc/sprite_16x16_tile_metaData.inc"
};

/**********************************************************************************************************************/
/*  20x20 map sprite tiles, may have multiple tiles for idle animations
**********************************************************************************************************************/
SET_MEMORY(".sprite_20x20_creature")
const uint8_t creatureSprites20x20[SPRITE_20x20_CREATURE_BYTES] = {
#include "inc/sprite_20x20_creature.inc"
};
SET_MEMORY(".sprite_20x20_item")
const uint8_t itemSprites20x20[SPRITE_20x20_ITEM_BYTES] = {
#include "inc/sprite_20x20_item.inc"
};
SET_MEMORY(".sprite_20x20_object")
const uint8_t objectSprites0x20[SPRITE_20x20_OBJECT_BYTES] = {
#include "inc/sprite_20x20_object.inc"
};
SET_MEMORY(".sprite_20x20_trainer")
const uint8_t trainerSprites20x20[SPRITE_20x20_TRAINER_BYTES] = {
#include "inc/sprite_20x20_trainer.inc"
};
SET_MEMORY(".sprite_20x20_tile")
const uint8_t tileSprites20x20[SPRITE_20x20_TILE_BYTES] = {
#include "inc/sprite_20x20_tile.inc"
};

SET_MEMORY(".sprite_20x20_creature_metaData")
const SpriteFrames creatureSpritesMetaData20x20[MAP_SPRITE_CREATURE_LAYOUT_SIZE] = {
#include "inc/sprite_20x20_creature_metaData.inc"
};
SET_MEMORY(".sprite_20x20_item_metaData")
const SpriteFrames itemSpritesMetaData20x20[MAP_SPRITE_ITEM_LAYOUT_SIZE] = {
#include "inc/sprite_20x20_item_metaData.inc"
};
SET_MEMORY(".sprite_20x20_object_metaData")
const SpriteFrames objectSpritesMetaData20x20[MAP_SPRITE_OBJECT_LAYOUT_SIZE] = {
#include "inc/sprite_20x20_object_metaData.inc"
};
SET_MEMORY(".sprite_20x20_trainer_metaData")
const SpriteFrames trainerSpritesMetaData20x20[MAP_SPRITE_TRAINER_LAYOUT_SIZE] = {
#include "inc/sprite_20x20_trainer_metaData.inc"
};
SET_MEMORY(".sprite_20x20_tile_metaData")
const SpriteFrames tileSpritesMetaData20x20[MAP_SPRITE_TILE_LAYOUT_SIZE] = {
#include "inc/sprite_20x20_tile_metaData.inc"
};


/**********************************************************************************************************************/
/*  24x24 map sprite tiles, may have multiple tiles for idle animations
**********************************************************************************************************************/
SET_MEMORY(".sprite_24x24_creature")
const uint8_t creatureSprites24x24[SPRITE_24x24_CREATURE_BYTES] = {
#include "inc/sprite_24x24_creature.inc"
};
SET_MEMORY(".sprite_24x24_item")
const uint8_t itemSprites24x24[SPRITE_24x24_ITEM_BYTES] = {
#include "inc/sprite_24x24_item.inc"
};
SET_MEMORY(".sprite_24x24_object")
const uint8_t objectSprites24x24[SPRITE_24x24_OBJECT_BYTES] = {
#include "inc/sprite_24x24_object.inc"
};
SET_MEMORY(".sprite_24x24_trainer")
const uint8_t trainerSprites24x24[SPRITE_24x24_TRAINER_BYTES] = {
#include "inc/sprite_24x24_trainer.inc"
};
SET_MEMORY(".sprite_24x24_tile")
const uint8_t tileSprites24x24[SPRITE_24x24_TILE_BYTES] = {
#include "inc/sprite_24x24_tile.inc"
};

SET_MEMORY(".sprite_24x24_creature_metaData")
const SpriteFrames creatureSpritesMetaData24x24[MAP_SPRITE_CREATURE_LAYOUT_SIZE] = {
#include "inc/sprite_24x24_creature_metaData.inc"
};
SET_MEMORY(".sprite_24x24_item_metaData")
const SpriteFrames itemSpritesMetaData24x24[MAP_SPRITE_ITEM_LAYOUT_SIZE] = {
#include "inc/sprite_24x24_item_metaData.inc"
};
SET_MEMORY(".sprite_24x24_object_metaData")
const SpriteFrames objectSpritesMetaData24x24[MAP_SPRITE_OBJECT_LAYOUT_SIZE] = {
#include "inc/sprite_24x24_object_metaData.inc"
};
SET_MEMORY(".sprite_24x24_trainer_metaData")
const SpriteFrames trainerSpritesMetaData24x24[MAP_SPRITE_TRAINER_LAYOUT_SIZE] = {
#include "inc/sprite_24x24_trainer_metaData.inc"
};
SET_MEMORY(".sprite_24x24_tile_metaData")
const SpriteFrames tileSpritesMetaData24x24[MAP_SPRITE_TILE_LAYOUT_SIZE] = {
#include "inc/sprite_24x24_tile_metaData.inc"
};


/**********************************************************************************************************************/
/*  32x32 map sprite tiles, may have multiple tiles for idle animations
**********************************************************************************************************************/
SET_MEMORY(".sprite_32x32_creature")
const uint8_t creatureSprites32x32[SPRITE_32x32_CREATURE_BYTES] = {
#include "inc/sprite_32x32_creature.inc"
};
SET_MEMORY(".sprite_32x32_item")
const uint8_t itemSprites32x32[SPRITE_32x32_ITEM_BYTES] = {
#include "inc/sprite_32x32_item.inc"
};
SET_MEMORY(".sprite_32x32_object")
const uint8_t objectSprites32x32[SPRITE_32x32_OBJECT_BYTES] = {
#include "inc/sprite_32x32_object.inc"
};
SET_MEMORY(".sprite_32x32_trainer")
const uint8_t trainerSprites32x32[SPRITE_32x32_TRAINER_BYTES] = {
#include "inc/sprite_32x32_trainer.inc"
};
SET_MEMORY(".sprite_32x32_tile")
const uint8_t tileSprites32x32[SPRITE_32x32_TILE_BYTES] = {
#include "inc/sprite_32x32_tile.inc"
};

SET_MEMORY(".sprite_32x32_creature_metaData")
const SpriteFrames creatureSpritesMetaData32x32[MAP_SPRITE_CREATURE_LAYOUT_SIZE] = {
#include "inc/sprite_32x32_creature_metaData.inc"
};
SET_MEMORY(".sprite_32x32_item_metaData")
const SpriteFrames itemSpritesMetaData32x32[MAP_SPRITE_ITEM_LAYOUT_SIZE] = {
#include "inc/sprite_32x32_item_metaData.inc"
};
SET_MEMORY(".sprite_32x32_object_metaData")
const SpriteFrames objectSpritesMetaData32x32[MAP_SPRITE_OBJECT_LAYOUT_SIZE] = {
#include "inc/sprite_32x32_object_metaData.inc"
};
SET_MEMORY(".sprite_32x32_trainer_metaData")
const SpriteFrames trainerSpritesMetaData32x32[MAP_SPRITE_TRAINER_LAYOUT_SIZE] = {
#include "inc/sprite_32x32_trainer_metaData.inc"
};
SET_MEMORY(".sprite_32x32_tile_metaData")
const SpriteFrames tileSpritesMetaData32x32[MAP_SPRITE_TILE_LAYOUT_SIZE] = {
#include "inc/sprite_32x32_tile_metaData.inc"
};

/**********************************************************************************************************************/
/*  64x64 map sprite tiles, may have multiple tiles for idle animations
**********************************************************************************************************************/
SET_MEMORY(".sprite_64x64_creature")
const uint8_t creatureSprites64x64[SPRITE_64x64_CREATURE_BYTES] = {
#include "inc/sprite_64x64_creature.inc"
};
SET_MEMORY(".sprite_64x64_item")
const uint8_t itemSprites64x64[SPRITE_64x64_ITEM_BYTES] = {
#include "inc/sprite_64x64_item.inc"
};
SET_MEMORY(".sprite_64x64_object")
const uint8_t objectSprites64x64[SPRITE_64x64_OBJECT_BYTES] = {
#include "inc/sprite_64x64_object.inc"
};
SET_MEMORY(".sprite_64x64_trainer")
const uint8_t trainerSprites64x64[SPRITE_64x64_TRAINER_BYTES] = {
#include "inc/sprite_64x64_trainer.inc"
};
SET_MEMORY(".sprite_64x64_tile")
const uint8_t tileSprites64x64[SPRITE_64x64_TILE_BYTES] = {
#include "inc/sprite_64x64_tile.inc"
};

SET_MEMORY(".sprite_64x64_creature_metaData")
const SpriteFrames creatureSpritesMetaData64x64[MAP_SPRITE_CREATURE_LAYOUT_SIZE] = {
#include "inc/sprite_64x64_creature_metaData.inc"
};
SET_MEMORY(".sprite_64x64_item_metaData")
const SpriteFrames itemSpritesMetaData64x64[MAP_SPRITE_ITEM_LAYOUT_SIZE] = {
#include "inc/sprite_64x64_item_metaData.inc"
};
SET_MEMORY(".sprite_64x64_object_metaData")
const SpriteFrames objectSpritesMetaData64x64[MAP_SPRITE_OBJECT_LAYOUT_SIZE] = {
#include "inc/sprite_64x64_object_metaData.inc"
};
SET_MEMORY(".sprite_64x64_trainer_metaData")
const SpriteFrames trainerSpritesMetaData64x64[MAP_SPRITE_TRAINER_LAYOUT_SIZE] = {
#include "inc/sprite_64x64_trainer_metaData.inc"
};
SET_MEMORY(".sprite_64x64_tile_metaData")
const SpriteFrames tileSpritesMetaData64x64[MAP_SPRITE_TILE_LAYOUT_SIZE] = {
#include "inc/sprite_64x64_tile_metaData.inc"
};



/**********************************************************************************************************************/
/* text font data
**********************************************************************************************************************/
SET_MEMORY(".font_8x8")
const uint8_t font8x8[CHARACTER_COUNT * FONT_8_BYTES_PER_CHAR] = {
#include "inc/data_font8x8.inc"
};
SET_MEMORY(".font_16x16")
const uint8_t font16x16[CHARACTER_COUNT * FONT_16_BYTES_PER_CHAR] = {
#include "inc/data_font16x16.inc"
};
SET_MEMORY(".font_20x20")
const uint8_t font20x20[CHARACTER_COUNT * FONT_20_BYTES_PER_CHAR] = {
#include "inc/data_font20x20.inc"
};
SET_MEMORY(".font_24x24")
const uint8_t font24x24[CHARACTER_COUNT * FONT_24_BYTES_PER_CHAR] = {
#include "inc/data_font24x24.inc"
};
SET_MEMORY(".font_32x32")
const uint8_t font32x32[CHARACTER_COUNT * FONT_32_BYTES_PER_CHAR] = {
#include "inc/data_font32x32.inc"
};

/**********************************************************************************************************************/
/* SOUNDS
**********************************************************************************************************************/
SET_MEMORY(".sounds_music_data")
const MusicData musicData[MUSIC_COUNT] = {
    // maybe one piece for each biome, when we how much space we are looking at
#include "inc/sounds_music_data.inc"
};
SET_MEMORY(".sounds_music_notes")
const Note songs[TOTAL_MUSIC_NOTES] = {
#include "inc/sounds_music.inc"
};

SET_MEMORY(".sounds_creatures")
const Note creatures[CREATURE_COUNT] = {
    //probably not Notes, we will see though
#include "inc/sounds_creatures.inc"
};
SET_MEMORY(".sounds_spells")
const Note spells[SPELL_COUNT] = {
    //probably not Notes, we will see though
#include "inc/sounds_spells.inc"
};
SET_MEMORY(".sounds_skills")
const Note attacks[ABILITY_COUNT] = {
    //probably not Notes, we will see though
#include "inc/sounds_skills.inc"
};
SET_MEMORY(".sounds_menus")
const Note menus[10] = {
#include "inc/sounds_menu.inc"
};
SET_MEMORY(".sounds_notes")
const int32_t noteFreqFixed[128] =
{
    /** 0 */ 818, 866, 918, 972, 1030, 1091, 1156, 1225, 1298, 1375, 1457, 1543,
    /*12 */ 1635, 1732, 1835, 1945, 2060, 2183, 2312, 2450, 2596, 2750, 2914, 3087,
    /*24 */ 3270, 3465, 3671, 3889, 4120, 4365, 4625, 4900, 5191, 5500, 5827, 6174,
    /*36 */ 6541, 6930, 7342, 7778, 8241, 8731, 9250, 9800, 10383, 11000, 11654, 12347,
    /*48 */ 13081, 13859, 14683, 15556, 16481, 17461, 18500, 19600, 20765, 22000, 23308, 24694,
    /*60 */ 26163, 27718, 29366, 31113, 32963, 34923, 36999, 39200, 41530, 44000, 46616, 49388,
    /*72 */ 52325, 55437, 58733, 62225, 65925, 69846, 73999, 78399, 83061, 88000, 93233, 98777,
    /*84 */ 104650, 110873, 117466, 124451, 131851, 139691, 147998, 156798, 166122, 176000, 186466, 197553,
    /*96 */ 209300, 221746, 234932, 248902, 263702, 279383, 295996, 313596, 332244, 352000, 372931, 395107,
    /*108*/ 418601, 443492, 469863, 497803, 527404, 558765, 591991, 627193, 664488, 704000, 745862, 790213,
    /*120*/ 837202, 886984, 939727, 995606, 1054808, 1117530, 1183982, 1254385
};

/**********************************************************************************************************************/
/* GAME DATA
**********************************************************************************************************************/
SET_MEMORY(".game_data_type_effects")
const int8_t typeEffects[TYPE_COUNT * TYPE_COUNT] = {
#include "inc/data_type_effects.inc"
};
SET_MEMORY(".game_data_creature_types")
const MonsterType creatureTypes[CREATURE_COUNT] = {
#include "inc/data_types_creatures.inc"
};
SET_MEMORY(".game_data_creature_stats")
const StatsRange creatureStats[CREATURE_COUNT] = {
#include "inc/data_creature_stats.inc"
};
SET_MEMORY(".game_data_learnable_skills")
const BitFieldUint8 learnableSkills[CREATURE_COUNT] = {
#include "inc/data_creature_skills.inc"
};
SET_MEMORY(".game_data_level_up_skills")
const CreatureSkillLearnLevels levelUpSkills[CREATURE_COUNT] = {
#include "inc/data_creature_level_up_skills.inc"
};
SET_MEMORY(".game_data_ability")
const SkillData abilityData[ABILITY_COUNT] = {
#include "inc/data_skills.inc"
};
SET_MEMORY(".game_data_spell")
const SpellData spellData[SPELL_COUNT] = {
#include "inc/data_spells.inc"
};
SET_MEMORY(".game_data_item")
const ItemData itemData[ITEM_COUNT] = {
#include "inc/data_items.inc"
};
SET_MEMORY(".game_data_object")
const ObjectData objectData[OBJECT_COUNT] = {
#include "inc/data_objects.inc"
};


/**********************************************************************************************************************/
/*      COLOR
**********************************************************************************************************************/
SET_MEMORY(".colors_16")
const uint8_t GetColor[PALETTE_COUNT * 2] = {
#include "inc/data_colors16.inc"
};
SET_MEMORY(".colors_256")
const uint8_t GetColor256[256 * 2] = {
#include "inc/data_colors256.inc"
};

#endif
