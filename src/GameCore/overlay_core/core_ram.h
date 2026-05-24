//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"
#include "enums.h"
#include "core_utils.h"


typedef struct
{
    /**********************************************************************************************************************
    *   Level data
    **********************************************************************************************************************/
    State state;
    uint16_t seed; // for reproducible RNG if desired
    uint16_t turn_count;
    uint16_t turn_final;
    uint8_t floor;
    uint8_t biome : 4;
    uint8_t theme : 4;
    uint8_t layout_type : 4;
    Camera camera;


    /**********************************************************************************************************************
    *   settings cache
    **********************************************************************************************************************/
    struct
    {
        FontSize fontSize;
    } settings;

    struct
    {
        uint8_t level;
        CharStr_uint16 volts;
    } hardware;

    /**********************************************************************************************************************
    *   input cache
    **********************************************************************************************************************/
    struct
    {
        uint16_t defaultGameLoopRate;
        uint16_t gameLoopRate;
        int8_t gameSpeed;
        char gameSpeedStr[16];
    } btns;


    /**********************************************************************************************************************
    *   battle mode data
    **********************************************************************************************************************/
    struct
    {
        ObjectsTypes moveType;
        ObjectType moveID;
        EntityId playerMonsterID;
        EntityId enemyMonsterID;
        char combatLog[2][40]; // TODO: expand o <= 30 lines for a full screen combat log, dont bother with scrolling, use a wraparound ptr
        char hpStr[10];
    } battleMode;


    /**********************************************************************************************************************
    *   map data
    **********************************************************************************************************************/
    uint8_t map[MAP_SIZE_BYTES];
    // EntityId objectMap[MAP_H][MAP_W];
    uint8_t fog[(MAP_H * MAP_W) / 8]; // TODO: not yet implemented
    // Node pathing[(MAP_H * MAP_W) / 2]; // TODO: not yet implemented
    Glyph16x16 tile; // temp RGB565 buffer (512 bytes on stack)
    Glyph buffer;
    uint8_t spriteCache[256];


    /**********************************************************************************************************************
    *   player data
    **********************************************************************************************************************/
    struct
    {
        // EntityId partyID[MAX_PARTY_SIZE];
        // EntityId itemID[MAX_BAG_SIZE];
        // SpellId spellID[MAX_SPELLBOOK_SIZE];

        uint16_t cur_xp[MAX_PARTY_SIZE];
        uint16_t tar_xp[MAX_PARTY_SIZE];

        // TODO: these are the "pokedexes" add checks to populate them
        BitFieldUint8 sacrificedCreatures;
        BitFieldUint8 knownCreatures;
        BitFieldUint8 knownSpells;
        BitFieldUint8 knownItems;
        BitFieldUint8 knownAbilities;
        BitFieldUint8 knownObjects;

        EntityId id;
        uint8_t currentBagSize;
        uint8_t currentSpellbookSize;
        Delta d;
        Delta scroll;
    } player;


    /**********************************************************************************************************************
    *   object data arrays
    **********************************************************************************************************************/
    struct
    {
        uint16_t total;
        Position position[MAX_ENTITY_CREATURE_COUNT];
        Position newPosition[MAX_ENTITY_CREATURE_COUNT]; // can be changed to hold delta, a uint8_t can hold up to 2
        uint8_t types[MAX_ENTITY_CREATURE_COUNT];
        ObjectType metaData[MAX_ENTITY_CREATURE_COUNT]; //any 8 bit data, Creature type, Item type, etc
        BitFieldUint8 onMap;
        BitFieldUint8 active;

        struct
        {
            uint8_t hovering[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t waterWalk[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t waterBreathing[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t repel[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t invisibility[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t wallWalking[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t fireEating[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t lineOfSight[MAX_ENTITY_CREATURE_COUNT]; // controls whether terrain blocks L/2oS
            uint8_t paralyzed[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t sleep[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t poison[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t frozen[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t disease[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t curse[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t hasted[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t fear[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t burned[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t light[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t slowed[MAX_ENTITY_CREATURE_COUNT / 2];
        } status;

        struct
        {
            uint8_t toxic[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t fire[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t water[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t ice[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t earth[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t magic[MAX_ENTITY_CREATURE_COUNT / 2];
            BitFieldUint8 toxicEating;
            BitFieldUint8 fireEating;
            BitFieldUint8 waterEating;
            BitFieldUint8 iceEating;
            BitFieldUint8 earthEating;
            BitFieldUint8 magicEating;
        } resist;

        struct
        {
            uint8_t strength[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t defence[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t magic[MAX_ENTITY_CREATURE_COUNT / 2];
            uint8_t speed[MAX_ENTITY_CREATURE_COUNT / 2];
        } stat;

        BitFieldUint8 alive;
        Stats stats[MAX_ENTITY_CREATURE_COUNT];
        Attacks attacks[MAX_ENTITY_CREATURE_COUNT];
        IntMax999 hp[MAX_ENTITY_CREATURE_COUNT];
        IntMax999 mp[MAX_ENTITY_CREATURE_COUNT];
        IntMax999 xp[MAX_ENTITY_CREATURE_COUNT]; // can be changed to hold delta, a uint8_t can hold up to 2
        IntMax99 speed[MAX_ENTITY_CREATURE_COUNT];
        Int99 level[MAX_ENTITY_CREATURE_COUNT];
        Senses senses[MAX_ENTITY_CREATURE_COUNT];
        Senses stealth[MAX_ENTITY_CREATURE_COUNT];
    } creatures;

    struct
    {
        uint16_t total;
        EntityId itemID[MAX_ENTITY_TRAINER_COUNT][MAX_BAG_SIZE];
        EntityId partyID[MAX_ENTITY_TRAINER_COUNT][MAX_PARTY_SIZE];
        SpellId spellID[MAX_ENTITY_TRAINER_COUNT][MAX_SPELLBOOK_SIZE];

        Position position[MAX_ENTITY_TRAINER_COUNT];
        Position newPosition[MAX_ENTITY_TRAINER_COUNT]; // can be changed to hold delta, a uint8_t can hold up to 2
        uint8_t types[MAX_ENTITY_TRAINER_COUNT];
        ObjectType metaData[MAX_ENTITY_TRAINER_COUNT]; //any 8 bit data, Creature type, Item type, etc
        BitFieldUint8 onMap;
        BitFieldUint8 active;

        BitFieldUint8 alive;
        IntMax99 speed[MAX_ENTITY_TRAINER_COUNT];
        Senses senses[MAX_ENTITY_TRAINER_COUNT];
        Senses stealth[MAX_ENTITY_TRAINER_COUNT];
    } trainers;

    struct
    {
        uint16_t total;
        Position position[MAX_ENTITY_OBJECT_COUNT];
        Position newPosition[MAX_ENTITY_OBJECT_COUNT]; // can be changed to hold delta, a uint8_t can hold up to 2
        uint8_t types[MAX_ENTITY_OBJECT_COUNT];
        ObjectType metaData[MAX_ENTITY_OBJECT_COUNT]; //any 8 bit data, Creature type, Item type, etc
        BitFieldUint8 onMap;
        BitFieldUint8 active;
        BitFieldUint8 toggle;
        BitFieldUint8 interactable;
    } objects;

    struct
    {
        uint16_t total;
        Position position[MAX_ENTITY_ITEM_COUNT];
        Position newPosition[MAX_ENTITY_ITEM_COUNT]; // can be changed to hold delta, a uint8_t can hold up to 2
        uint8_t types[MAX_ENTITY_ITEM_COUNT];
        ObjectType metaData[MAX_ENTITY_ITEM_COUNT]; //any 8 bit data, Creature type, Item type, etc
        BitFieldUint8 onMap;
        BitFieldUint8 active;
    } items;

    /**********************************************************************************************************************
    *   ui cache data
    **********************************************************************************************************************/
    struct
    {
        SmallStringArray text[MAX_MENU_SIZE];
        uint8_t depth;
        Vec_8 eraseSel;
        Vec_8_Signed sel[MAX_MENU_DEPTH]; //TODO: placeholder until I know the depth
        Vec_8 menuScrollOffsetCache; //TODO: placeholder until I know the depth
        Vec_8 menuScrollOffset[MAX_MENU_DEPTH]; //TODO: placeholder until I know the depth
        uint8_t selectedMenu;
        uint16_t lineHeight;
        uint8_t displayedMenu;
        uint8_t visibleMenuOptions;
        uint8_t totalMenuOptions;
        bool forceRedraw;
        UseFrameBack useOnPartyMember;
        uint16_t colorCache;
        uint16_t x; // in tiles
        uint16_t y;
        uint16_t h;
        SubMenu* subMenus;
        uint16_t menuSleepTime;

        struct
        {
            bool open;
            EntityId displayId;
            EntityId id;
            // ObjectType  objectType;
        } gameMenu;
    } menu;

    /**********************************************************************************************************************
    *   sound cache data
    **********************************************************************************************************************/
    struct
    {
        bool w;
        uint16_t master_volume;
        uint16_t master_dimmer;
        Note notes[GENERATED_MELODY_LENGTH * 2];
    } music;
} CoreRunState;


extern CoreRunState g_core; // Declaration only


extern const SpellEffect spellFunctions[SPELL_COUNT];
extern const ItemEffect itemFunctions[ITEM_COUNT];


void GameRun_Reset(void); // call at new game / death
