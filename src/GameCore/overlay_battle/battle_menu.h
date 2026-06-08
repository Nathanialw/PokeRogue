//
// Created by nathanial on 3/8/26.
//
#pragma once
#include "types.h"


void InitBattleMenu(void);
void UpdateBattleMenu(InputInterface input, GraphicsInterface graphics, MemoryInterface memory);
bool BattleMenuCommand(GraphicsInterface graphics, HardwareInterface hardware, InputInterface input, MemoryInterface memory);
void ExitMenu(void);
