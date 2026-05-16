//
// Created by nathanial on 2/22/26.
//
#pragma once
#include "memory_ram.h"


Position FindOpenMapLocation(HardwareInterface hardware, ObjectsTypes type);
void InitMap(HardwareInterface hardware);
void GoNextLevel(HardwareInterface hardware, MemoryInterface memory, MapLevelChange dir);
bool IsFogged(uint16_t x, uint16_t y);
void SetMapFog(uint8_t set);
void SetFog(uint16_t x, uint16_t y, bool fogged);
Position GetRandomMapTile(HardwareInterface hardware, ObjectsTypes type, bool emptyOnly);
Position GetSelectedTile(HardwareInterface hardware, bool emptyOnly);
uint8_t GetMapTile(uint8_t x, uint8_t y);
void GenerateDungeon(HardwareInterface hardware, uint8_t type);
bool TileHasCorpse(Position pos);
