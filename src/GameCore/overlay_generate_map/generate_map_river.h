//
// Created by nathanial on 6/5/26.
//

#pragma once
#include "types.h"
#include "enums.h"


typedef enum
{
    RIVER_VERTICAL,
    RIVER_HORIZONTAL,
} RiverDirection;

void GenerateRiver(HardwareInterface hardware, uint8_t x, uint8_t y, const uint8_t size, MapTile type);
void WindingRiver(HardwareInterface hardware, MapTile type);
void CreateRiver(HardwareInterface hardware, MapTile type);

void GenerateLake(HardwareInterface hardware, uint8_t x, uint8_t y, const uint8_t size, MapTile type);

void AddTiles(HardwareInterface hardware, uint8_t x, uint8_t y, const uint8_t size, MapTile type);

void AddBridges(HardwareInterface hardware);
void AddPits(HardwareInterface hardware);