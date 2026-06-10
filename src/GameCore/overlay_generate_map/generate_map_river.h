//
// Created by nathanial on 6/5/26.
//

#pragma once
#include "types.h"
#include "enums.h"



void GenerateRiver(uint8_t x, uint8_t y, MapTile type);
void GenerateLake(HardwareInterface hardware, uint8_t x, uint8_t y, const uint8_t size, MapTile type);