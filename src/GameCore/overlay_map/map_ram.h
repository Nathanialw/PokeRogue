//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "common/enums.h"
#include "common/types.h"

typedef struct
{
    char name[SMALL_STRINGS];
    char* desc;
    SpriteLayout layout;
    char* typeA;
    char* typeB;
} EntityData;


typedef struct
{
    /**********************************************************************************************************************
 *   graphics cache
 **********************************************************************************************************************/
    struct
    {
        // uint16_t frameBuffer[BUFFER_H*SCREEN_W];
        // PartialFrameBuffer frameBuffer;

        bool dirtyTiles[VIEW_TH][VIEW_TW];
        Creature newSprites[VIEW_TH][VIEW_TW];
        Tile tileCache;

        Glyph16x16 tilePixels; // 512 bytes
        Glyph16x16 spritePixels; // 512 bytes
        Glyph spriteCache; // 512 bytes
        Sprite entityCache; // 512 bytes
        uint8_t tile_id; // Which tile is cached
        uint8_t sprite_id; // Which sprite is cached
        uint8_t dirty; // Flag if needs refresh
    } tileCache;

    /**********************************************************************************************************************
    *   Dirty tile rendering cache arrays
    **********************************************************************************************************************/
    struct
    {
        uint8_t vision[(VIEW_TH * VIEW_TW) / 8]; // TODO: not yet implemented
        uint8_t viewTiles[VIEW_TH][VIEW_TW];
        uint8_t dirtyTiles[(VIEW_TH * VIEW_TW) / 8];
        ViewEntities viewCreatures;
        ViewEntities viewItems;
        ViewEntities viewObjects;
    } view;

    uint8_t meta[TFT_H / BUFFER_H];
    EntityId units[ENTITY_COUNT];

    EntityData entityData;

    uint8_t spriteCache[256];
    Glyph16x16 tile; // temp RGB565 buffer (512 bytes on stack)

    StatsRange statsCache;

    const char power[SMALL_STRINGS];
    const char rarity[SMALL_STRINGS];
} MapRunState;


extern MapRunState g_map; // Declaration only


extern const ObjectEffect objectFunctions[OBJECT_COUNT];
