//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"

bool CastSpell(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, EntityId partyID, EntityId enemyID);
bool UseItem(MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId e_id);
