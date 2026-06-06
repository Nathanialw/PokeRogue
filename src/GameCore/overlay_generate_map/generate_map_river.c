//
// Created by nathanial on 6/5/26.
//

#include "generate_map_river.h"

#include "core_map.h"
#include "lib_memory.h"


SET_MEMORY(".map_gen")
void GenerateRiver(uint8_t x, uint8_t y, TileType type)
{
    uint8_t direction_weighting = 1;

    for (uint8_t i = 0; i < MAP_W; i++)
    {
        SetMapTile(x + i, y, type);
    }
}


SET_MEMORY(".map_gen")
void CheckAdjacentTiles(HardwareInterface hardware, uint8_t x, uint8_t y, TileType type, uint8_t depth, const uint8_t max_depth)
{
    depth++;
    if (depth > max_depth)
        return;

    SetMapTile(x, y, type);
    uint8_t growth_chance = 10;

    if (hardware.GetRandom_uint8_t(1, growth_chance) < 8 && GetMapTile(x - 1, y) != type)
        CheckAdjacentTiles(hardware, x - 1, y, type, depth, max_depth);
    if (hardware.GetRandom_uint8_t(1, growth_chance) < 8 && GetMapTile(x + 1, y) != type)
        CheckAdjacentTiles(hardware, x + 1, y, type, depth, max_depth);
    if (hardware.GetRandom_uint8_t(1, growth_chance) < 8 && GetMapTile(x, y - 1) != type)
        CheckAdjacentTiles(hardware, x, y - 1, type, depth, max_depth);
    if (hardware.GetRandom_uint8_t(1, growth_chance) < 8 && GetMapTile(x, y + 1) != type)
        CheckAdjacentTiles(hardware, x, y + 1, type, depth, max_depth);
}

SET_MEMORY(".map_gen")
void GenerateLake(HardwareInterface hardware, uint8_t x, uint8_t y, const uint8_t size, TileType type)
{
    CheckAdjacentTiles(hardware, x, y, type, 0, size);
}
