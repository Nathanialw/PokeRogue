//
// Created by nathanial on 5/19/26.
//

#include "core_map.h"
#include "lib_memory.h"

#include "core_ram.h"
#include "core_utils.h"


/**********************************************************************************************************************/
/** Takes in a map position and returns the index of the tile type
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t GetMapTile(uint8_t x, uint8_t y)
{
    uint16_t index = (y * MAP_W) + x;
    return g_core.map[index];
    //
    // uint8_t byte = g_core.map[index / 2];
    // if (index & 1)
    //     return byte >> 4; // High nibble for odd indices
    //
    // return byte & 0x0F; // Low nibble for even indices
}

/**********************************************************************************************************************/
/** Sets the map tile at the given position to the given tile index
**********************************************************************************************************************/
SET_MEMORY(".core")
void SetMapTile(uint8_t x, uint8_t y, MapTile tile)
{

    uint16_t index = (y * MAP_W) + x;
    g_core.map[index] = tile;

    // uint8_t* byte = &g_core.map[index / 2];
    // if (index & 1)
    // {
    //     *byte = (*byte & 0x0F) | (tile << 4); // Set high nibble
    // }
    // else
    // {
    //     *byte = (*byte & 0xF0) | (tile & 0x0F); // Set low nibble
    // }
}

/**********************************************************************************************************************/
/**Returns the array of entities on map status
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t* GetEntitiesOnMap(ObjectsTypes type)
{
    if (type == CREATURE)
        return g_core.creatures.onMap;
    if (type == ITEM)
        return g_core.items.onMap;
    if (type == OBJECT)
        return g_core.objects.onMap;
    if (type == TRAINER)
        return g_core.trainers.onMap;
    if (type == ENVIRONMENT_OBJECT)
        return g_core.environment_objects.onMap;
    return NULL;
}


/**********************************************************************************************************************/
/** Takes in the entity ID of the querying object, it's position, an array of positions to test against, the size of that array
 *  Returns the entity that is in the given cell
 *  Returns NO_OBJECT if none found
// TODO hashmap was a little pricey on memory, maybe a clever implementation would work, linear search for now
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId CheckTile(ObjectsTypes type, EntityId e_id, Position pos, Position* positions, uint8_t n)
{
    uint8_t* onMap = GetEntitiesOnMap(type);

    for (uint16_t i = 0; i < n; i++)
    {
        if (!GetBit(onMap, i)) continue;
        if ((type == CREATURE || type == TRAINER) && e_id != NO_ENTITY && i == e_id) continue;

        Position t_pos = positions[i];
        if (t_pos.x == pos.x && t_pos.y == pos.y)
            return i;
    }
    return NO_ENTITY;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId CheckTileForEntity(ObjectsTypes type, EntityId e_id, Position pos)
{
    if (type == CREATURE)
    {
        return CheckTile(type, e_id, pos, g_core.creatures.position, MAX_ENTITY_CREATURE_COUNT);
    }

    if (type == ITEM)
    {
        return CheckTile(type, e_id, pos, g_core.items.position, MAX_ENTITY_ITEM_COUNT);
    }

    if (type == OBJECT)
    {
        return CheckTile(type, e_id, pos, g_core.objects.position, MAX_ENTITY_OBJECT_COUNT);
    }

    if (type == TRAINER)
    {
        return CheckTile(type, e_id, pos, g_core.trainers.position, MAX_ENTITY_TRAINER_COUNT);
    }

    if (type == ENVIRONMENT_OBJECT)
    {
        return CheckTile(type, e_id, pos, g_core.environment_objects.position, MAX_ENTITY_ENVIRONMENT_OBJECT_COUNT);
    }

    return NO_ENTITY;
}


/**********************************************************************************************************************/
/** Searches map for a random empty tile
 *  returns tile position when it is found
**********************************************************************************************************************/
SET_MEMORY(".core")
Position FindOpenMapLocation(HardwareInterface hardware, ObjectsTypes type)
{
    while (1)
    {
        Position pos;
        pos.x = hardware.GetRandom_uint8_t(16, MAP_W - 32);
        pos.y = hardware.GetRandom_uint8_t(16, MAP_H - 32);
        if (GetMapTile(pos.x, pos.y) == FLOOR_DIRT && CheckTileForEntity(type, NO_ENTITY, pos) == NO_ENTITY)
        {
            return pos;
        }
    }
}



/**********************************************************************************************************************/
/** Sets the fog value of the entire map to the given fog value
**********************************************************************************************************************/
SET_MEMORY(".core")
void SetMapFog(const uint8_t set)
{
    for (uint16_t y = 0; y < MAP_H; y++)
        for (uint16_t x = 0; x < MAP_W; x++)
        {
            g_core.fog[y][x] = set;
        }
}
