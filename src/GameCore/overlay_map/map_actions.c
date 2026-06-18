//
// Created by nathanial on 5/19/26.
//

#include "map_actions.h"

#include "lib_decl.h"
#include "lib_memory.h"
#include "lib_debugging.h"

#include "types.h"

#include "core_memory_access.h"
#include "core_entities.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_state.h"
#include "core_utils.h"
#include "lib_enums.h"
#include "map_menu.h"

#include "map_ram.h"


/**********************************************************************************************************************/
/* check it it is usable on party, open party framw
 *
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractObject(MemoryInterface memory, HardwareInterface hardware, EntityId object_e_id, EntityId e_id, ObjectsTypes entity_type)
{
    if (object_e_id == NO_ENTITY) return false;
    Object object_type_id = GetObjectType(object_e_id);
    ObjectData object_data;
    Flash_GetObjectData(memory, &object_data, object_type_id);

    if (GetBit(g_core.objects.interactable, object_e_id))
    {
        if (object_data.consumable_party)
        {
            if (GetInputState() == INPUT_USE)
            {
                uint8_t selection = g_core.menu.sel[0].y;
                EntityId creature_id = GetPlayerMonsterIDs()[selection];
                ActionOutcome action_outcome = UseMapObject(hardware, memory, object_type_id, object_e_id, creature_id, object_data, entity_type, 0);
                if (action_outcome == ACTION_SUCCEEDED)
                {
                    BackUseOnParty(memory);
                    if (object_data.consumable)
                        SetBit(g_core.objects.interactable, object_e_id, false);
                    SetInputState(INPUT_ACTING);
                    return ACTION_SUCCEEDED;
                }
                return ACTION_CANNOT;
            }

            SetInputState(INPUT_USE);
            OpenUseOnParty(hardware, memory, BACK_USE_OBJECT_PARTY);
        }
        else if (object_data.consumable_spellbook)
        {
            if (GetInputState() == INPUT_USE)
            {
                uint8_t selection = 0;
                EntityId creature_id = GetPlayerMonsterIDs()[selection];
                ActionOutcome action_outcome = UseMapObject(hardware, memory, object_type_id, object_e_id, creature_id, object_data, entity_type, 0);
                if (action_outcome == ACTION_SUCCEEDED)
                {
                    BackUseOnParty(memory);
                    if (object_data.consumable)
                        SetBit(g_core.objects.interactable, object_e_id, false);
                    SetInputState(INPUT_ACTING);
                    return ACTION_SUCCEEDED;
                }
                return ACTION_CANNOT;
            }

            SetInputState(INPUT_USE);
            OpenUseOnSpellPage(hardware, memory, BACK_USE_OBJECT_SPELL);
        }
        else
        {
            ActionOutcome action_outcome = UseMapObject(hardware, memory, object_type_id, object_e_id, e_id, object_data, entity_type, 0);
            if (action_outcome == ACTION_SUCCEEDED)
            {
                if (object_data.consumable)
                    SetBit(g_core.objects.interactable, object_e_id, false);
                return ACTION_SUCCEEDED;
            }
        }
    }


    return ACTION_CANNOT;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractObjectStepOn(MemoryInterface memory, HardwareInterface hardware, EntityId object_e_id, EntityId e_id, ObjectsTypes entity_type)
{
    if (object_e_id == NO_ENTITY) return false;
    Object object_type_id = GetObjectType(object_e_id);
    ObjectData object_data;
    Flash_GetObjectData(memory, &object_data, object_type_id);

    if (object_data.on_step)
    {
        return UseMapObject(hardware, memory, object_type_id, object_e_id, e_id, object_data, entity_type, 0);
    }
    return ACTION_FAILED;
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
    else if (GetPlayerSpellbook()->page[spellbook_index].pp > 0)
    {
        SpellData spellData;
        Flash_GetSpellData(memory, &spellData, spellID);;
        action_outcome = CastMapSpell(hardware, memory, spellID, caster_id, target_id, spellData);


        if (action_outcome == ACTION_SUCCEEDED)
        {
            DEBUG("Spell success spellID: %d", spellID);
            GetPlayerSpellbook()->page[spellbook_index].pp--;
            return true;
        }
        else if (action_outcome == ACTION_FAILED)
        {
            DEBUG("Spell failed spellID: %d", spellID);
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
