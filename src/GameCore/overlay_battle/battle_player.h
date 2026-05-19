//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "types.h"


bool PlayerDefeated(void);
bool CheckBattleEnd(EntityId attackerID, EntityId defenderID);
bool CheckPlayerAttackOutcome();
bool CheckEnemyAttackOutcome();
bool IsInParty(EntityId id);
