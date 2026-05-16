//
// Created by nathanial on 3/8/26.
//
#pragma once
#include "inttypes.h"
#include "types.h"


void InitBattleMenu(void);
void UpdateBattleMenu(InputInterface input);
bool BattleMenuCommand(HardwareInterface hardware, InputInterface input, MemoryInterface memory);
void ExitMenu(void);
