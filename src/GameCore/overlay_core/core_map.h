//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "enums.h"
#include "lib_decl.h"
#include "types.h"

uint8_t GetMapTile(uint8_t x, uint8_t y);
void SetMapTile(uint8_t x, uint8_t y, TileType tile);
Position FindOpenRoomLocation(HardwareInterface hardware, ObjectsTypes type, uint8_t n);


Position FindOpenMapLocation(HardwareInterface hardware, ObjectsTypes type);
EntityId CheckTileForEntity(ObjectsTypes type, EntityId e_id, Position pos);
void SetMapFog(const uint8_t set);
