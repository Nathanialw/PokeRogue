//
// Created by nathanial on 5/8/26.
//

#include "core_save.h"

#include "common/constants.h"
#include "common/types.h"

/**********************************************************************************************************************/
/** Player data
**********************************************************************************************************************/
typedef struct
{
    ItemTypes type_id;
} SaveBagItem;

typedef struct
{
    ItemTypes type_id;
    IntMax999 hp;
    IntMax999 mp;
    IntMax999 xp;
    Int99 level;
    Attacks abilities;
    Stats stats;

    //status effects
    uint8_t hovering : 4;
    uint8_t waterWalk : 4;
    uint8_t waterBreathing : 4;
    uint8_t repel : 4;
    uint8_t invisibility : 4;
    uint8_t wallWalking : 4;
    uint8_t fireEating : 4;
    uint8_t lineOfSight : 4;
    uint8_t paralyzed : 4;
    uint8_t sleep : 4;
    uint8_t poison : 4;
    uint8_t frozen : 4;
    uint8_t disease : 4;
    uint8_t curse : 4;
    uint8_t hasted : 4;
    uint8_t fear : 4;
    uint8_t burned : 4;
    uint8_t light : 4;
    uint8_t slowed : 4;

    uint8_t toxic : 4;
    uint8_t fire : 4;
    uint8_t water : 4;
    uint8_t ice : 4;
    uint8_t earth : 4;
    uint8_t magic : 4;

    uint16_t toxicEating : 1;
    uint16_t waterEating : 1;
    uint16_t iceEating : 1;
    uint16_t earthEating : 1;
    uint16_t magicEating : 1;
} SavePartyCreature;

typedef struct
{
    uint8_t type_id;
    uint8_t pp_cur : 4;
    uint8_t pp_max : 4;
} SaveSpellbook;


/**********************************************************************************************************************/
/** Entity data
**********************************************************************************************************************/
typedef struct
{
    uint8_t trainer_id;
    Position position;
} SaveTrainer;

typedef struct
{
    uint8_t type_id;
    Position position;
} SaveItem;

typedef struct
{
    uint8_t type_id;
    Position position;
    uint16_t hp : 12;
    uint16_t alive : 1;

    //status effects
    uint16_t toxicEating : 1;
    uint16_t waterEating : 1;
    uint16_t iceEating : 1;
    uint16_t earthEating : 1;
    uint16_t magicEating : 1;

    uint8_t hovering : 4;
    uint8_t waterWalk : 4;
    uint8_t waterBreathing : 4;
    uint8_t repel : 4;
    uint8_t invisibility : 4;
    uint8_t wallWalking : 4;
    uint8_t fireEating : 4;
    uint8_t lineOfSight : 4;
    uint8_t paralyzed : 4;
    uint8_t sleep : 4;
    uint8_t poison : 4;
    uint8_t frozen : 4;
    uint8_t disease : 4;
    uint8_t curse : 4;
    uint8_t hasted : 4;
    uint8_t fear : 4;
    uint8_t burned : 4;
    uint8_t light : 4;
    uint8_t slowed : 4;

    uint8_t toxic : 4;
    uint8_t fire : 4;
    uint8_t water : 4;
    uint8_t ice : 4;
    uint8_t earth : 4;
    uint8_t magic : 4;
} SaveCreature;

typedef struct
{
    uint8_t type_id;
    Position position;
    uint16_t hp : 12;
    uint16_t alive : 1;
    uint16_t _UNUSED : 3;
} SaveObject;

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
typedef struct
{
    struct
    {
        const uint16_t seed;
        const uint16_t turnCount;
        const uint16_t turnFinal;
        const uint16_t floor;
        const uint8_t biome : 4;
        const uint8_t theme : 4;
        const uint8_t map_tiles[MAP_SIZE_BYTES]; // map tiles in bits 120 x 128 x 6 (64 num_tile_ids)
    } gameState;

    // backpack, party
    struct
    {
        const SaveBagItem bag[MAX_BAG_SIZE];
        const SavePartyCreature party[MAX_PARTY_SIZE];
        const SaveSpellbook spells[MAX_SPELL_SIZE];
    } player;

    struct
    {
        const BitFieldUint8 trainers;
        const BitFieldUint8 items;
        const BitFieldUint8 skills;
        const BitFieldUint8 creature;
        const BitFieldUint8 sacrificedCreature;
        const BitFieldUint8 spells;
    } known;

    struct
    {
        const SaveTrainer trainers[NUM_MAP_TRAINERS]; // type_id, position
        const SaveCreature creatures[NUM_BIOME_CREATURES + NUM_THEME_CREATURES]; // type_id, position, hp current (generate max with seed), alive (assumed to be onMap)
        const SaveObject objects[NUM_MAP_OBJECTS]; // type_id, used
        const SaveItem items[NUM_MAP_ITEMS]; // type_id, position (assumed to be onMap)
    } entities;
} Save;

#define SAVE_ADDR_SEED
#define SAVE_ADDR_TURN_COUNT
#define SAVE_ADDR_TURN_FINAL
#define SAVE_ADDR_FLOOR
#define SAVE_ADDR_BIOME
#define SAVE_ADDR_THEME
#define SAVE_ADDR_MAP_TILES

#define SAVE_ADDR_PLAYER_BAG
#define SAVE_ADDR_PLAYER_PARTY
#define SAVE_ADDR_PLAYER_SPELLS

#define SAVE_ADDR_KNOWN_TRAINERS
#define SAVE_ADDR_KNOWN_ITEMS
#define SAVE_ADDR_KNOWN_SKILLS
#define SAVE_ADDR_KNOWN_CREATURES
#define SAVE_ADDR_KNOWN_SACRIFICED_CREATURES
#define SAVE_ADDR_KNOWN_SPELLS

#define SAVE_ADDR_ENTITIES_TRAINERS
#define SAVE_ADDR_ENTITIES_CREATURES
#define SAVE_ADDR_ENTITIES_OBJECTS
#define SAVE_ADDR_ENTITIES_ITEMS
