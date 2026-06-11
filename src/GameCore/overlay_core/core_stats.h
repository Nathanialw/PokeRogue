//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "types.h"

void SetXPToLevel(EntityId id, IntMax999* xp);
void GainXPFromKill(EntityId id, EntityId dead_id);
void GainXP(EntityId creature_id, uint16_t xp_value);

void GetStats(HardwareInterface hardware, MemoryInterface memory, Stats *stats, Creature type, uint8_t level);

IntMax999 GetHP(Creature type, uint8_t level);
IntMax999 GetMP(Creature type, uint8_t level);

void SetDefaultSkills(MemoryInterface memory, EntityId id, Type type);
