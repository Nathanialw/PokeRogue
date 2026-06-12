//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "types.h"

EntityId PlayerCaptureMonster(EntityId e_id);

EntityId DropItem(EntityId trainer_id, EntityId item_id);
EntityId* GetPlayerMonsterIDs(void);
void DestroyPlayerCreature(HardwareInterface hardware);
void DestroyEnemyCreature(HardwareInterface hardware);

void ConsumeItem(EntityId trainer_id, uint8_t idx, EntityId e_id);
EntityId GetPlayerID(void);
BagData GetPlayerBagData(void);
SpellBook* GetPlayerSpellbook(void);
EntityId GetPlayerEffects(PlayerEffects playerEffect);
