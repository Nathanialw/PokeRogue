//
// Created by nathanial on 2/26/26.
//
#pragma once
#include "data_constants.inc"

#include "lib_types.h"

/**********************************************************************************************************************/
/*
 *  This file holds the global constants values
 *  If only used in one file do try to move them to that file
 *
**********************************************************************************************************************/

// compile options
#define INCLUDE_BATTLERS

/**********************************************************************************************************************/
/** Function macros
**********************************************************************************************************************/
#define ASSERT_STRING_FITS(ARRAY, STRING) _Static_assert(sizeof(STRING) <= ALIGNED_SIZE, "String " #STRING " too long for " #ARRAY)
#define ASSERT_ALIGNED8(N) _Static_assert(((N) % 8) == 0, "ALIGNED_SIZE must be divisible by " #N)
#define ASSERT_ALIGNED16(N) _Static_assert(((N) % 16) == 0, "ALIGNED_SIZE must be divisible by " #N)
#define ASSERT_ALIGNED32(N) _Static_assert(((N) % 32) == 0, "ALIGNED_SIZE must be divisible by " #N)

/**********************************************************************************************************************/
/** ENUMS constants
**********************************************************************************************************************/
#define TYPE_COUNT 16
#define THEME_COUNT 16
#define BIOME_COUNT 16
#define MAX_LEVELS 35


_Static_assert(ITEM_COUNT <= 256, "max must be 256 - one byte");
_Static_assert(ABILITY_COUNT <= 256, "max must be 256 - one byte");
_Static_assert(CREATURE_COUNT <= 256, "TOTAL MONSTERS MUST BE 256");
_Static_assert(SPELL_COUNT <= 256, "max must be 256 - one byte");
_Static_assert(OBJECT_COUNT <= 256, "max must be 256 - one byte");

#define PALETTE_COUNT 64
#define CHARACTER_COUNT 256

#define NUM_SPRITE_FRAMES 3

#define CREATURE_SPRITE_COUNT (CREATURE_COUNT * NUM_SPRITE_FRAMES)
#define TRAINER_SPRITE_COUNT (TRAINER_COUNT * NUM_SPRITE_FRAMES)
#define OBJECT_SPRITE_COUNT (ITEM_COUNT * NUM_SPRITE_FRAMES)
#define ITEM_SPRITE_COUNT (OBJECT_COUNT * NUM_SPRITE_FRAMES)
#define TILE_SPRITE_COUNT (TILE_COUNT * NUM_SPRITE_FRAMES)


/**********************************************************************************************************************/
/** STRING ARRAYS constants
 *  multiples of 16 for pico cache
**********************************************************************************************************************/
#define SMALL_STRINGS 16   // Cache line size - perfect for names/menu items
#define MEDIUM_STRINGS 32   // Cache line size - perfect for names/menu items
#define LARGE_STRINGS 128  // Plenty for descriptions (fits 1-2 sentences)


/**********************************************************************************************************************/
/**INPUT constants
**********************************************************************************************************************/
#define MENU_INPUT_POLLING_RATE 200
#define MENU_INPUT_POLLING_RATE_INIT 200

/**********************************************************************************************************************/
/**PLAYER constants
**********************************************************************************************************************/
#define MAX_PARTY_SIZE 6
#define MAX_SPELLBOOK_SIZE 30
#define SPELL_INDEX_NULL 255
#define DEFAULT_SPELLBOOK_SIZE 8
#define MAX_ITEM_SIZE 25
#define MAX_SPELL_SIZE 16    // spells not implemented yet, still a maybe
#define PERK_BAG_SIZE 0     // perks not implemented yet, still a maybe
#define MAX_BAG_SIZE (DEFAULT_BAG_SIZE + MAX_ITEM_SIZE + MAX_SPELL_SIZE + PERK_BAG_SIZE)


/**********************************************************************************************************************/
/**CAMERA constants
**********************************************************************************************************************/
#define VIEW_TW (SCREEN_W / MAP_TILE_W)
#define VIEW_TH (SCREEN_H / MAP_TILE_H)
#define CAM_OFFSET_Y  ((VIEW_TH / 2))
#define CAM_OFFSET_X  (((VIEW_TW / 2) - 1))

/**********************************************************************************************************************/
/** ENTITY constants
**********************************************************************************************************************/
#if defined(TEST_MAP)
#define MAX_ENTITY_ITEM_COUNT 255
#define MAX_ENTITY_OBJECT_COUNT 255
#define MAX_ENTITY_CREATURE_COUNT 255
#define MAX_ENTITY_TRAINER_COUNT 255
#else
#define MAX_ENTITY_ITEM_COUNT 254
#define MAX_ENTITY_OBJECT_COUNT 254
#define BASE_ENTITY_OBJECT_COUNT MAP_H //object count scales with map size
#define MAX_ENTITY_CREATURE_COUNT 32
#define MAX_ENTITY_TRAINER_COUNT 4
#endif


