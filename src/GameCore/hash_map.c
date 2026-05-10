//
// Created by nathanial on 4/11/26.
//
#include "hash_map.h"
#include "constants.h"

#define DELETED   254
#define MAX_ENTRIES (ENTITY_COUNT)
#define HASH_TABLE_SIZE 256

// Fast hash for 8-bit coordinates
static inline uint8_t HashPosition(uint8_t x, uint8_t y)
{
    return (x * 131) ^ (y * 137);
}

void HashmapInit(CompactHashMap* map)
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        map->entries[i].id = NO_ENTITY; 
        map->entries[i].x = 0;
        map->entries[i].y = 0;
    }
    map->count = 0;
}

bool HashmapInsert(CompactHashMap* map, uint8_t x, uint8_t y, uint8_t id)
{
    if (map->count >= MAX_ENTRIES) return false;

    uint8_t index = HashPosition(x, y) & (HASH_TABLE_SIZE - 1);
    uint8_t original = index;

    do
    {
        // Empty or deleted slot - use it
        if (map->entries[index].id == NO_ENTITY || map->entries[index].id == DELETED)
        {
            map->entries[index].x = x;
            map->entries[index].y = y;
            map->entries[index].id = id;
            map->count++;
            return true;
        }

        // Update existing
        if (map->entries[index].x == x && map->entries[index].y == y)
        {
            map->entries[index].id = id;
            return true;
        }

        index = (index + 1) & (HASH_TABLE_SIZE - 1);
    }
    while (index != original);

    return false;
}

uint8_t HashmapGet(CompactHashMap* map, uint8_t x, uint8_t y)
{
    uint8_t index = HashPosition(x, y) & (HASH_TABLE_SIZE - 1);
    uint8_t original = index;

    do
    {
        if (map->entries[index].id == NO_ENTITY)
        {
            return NO_ENTITY;
        }

        // Skip deleted, but continue searching
        if (map->entries[index].id != DELETED &&
            map->entries[index].x == x &&
            map->entries[index].y == y)
        {
            return map->entries[index].id;
        }

        index = (index + 1) & (HASH_TABLE_SIZE - 1);
    }
    while (index != original);

    return NO_ENTITY;
}

bool HashmapRemove(CompactHashMap* map, uint8_t x, uint8_t y)
{
    uint8_t index = HashPosition(x, y) & (HASH_TABLE_SIZE - 1);
    uint8_t original = index;

    do
    {
        if (map->entries[index].id == NO_ENTITY)
        {
            return false;
        }

        if (map->entries[index].id != DELETED &&
            map->entries[index].x == x &&
            map->entries[index].y == y)
        {
            map->entries[index].id = DELETED;
            map->count--;
            return true;
        }

        index = (index + 1) & (HASH_TABLE_SIZE - 1);
    }
    while (index != original);

    return false;
}
