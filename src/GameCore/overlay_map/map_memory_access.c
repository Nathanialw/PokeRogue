//
// Created by nathanial on 5/19/26.
//

#include "map_memory_access.h"
#include "lib_memory.h"

#include "types.h"

#include "core_ram.h"

#include "map_ram.h"
#include "memory_constants.inc"


/**********************************************************************************************************************/
/*      ENTITIES
**********************************************************************************************************************/
SET_MEMORY(".map")
uint8_t Flash_GetStatGrowth(MemoryInterface memory, Creature type)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.creatureStats[type].growth;
#else
    const uint8_t length = 1;
    uint8_t struct_bytes[length];
    memory.GetRom(GAME_DATA_CREATURE_STATS_POSITION + type, struct_bytes, length);
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, struct_bytes[i]);
    memory.Print(new_line);
#endif
    return struct_bytes[0];
#endif
}

SET_MEMORY(".map")
Creature Flash_GetBiomeCreature(MemoryInterface memory, uint8_t biome, Creature index)
{
#ifdef STANDALONE
    return g_gameFlash.tileset.monsterGroups[biome][index];
#else
    const uint8_t length = 1;
    uint8_t struct_bytes[length];
    memory.GetRom(CHAR_SPRITES_BIOMES_POSITION + index, struct_bytes, length);
#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, struct_bytes[i]);
    memory.Print(new_line);
#endif
    return struct_bytes[0];
#endif
}

SET_MEMORY(".map")
Creature Flash_GetThemeCreature(MemoryInterface memory, uint8_t theme, Creature index)
{
#ifdef STANDALONE
    return g_gameFlash.tileset.themeGroups[theme][creature_type];
#else
    const uint8_t length = 1;
    uint8_t struct_bytes[length];
    memory.GetRom(TILESET_THEME_POSITION + index, struct_bytes, length);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < length; i++)
        memory.Print(str_spawn_creature_type, struct_bytes[i]);
    memory.Print(new_line);
#endif
    return struct_bytes[0];
#endif
}


/**********************************************************************************************************************/
/**     MAP
**********************************************************************************************************************/
SET_MEMORY(".map")
void Flash_GetBiomeTile(MemoryInterface memory, Tile* tile, uint8_t biomeType, uint8_t tile_id)
{
#ifdef STANDALONE
    return g_gameFlash.sprites.biomes[biomeType][tile_id];
#else
    memory.GetRom(CHAR_SPRITES_BIOMES_POSITION + (g_core.biome * (NUM_TILES * sizeof(Tile))) + (tile_id * sizeof(Tile)), tile->bytes, sizeof(Tile));

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(Tile); i++)
        memory.Print(str_spawn_creature_type, tile->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}


/**********************************************************************************************************************/
/*      SPRITES
**********************************************************************************************************************/
SET_MEMORY(".map")
void Flash_GetTextSpriteMetadata(MemoryInterface memory, Sprite* sprite, ObjectsTypes type, uint8_t index)
{
#ifdef STANDALONE
    if (type == ITEM)
    {
        return g_gameFlash.sprites.items[type];
    }
    else if (type == CREATURE)
    {
        return g_gameFlash.sprites.monsters[type];
    }
    else if (type == OBJECT)
    {
        return g_gameFlash.sprites.objects[type];
    }
#else

    if (type == ITEM)
        memory.GetRom(CHAR_SPRITES_ITEMS_POSITION + (index * sizeof(Sprite)), sprite->bytes, sizeof(Sprite));
    else if (type == CREATURE)
        memory.GetRom(CHAR_SPRITES_MONSTERS_POSITION + (index * sizeof(Sprite)), sprite->bytes, sizeof(Sprite));
    else if (type == OBJECT)
        memory.GetRom(CHAR_SPRITES_OBJECTS_POSITION + (index * sizeof(Sprite)), sprite->bytes, sizeof(Sprite));
    else if (type == TRAINER)
        memory.GetRom(CHAR_SPRITES_TRAINERS_POSITION + (index * sizeof(Sprite)), sprite->bytes, sizeof(Sprite));

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(Sprite); i++)
        memory.Print(str_spawn_creature_type, sprite->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".map")
