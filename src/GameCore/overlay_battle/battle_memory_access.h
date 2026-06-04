//
// Created by nathanial on 5/19/26.
//
#pragma once

#include "lib_decl.h"
#include "types.h"


//ANIMATION
void Flash_BattlerAttackAnimation(MemoryInterface memory, EntityId id, ObjectsTypes type, bool player);
void Flash_BattlerStruckAnimation(MemoryInterface memory, EntityId id, ObjectsTypes type, bool player);

void Flash_GetBattleMenuList(MemoryInterface memory, uint8_t* text, uint8_t idx);

bool Flash_GetSkillEffect(MemoryInterface memory, uint8_t index, EntityId id, EntityId target_id, SkillData skillData);
