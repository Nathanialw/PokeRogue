//
// Created by nathanial on 3/31/26.
//
#pragma once

#include "types.h"


void PrintCombatLog(HardwareInterface hardware, MemoryInterface memory, EntityId creatureID, uint16_t damage);
void CombatLogLine(HardwareInterface hardware, char* dest, const char* prefix, const char* suffix, uint16_t value);
