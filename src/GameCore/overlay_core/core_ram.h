//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"
#include "enums.h"


typedef struct
{
    /**********************************************************************************************************************
    *   Level data
    **********************************************************************************************************************/
    State state;
    uint16_t seed; // for reproducible RNG if desired
    bool initialized;
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
        EntityId playerMonsterID;
        EntityId enemyMonsterID;
        EntityId enemy_trainer_id;

        ObjectsTypes moveType;
        ObjectType moveID;
        uint8_t current_line;
        char combatLog[COMBAT_LOG_SIZE][40]; // TODO: expand o <= 30 lines for a full screen combat log, dont bother with scrolling, use a wraparound ptr
        char hpStr[10];
        int16_t battle_hp_cache[2];
        int16_t battle_mp_cache[2];
        int16_t battle_xp_cache;
        int16_t battle_xp_max_cache;
    } battleMode;

    char tooltip_text[MAX_OBJECT_EFFECTS + 1][LARGE_STRINGS];
    uint8_t tooltip_length;

    /**********************************************************************************************************************
    *   map data
    **********************************************************************************************************************/
    uint8_t map[MAP_SIZE_BYTES];
    // EntityId objectMap[MAP_H][MAP_W];
    uint8_t fog[MAP_H][MAP_W]; // TODO: not yet implemented
    // Node pathing[(MAP_H * MAP_W) / 2]; // TODO: not yet implemented
    Glyph tile; // temp RGB565 buffer (512 bytes on stack)
    Glyph buffer;
    Glyph spriteCache;

    struct
    {
        Glyph spritePixels; // 512 bytes
        Glyph spriteCache; // 512 bytes
    } tileCache;

    //TODO: make into a union with something else
    Room rooms[MAX_ROOMS];
    uint8_t roomCount;

    union
    {
        StatsRange statsCache;
        Attributes attributesCache;
        Resists resistsCache;
    };

    uint16_t area_down_y;
    bool update_right_inventory;
    bool update_right_party;
    bool update_right_text;
    bool update_left_spellbook;
    bool update_left_player;
    bool update_left_text;
    bool update_right_text_clear;
    bool update_text;
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
        BitFieldUint8 defeated_trainers;
        BitFieldUint8 sacrificedCreatures;
        BitFieldUint8 knownCreatures;
        BitFieldUint8 knownSpells;
        BitFieldUint8 knownItems;
        BitFieldUint8 knownAbilities;
        BitFieldUint8 knownObjects;

        EntityId cachedItems[MAX_BAG_SIZE];
        EntityId cachedParty[MAX_PARTY_SIZE];

        uint8_t vision_radius;
        EntityId id;

        Delta d;
        Delta scroll;
        BitFieldUint8 effects;
    } player;


    /**********************************************************************************************************************
    *   object data arrays
    **********************************************************************************************************************/
    struct
    {
        // uint16_t total;
        Position position[MAX_ENTITY_CREATURE_COUNT];
        Position newPosition[MAX_ENTITY_CREATURE_COUNT]; // can be changed to hold delta, a uint8_t can hold up to 2
        uint8_t types[MAX_ENTITY_CREATURE_COUNT];
        ObjectType metaData[MAX_ENTITY_CREATURE_COUNT]; //any 8 bit data, Creature type, Item type, etc
        BitFieldUint8 onMap;
        BitFieldUint8 active;

        CreatureBuffs buffs[MAX_ENTITY_CREATURE_COUNT];
        CreatureDebuffs debuffs[MAX_ENTITY_CREATURE_COUNT];
        BitFieldUint8 alive;

        Absorb absorb[MAX_ENTITY_CREATURE_COUNT];
        Resists resists[MAX_ENTITY_CREATURE_COUNT];
        Attributes attributes[MAX_ENTITY_CREATURE_COUNT];
        Stats stats[MAX_ENTITY_CREATURE_COUNT];
        Attacks attacks[MAX_ENTITY_CREATURE_COUNT];
        uint_max999 hp[MAX_ENTITY_CREATURE_COUNT];
        uint_max999 mp[MAX_ENTITY_CREATURE_COUNT];
        uint_max999 xp[MAX_ENTITY_CREATURE_COUNT]; // can be changed to hold delta, a uint8_t can hold up to 2
        IntMax99 speed[MAX_ENTITY_CREATURE_COUNT];
        uint99 level[MAX_ENTITY_CREATURE_COUNT];
        Senses senses[MAX_ENTITY_CREATURE_COUNT];
        Senses stealth[MAX_ENTITY_CREATURE_COUNT];
    } creatures;

    struct
    {
        TrainerBuffs buffs[MAX_ENTITY_TRAINER_COUNT];

        // uint16_t total;
        EntityId partyID[MAX_ENTITY_TRAINER_COUNT][MAX_PARTY_SIZE];
        EntityId itemID[MAX_ENTITY_TRAINER_COUNT][MAX_BAG_SIZE];
        BagData bag[MAX_ENTITY_TRAINER_COUNT];
        SpellBook spellbook[MAX_ENTITY_TRAINER_COUNT];

        Position position[MAX_ENTITY_TRAINER_COUNT];
        Position newPosition[MAX_ENTITY_TRAINER_COUNT]; // can be changed to hold delta, a uint8_t can hold up to 2
        uint8_t types[MAX_ENTITY_TRAINER_COUNT];
        ObjectType metaData[MAX_ENTITY_TRAINER_COUNT]; //any 8 bit data, Creature type, Item type, etc
        BitFieldUint8 onMap;
        BitFieldUint8 active;
        uint8_t currentPartySize[MAX_ENTITY_TRAINER_COUNT];

        BitFieldUint8 alive;
        IntMax99 speed[MAX_ENTITY_TRAINER_COUNT];
        Senses senses[MAX_ENTITY_TRAINER_COUNT];
        Senses stealth[MAX_ENTITY_TRAINER_COUNT];

        //gain xp via sacrifices
        uint_max999 xp[MAX_ENTITY_TRAINER_COUNT];
        uint99 level[MAX_ENTITY_TRAINER_COUNT];
        SkillsGeneral skill_general[MAX_ENTITY_TRAINER_COUNT];
        SkillsMage skill_mage[MAX_ENTITY_TRAINER_COUNT];
        SkillsWarrior skill_warrior[MAX_ENTITY_TRAINER_COUNT];
        SkillsRogue skill_rogue[MAX_ENTITY_TRAINER_COUNT];
        //skills
    } trainers;

    struct
    {
        // uint16_t total;
        Position position[MAX_ENTITY_OBJECT_COUNT];
        uint8_t types[MAX_ENTITY_OBJECT_COUNT];
        ObjectType metaData[MAX_ENTITY_OBJECT_COUNT]; //any 8 bit data, Creature type, Item type, etc
        BitFieldUint8 onMap;
        BitFieldUint8 active;
        BitFieldUint8 toggle;
        BitFieldUint8 interactable;
    } objects;

    struct
    {
        // uint16_t total;
        Position position[MAX_ENTITY_OBJECT_COUNT];
        uint8_t types[MAX_ENTITY_OBJECT_COUNT];
        ObjectType metaData[MAX_ENTITY_OBJECT_COUNT]; //any 8 bit data, Creature type, Item type, etc
        BitFieldUint8 onMap;
        BitFieldUint8 active;
        BitFieldUint8 toggle;
        BitFieldUint8 interactable;
    } environment_objects;

    struct
    {
        // uint16_t total;
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
        uint8_t max_visible_menu_options;
        uint8_t occupied_visible_menu_options;
        uint8_t totalMenuOptions;
        bool forceRedraw;
        UseFrameBack useOnPartyMember;
        Color colorCache;
        uint16_t x; // in tiles
        uint16_t y;
        uint16_t h;
        uint16_t x_offset;
        SubMenu* subMenus;
        uint16_t menuSleepTime;
        ObjectsTypes entity_list_type;

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


uint8_t GetCreatureSoundId(uint8_t creature_id);
uint8_t GetSpellSoundId(uint8_t spell_id);
uint8_t GetItemSoundId(uint8_t item_id);
uint8_t GetTileSoundId(uint8_t tile_id);
uint8_t GetTrainerSoundId(uint8_t trainer_id);
uint8_t GetObjectSoundId(uint8_t object_id);
uint8_t GetSkillSoundId(uint8_t skill_id);
uint8_t GetMenuSoundId(MenuSounds mune_sound);
