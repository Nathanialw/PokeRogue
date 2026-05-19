//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "../common/types.h"

bool CastSpell(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, EntityId partyID, EntityId enemyID);
bool UseItem(MemoryInterface memory, EntityId item_id, EntityId e_id);
