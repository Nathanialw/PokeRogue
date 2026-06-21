//
// Created by nathanial on 2/22/26.
//
#pragma once
#include "lib_decl.h"

#include "constants.h"
#include "enums.h"

/**********************************************************************************************************************
*
*********************************************************************************************************************/
typedef char CharStr_uint8[4];
typedef char CharStr_max999[4];
typedef char CharStr_max99[4];
typedef char CharStr_99[3];
typedef char CharStr_uint16[6];


typedef uint8_t EntityId;
typedef uint8_t CreatureID;
typedef uint8_t SpellId;
typedef uint8_t ItemId;
typedef uint8_t ObjectId;
typedef uint8_t SkillId;
typedef uint8_t TrainerId;

typedef int8_t int99;

typedef uint16_t Pixel;
typedef uint16_t TileSet[NUM_TILES * TILE_PIXELS];
typedef uint16_t Glyph16x96s[49];
typedef uint16_t Glyph16x96[(16 * 96)];
typedef char StatusLine[10];
typedef Ability Attacks[8];
typedef char SmallStringArray[SMALL_STRINGS];
typedef uint16_t MapSprite[TILE_W * TILE_H];

typedef bool (*Battle_Animation)(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, bool onAttacker);

/**********************************************************************************************************************/
/**Bitfield types
**********************************************************************************************************************/
/**********************************************************************************************************************/
/** assumes 255 entities
**********************************************************************************************************************/
typedef uint8_t BitFieldUint8[32];
typedef uint16_t BitFieldUint16[16];
typedef uint32_t BitFieldUint32[8];

typedef union
{
    uint8_t bytes[32];
    uint16_t words[16];
    uint32_t dwords[8];
} BitFieldUnion;

/**********************************************************************************************************************
*   entity view for rendering
**********************************************************************************************************************/
typedef struct
{
    uint8_t viewEntities[VIEW_TH][VIEW_TW];
    uint8_t newSprites[VIEW_TH][VIEW_TW];
} ViewEntities;


/**********************************************************************************************************************
*   Creature skills
**********************************************************************************************************************/
#define MAX_LEARNABLE_SKILLS 16

typedef struct
{
    uint8_t skillID;
    uint8_t level;
} SkillLearnLevel;

typedef union
{
    SkillLearnLevel c[MAX_LEARNABLE_SKILLS];
    uint8_t bytes[32];
} CreatureSkillLearnLevels;

_Static_assert(sizeof(CreatureSkillLearnLevels) == 32, "SkillLearnLevel must be 32 bytes");

/**********************************************************************************************************************
*   MENUS
**********************************************************************************************************************/
typedef bool (*SubMenu)(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory, bool update);
typedef uint16_t MainMenuPtr[MAIN_MENU_W];


/**********************************************************************************************************************/
/**  Stores an array of 64 uin16_t pixels
*   can be accessed as a linear array or as a 2d array 8x8
**********************************************************************************************************************/
typedef union
{
    uint16_t pixels[TILE_PIXELS / 4];
    uint16_t pixels_2d[TILE_W / 4][TILE_H / 4];
} Glyph8x8;

// _Static_assert(sizeof(Glyph8x8) == 128, "Glyph8x8 must be 128 bytes");

/**********************************************************************************************************************/
/**  Stores an array of 256 uin16_t pixels
*   can be accessed as a linear array or as a 2d array 16x16
**********************************************************************************************************************/
typedef union
{
    uint16_t pixels[ICON_PIXELS];
    uint16_t pixels_2d[ICON_W][ICON_H];
    uint8_t bytes[ICON_PIXELS * 2];


    // uint16_t glyph[16];
    // uint8_t bytes[FONT_32_BYTES_PER_CHAR];
} Glyph;


// _Static_assert(sizeof(Glyph16x16) == 512, "Glyph16x16 must be 512 bytes");