#define MAX_DEFAULT_TRAINER_SPELLS 6
#define MAX_DEFAULT_TRAINER_ITEMS 6

#define ENTITY_ITEM_COUNT 255
#define ENTITY_COUNT 100
#define NO_ENTITY 255
#define MAX_ABILITIES 6
#define TOTAL_SPAWNABLE_OBJECT_TYPES 4

#define MAX_CREATURE_LEVEL 99

#define MAX_PP 16
#define MAX_STATUS_VALUE 16
#define MAX_MAX_STATUS_EFFECTS 16

/**********************************************************************************************************************/
/** Icon constants
**********************************************************************************************************************/
#define ICON_W 80
#define ICON_H 80
#define BUFF_W 48
#define BUFF_H 48
#define ICON_PIXELS (ICON_W * ICON_H)

/**********************************************************************************************************************/
/** Player Defaults
**********************************************************************************************************************/
#define DEFAULT_LIGHT_RADIUS 7
#define DEFAULT_BAG_SIZE 10


/**********************************************************************************************************************/
/**BATTLE FRAMES constants
**********************************************************************************************************************/
#define BATTLER_TILES_W 7
#define BATTLER_TILES_H 7
#define BATTLER_AREA_W ((BATTLER_TILES_W +2) * TILE_W)
#define BATTLER_AREA_H (BATTLER_TILES_H * TILE_H)
#define BATTLER_OFFSET ((BATTLER_AREA_W - BATTLER_AREA_H) / 2)

#define RESOURCE_FRAME_W (TILE_W * 6)
#define RESOURCE_FRAME_H (TEXT_W * 5)
#define RESOURCE_WIDTH (RESOURCE_FRAME_W-TILE_W)
#define RESOURCE_TEXT_FRAME_W (TEXT_W * 10)
#define RESOURCE_HEIGHT TEXT_W
#define BUFF_FRAME_H ((BUFF_H * 2) + 6)

#define BATTLE_MENU_HEIGHT (TEXT_H * 6)
#define DIALOGUE_H  (TEXT_H * 8)
#define DIALOGUE_BOX_FRAME      ((Rect_16){0, SCREEN_H-DIALOGUE_H, SCREEN_W, DIALOGUE_H})
_Static_assert(DIALOGUE_H + RESOURCE_FRAME_H + BATTLER_AREA_H <= TFT_H, "cannot exceed screen height of screen");

#define PLAYER_STATUS_FRAME_X (SCREEN_W - (TEXT_W * 36))
#define PLAYER_STATUS_FRAME_Y (SCREEN_H - RESOURCE_FRAME_H - DIALOGUE_H-(BUFF_FRAME_H*2))
#define STATUS_FRAME_W (RESOURCE_FRAME_W + (TEXT_W*2) + RESOURCE_TEXT_FRAME_W)
#define STATUS_FRAME_H (RESOURCE_FRAME_H+RESOURCE_FRAME_H)


#define PLAYER_BATTLER_FRAME    ((Rect_16){0, SCREEN_H-BATTLER_AREA_H-DIALOGUE_H-BATTLE_MENU_HEIGHT, BATTLER_AREA_W, BATTLER_AREA_H})
#define PLAYER_RESOURCE_FRAME   ((Rect_16){SCREEN_W-RESOURCE_FRAME_W-TEXT_W, PLAYER_STATUS_FRAME_Y, RESOURCE_FRAME_W, RESOURCE_FRAME_H})
#define PLAYER_STAT_TEXT_FRAME  ((Rect_16){PLAYER_STATUS_FRAME_X, PLAYER_STATUS_FRAME_Y, RESOURCE_TEXT_FRAME_W, RESOURCE_FRAME_H})
#define PLAYER_BUFF_FRAME       ((Rect_16){SCREEN_W-RESOURCE_FRAME_W-RESOURCE_TEXT_FRAME_W - (TEXT_W*2), PLAYER_STATUS_FRAME_Y+RESOURCE_FRAME_H, STATUS_FRAME_W, BUFF_FRAME_H})
#define PLAYER_DEBUFF_FRAME     ((Rect_16){SCREEN_W-RESOURCE_FRAME_W-RESOURCE_TEXT_FRAME_W - (TEXT_W*2), PLAYER_STATUS_FRAME_Y+RESOURCE_FRAME_H+BUFF_FRAME_H, STATUS_FRAME_W, BUFF_FRAME_H})


