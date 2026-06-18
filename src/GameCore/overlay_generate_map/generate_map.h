//
// Created by nathanial on 2/22/26.
//
#pragma once
#include "lib_decl.h"
#include "types.h"


void InitMap(HardwareInterface hardware, AudioInterface audio);
void SetMapBorder(void);

void FindHallDeadEnds();
void FindHalls();
void FindWalls();
void FindCorners();
void FindWater();
void FindWaterAdjacent();

Position FindRandomHallPosition(HardwareInterface hardware, ObjectsTypes type);
Position FindRandomNookPosition(HardwareInterface hardware, ObjectsTypes type);
Position FindRandomWallPosition(HardwareInterface hardware, ObjectsTypes type);
Position FindRandomCornerPosition(HardwareInterface hardware, ObjectsTypes type);
Position FindRandomWaterPosition(HardwareInterface hardware, ObjectsTypes type);
Position FindRandomWaterAdjacentPosition(HardwareInterface hardware, ObjectsTypes type);
