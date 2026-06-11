//
// Created by nathanial on 5/19/26.
//
#include "map_ram.h"
#include "lib_memory.h"

#include "inc/decl_objects_Interact.inc"
#include "inc/decl_items_UseMap.inc"
#include "inc/decl_spells_CastMap.inc"


SET_MEMORY(".map.rodata")
const ObjectEffect objectFunctions[OBJECT_COUNT] = {
#include "inc/funcs_objects_Interact.inc"
};


SET_MEMORY(".map.rodata")
const SpellEffectMap spellFunctionsMap[SPELL_COUNT] = {
#include "inc/funcs_spells_CastMap.inc"
};

SET_MEMORY(".map.rodata")
const ItemEffect itemFunctionsMap[ITEM_COUNT] = {
#include "inc/funcs_items_UseMap.inc"
};


SET_MEMORY(".map.data")
MapRunState g_map = {
    .power = "Powr:\0",
    .rarity = "Rare:\0",

    .objectCollision = NO_OBJECT,
    .itemCollision = NO_ITEM,
    .clearTooltip = false,
};


SET_MEMORY(".map")
ActionOutcome CastMapSpell(HardwareInterface hardware, MemoryInterface memory, uint8_t spellType, EntityId caster_id, EntityId target_id, SpellData spellData)
{
    return spellFunctionsMap[spellType](hardware, memory, caster_id, target_id, spellData);
}


SET_MEMORY(".map")
ActionOutcome UseMapItem(HardwareInterface hardware, MemoryInterface memory, uint8_t itemType, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return itemFunctionsMap[itemType](hardware, memory, item_id, user_id, target_id, itemData, index);
}


SET_MEMORY(".map")
ActionOutcome UseMapObject(HardwareInterface hardware, uint8_t objectType, EntityId object_id, EntityId target_id, ObjectData objectData)
{
    return objectFunctions[objectType](hardware, object_id, target_id, objectData);
}
