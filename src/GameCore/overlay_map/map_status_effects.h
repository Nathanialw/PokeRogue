//
// Created by nathanial on 4/11/26.
//
#pragma once
#include "lib_decl.h"
#include "types.h"

void UpdateObjectStatusEffects(HardwareInterface hardware);
void GetCreatureStatusEffectStateBuffs(uint8_t* buff_values, EntityId creature_id);
void GetCreatureStatusEffectStateDebuffs(uint8_t* buff_values, EntityId creature_id);