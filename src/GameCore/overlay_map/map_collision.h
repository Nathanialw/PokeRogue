//
// Created by nathanial on 2/21/26.
//
#pragma once
#include "types.h"



bool CheckInteractionStepOn(uint8_t tile, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool CheckInteractionStepOff(uint8_t tile, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
void StartBattle(EntityId id);

