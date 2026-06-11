//
// Created by nathanial on 5/19/26.
//

#include "map_actions.h"

#include "lib_decl.h"
#include "lib_memory.h"
#include "types.h"

#include "core_memory_access.h"
#include "core_entities.h"
#include "core_ram.h"
#include "lib_debugging.h"

#include "map_memory_access.h"
#include "map_ram.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractObject(MemoryInterface memory, HardwareInterface hardware, EntityId object_e_id, EntityId e_id)
{
    if (object_e_id == NO_ENTITY) return false;
    Object object_type = GetObjectType(object_e_id);
    ObjectData object_data;
    Flash_GetObjectData(memory, &object_data, object_type);
    return UseMapObject(hardware, object_type, object_e_id, e_id, object_data);
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome CastSpellMap(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, uint8_t spellbook_index, EntityId caster_id, EntityId target_id)
{
    // DEBUG("spell data %s id: %d  partyid: %d enemyid: %d", g_gameFlash.text.names.spells[spellID], spellID, partyID, enemyID);
    ActionOutcome action_outcome = ACTION_CANNOT;

    // currently used for scrolls to cast spells
    if (spellbook_index == SPELL_INDEX_NULL)
    {
        SpellData spellData;
        Flash_GetSpellData(memory, &spellData, spellID);;
        action_outcome = CastMapSpell(hardware, memory, spellID, caster_id, target_id, spellData);

        if (action_outcome == ACTION_SUCCEEDED)
        {
            DEBUG("Scroll success spellID: %d", spellID);
            return true;
        }
        else if (action_outcome == ACTION_FAILED)
        {
            DEBUG("Scroll failed spellID: %d", spellID);
        }
        else if (action_outcome == ACTION_CANNOT)
        {
            DEBUG("Cannot use this now spellID: %d", spellID);
        }
    }
    else if (g_core.trainers.spellPage[caster_id][spellbook_index].pp > 0)
    {
        SpellData spellData;
        Flash_GetSpellData(memory, &spellData, spellID);;
        action_outcome = CastMapSpell(hardware, memory, spellID, caster_id, target_id, spellData);


        if (action_outcome == ACTION_SUCCEEDED)
        {
            DEBUG("Scroll success spellID: %d", spellID);
            g_core.trainers.spellPage[caster_id][spellbook_index].pp--;
            return true;
        }
        else if (action_outcome == ACTION_FAILED)
        {
            DEBUG("Scroll failed spellID: %d", spellID);
        }
        else if (action_outcome == ACTION_CANNOT)
        {
            DEBUG("Cannot use this now spellID: %d", spellID);
        }
        return action_outcome;
    }

    DEBUG("Not enough pp points");
    return action_outcome;
}

/**********************************************************************************************************************
*  if e_id = NO_ENTITY it will attempt to use the item on the player
*  is a valid e_id is passed, it will attempt to use the item on that entity
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome UseItemMap(HardwareInterface hardware, MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId user_id, EntityId target_id, uint8_t index)
{
    if (item_id == NO_ENTITY) return false;
    ItemTypes itemType = GetItemType(item_id);
    return UseMapItem(hardware, memory, itemType, item_id, user_id, target_id, *itemData, index);
}
