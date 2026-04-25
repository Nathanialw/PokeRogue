//
// Created by nathanial on 3/31/26.
//
#pragma once

#include "types.h"


void PrintCombatLog(EntityId creatureID, uint16_t damage);
void CombatLogLine(char* dest, const char* prefix, const char* suffix, uint16_t value);