/**********************************************************************************************************************/
/**  stores entity action data imported from the DB
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint8_t power;
        uint8_t level;

        union
        {
            struct
            {
                uint8_t pp : 4;
                uint8_t type : 4;
            };

            uint8_t data;
        };

        union
        {
            struct
            {
                uint8_t use_on_party_member : 1;
                uint8_t use_on_enemy : 1;
                uint8_t use_on_trainer : 1;

                uint8_t _pad4 : 1;
                uint8_t _pad3 : 1;
                uint8_t _pad2 : 1;
                uint8_t _pad1 : 1;
                uint8_t _pad0 : 1;
            };

            uint8_t flags : 8;
        };
    };


    uint8_t bytes[4];
} SpellData;

_Static_assert(sizeof(SpellData) == 4, "SpellData must be 4 bytes");

typedef union
{
    struct
    {
        uint8_t power;
        uint8_t power_special;
        uint8_t manaCost;
        uint8_t type : 4;
        //TODO: bits unused
        uint8_t _pad : 4;
        //hit chance?
        //crit chance?


        //effects
        union
        {
            struct
            {
                uint16_t bleed : 1;
                uint16_t blind : 1;
                uint16_t burn : 1;
                uint16_t curse : 1;
                uint16_t disease : 1;
                uint16_t disarm : 1;
                uint16_t enfeeble : 1;
                uint16_t fear : 1;
                uint16_t freeze : 1;
                uint16_t paralyze : 1;
                uint16_t petrify : 1;
                uint16_t poison : 1;
                uint16_t root : 1;
                uint16_t sap : 1;
                uint16_t sleep : 1;
                uint16_t slow : 1;
            } debuff;

            uint16_t debuff_flags;
        };


        union
        {
            struct
            {
                uint16_t berserk : 1;
                uint16_t fire_eating : 1;
                uint16_t flying : 1;
                uint16_t haste : 1;
                uint16_t invigorate : 1;
                uint16_t invisible : 1;
                uint16_t lifelink : 1;
                uint16_t magic_shield : 1;
                uint16_t reflect : 1;
                uint16_t regeneration : 1;
                uint16_t revitalize : 1;
                uint16_t spell_power : 1;
                uint16_t stoneskin : 1;
                uint16_t thorns : 1;
                uint16_t vampiric_aura : 1;
                uint16_t warded : 1;
            } buff;
            uint16_t buff_flags;
        };
    };

    uint8_t bytes[8];
} SkillData;

_Static_assert(sizeof(SkillData) == 8, "SkillData must be 8 bytes");

typedef union
{
    struct
    {
        union
        {
            uint8_t chance;
            uint8_t power;
            uint8_t value;
        };

        union
        {
            struct
            {
                uint8_t type : 4;
                uint8_t level : 4;
            };

            uint8_t data;
        };

        union
        {
            struct
            {
                uint8_t consumable : 1;
                uint8_t consumable_party : 1;
                uint8_t consumable_spellbook : 1;
                uint8_t _pad : 5;
            };

            uint8_t flags;
        };
    };

    uint8_t bytes[3];
} ItemData;

_Static_assert(sizeof(ItemData) == 3, "ItemData must be 3 bytes");

typedef union
{
    struct
    {
        union
        {
            uint8_t chance;
            uint8_t power;
        };

        union
        {
            struct
            {
                uint8_t type : 4;
                uint8_t level : 4;
            };

            uint8_t data;
        };

        union
        {
            struct
            {
                //object properties
                uint8_t consumable : 1;
                uint8_t interactable : 1;
                uint8_t on_step : 1;
                uint8_t hallway : 1; //spawn property
                uint8_t nook : 1; //spawn property
                uint8_t water : 1; //spawn property
                uint8_t map_generatable : 1; //spawn property
                uint8_t water_adjacent : 1; //spawn property

                uint8_t corner : 1; //spawn property
                uint8_t on_wall : 1; //spawn property
                uint8_t against_wall : 1; //spawn property
                uint8_t room_center : 1; //spawn property
                uint8_t consumable_party : 1;
                uint8_t consumable_spellbook : 1;
                uint8_t _pad1 : 1;
                uint8_t _pad0 : 1;
            };

            uint16_t flags : 16;
        };
    };

    uint8_t bytes[4];
} ObjectData;

_Static_assert(sizeof(ObjectData) == 4, "ObjectData must be 4 bytes");


typedef struct
{
    SpellData spellData;
    uint8_t pp;
} SpellPage;

typedef struct
{
    uint8_t current_max_pages;
    uint8_t occupied_pages;
    SpellId spell_id[MAX_SPELLBOOK_SIZE];
    SpellPage page[MAX_SPELLBOOK_SIZE];
} SpellBook;


typedef struct
{
    uint8_t occupied_slots;
    uint8_t current_max_size;
} BagData;


typedef ActionOutcome (*SkillEffect)(HardwareInterface hardware, MemoryInterface memory, EntityId trainer_id, EntityId attackerID, EntityId defenderID, SkillData abilityData);
typedef ActionOutcome (*ItemEffect)(HardwareInterface hardware, MemoryInterface memory, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index);
typedef ActionOutcome (*SpellEffect)(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData);
typedef ActionOutcome (*SpellEffectMap)(HardwareInterface hardware, MemoryInterface memory, EntityId caster_id, EntityId enemy_id, SpellData spellData);
typedef ActionOutcome (*ObjectEffect)(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, EntityId e_id, ObjectData objectData, ObjectsTypes objectType, uint8_t index);


/**********************************************************************************************************************/
/**Store 2 integers each max 255
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint8_t x;
        uint8_t y;
    };

    uint16_t index;
} Position;

_Static_assert(sizeof(Position) == 2, "ObjectType must be 2 bytes");

/**********************************************************************************************************************/
/**Stores the type id of a game object
**********************************************************************************************************************/
typedef union
{
    uint8_t unused;
    uint8_t value;

    //items
    uint8_t CreatureID;
    uint8_t spell_id;
    uint8_t AbilityId;
    uint8_t ItemId;


    //objects
    union
    {
        uint8_t toggleable : 1;
        uint8_t active : 1;
        uint8_t active1 : 6;
    };
} ObjectType;

