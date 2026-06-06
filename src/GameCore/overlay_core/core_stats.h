//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "types.h"

void SetXPToLevel(EntityId id, IntMax999* xp);
void GainXP(EntityId id, EntityId dead_id);


void GetStats(HardwareInterface hardware, MemoryInterface memory, Stats *stats, Creature type, uint8_t level);

IntMax999 GetHP(Creature type, uint8_t level);
IntMax999 GetMP(Creature type, uint8_t level);

void GetSkills(MemoryInterface memory, EntityId id, Type type);
