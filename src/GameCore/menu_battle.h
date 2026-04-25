//
// Created by nathanial on 3/8/26.
//
#pragma once
#include "inttypes.h"
#include "types.h"

const char* GetBattleMenuList(uint8_t idx);
void InitBattleMenu(void);
void UpdateBattleMenu(void);
bool BattleMenuCommand(void);
void ExitMenu(void);
