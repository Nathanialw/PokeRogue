//
// Created by nathanial on 2/22/26.
//
#pragma once
#include <stdint.h>
#include "memory_ram.h"


Position FindOpenMapLocation(ObjectsTypes type);
void InitMap(void);
void GoNextLevel(MapLevelChange dir);
bool IsFogged(uint16_t x, uint16_t y);
void SetMapFog(uint8_t set);
void SetFog(uint16_t x, uint16_t y, bool fogged);
Position GetRandomMapTile(ObjectsTypes type, bool emptyOnly);
Position GetSelectedTile(bool emptyOnly);
uint8_t GetMapTile(uint8_t x, uint8_t y);
void GenerateDungeon(uint8_t type);
bool TileHasCorpse(Position pos);
