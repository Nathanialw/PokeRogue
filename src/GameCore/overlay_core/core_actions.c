//
// Created by nathanial on 5/19/26.
//

#include "core_actions.h"
#include "lib_decl.h"
#include "lib_memory.h"

#include "types.h"

#include "core_entities.h"
#include "core_memory_access.h"


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".core")
bool CastSpell(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, EntityId partyID, EntityId enemyID)
{
    // DEBUG("spell data %s id: %d  partyid: %d enemyid: %d", g_gameFlash.text.names.spells[spellID], spellID, partyID, enemyID);
    SpellData spellData;
    Flash_GetSpellData(memory, &spellData, spellID);;
    return Flash_GetSpellEffect(hardware, memory, spellID, partyID, enemyID, spellData);
}

/**********************************************************************************************************************

*  if e_id = NO_ENTITY it will attempt to use the item on the player
*  is a valid e_id is passed, it will attempt to use the item on that entity
**********************************************************************************************************************/
SET_MEMORY(".core")
bool UseItem(MemoryInterface memory, ItemData *itemData, EntityId item_id, EntityId e_id)
{
    if (item_id == NO_ENTITY) return false;
    ItemTypes itemType = GetItemType(item_id);
    return Flash_GetItemEffect(memory, itemType, item_id, e_id, *itemData);
}
