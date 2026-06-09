//
// Created by nathanial on 4/13/26.
//

#include "battle_actions.h"

#include "lib_memory.h"
#include "lib_debugging.h"

#include "core_ram.h"
#include "core_memory_access.h"
#include "core_utils.h"
#include "core_entities.h"

#include "battle_memory_access.h"
#include "battle_ram.h"
#include "battle_ui.h"
#include "core_graphics.h"

bool AdjustMana(EntityId creature_id, int16_t mana)
{
    IntMax999 mp = g_core.creatures.mp[creature_id];
    uint16_t current_mana = Int999GetCurrent(&mp);
    g_core.battleMode.battle_mp_cache = current_mana;

    if (mana < 0)
    {
        if (current_mana < (mana * -1))
            return false;
    }
    else
    {
        if (current_mana >= mana)
            return false;
    }

    current_mana += mana;
    Int999SetCurrent(&mp, current_mana);
    g_core.creatures.mp[creature_id] = mp;

    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseSkill(HardwareInterface hardware, MemoryInterface memory, bool player)
{
    EntityId player_creature_id = g_core.battleMode.playerMonsterID;
    EntityId ai_creature_id = g_core.battleMode.enemyMonsterID;
    Ability ability;

    if (player)
    {
        ability = g_core.creatures.attacks[player_creature_id][g_core.menu.sel->y];
        SkillData ability_data;
        Flash_GetSkillData(memory, &ability_data, ability);

        if (!AdjustMana(player_creature_id, -ability_data.manaCost))
        {
            PrintCombatLogText(hardware, memory, "Not enough Mana");
            return false;
        }

        PrintCombatLogText(hardware, memory, "Player Casting");
        g_battle.end_battle = Flash_GetSkillEffect(hardware, memory, ability, player_creature_id, ai_creature_id, ability_data);
    }
    else
    {
        uint8_t num_abilities = 0;
        for (uint8_t i = 0; i < MAX_ABILITIES; ++i)
            if (g_core.creatures.attacks[ai_creature_id][i] != NO_ABILITY)
                num_abilities++;
        if (num_abilities == 0) return false;
        uint8_t idx = hardware.GetRandom_uint8_t(0, num_abilities - 1);

        ability = g_core.creatures.attacks[ai_creature_id][idx];

        if (ability == NO_ABILITY)
            for (uint8_t i = 0; i < MAX_ABILITIES; ++i)
            {
                DEBUG("skill %d: %d index - %d ", i, g_core.creatures.attacks[ai_creature_id][i], idx);
            }

        if (ability == NO_ABILITY) return false;

        SkillData ability_data;
        Flash_GetSkillData(memory, &ability_data, ability);
        if (!AdjustMana(ai_creature_id, -ability_data.manaCost))
            return false;

        PrintCombatLogText(hardware, memory, "Enemy Casting");
        Flash_GetSkillEffect(hardware, memory, ability, ai_creature_id, player_creature_id, ability_data);
    }

    //  set move animation cache
    g_core.battleMode.moveID.AbilityId = ability;
    g_core.battleMode.moveType = SKILL;
    return true;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CastSpellBattle(HardwareInterface hardware, MemoryInterface memory, SpellId spellID, EntityId partyID, EntityId enemyID)
{
    // DEBUG("spell data %s id: %d  partyid: %d enemyid: %d", g_gameFlash.text.names.spells[spellID], spellID, partyID, enemyID);
    SpellData spellData;
    Flash_GetSpellData(memory, &spellData, spellID);;
    return CastBattleSpell(hardware, memory, spellID, partyID, enemyID, spellData);
}

/**********************************************************************************************************************

*  if e_id = NO_ENTITY it will attempt to use the item on the player
*  is a valid e_id is passed, it will attempt to use the item on that entity
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool UseItemBattle(HardwareInterface hardware, MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId e_id)
{
    if (item_id == NO_ENTITY) return false;
    ItemTypes itemType = GetItemType(item_id);
    return UseBattleItem(hardware, memory, itemType, item_id, e_id, *itemData);
}
