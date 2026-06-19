//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "types.h"


bool PlayerDefeated(void);
bool CheckPlayerAttackOutcome(void);
bool UpdateBattleCreature(void);
bool CheckEnemyAttackOutcome(void);
bool IsInParty(EntityId id);
bool SendNextPartyCreature(void);