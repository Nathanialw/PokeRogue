//
// Created by nathanial on 5/19/26.
//

#include "core_map.h"

#include "core_ram.h"


/**********************************************************************************************************************/
/** Takes in a map position and returns the index of the tile type
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t GetMapTile(uint8_t x, uint8_t y)
{
    uint16_t index = (y * MAP_W) + x;
    uint8_t byte = g_core.map[index / 2];
    if (index & 1)
        return byte >> 4; // High nibble for odd indices

    return byte & 0x0F; // Low nibble for even indices
}

/**********************************************************************************************************************/
/** Sets the map tile at the given position to the given tile index
**********************************************************************************************************************/
SET_MEMORY(".core")
void SetMapTile(uint8_t x, uint8_t y, TileType tile)
{
    uint16_t index = (y * MAP_W) + x;
    uint8_t* byte = &g_core.map[index / 2];
    if (index & 1)
    {
        *byte = (*byte & 0x0F) | (tile << 4); // Set high nibble
    }
    else
    {
        *byte = (*byte & 0xF0) | (tile & 0x0F); // Set low nibble
    }
}