void Flash_GetMapTileMetadata(MemoryInterface memory, SpriteFrames* sprite, uint8_t index)
{
#if defined(MAP_TILES_16)
    memory.GetRom(SPRITE_16X16_TILE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
#elif defined(MAP_TILES_20)
    memory.GetRom(SPRITE_20X20_TILE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
#elif defined(MAP_TILES_24)
    memory.GetRom(SPRITE_24X24_TILE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
#elif defined(MAP_TILES_32)
    memory.GetRom(SPRITE_32X32_TILE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
#elif defined(MAP_TILES_64)
    memory.GetRom(SPRITE_64X64_TILE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(Sprite); i++)
        memory.Print(str_spawn_creature_type, sprite->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".map")
void Flash_GetMapTile(MemoryInterface memory, uint8_t* bytes, SpriteFrames* sprite)
{
#if defined(MAP_TILES_16)
    memory.GetRom(SPRITE_16X16_TILE_POSITION + sprite->index, bytes, sprite->size);
#elif  defined(MAP_TILES_20)
    memory.GetRom(SPRITE_20X20_TILE_POSITION + sprite->index, bytes, sprite->size);
#elif  defined(MAP_TILES_24)
    memory.GetRom(SPRITE_24X24_TILE_POSITION + sprite->index, bytes, sprite->size);
#elif  defined(MAP_TILES_32)
    memory.GetRom(SPRITE_32X32_TILE_POSITION + sprite->index, bytes, sprite->size);
#elif  defined(MAP_TILES_64)
    memory.GetRom(SPRITE_64X64_TILE_POSITION + sprite->index, bytes, sprite->size);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(Sprite); i++)
        memory.Print(str_spawn_creature_type, sprite->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".map")
void Flash_GetMapSpriteMetadata(MemoryInterface memory, SpriteFrames* sprite, ObjectsTypes type, uint8_t index)
{
#if defined(MAP_TILES_16)
    if (type == ITEM)
        memory.GetRom(SPRITE_16X16_ITEM_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == CREATURE)
        memory.GetRom(SPRITE_16X16_CREATURE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == OBJECT)
        memory.GetRom(SPRITE_16X16_OBJECT_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == TRAINER)
        memory.GetRom(SPRITE_16X16_TRAINER_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
#elif defined(MAP_TILES_20)
    if (type == ITEM)
        memory.GetRom(SPRITE_20X20_ITEM_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == CREATURE)
        memory.GetRom(SPRITE_20X20_CREATURE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == OBJECT)
        memory.GetRom(SPRITE_20X20_OBJECT_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == TRAINER)
        memory.GetRom(SPRITE_20X20_TRAINER_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
#elif defined(MAP_TILES_24)
    if (type == ITEM)
        memory.GetRom(SPRITE_24X24_ITEM_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == CREATURE)
        memory.GetRom(SPRITE_24X24_CREATURE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == OBJECT)
        memory.GetRom(SPRITE_24X24_OBJECT_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == TRAINER)
        memory.GetRom(SPRITE_24X24_TRAINER_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
#elif defined(MAP_TILES_32)
    if (type == ITEM)
        memory.GetRom(SPRITE_32X32_ITEM_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == CREATURE)
        memory.GetRom(SPRITE_32X32_CREATURE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == OBJECT)
        memory.GetRom(SPRITE_32X32_OBJECT_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == TRAINER)
        memory.GetRom(SPRITE_32X32_TRAINER_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
#elif defined(MAP_TILES_64)
    if (type == ITEM)
        memory.GetRom(SPRITE_64X64_ITEM_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == CREATURE)
        memory.GetRom(SPRITE_64X64_CREATURE_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == OBJECT)
        memory.GetRom(SPRITE_64X64_OBJECT_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));
    else if (type == TRAINER)
        memory.GetRom(SPRITE_64X64_TRAINER_METADATA_POSITION + (index * sizeof(SpriteFrames)), sprite->bytes, sizeof(SpriteFrames));

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(Sprite); i++)
        memory.Print(str_spawn_creature_type, sprite->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".map")
void Flash_GetMapSprite(MemoryInterface memory, uint8_t* bytes, SpriteFrames* sprite, ObjectsTypes type)
{
#if defined(MAP_TILES_16)
    if (type == ITEM)
        memory.GetRom(SPRITE_16X16_ITEM_POSITION + sprite->index, bytes, sprite->size);
    else if (type == CREATURE)
        memory.GetRom(SPRITE_16X16_CREATURE_POSITION + sprite->index, bytes, sprite->size);
    else if (type == OBJECT)
        memory.GetRom(SPRITE_16X16_OBJECT_POSITION + sprite->index, bytes, sprite->size);
    else if (type == TRAINER)
        memory.GetRom(SPRITE_16X16_TRAINER_POSITION + sprite->index, bytes, sprite->size);
#elif  defined(MAP_TILES_20)
    if (type == ITEM)
        memory.GetRom(SPRITE_20X20_ITEM_POSITION + sprite->index, bytes, sprite->size);
    else if (type == CREATURE)
        memory.GetRom(SPRITE_20X20_CREATURE_POSITION + sprite->index, bytes, sprite->size);
    else if (type == OBJECT)
        memory.GetRom(SPRITE_20X20_OBJECT_POSITION + sprite->index, bytes, sprite->size);
    else if (type == TRAINER)
        memory.GetRom(SPRITE_20X20_TRAINER_POSITION + sprite->index, bytes, sprite->size);
#elif  defined(MAP_TILES_24)
    if (type == ITEM)
        memory.GetRom(SPRITE_24X24_ITEM_POSITION + sprite->index, bytes, sprite->size);
    else if (type == CREATURE)
        memory.GetRom(SPRITE_24X24_CREATURE_POSITION + sprite->index, bytes, sprite->size);
    else if (type == OBJECT)
        memory.GetRom(SPRITE_24X24_OBJECT_POSITION + sprite->index, bytes, sprite->size);
    else if (type == TRAINER)
        memory.GetRom(SPRITE_24X24_TRAINER_POSITION + sprite->index, bytes, sprite->size);
#elif  defined(MAP_TILES_32)
    if (type == ITEM)
        memory.GetRom(SPRITE_32X32_ITEM_POSITION + sprite->index, bytes, sprite->size);
    else if (type == CREATURE)
        memory.GetRom(SPRITE_32X32_CREATURE_POSITION + sprite->index, bytes, sprite->size);
    else if (type == OBJECT)
        memory.GetRom(SPRITE_32X32_OBJECT_POSITION + sprite->index, bytes, sprite->size);
    else if (type == TRAINER)
        memory.GetRom(SPRITE_32X32_TRAINER_POSITION + sprite->index, bytes, sprite->size);
#elif  defined(MAP_TILES_64)
    if (type == ITEM)
        memory.GetRom(SPRITE_64X64_ITEM_POSITION + sprite->index, bytes, sprite->size);
    else if (type == CREATURE)
        memory.GetRom(SPRITE_64X64_CREATURE_POSITION + sprite->index, bytes, sprite->size);
    else if (type == OBJECT)
        memory.GetRom(SPRITE_64X64_OBJECT_POSITION + sprite->index, bytes, sprite->size);
    else if (type == TRAINER)
        memory.GetRom(SPRITE_64X64_TRAINER_POSITION + sprite->index, bytes, sprite->size);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(Sprite); i++)
        memory.Print(str_spawn_creature_type, sprite->bytes[i]);
    memory.Print(new_line);
#endif
#endif
}


/**********************************************************************************************************************/
/*      Text
**********************************************************************************************************************/

/**********************************************************************************************************************/
/*  for fixed length string strings in an array
 *  use length * index to get the offset
**********************************************************************************************************************/
// UI
SET_MEMORY(".map")
void Flash_GetOptionText(MemoryInterface memory, uint8_t* textBuffer, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.menus.options[index];
#else
    memory.GetRom(STRINGS_MENU_OPTIONS_POSITION + (SMALL_STRINGS * index), textBuffer, SMALL_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, textBuffer[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".map")
void Flash_GetCreatureDescription(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.monsters[index];
#else
    memory.GetRom(STRINGS_DESCRIPTIONS_CREATURES_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < LARGE_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".map")
void Flash_GetObjectDescription(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.objects[index];
#else
    memory.GetRom(STRINGS_DESCRIPTIONS_OBJECTS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < LARGE_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".map")
void Flash_GetItemDescription(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.items[index];
#else
    memory.GetRom(STRINGS_DESCRIPTIONS_ITEMS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < LARGE_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".map")
void Flash_GetSpellDescription(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.spells[index];
#else
    memory.GetRom(STRINGS_DESCRIPTIONS_SPELLS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < LARGE_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".map")
void Flash_GetSkillDescription(MemoryInterface memory, char* text, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.text.descriptions.attacks[index];
#else
    memory.GetRom(STRINGS_DESCRIPTIONS_SKILLS_POSITION + (LARGE_STRINGS * index), (uint8_t*)text, LARGE_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < LARGE_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}

SET_MEMORY(".map")
void Flash_GetTypeName(MemoryInterface memory, char* text, uint8_t typeIndex)
{
#ifdef STANDALONE
    return g_gameFlash.text.types[typeIndex];
#else
    memory.GetRom(STRINGS_TYPES_POSITION + (SMALL_STRINGS * typeIndex), (uint8_t*)text, SMALL_STRINGS);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}


SET_MEMORY(".map")
void Flash_GetObjectData(MemoryInterface memory, ObjectData* object_data, uint8_t index)
{
#ifdef STANDALONE
    return g_gameFlash.gameData.objectData[index];
#else

    memory.GetRom(GAME_DATA_OBJECT_POSITION + index, object_data->bytes, sizeof(ObjectData));

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(Tile); i++)
        memory.Print(str_spawn_creature_type);
    memory.Print(new_line);
    return object_data;
#endif
#endif
}


/*****************************************************************************************************************************
*   FUNCTION ARRAYS
*
*****************************************************************************************************************************/

SET_MEMORY(".map")
bool Flash_GetObjectEffect(MemoryInterface memory, HardwareInterface hardware, uint8_t objectType, EntityId object_id, EntityId target_id, ObjectData objectData)
{
#ifdef STANDALONE
    return g_gameFlash.funcs.objectFunctions[objectType](object_id, target_id, objectData);
#else
    return objectFunctions[objectType](hardware, object_id, target_id, objectData);
#endif
}
