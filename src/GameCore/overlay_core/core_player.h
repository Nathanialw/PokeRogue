//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "types.h"

EntityId PlayerCaptureMonster(EntityId e_id);

EntityId PlayerPickItem(EntityId e_id);
EntityId* GetPlayerMonsterIDs(void);
void DestroyPlayerCreature(HardwareInterface hardware);
void DestroyEnemyCreature(HardwareInterface hardware);

void ConsumeItem(uint8_t idx, EntityId e_id);
EntityId GetPlayerID(void);
