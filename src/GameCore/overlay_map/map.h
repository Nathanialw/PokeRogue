//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"

Position GetRandomMapTile(HardwareInterface hardware, ObjectsTypes type, bool emptyOnly);
Position GetSelectedTile(HardwareInterface hardware, bool emptyOnly);
bool TileHasCorpse(Position pos);
void GoNextLevel(HardwareInterface hardware, MemoryInterface memory, MapLevelChange dir);
bool IsFogged(uint16_t x, uint16_t y);
void SetFog(uint16_t x, uint16_t y, bool fogged);
void SetMapFog(uint8_t set);
Position FindOpenMapLocation(HardwareInterface hardware, ObjectsTypes type);
