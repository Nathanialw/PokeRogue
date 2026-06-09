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
bool InteractObject(MemoryInterface memory, HardwareInterface hardware, EntityId object_e_id, EntityId e_id)
{
    if (object_e_id == NO_ENTITY) return false;
    Object object_type = GetObjectType(object_e_id);
    ObjectData object_data;
    Flash_GetObjectData(memory, &object_data, object_type);
    return Flash_GetObjectEffect(memory, hardware, object_type, object_e_id, e_id, object_data);
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CastSpellMap(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, uint8_t spellbook_index, EntityId caster_id, EntityId target_id)
{
    // DEBUG("spell data %s id: %d  partyid: %d enemyid: %d", g_gameFlash.text.names.spells[spellID], spellID, partyID, enemyID);
    if (g_core.trainers.spellPage[caster_id][spellbook_index].pp > 0)
    {
        SpellData spellData;
        Flash_GetSpellData(memory, &spellData, spellID);;
        if (CastMapSpell(hardware, memory, spellID, caster_id, target_id, spellData))
        {
            g_core.trainers.spellPage[caster_id][spellbook_index].pp--;
        }
        return true;
    }

    DEBUG("Not enough pp points");
    return false;
}

/**********************************************************************************************************************

*  if e_id = NO_ENTITY it will attempt to use the item on the player
*  is a valid e_id is passed, it will attempt to use the item on that entity
**********************************************************************************************************************/
SET_MEMORY(".map")
bool UseItemMap(HardwareInterface hardware, MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId e_id)
{
    if (item_id == NO_ENTITY) return false;
    ItemTypes itemType = GetItemType(item_id);
    return UseMapItem(hardware, memory, itemType, item_id, e_id, *itemData);
}
