//
// Created by nathanial on 5/19/26.
//
#pragma once

#include "lib_decl.h"
#include "types.h"


SpriteLayout Flash_GetBattlerLayout(MemoryInterface memory, uint8_t creatureType, bool front);
const uint8_t* Flash_GetBattlerArray(MemoryInterface memory, bool front);

//ANIMATION
void Flash_BattlerAttackAnimation(MemoryInterface memory, EntityId id, ObjectsTypes type, bool player);
void Flash_BattlerStruckAnimation(MemoryInterface memory, EntityId id, ObjectsTypes type, bool player);

void Flash_GetBattleMenuList(MemoryInterface memory, uint8_t* text, uint8_t idx);

void Flash_GetBattleMenuList(MemoryInterface memory, uint8_t* text, uint8_t idx);

bool Flash_GetSkillEffect(MemoryInterface memory, uint8_t index, EntityId id, EntityId target_id, SkillData skillData);
