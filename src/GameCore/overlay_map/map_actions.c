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

typedef struct
{
    uint8_t effect_indexes[MAX_OBJECT_EFFECTS];
    uint8_t weights[MAX_OBJECT_EFFECTS];
    uint8_t number_of_effects;
} ObjectEffectsCache;

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
void GetObjectEffects(const ObjectData* object_data, ObjectEffectsCache* cache)
{
    //calculate effect chances
    //select random effect

    //create and set caches to default
    cache->number_of_effects = 0;
    for (uint8_t i = 0; i < MAX_OBJECT_EFFECTS; i++) cache->effect_indexes[i] = NO_EFFECT;
    for (uint8_t i = 0; i < MAX_OBJECT_EFFECTS; i++) cache->weights[i] = 0;

    //iterate object data
    for (uint8_t i = 0; i < MAX_OBJECT_EFFECTS; i++)
    {
        if (object_data->effects.effects[i] == NO_EFFECT) continue;
        //get the chance of the given effect
        uint8_t value = (object_data->effects.chance >> (i * 2)) & 0x03;

        //check if it already exists, increment if found
        bool exists = false;
        for (uint8_t j = 0; j < MAX_OBJECT_EFFECTS; j++)
        {
            if (cache->effect_indexes[j] == object_data->effects.effects[i])
            {
                cache->weights[j] += value;
                exists = true;
            }
        }

        //add if it doesn't exist
        if (!exists)
        {
            cache->effect_indexes[cache->number_of_effects] = object_data->effects.effects[i];
            cache->weights[cache->number_of_effects] += value;
            cache->number_of_effects++;
        }
    }
}

/**********************************************************************************************************************/
/* check it it is usable on party, open party framw
 *
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome InteractObject(MemoryInterface memory, HardwareInterface hardware, EntityId object_e_id, EntityId e_id, ObjectsTypes entity_type)
{
    if (object_e_id == NO_ENTITY) return false;
    if (GetBit(g_core.objects.interactable, object_e_id))
    {
        Object object_type_id = GetObjectType(object_e_id);
        ObjectData object_data;
        Flash_GetObjectData(memory, &object_data, object_type_id);

        ObjectEffectsCache cache;
        GetObjectEffects(&object_data, &cache);
        //TODO use cache data to randomly select an object effect


        if (object_data.consumable_party)
        {
            if (GetInputState() == INPUT_USE)
            {
                uint8_t selection = g_core.menu.sel[0].y;
                EntityId creature_id = GetPlayerMonsterIDs()[selection];
                ActionOutcome action_outcome = UseMapObject(hardware, memory, object_type_id, object_e_id, creature_id, object_data, entity_type, selection);
                if (action_outcome == ACTION_SUCCEEDED)
                {
                    BackUseOnParty(memory);
                    if (object_data.consumable)
                        SetBit(g_core.objects.interactable, object_e_id, false);
                    SetInputState(INPUT_ACTING);
                    g_core.update_right_party = true;
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
                uint8_t selection = g_core.menu.sel[0].y;
                EntityId creature_id = GetPlayerMonsterIDs()[selection];
                ActionOutcome action_outcome = UseMapObject(hardware, memory, object_type_id, object_e_id, creature_id, object_data, entity_type, selection);
                if (action_outcome == ACTION_SUCCEEDED)
                {
                    BackUseOnParty(memory);
                    if (object_data.consumable)
                        SetBit(g_core.objects.interactable, object_e_id, false);
                    SetInputState(INPUT_ACTING);
                    g_core.update_left_spellbook = true;
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
                g_core.update_left_player = true;
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

    ObjectEffectsCache cache;
    GetObjectEffects(&object_data, &cache);

    //TODO use the cahce data to pupulate the string data for the tooltip
    if (e_id == GetPlayerID())
    {
        DEBUG(" %d %d %d %d %d %d", cache.effect_indexes[0], cache.effect_indexes[1], cache.effect_indexes[2], cache.effect_indexes[3], cache.effect_indexes[4], cache.effect_indexes[5]);
        Flash_GetObjectName(memory, g_core.tooltip_text[0], object_type_id);

        uint8_t total = 0;
        for (uint8_t i = 0; i < MAX_OBJECT_EFFECTS; i++)
        {
            g_core.tooltip_text[i+1][0] = '\0';
            total += cache.weights[i];
        }

        for (uint8_t i = 0; i < MAX_OBJECT_EFFECTS; i++)
        {
            if (cache.weights[i] == 0) continue;
            uint8_t percent = (cache.weights[i] * 100) / total;
            CharStr_uint8 intstr;
            GetAsChars_uint8(percent, &intstr, true, false);

            char* cursor = g_core.tooltip_text[i + 1];
            g_core.tooltip_text[i + 1][0] = (intstr[0] == '0') ? ' ' : intstr[0];
            g_core.tooltip_text[i + 1][1] = intstr[1];
            g_core.tooltip_text[i + 1][2] = intstr[2];
            g_core.tooltip_text[i + 1][3] = '%';
            g_core.tooltip_text[i + 1][4] = ' ';
            Flash_GetObjectEffectText(memory, cursor + 5, cache.effect_indexes[i]);
            DEBUG("%s", g_core.tooltip_text[i+1]);
        }
        g_core.update_right_text = true;
        g_core.update_right_text_clear = true;
    }

    if (object_data.on_step && GetBit(g_core.objects.interactable, object_e_id))
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
            g_core.update_left_spellbook = true;
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