_Static_assert(sizeof(ObjectType) == 1, "ObjectType must be 1 byte");

/**********************************************************************************************************************/
/**  Stores 2 integers each with the max value of 999
*   Used for resources where current/max and max <= 999
*   4 additional bits for flags
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint8_t current_low; // Lower 8 bits of current HP
        uint8_t max_low; // Lower 8 bits of max HP
        uint8_t current_high : 2; // [curr_hi:2][max_hi:2][flags:4]
        uint8_t max_high : 2; // [curr_hi:2][max_hi:2][flags:4]
        //TODO: bits unused
        uint8_t flags : 4; // Raw 4 bits
    };

    uint8_t bytes[3];
} uint_max999;

_Static_assert(sizeof(uint_max999) == 3, "IntMax999 must be 3 bytes");

/**********************************************************************************************************************/
/**  Stores 2 integers each with the max value of 99
*   Used for resources where current/max and max <= 99
*   2 additional bits for flags
**********************************************************************************************************************/
typedef struct
{
    uint16_t current : 7; // max 128
    uint16_t max : 7; // max 128
    //TODO: bits unused
    bool negativeEffect : 1; // 1 bits for flag
    bool positiveEffect : 1; // 1 bits for flag
} IntMax99;

_Static_assert(sizeof(IntMax99) == 2, "IntMax99 must be 2 bytes");

/**********************************************************************************************************************/
/**  the first 4 bits hold the value < 16
*   the remaining 4 bits hold flags
*   you can have a max 16 value while using the remaining bit as flags
**********************************************************************************************************************/
typedef struct
{
    uint8_t current : 4; // max 15
    uint8_t greater : 4;
} Int16;

_Static_assert(sizeof(Int16) == 1, "Int16 must be 1 byte");

