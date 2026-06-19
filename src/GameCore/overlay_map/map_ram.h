//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "enums.h"
#include "types.h"

typedef struct
{
    char name[SMALL_STRINGS];
    char desc[LARGE_STRINGS];
    SpriteLayout layout;
    char typeA[SMALL_STRINGS];
    char typeB[SMALL_STRINGS];
} EntityData;


typedef struct
{
    /**********************************************************************************************************************
 *   graphics cache
 **********************************************************************************************************************/
    struct
    {
        Tile tileCache;

        Glyph tilePixels; // 512 bytes
        Glyph spritePixels; // 512 bytes
        Glyph spriteCache; // 512 bytes
        Sprite entityCache; // 512 bytes
        uint8_t tile_id; // Which tile is cached
        uint8_t sprite_id; // Which sprite is cached
    } tileCache;


    /**********************************************************************************************************************
    *   Dirty tile rendering cache arrays
    **********************************************************************************************************************/
    struct
    {
        uint8_t vision[VIEW_TH][VIEW_TW]; // TODO: not yet implemented
        uint8_t viewTiles[VIEW_TH][VIEW_TW];
        uint8_t dirtyTiles[(VIEW_TH * VIEW_TW) / 8];
        ViewEntities viewCreatures;
        ViewEntities viewItems;
        ViewEntities viewObjects;
        ViewEntities viewTrainers;
    } view;


    uint8_t meta[TFT_H / BUFFER_H];
    EntityId units[MAX_ENTITY_CREATURE_COUNT];

    EntityData entityData;
    uint8_t spriteCache[256];


    Glyph glyph;
    Glyph buffer;

    const char power[SMALL_STRINGS];
    const char rarity[SMALL_STRINGS];


    EntityId objectCollision;
    EntityId itemCollision;
    char text[320 / 8];
    bool clearTooltip;
} MapRunState;


extern MapRunState g_map; // Declaration only


extern const ObjectEffect objectFunctions[OBJECT_COUNT];


ActionOutcome UseMapItem(HardwareInterface hardware, MemoryInterface memory, uint8_t itemType, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index);
ActionOutcome CastMapSpell(HardwareInterface hardware, MemoryInterface memory, uint8_t spellType, EntityId caster_id, EntityId target_id, SpellData spellData);
ActionOutcome UseMapObject(HardwareInterface hardware, MemoryInterface memory, ObjectId object_type_id, EntityId object_id, EntityId target_id, ObjectData objectData, ObjectsTypes entity_type, uint8_t index);
