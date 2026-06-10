//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"

bool InteractObject(MemoryInterface memory, HardwareInterface hardware, EntityId object_id, EntityId e_id);
bool CastSpellMap(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, uint8_t spellbook_index, EntityId caster_id, EntityId target_id);
bool UseItemMap(HardwareInterface hardware, MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId user_id, EntityId target_id, uint8_t index);
