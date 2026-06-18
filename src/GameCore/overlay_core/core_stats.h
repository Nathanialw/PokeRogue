//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "types.h"

void SetXPToLevel(EntityId id, uint_max999* xp);
void GainXPFromKill(EntityId id, EntityId dead_id);
void GainXP(EntityId creature_id, uint16_t xp_value);

void GetStats(HardwareInterface hardware, MemoryInterface memory, Stats *stats, Creature type, uint8_t level);

uint_max999 GetHP(Creature type, uint8_t level);
uint_max999 GetMP(Creature type, uint8_t level);

void SetDefaultSkills(MemoryInterface memory, EntityId id, Type type);

uint8_t GetStatusEffect(uint8_t* status_effect, EntityId creature_id);
uint8_t SetStatusEffect(uint8_t* status_effect, EntityId creature_id, uint8_t value);
uint8_t IncrementStatusEffect(uint8_t status_value, EntityId creature_id);
uint8_t DecrementStatusEffect(uint8_t status_value, EntityId creature_id);