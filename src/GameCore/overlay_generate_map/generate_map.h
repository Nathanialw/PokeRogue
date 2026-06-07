//
// Created by nathanial on 2/22/26.
//
#pragma once
#include "lib_decl.h"
#include "types.h"


void InitMap(HardwareInterface hardware);
void SetMapBorder(void);
Position FindHallDeadEnd(ObjectsTypes type, uint8_t start_x, uint8_t start_y);