/**********************************************************************************************************************/
/**  the first 5 bits hold the value < 32
*   the remaining 3 bits hold flags
*   you can have a max 32 value while using the remaining bit as flags
**********************************************************************************************************************/
typedef struct
{
    uint8_t current : 5; // max 31
    uint8_t greater : 3;
} Int32;

_Static_assert(sizeof(Int32) == 1, "Int32 must be 1 byte");

/**********************************************************************************************************************/
/**  the first 6 bits hold the value < 64
*   the remaining 2 bits hold flags
*   max 64 value while using the remaining bit as flags
**********************************************************************************************************************/
typedef struct
{
    uint8_t current : 6; // max 63
    uint8_t greater : 2;
} Int64;

_Static_assert(sizeof(Int64) == 1, "Int64 must be 1 byte");

/**********************************************************************************************************************/
/**  the top 7 bits hold the value < 128 - meant for max 99 applications
*   the bottom bit holds a flag
*   max 99 value while using the remaining bit as a flag
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint8_t value : 7; // max 127
        uint8_t greater : 1;
    };

    struct
    {
        uint8_t resist : 7; // max 127
        uint8_t absorb_bool : 1;
    };

    uint8_t byte;
} uint99;

/**********************************************************************************************************************/
/**  the top 10 bits hold the value < 1023 - meant for max 999 applications
*   the bottom  6 bits holds flags
*   max 999 value while using the remaining bits as flags
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint16_t value : 10; // max 999
        uint16_t flags : 6;
    };

    struct
    {
        uint16_t _pad_value : 10; // max 999
        uint16_t _pad0 : 1;
        uint16_t _pad1 : 1;
        uint16_t _pad2 : 1;
        uint16_t _pad3 : 1;
        uint16_t _pad4 : 1;
        uint16_t _pad5 : 1;
    };

    uint8_t byte[2];
} Int999;

_Static_assert(sizeof(Int999) == 2, "Int99 must be 2 byte");

/**********************************************************************************************************************/
/** holds the metadata of each object in the sprite arrays
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint32_t idx;
        uint8_t emptyIndexes[7];
        uint16_t palette[16];
    };

    uint8_t bytes[44];
} SpriteLayout;

_Static_assert(sizeof(SpriteLayout) == 44, "SpriteLayout must be 44 bytes");

/**********************************************************************************************************************/
/** holds 2 2-byte unsigned integers
**********************************************************************************************************************/
typedef struct
{
    uint16_t x;
    uint16_t y;
} Vec_16;

_Static_assert(sizeof(Vec_16) == 4, "Vec_16 must be 4 bytes");

/**********************************************************************************************************************/
/** holds 2 1-byte unsigned integers
**********************************************************************************************************************/
typedef struct
{
    uint8_t x;
    uint8_t y;
} Vec_8;

_Static_assert(sizeof(Vec_8) == 2, "Vec_8 must be 2 bytes");

/**********************************************************************************************************************/
/** holds 2 1-byte signed integers
**********************************************************************************************************************/
typedef struct
{
    int8_t x;
    int8_t y;
} Vec_8_Signed;

_Static_assert(sizeof(Vec_8_Signed) == 2, "Vec_8_Signed must be 2 bytes");

/**********************************************************************************************************************/
/** defines a rectangle each 1-byte value max 255
**********************************************************************************************************************/
typedef struct
{
    uint8_t x;
    uint8_t y;
    uint8_t w;
    uint8_t h;
} Rect_8;

_Static_assert(sizeof(Rect_8) == 4, "Rect_8 must be 4 bytes");

/**********************************************************************************************************************
** 16 types of tiles, each have a move limiting effect
** ie no_effect, wall, water, lava, acid, etc
**********************************************************************************************************************/
typedef struct
{
    uint8_t u : 4;
    uint8_t d : 4;
    uint8_t r : 4;
    uint8_t l : 4;
} Node;

_Static_assert(sizeof(Node) == 2, "Node must be 2 bytes");


