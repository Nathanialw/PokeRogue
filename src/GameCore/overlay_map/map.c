//
// Created by nathanial on 5/19/26.
//

#include "map.h"
#include "lib_memory.h"

#include "constants.h"
#include "core_map.h"
#include "core_ram.h"
#include "lib_debugging.h"

#include "map_entities.h"


/**********************************************************************************************************************/
/** Returns the position of a random map tile
 *  if emptyOnly == true will only return an empty tile
**********************************************************************************************************************/
SET_MEMORY(".map")
Position GetRandomMapTile(HardwareInterface hardware, ObjectsTypes type, bool emptyOnly)
{
    do
    {
        uint8_t x = hardware.GetRandom_uint8_t(0, MAP_W - 1);
        uint8_t y = hardware.GetRandom_uint8_t(0, MAP_H - 1);
        Position pos = {x, y};

        if (emptyOnly)
        {
            if (GetMapTile(x, y) == GROUND && CheckTileForEntity(type, NO_ENTITY, pos) == NO_ENTITY)
            {
                return pos;
            }
        }
        else
        {
            return pos;
        }
    }
    while (1);
}


/**********************************************************************************************************************/
/** TODO: NOT YET IMPLEMENTED
 *  Returns the position of the tile selected by the player
 *  TODO: we need a way to have an unlocked camera
**********************************************************************************************************************/
SET_MEMORY(".map")
Position GetSelectedTile(HardwareInterface hardware, bool emptyOnly)
{
    uint8_t x = hardware.GetRandom_uint8_t(0, MAP_W - 1);
    uint8_t y = hardware.GetRandom_uint8_t(0, MAP_H - 1);
    Position pos = {x, y};
    return pos;
}


/**********************************************************************************************************************/
/** TODO: NOT YET IMPLEMENTED
 *  Checks whether a given map cell position contains a corpse
 *  TODO: search objects for one in the current tile
**********************************************************************************************************************/
SET_MEMORY(".map")
bool TileHasCorpse(Position pos)
{
    return GetMapTile(pos.x, pos.y) == GROUND;
}


/**********************************************************************************************************************/
/*  increments level value
 *  generates a new map
 *  populates new map
 *  place player onto the map in an empty cell
**********************************************************************************************************************/
SET_MEMORY(".map")
void GoNextLevel(HardwareInterface hardware, MemoryInterface memory, MapLevelChange dir)
{
    if (dir == MAP_LEVEL_UP && g_core.floor > 1)
        g_core.floor--;
    else if (dir == MAP_LEVEL_DOWN && g_core.floor < MAX_LEVELS)
        g_core.floor++;

    // UpdateLevel(g_core.floor, DESERT);
    g_core.state.overlay = OVERLAY_GEN_MAP;
}


/**********************************************************************************************************************/
/*
 *  FOG
 *
**********************************************************************************************************************/

/**********************************************************************************************************************/
/** Takes in a given position and returns a bool
 *      if fog == true -> returns true
 *      if fog == false -> returns false
**********************************************************************************************************************/
SET_MEMORY(".map")
bool IsFogged(uint16_t x, uint16_t y)
{
    uint16_t idx = (y * MAP_W) + x;
    return (g_core.fog[idx >> 3] >> (idx & 7)) & 1;
}

/**********************************************************************************************************************/
/** Sets the fog value at the given position to the given fog value
**********************************************************************************************************************/
SET_MEMORY(".map")
void SetFog(uint16_t x, uint16_t y, bool fogged)
{
    uint16_t idx = y * MAP_W + x;
    uint8_t mask = 1 << (idx & 7);
    if (fogged)
        g_core.fog[idx >> 3] |= mask;
    else
        g_core.fog[idx >> 3] &= ~mask;
}

/**********************************************************************************************************************/
/** Sets the fog value of the entire map to the given fog value
**********************************************************************************************************************/
SET_MEMORY(".map")
void SetMapFog(uint8_t set)
{
    for (uint16_t y = 0; y < MAP_H / 8; y++)
        for (uint16_t x = 0; x < MAP_W / 8; x++)
        {
            // SetFog(x, y, set);
            g_core.fog[y + (x * MAP_W / 8)] = set;
        }
}

/**********************************************************************************************************************/
/*
 *  INITIALIZATION
 *
**********************************************************************************************************************/


/**********************************************************************************************************************/
/** Searches map for a random empty tile
 *  returns tile position when it is found
**********************************************************************************************************************/
SET_MEMORY(".map")
Position FindOpenMapLocation(HardwareInterface hardware, ObjectsTypes type)
{
    while (1)
    {
        Position pos;
        pos.x = hardware.GetRandom_uint8_t(16, MAP_W - 32);
        pos.y = hardware.GetRandom_uint8_t(16, MAP_H - 32);
        DEBUG("POS %d %d", pos.x, pos.y);
        if (GetMapTile(pos.x, pos.y) == GROUND && CheckTileForEntity(type, NO_ENTITY, pos) == NO_ENTITY)
        {
            DEBUG("SUCCESS");
            return pos;
        }
    }
}
