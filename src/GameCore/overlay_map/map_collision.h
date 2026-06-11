//
// Created by nathanial on 2/21/26.
//
#pragma once
#include "types.h"



bool CheckInteractionStepOn(HardwareInterface hardware, MemoryInterface memory, uint8_t tile, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool CheckInteractionStepOff(HardwareInterface hardware, MemoryInterface memory, uint8_t tile, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
void StartBattleTrainer(EntityId id);
void StartBattleCreature(EntityId id);