/**********************************************************************************************************************/
/** This camera struct assumes the max size of the map is 255 x 255
*  defines a rectangle
*       position values max <65536
*       position values max <256
**********************************************************************************************************************/
typedef struct Camera
{
    int16_t x;
    int16_t y;
    uint16_t w;
    uint16_t h;
} Camera;

_Static_assert(sizeof(Camera) == 8, "Camera must be 8 bytes");


/**********************************************************************************************************************/
/** Detection values for creatures packed into 1 byte
 *  Separates out sounds, sight and smell into discrete values
 *      sight value max <8
 *      sound value max <8
 *      smell value max <4
**********************************************************************************************************************/
typedef struct Senses
{
    uint8_t sight : 3;
    uint8_t sound : 3;
    uint8_t smell : 2;
} Senses;

_Static_assert(sizeof(Senses) == 1, "Senses must be 1 byte");

/**********************************************************************************************************************
** Generated stat values for each creature
 *  Grows with levels and can be modified by items/spells/skill
 *  each value is 1 byte - max <256
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint64_t attack : 10; //base damage
        uint64_t defence : 10; //damage reduction
        uint64_t speed : 10; //turn count modifier, flee calculation
        uint64_t magic : 10; //skill power damage modifier
        uint64_t accuracy : 10; //accuracy...
        uint64_t loyalty : 10; //increases chance ot recapture

        uint64_t _pad2 : 4;
    };

    uint64_t raw;
    uint8_t bytes[8];
} Stats;

_Static_assert(sizeof(Stats) == 8, "Stats must be 6 bytes");


/**********************************************************************************************************************
**
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint64_t strength : 10; //crit and damage
        uint64_t fortitude : 10; //hp modifier
        uint64_t intelligence : 10; //skill power damage modifier
        uint64_t agility : 10; //dodge
        uint64_t dexterity : 10; //crit
        uint64_t stamina : 10; //mana pool modifier

        uint64_t _pad1 : 4;
    };

    uint64_t raw;
    uint8_t bytes[8];
} Attributes;

_Static_assert(sizeof(Attributes) == 8, "Stats must be 4 bytes");


/**********************************************************************************************************************
**
**********************************************************************************************************************/
typedef union
{
    struct
    {
        int99 toxic;
        int99 fire;
        int99 water;
        int99 ice;
        int99 earth;
        int99 magic;
    };

    uint8_t bytes[6];
} Resists;

_Static_assert(sizeof(Resists) == 6, "Stats must be 6 bytes");

/**********************************************************************************************************************
**
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint8_t toxic : 1;
        uint8_t fire : 1;
        uint8_t water : 1;
        uint8_t ice : 1;
        uint8_t earth : 1;
        uint8_t magic : 1;

        uint8_t pad0 : 1;
        uint8_t pad1 : 1;
    };

    uint8_t bytes[1];
} Absorb;

_Static_assert(sizeof(Absorb) == 1, "Stats must be 1 bytes");

/**********************************************************************************************************************
** Min and max values of stats
** Growth per level data for a creature
**********************************************************************************************************************/
typedef union
{
    struct
    {
        Stats min;
        Stats max;

        struct
        {
            uint8_t attack : 4;
            uint8_t defence : 4;
            uint8_t speed : 4;
            uint8_t magic : 4;
        } growth;

        uint8_t hp_base;
        uint8_t hp_growth;
        uint8_t mp_base;
        uint8_t mp_growth;

        uint8_t _pad0;
        uint8_t _pad1;
    };

    uint8_t bytes[24];
} StatsRange;

_Static_assert(sizeof(StatsRange) == 24, "StatsRange must be 10 bytes");

