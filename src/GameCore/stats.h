//
// Created by nathanial on 2/22/26.
//
#pragma once
#include "types.h"

typedef char StatusPrefix[3];


Stats GetStats(HardwareInterface hardware, MemoryInterface memory, Creature type, uint8_t level);
void GetStatLine(HardwareInterface hardware, uint16_t cur, uint16_t max, uint8_t max_chars, char* dest, const StatusPrefix prefix);
IntMax999 SetXPToLevel(EntityId id);
void GainXP(EntityId id, EntityId dead_id);

IntMax999 GetHP(Creature type, uint8_t level);
IntMax999 GetMP(Creature type, uint8_t level);


