//
// Created by nathanial on 5/19/26.
//

#include "core_actions.h"
#include "lib_decl.h"

#include "types.h"

#include "core_entities.h"
#include "core_memory_access.h"



/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastSpell(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, EntityId partyID, EntityId enemyID)
{
    // DEBUG("spell data %s id: %d  partyid: %d enemyid: %d", g_gameFlash.text.names.spells[spellID], spellID, partyID, enemyID);
    SpellData spellData = Flash_GetSpellData(memory, spellID);;
    return Flash_GetSpellEffect(hardware, memory, spellID, partyID, enemyID, spellData);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseItem(MemoryInterface memory, EntityId item_id, EntityId e_id)
{
    if (item_id == NO_ENTITY) return false;
    ItemTypes itemType = GetItemType(item_id);
    ItemData itemData = Flash_GetItemData(memory, item_id);
    return Flash_GetItemEffect(memory, itemType, item_id, e_id, itemData);
}
