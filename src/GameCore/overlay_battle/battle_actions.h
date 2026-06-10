//
// Created by nathanial on 4/13/26.
//
#pragma once

#include "types.h"


bool UseSkill(HardwareInterface hardware, MemoryInterface memory, bool player);
bool UseItemBattle(HardwareInterface hardware, MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId user_id, EntityId target_id, uint8_t index);
bool CastSpellBattle(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, uint8_t spellbook_index, EntityId caster_id, EntityId target_id);
