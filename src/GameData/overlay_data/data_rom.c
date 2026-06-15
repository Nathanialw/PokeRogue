// Created by nathanial on 2/26/26.
//
#include "data_rom.h"

#include "types.h"
#include "enums.h"

#include "lib_memory.h"


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
#include "lib/map_sprite_biome_tiles.inc"
};


/**********************************************************************************************************************/
/*      TILESETS
**********************************************************************************************************************/
SET_MEMORY(".tileset_theme")
const Creature monsterGroups[BIOME_COUNT][BIOME_MONSTER_TYPES] = {
#include "lib/data_tileset_monsterGroups.inc"
};
SET_MEMORY(".tileset_creatures")
const Creature themeGroups[BIOME_COUNT][THEME_MONSTER_TYPES] = {
#include "lib/data_tileset_themeGroups.inc"
};


/**********************************************************************************************************************/
/*     STRINGS
**********************************************************************************************************************/
//      menus
SET_MEMORY(".strings_menu_main")
const char Text_Menu_main[MAIN_MENUS_SIZE][SMALL_STRINGS] = {
#include "lib/text_menu_main.inc"
};
SET_MEMORY(".strings_menu_battle")
const char Text_Menu_battleMenu[BATTLE_MENU_SIZE][SMALL_STRINGS] = {
#include "lib/text_menu_battle.inc"
};
SET_MEMORY(".strings_menu_options")
const char Text_Menu_options[OPTIONS_MENU_SIZE][SMALL_STRINGS] = {
#include "lib/text_menu_options.inc"
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
/*  BATTLERS
**********************************************************************************************************************/
SET_MEMORY(".sprite_battler_layout_back_16")
const SpriteLayout battler_back_layout[CREATURE_COUNT] = {
#include "inc/sprite_creature_back_layout_16x16.inc"
};
SET_MEMORY(".sprite_battler_layout_front_16")
const SpriteLayout battler_front_layout[CREATURE_COUNT] = {
#include "inc/sprite_creature_front_layout_16x16.inc"
};
SET_MEMORY(".sprite_battler_back_16")
const uint8_t battler_back[SPRITE_CREATURE_BACK_BYTES_16] = {
#include "inc/sprite_creature_back_16x16.inc"
};
SET_MEMORY(".sprite_battler_front_16")
const uint8_t battler_front[SPRITE_CREATURE_FRONT_BYTES_16] = {
#include "inc/sprite_creature_front_16x16.inc"
};

SET_MEMORY(".sprite_items_layout_16")
const SpriteLayout itemLayout[ITEM_COUNT] = {
#include "inc/sprite_item_layout_16x16.inc"
};
SET_MEMORY(".sprite_skills_layout_16")
const SpriteLayout skillLayout[ABILITY_COUNT] = {
#include "inc/sprite_skill_layout_16x16.inc"
};
SET_MEMORY(".sprite_spells_layout_16")
const SpriteLayout spellLayout[SPELL_COUNT] = {
#include "inc/sprite_spell_layout_16x16.inc"
};
SET_MEMORY(".sprite_objects_layout_16")
const SpriteLayout objectLayout[OBJECT_COUNT] = {
#include "inc/sprite_object_layout_16x16.inc"
};
SET_MEMORY(".sprite_trainer_layout_16")
const SpriteLayout trainerLayout[TRAINER_COUNT] = {
#include "inc/sprite_trainer_layout_16x16.inc"
};


SET_MEMORY(".sprite_items_16")
const uint8_t sprites_items[SPRITE_ITEM_BYTES_16] = {
#include "inc/sprite_item_16x16.inc"
};
SET_MEMORY(".sprite_skills_16")
const uint8_t sprites_skills[SPRITE_SKILL_BYTES_16] = {
#include "inc/sprite_skill_16x16.inc"
};
SET_MEMORY(".sprite_spells_16")
const uint8_t sprites_spells[SPRITE_SPELL_BYTES_16] = {
#include "inc/sprite_spell_16x16.inc"
};
SET_MEMORY(".sprite_objects_16")
const uint8_t sprites_objects[SPRITE_OBJECT_BYTES_16] = {
#include "inc/sprite_object_16x16.inc"
};
SET_MEMORY(".sprite_trainers_16")
const uint8_t sprites_trainers[SPRITE_TRAINER_BYTES_16] = {
#include "inc/sprite_trainer_16x16.inc"
};


// 64x64 7x7 battlers

SET_MEMORY(".sprite_battler_layout_back_64")
const SpriteLayout battler_back_layout_64[CREATURE_COUNT] = {
#include "inc/sprite_creature_back_layout_64x64.inc"
};
SET_MEMORY(".sprite_battler_layout_front_64")
const SpriteLayout battler_front_layout_64[CREATURE_COUNT] = {
#include "inc/sprite_creature_front_layout_64x64.inc"
};
SET_MEMORY(".sprite_battler_back_64")
const uint8_t battler_back_64[SPRITE_CREATURE_BACK_BYTES_64] = {
#include "inc/sprite_creature_back_64x64.inc"
};
SET_MEMORY(".sprite_battler_front_64")
const uint8_t battler_front_64[SPRITE_CREATURE_FRONT_BYTES_64] = {
#include "inc/sprite_creature_front_64x64.inc"
};


SET_MEMORY(".sprite_items_layout_64")
const SpriteLayout itemLayout_64[ITEM_COUNT] = {
#include "inc/sprite_item_layout_64x64.inc"
};
SET_MEMORY(".sprite_skills_layout_64")
const SpriteLayout skillLayout_64[ABILITY_COUNT] = {
#include "inc/sprite_skill_layout_64x64.inc"
};
SET_MEMORY(".sprite_spells_layout_64")
const SpriteLayout spellLayout_64[SPELL_COUNT] = {
#include "inc/sprite_spell_layout_64x64.inc"
};
SET_MEMORY(".sprite_objects_layout_64")
const SpriteLayout objectLayout_64[OBJECT_COUNT] = {
#include "inc/sprite_object_layout_64x64.inc"
};
SET_MEMORY(".sprite_trainer_layout_64")
const SpriteLayout trainerLayout_64[TRAINER_COUNT] = {
#include "inc/sprite_trainer_layout_64x64.inc"
};


SET_MEMORY(".sprite_items_64")
const uint8_t sprites_items_64[SPRITE_ITEM_BYTES_64] = {
#include "inc/sprite_item_64x64.inc"
};
SET_MEMORY(".sprite_skills_64")
const uint8_t sprites_skills_64[SPRITE_SKILL_BYTES_64] = {
#include "inc/sprite_skill_64x64.inc"
};
SET_MEMORY(".sprite_spells_64")
const uint8_t sprites_spells_64[SPRITE_SPELL_BYTES_64] = {
#include "inc/sprite_spell_64x64.inc"
};
SET_MEMORY(".sprite_objects_64")
const uint8_t sprites_objects_64[SPRITE_OBJECT_BYTES_64] = {
#include "inc/sprite_object_64x64.inc"
};
SET_MEMORY(".sprite_trainers_64")
const uint8_t sprites_trainers_64[SPRITE_TRAINER_BYTES_64] = {
#include "inc/sprite_trainer_64x64.inc"
};


/**********************************************************************************************************************/
/*
 *      MAP SPRITES
 *
**********************************************************************************************************************/
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
const SpriteFrames creatureSpritesMetaData16x16[CREATURE_COUNT] = {
#include "inc/sprite_16x16_creature_metaData.inc"
};
SET_MEMORY(".sprite_16x16_item_metaData")
const SpriteFrames itemSpritesMetaData16x16[ITEM_COUNT] = {
#include "inc/sprite_16x16_item_metaData.inc"
};
SET_MEMORY(".sprite_16x16_object_metaData")
const SpriteFrames objectSpritesMetaData16x16[OBJECT_COUNT] = {
#include "inc/sprite_16x16_object_metaData.inc"
};
SET_MEMORY(".sprite_16x16_trainer_metaData")
const SpriteFrames trainerSpritesMetaData16x16[TRAINER_COUNT] = {
#include "inc/sprite_16x16_trainer_metaData.inc"
};
SET_MEMORY(".sprite_16x16_tile_metaData")
const SpriteFrames tileSpritesMetaData16x16[TILE_COUNT] = {
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
const SpriteFrames creatureSpritesMetaData20x20[CREATURE_COUNT] = {
#include "inc/sprite_20x20_creature_metaData.inc"
};
SET_MEMORY(".sprite_20x20_item_metaData")
const SpriteFrames itemSpritesMetaData20x20[ITEM_COUNT] = {
#include "inc/sprite_20x20_item_metaData.inc"
};
SET_MEMORY(".sprite_20x20_object_metaData")
const SpriteFrames objectSpritesMetaData20x20[OBJECT_COUNT] = {
#include "inc/sprite_20x20_object_metaData.inc"
};
SET_MEMORY(".sprite_20x20_trainer_metaData")
const SpriteFrames trainerSpritesMetaData20x20[TRAINER_COUNT] = {
#include "inc/sprite_20x20_trainer_metaData.inc"
};
SET_MEMORY(".sprite_20x20_tile_metaData")
const SpriteFrames tileSpritesMetaData20x20[TILE_COUNT] = {
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
const SpriteFrames creatureSpritesMetaData24x24[CREATURE_COUNT] = {
#include "inc/sprite_24x24_creature_metaData.inc"
};
SET_MEMORY(".sprite_24x24_item_metaData")
const SpriteFrames itemSpritesMetaData24x24[ITEM_COUNT] = {
#include "inc/sprite_24x24_item_metaData.inc"
};
SET_MEMORY(".sprite_24x24_object_metaData")
const SpriteFrames objectSpritesMetaData24x24[OBJECT_COUNT] = {
#include "inc/sprite_24x24_object_metaData.inc"
};
SET_MEMORY(".sprite_24x24_trainer_metaData")
const SpriteFrames trainerSpritesMetaData24x24[TRAINER_COUNT] = {
#include "inc/sprite_24x24_trainer_metaData.inc"
};
SET_MEMORY(".sprite_24x24_tile_metaData")
const SpriteFrames tileSpritesMetaData24x24[TILE_COUNT] = {
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
const SpriteFrames creatureSpritesMetaData32x32[CREATURE_COUNT] = {
#include "inc/sprite_32x32_creature_metaData.inc"
};
SET_MEMORY(".sprite_32x32_item_metaData")
const SpriteFrames itemSpritesMetaData32x32[ITEM_COUNT] = {
#include "inc/sprite_32x32_item_metaData.inc"
};
SET_MEMORY(".sprite_32x32_object_metaData")
const SpriteFrames objectSpritesMetaData32x32[OBJECT_COUNT] = {
#include "inc/sprite_32x32_object_metaData.inc"
};
SET_MEMORY(".sprite_32x32_trainer_metaData")
const SpriteFrames trainerSpritesMetaData32x32[TRAINER_COUNT] = {
#include "inc/sprite_32x32_trainer_metaData.inc"
};
SET_MEMORY(".sprite_32x32_tile_metaData")
const SpriteFrames tileSpritesMetaData32x32[TILE_COUNT] = {
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
const SpriteFrames creatureSpritesMetaData64x64[CREATURE_COUNT] = {
#include "inc/sprite_64x64_creature_metaData.inc"
};
SET_MEMORY(".sprite_64x64_item_metaData")
const SpriteFrames itemSpritesMetaData64x64[ITEM_COUNT] = {
#include "inc/sprite_64x64_item_metaData.inc"
};
SET_MEMORY(".sprite_64x64_object_metaData")
const SpriteFrames objectSpritesMetaData64x64[OBJECT_COUNT] = {
#include "inc/sprite_64x64_object_metaData.inc"
};
SET_MEMORY(".sprite_64x64_trainer_metaData")
const SpriteFrames trainerSpritesMetaData64x64[TRAINER_COUNT] = {
#include "inc/sprite_64x64_trainer_metaData.inc"
};
SET_MEMORY(".sprite_64x64_tile_metaData")
const SpriteFrames tileSpritesMetaData64x64[TILE_COUNT] = {
#include "inc/sprite_64x64_tile_metaData.inc"
};


/**********************************************************************************************************************/
/* text font data
**********************************************************************************************************************/
SET_MEMORY(".font_8x8")
const uint8_t font8x8[CHARACTER_COUNT * FONT_8_BYTES_PER_CHAR] = {
#include "lib/data_font8x8.inc"
};
SET_MEMORY(".font_16x16")
const uint8_t font16x16[CHARACTER_COUNT * FONT_16_BYTES_PER_CHAR] = {
#include "lib/data_font16x16.inc"
};
SET_MEMORY(".font_20x20")
const uint8_t font20x20[CHARACTER_COUNT * FONT_20_BYTES_PER_CHAR] = {
#include "lib/data_font20x20.inc"
};
SET_MEMORY(".font_24x24")
const uint8_t font24x24[CHARACTER_COUNT * FONT_24_BYTES_PER_CHAR] = {
#include "lib/data_font24x24.inc"
};
SET_MEMORY(".font_32x32")
const uint8_t font32x32[CHARACTER_COUNT * FONT_32_BYTES_PER_CHAR] = {
#include "lib/data_font32x32.inc"
};

/**********************************************************************************************************************/
/* SOUNDS
**********************************************************************************************************************/
SET_MEMORY(".sounds_music_data")
const MusicData musicData[MUSIC_COUNT] = {
    // maybe one piece for each biome, when we how much space we are looking at
#include "lib/sounds_music_data.inc"
};
SET_MEMORY(".sounds_music_notes")
const Note songs[TOTAL_MUSIC_NOTES] = {
#include "lib/sounds_music.inc"
};

SET_MEMORY(".sounds_creatures")
const Note creatures[CREATURE_COUNT] = {
    //probably not Notes, we will see though
//#include "lib/sounds_creatures.inc"
};
SET_MEMORY(".sounds_spells")
const Note spells[SPELL_COUNT] = {
    //probably not Notes, we will see though
//#include "lib/sounds_spells.inc"
};
SET_MEMORY(".sounds_skills")
const Note attacks[ABILITY_COUNT] = {
    //probably not Notes, we will see though
//#include "lib/sounds_skills.inc"
};
SET_MEMORY(".sounds_menus")
const Note menus[10] = {
// #include "lib/sounds_menu.inc"
};



/**********************************************************************************************************************/
/* GAME DATA
**********************************************************************************************************************/
SET_MEMORY(".game_data_type_effects")
const int8_t typeEffects[TYPE_COUNT * TYPE_COUNT] = {
#include "lib/data_type_effects.inc"
};
SET_MEMORY(".game_data_creature_types")
const MonsterType creatureTypes[CREATURE_COUNT] = {
#include "inc/data_types_creatures.inc"
};
SET_MEMORY(".game_data_creature_stats")
const StatsRange creatureStats[CREATURE_COUNT] = {
#include "inc/data_creatures.inc"
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
SET_MEMORY(".game_data_trainer")
const TrainerData trainerData[TRAINER_COUNT] = {
#include "inc/data_trainers.inc"
};

/**********************************************************************************************************************/
/*      COLOR
**********************************************************************************************************************/
SET_MEMORY(".colors_16")
const uint8_t GetColor[PALETTE_COUNT * 2] = {
#include "lib/data_colors16.inc"
};
SET_MEMORY(".colors_256")
const uint8_t GetColor256[256 * 2] = {
#include "lib/data_colors256.inc"
};


// TODO set note data
SET_MEMORY(".core.rodata")
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
