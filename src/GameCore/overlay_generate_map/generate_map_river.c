//
// Created by nathanial on 6/5/26.
//

#include "generate_map_river.h"

#include "core_map.h"
#include "generate_map.h"
#include "lib_memory.h"


SET_MEMORY(".map_gen")
static inline int clamp(int value, int min, int max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

SET_MEMORY(".map_gen")
void CheckAdjacentTiles(HardwareInterface hardware, uint8_t x, uint8_t y, MapTile type, uint8_t depth, const uint8_t max_depth)
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
void GenerateLake(HardwareInterface hardware, uint8_t x, uint8_t y, const uint8_t size, MapTile type)
{
    CheckAdjacentTiles(hardware, x, y, type, 0, size);
}

SET_MEMORY(".map_gen")
void GenerateRiver(HardwareInterface hardware, uint8_t x, uint8_t y, const uint8_t size, MapTile type)
{
    for (uint16_t x = 0; x < MAP_W; x++)
    {
        SetMapTile(x, 30, type);
    }
}


void CreateRiver(HardwareInterface hardware, MapTile type)
{
    int x = 0;
    int y = hardware.GetRandom_uint8_t(MAP_H >> 2, 3 * MAP_H >> 2);

    uint8_t arr[MAP_W]; // size MAP_W, indices 0..MAP_W-1

    while (x < MAP_W)
    {
        // 1. Place tile and remember y for this column
        SetMapTile(x, y, type);
        arr[x] = y;

        // 2. Move vertically (up/down/stay)
        int dy = hardware.GetRandom_uint8_t(0, 2) - 1; // -1, 0, +1
        y = y + dy;
        // Clamp without a separate function
        if (y < 0) y = 0;
        if (y >= MAP_H) y = MAP_H - 1;

        // 3. Occasionally add an extra diagonal step
        if (hardware.GetRandom_uint8_t(1, 100) < 20)
        {
            x++;
            // Ensure we don't go out of bounds
            if (x < MAP_W)
            {
                SetMapTile(x, y, type);
                arr[x] = y;
            }
        }

        x++;
    }

    // Thicken using the recorded centre line
    const uint8_t width = hardware.GetRandom_uint8_t(2, 6);
    for (uint16_t i = 0; i < MAP_W; i++) // use a larger type to be safe
        CheckAdjacentTiles(hardware, i, arr[i], type, 0, width);
}


SET_MEMORY(".map_gen")
void AddTiles(HardwareInterface hardware, uint8_t x, uint8_t y, const uint8_t size, MapTile type)
{
    CheckAdjacentTiles(hardware, x, y, type, 0, size);
}

/*****************************
    check if a corridor is crossed by fluid, porioritize if found
    find 2 land tiles on the opposite side of fliud
    determine which directtion bridge is
    creat bridge across water
/*****************************/
SET_MEMORY(".map_gen")
void AddBridges(HardwareInterface hardware)
{
}

/*****************************
    add pits to corridor tiles
/*****************************/
SET_MEMORY(".map_gen")
void AddPits(HardwareInterface hardware)
{
    MapTile arr[8] = {PIT_SMALL, PIT_ACID, PIT_MINOR, PIT_LAVA, PIT_SNAKE, PIT_SPIKES, PIT_WATER, PIT_WIDE};

    for (uint16_t i = 0; i < 20; i++)
    {
        MapTile t = arr[hardware.GetRandom_uint8_t(0, 7)];
        Position pos = FindRandomHallPosition(hardware, OBJECT);
        SetMapTile(pos.x, pos.y, t);
    }
}