/**********************************************************************************************************************/
/** stores the 2 type values each monster has
 *  assumes 16 typ values
 *  each value uses 4 bits
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint8_t typeA :
        4;
        uint8_t typeB : 4;
    };

    uint8_t bytes[1];
} MonsterType;

_Static_assert(sizeof(MonsterType) == 1, "MonsterType must be 1 byte");


/**********************************************************************************************************************/
/** index into the font array to retrieve the glyph data
 *  color value of the glyph
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint8_t glyph_index;
        uint8_t fg : 6;
        //TODO: bits unused - possibly palette data
        uint8_t _pad : 2; //future use
    };

    uint8_t bytes[2];
} Sprite;

_Static_assert(sizeof(Sprite) == 2, "Sprite must be 2 bytes");


/**********************************************************************************************************************/
/** index into the font array to retrieve the glyph data
 *  color value of the background
 *  color value of the glyph
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint8_t glyph_index;
        uint8_t bg : 6;
        uint8_t _pad0 : 2;
        uint8_t fg : 6;
        uint8_t pad1 : 2;
        //TODO: bits unused - possibly palette data
    };

    uint8_t bytes[3];
} Tile;

_Static_assert(sizeof(Tile) == 3, "Sprite must be 3 bytes");


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint32_t index;
        uint32_t size;
        uint16_t palette[16];
    };

    uint8_t bytes[40];
} SpriteFrames;


_Static_assert(sizeof(SpriteFrames) == 40, "Sprite must be 40 bytes");


typedef struct
{
    uint16_t x, y, w, h;
} Room;


typedef union
{
    struct
    {
        CreatureID party[MAX_PARTY_SIZE];
        SpellId spells[MAX_DEFAULT_TRAINER_SPELLS];
        ItemId items[MAX_DEFAULT_TRAINER_ITEMS];
    };

    uint8_t bytes[MAX_DEFAULT_TRAINER_SPELLS + MAX_PARTY_SIZE + MAX_DEFAULT_TRAINER_ITEMS];
} TrainerData;


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint32_t bleed : 4;
        uint32_t blind : 4;
        uint32_t burn : 4;
        uint32_t curse : 4;
        uint32_t disease : 4;
        uint32_t disarm : 4;
        uint32_t enfeeble : 4;
        uint32_t fear : 4;
        uint32_t freeze : 4;
        uint32_t paralyze : 4;
        uint32_t petrify : 4;
        uint32_t poison : 4;
        uint32_t root : 4;
        uint32_t sap : 4;
        uint32_t sleep : 4;
        uint32_t slow : 4;
    };

    uint32_t raw;
    uint8_t bytes[8];
} CreatureDebuffs;

_Static_assert(sizeof(CreatureDebuffs) == 8, "Sprite must be 8 bytes");
/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
typedef union
{
    struct
    {
        uint32_t berserk : 4;
        uint32_t fire_eating : 4;
        uint32_t flying : 4;
        uint32_t haste : 4;
        uint32_t invigorate : 4;
        uint32_t invisible : 4;
        uint32_t lifelink : 4;
        uint32_t magic_shield : 4;
        uint32_t reflect : 4;
        uint32_t regeneration : 4;
        uint32_t revitalize : 4;
        uint32_t spell_power : 4;
        uint32_t stoneskin : 4;
        uint32_t thorns : 4;
        uint32_t vampiric_aura : 4;
        uint32_t warded : 4;
    };

    uint32_t raw;
    uint8_t bytes[8];
} CreatureBuffs;


_Static_assert(sizeof(CreatureBuffs) == 8, "Sprite must be 8 bytes");

typedef union
{
    struct
    {
        uint32_t line_of_sight : 4;
        uint32_t light : 4;
        uint32_t hovering : 4;
        uint32_t water_walk : 4;
        uint32_t water_breathing : 4;
        uint32_t repel : 4;
        uint32_t invisibility : 4;
        uint32_t wall_walking : 4;
        uint32_t _pad7 : 4;
        uint32_t _pad6 : 4;
        uint32_t _pad5 : 4;
        uint32_t _pad4 : 4;
        uint32_t _pad3 : 4;
        uint32_t _pad2 : 4;
        uint32_t _pad1 : 4;
        uint32_t _pad0 : 4;
    };

    uint32_t raw;
    uint8_t bytes[8];
} TrainerBuffs;


_Static_assert(sizeof(TrainerBuffs) == 8, "Sprite must be 8 bytes");
