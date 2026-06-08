//
// Created by nathanial on 2/22/26.
//
#pragma once
#include "lib_decl.h"
#include "types.h"


void InitMap(HardwareInterface hardware);
void SetMapBorder(void);
Position FindHallDeadEnd(ObjectsTypes type, Position position);
Position FindHall(ObjectsTypes type, Position position);