//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "types.h"

ActionOutcome InteractObject(MemoryInterface memory, HardwareInterface hardware, EntityId object_id, EntityId trainer_id, ObjectsTypes entity_type);
ActionOutcome InteractObjectStepOn(MemoryInterface memory, HardwareInterface hardware, EntityId object_e_id, EntityId e_id, ObjectsTypes entity_type);
ActionOutcome CastSpellMap(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, uint8_t spellbook_index, EntityId caster_id, EntityId target_id);
ActionOutcome UseItemMap(HardwareInterface hardware, MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId user_id, EntityId target_id, uint8_t index);
ActionOutcome InteractEnvinronmentObjectStepOn(MemoryInterface memory, HardwareInterface hardware, EntityId object_e_id, EntityId e_id, ObjectsTypes entity_type);