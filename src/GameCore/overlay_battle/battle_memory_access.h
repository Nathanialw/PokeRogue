//
// Created by nathanial on 5/19/26.
//
#pragma once

#include "lib_decl.h"
#include "types.h"


//ANIMATION
void Flash_BattlerAttackAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, EntityId id, ObjectsTypes type, bool player);
void Flash_BattlerStruckAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, EntityId id, ObjectsTypes type, bool player);

void Flash_GetBattleMenuList(MemoryInterface memory, uint8_t* text, uint8_t idx);

