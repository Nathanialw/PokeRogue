//
// Created by nathanial on 4/13/26.
//

#include "battles.h"

#include "entities.h"
#include "lib_debugging.h"
#include "memory_access.h"
#include "memory_ram.h"
#include "memory_rom.h"



/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
void GetSkills(MemoryInterface memory, EntityId id, Type type)
{
    uint8_t i = 0;
    while (i < MAX_ABILITIES)
    {
        g_run.creatures.attacks[id][i] = NO_ABILITY;
        i++;
    }

    for (uint8_t i = 0; i < MAX_ABILITIES; ++i)
        g_run.creatures.attacks[id][i] = Flash_GetSkill(memory, type, i).skillID;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseSkill(HardwareInterface hardware, MemoryInterface memory, bool player)
{
    EntityId player_creature_id = g_run.battleMode.playerMonsterID;
    EntityId ai_creature_id = g_run.battleMode.enemyMonsterID;
    Ability ability;

    if (player)
    {
        g_run.battleMode.combatLog[0][0] = '\0';
        ability = g_run.creatures.attacks[player_creature_id][g_run.menu.sel->y];
        SkillData ability_data = Flash_GetSkillData(memory, ability);
        Flash_GetSkillEffect(memory, ability, player_creature_id, ai_creature_id, ability_data);
    }
    else
    {
        g_run.battleMode.combatLog[1][0] = '\0';
        uint8_t num_abilities = 0;
        for (uint8_t i = 0; i < MAX_ABILITIES; ++i)
            if (g_run.creatures.attacks[ai_creature_id][i] != NO_ABILITY)
                num_abilities++;
        if (num_abilities == 0) return false;
        uint8_t idx = hardware.GetRandom_uint8_t(0, num_abilities);
        ability = g_run.creatures.attacks[ai_creature_id][idx];
        SkillData ability_data = Flash_GetSkillData(memory, ability);
        Flash_GetSkillEffect(memory, ability, ai_creature_id, player_creature_id, ability_data);
    }

    //  set move animation cache
    g_run.battleMode.moveID.AbilityId = ability;
    g_run.battleMode.moveType = SKILL;
    return true;
}



/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool CastSpell(MemoryInterface memory, SpellId spellID, EntityId partyID, EntityId enemyID)
{
    // DEBUG("spell data %s id: %d  partyid: %d enemyid: %d", g_gameFlash.text.names.spells[spellID], spellID, partyID, enemyID);
    SpellData spellData = Flash_GetSpellData(memory, spellID);;
    return Flash_GetSpellEffect(memory, spellID, partyID, enemyID, spellData);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool UseItem(MemoryInterface memory, EntityId item_id, EntityId e_id)
{
    if (item_id == NO_ENTITY) return false;
    ItemTypes itemType = GetItemType(item_id);
    ItemData itemData = Flash_GetItemData(memory, item_id);
    return Flash_GetItemEffect(memory, itemType, item_id, e_id, itemData);
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
bool InteractObject(MemoryInterface memory, EntityId object_e_id, EntityId e_id)
{
    DEBUG("interacting with object %d", object_e_id);
    if (object_e_id == NO_ENTITY) return false;
    Object object_type = GetObjectType(object_e_id);
    ObjectData object_data = Flash_GetObjectData(memory, object_type);
    DEBUG("%d object type: %d", object_type, object_data.type);
    return Flash_GetObjectEffect(memory, object_type, object_e_id, e_id, object_data);
}
