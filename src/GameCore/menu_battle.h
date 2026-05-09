//
// Created by nathanial on 3/8/26.
//
#pragma once
#include "inttypes.h"
#include "types.h"

const char* GetBattleMenuList(uint8_t idx);
void InitBattleMenu(void);
void UpdateBattleMenu(InputInterface input);
bool BattleMenuCommand(InputInterface input);
void ExitMenu(void);
