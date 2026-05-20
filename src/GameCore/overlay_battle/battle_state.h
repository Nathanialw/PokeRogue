//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "enums.h"
#include "lib_decl.h"

State SetBattleState(BattleState state);
uint8_t BattleLoopMain(GameInterface* spi);
