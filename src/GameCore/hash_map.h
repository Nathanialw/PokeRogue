//
// Created by nathanial on 4/11/26.
//
#pragma once

#include <stdint.h>
#include <stdbool.h>

// Valid IDs are 0x00 to 0xFD (0-253)

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t id;  // NO_ENTITY (255) = empty, DELETED (254) = tombstone, 0-253 = valid ID
} HashMapEntry;

typedef struct {
    HashMapEntry entries[256];
    uint8_t count;
} CompactHashMap;

void HashmapInit(CompactHashMap* map);
bool HashmapInsert(CompactHashMap* map, uint8_t x, uint8_t y, uint8_t id);
uint8_t HashmapGet(CompactHashMap* map, uint8_t x, uint8_t y);
bool HashmapRemove(CompactHashMap* map, uint8_t x, uint8_t y);