//
// Created by nathanial on 4/13/26.
//
#pragma once

#include "../common/types.h"


bool UseSkill(HardwareInterface hardware, MemoryInterface memory, bool player);
bool UseItemBattle(HardwareInterface hardware, MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId e_id);
bool CastSpellBattle(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, EntityId partyID, EntityId enemyID);