#define ENEMY_BATTLER_FRAME     ((Rect_16){SCREEN_W-BATTLER_AREA_W, 0, BATTLER_AREA_W, BATTLER_AREA_H})
#define ENEMY_RESOURCE_FRAME    ((Rect_16){TEXT_W, TEXT_W, RESOURCE_FRAME_W, RESOURCE_FRAME_H})
#define ENEMY_STAT_TEXT_FRAME   ((Rect_16){RESOURCE_FRAME_W + (TEXT_W*2), TEXT_H, RESOURCE_TEXT_FRAME_W, RESOURCE_FRAME_H})
#define ENEMY_BUFF_FRAME        ((Rect_16){TEXT_W, TEXT_H + RESOURCE_FRAME_H, STATUS_FRAME_W, BUFF_FRAME_H})
#define ENEMY_DEBUFF_FRAME      ((Rect_16){TEXT_W, TEXT_H + RESOURCE_FRAME_H+BUFF_FRAME_H, STATUS_FRAME_W, BUFF_FRAME_H})


#define BATTLE_MENU_BOX_FRAME   ((Rect_16){0, SCREEN_H-DIALOGUE_H-BATTLE_MENU_HEIGHT, SCREEN_W-STATUS_FRAME_W, BATTLE_MENU_HEIGHT})
#define BATTLE_MENU_X 0
#define BATTLE_MENU_Y ((SCREEN_H-DIALOGUE_H-BATTLE_MENU_HEIGHT) / TEXT_H)
#define BATTLE_MENU_W 2
#define BATTLE_MENU_H 6

#define BATTLE_MENU_COL_1 0
#define BATTLE_MENU_COL_2 20

#define BATTLE_LIST_X 0
#define BATTLE_LIST_Y 9
#define BATTLE_LIST_H (BATTLER_AREA_H / TEXT_H)

/**********************************************************************************************************************/
/**MAP constants
**********************************************************************************************************************/

#define MAX_ROOMS 128

// #define MAP_TILES_16
// #define MAP_TILES_20
// #define MAP_TILES_24
// #define MAP_TILES_32
#define MAP_TILES_64

#if defined(CARTRIDGE)
#define MAP_TILE_W 16
#define MAP_TILE_H 16
#else
#if defined(MAP_TILES_16)
#define MAP_TILE_W 16
#define MAP_TILE_H 16
#elif defined(MAP_TILES_20)
#define MAP_TILE_W 20
#define MAP_TILE_H 20
#elif defined(MAP_TILES_24)
#define MAP_TILE_W 24
#define MAP_TILE_H 24
#elif defined(MAP_TILES_32)
#define MAP_TILE_W 32
#define MAP_TILE_H 32
#elif defined(MAP_TILES_64)
#define MAP_TILE_W 64
#define MAP_TILE_H 64
#else

#define MAP_TILE_W (SCREEN_W / 20)
#define MAP_TILE_H (SCREEN_H / 20)
#endif
#endif

#define TILE_PIXELS (MAP_TILE_W * MAP_TILE_H)
#define MAP_W 64
#define MAP_H 64
#define MAP_TILE_BITS 8
#define MAP_SIZE_CELLS MAP_W * MAP_H
#define MAP_SIZE_BITS (MAP_SIZE_CELLS * MAP_TILE_BITS)
#define MAP_SIZE_BYTES (MAP_SIZE_BITS / 8)
#define MAP_EDGE 0


#define NUM_MAP_TRAINERS 4
#define NUM_MAP_ITEMS 16
#define NUM_MAP_OBJECTS 16
#define NUM_BIOME_CREATURES 16
#define NUM_THEME_CREATURES 16
#define BIOME_MONSTER_TYPES 8
#define THEME_MONSTER_TYPES 7
#define MONSTER_TYPES (BIOME_MONSTER_TYPES + THEME_MONSTER_TYPES + 1)// + one for player sprite
#define MAX_MAP_ITEM_TYPES 16
#define NUM_TILES 256

/**********************************************************************************************************************/
/**MENUS constants
**********************************************************************************************************************/
#define FONT_8_BYTES_PER_CHAR 8
#define FONT_16_BYTES_PER_CHAR 32
#define FONT_20_BYTES_PER_CHAR 50
#define FONT_24_BYTES_PER_CHAR 72
#define FONT_32_BYTES_PER_CHAR 128

#define FONT_OFFSET 32

#define MAIN_MENU_X ((SCREEN_W / TEXT_W) - SMALL_STRINGS)
#define MAIN_MENU_Y 0
#define MAIN_MENU_W (SMALL_STRINGS * TEXT_W)
#define MAIN_MENU_H (SCREEN_H / TEXT_H)
#define MAIN_MENU_LIST_H ((SCREEN_H / TEXT_H) - 2)

#define GLYPH_ROWS_8x8   8
#define MAX_MENU_SIZE (MAIN_MENU_H * 2)
#define MAX_MENU_DEPTH 3
#define BATTLE_MENU_SIZE 6

#define COMBAT_LOG_SIZE 255
#define COMBAT_LOG_LINES 8


/**********************************************************************************************************************/
/**STAT MODIFIERS cosntants
**********************************************************************************************************************/
#define HASTED_PERCENT 25
#define SLOWED_PERCENT 25

/**********************************************************************************************************************/
/**SOUNDS constants
**********************************************************************************************************************/
#define GENERATED_MELODY_LENGTH 64
