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
#include "core_player.h"

#include "battle_ram.h"
#include "battle_state.h"
#include "battle_ui.h"

bool AdjustMana(EntityId creature_id, int16_t mana)
{
    uint_max999 mp = g_core.creatures.mp[creature_id];
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
ActionOutcome UseSkill(HardwareInterface hardware, MemoryInterface memory, bool player)
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

        //TODO not sure what to do with the outcome value of skills yet
        ActionOutcome action_outcome = Flash_GetSkillEffect(hardware, memory, ability, GetPlayerID(), player_creature_id, ai_creature_id, ability_data);
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
        //TODO not sure what to do with the outcome value of skills yet
        ActionOutcome action_outcome = Flash_GetSkillEffect(hardware, memory, ability, g_core.battleMode.enemy_trainer_id, ai_creature_id, player_creature_id, ability_data);
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
ActionOutcome CastSpellBattle(HardwareInterface hardware, MemoryInterface memory, SpellId spell_id, uint8_t spellbook_index, EntityId caster_id, EntityId target_id)
{
    ActionOutcome action_outcome = ACTION_CANNOT;

    if (spellbook_index == SPELL_INDEX_NULL || GetPlayerSpellbook()->page[spellbook_index].pp > 0)
    {
        SpellData spellData;
        Flash_GetSpellData(memory, &spellData, spell_id);;
        action_outcome = CastBattleSpell(hardware, memory, spell_id, caster_id, g_core.battleMode.playerMonsterID, target_id, spellData);

        if (action_outcome == ACTION_SUCCEEDED)
        {
            if (spellbook_index != SPELL_INDEX_NULL)
                GetPlayerSpellbook()->page[spellbook_index].pp--;

            PrintCombatLogText(hardware, memory, "Cast Spell Success");
            g_battle.effect_animation_index = spell_id;
            g_battle.effect_type = SPELL;
            g_battle.pass_turn = true;
            SetBattleState(BATTLE_ATTACK);
        }
        else if (action_outcome == ACTION_FAILED)
        {
            PrintCombatLogText(hardware, memory, "Cast Spell Failed");
            g_battle.pass_turn = true;
        }
        else if (action_outcome == ACTION_CANNOT)
        {
            PrintCombatLogText(hardware, memory, "Cannot cast spell");
        }
    }

    else if (GetPlayerSpellbook()->page[spellbook_index].pp == 0)
    {
        action_outcome = ACTION_CANNOT;
        DEBUG("Not enough pp points");
    }

    return action_outcome;
}

/**********************************************************************************************************************

*  if e_id = NO_ENTITY it will attempt to use the item on the player
*  is a valid e_id is passed, it will attempt to use the item on that entity
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome UseItemBattle(HardwareInterface hardware, MemoryInterface memory, ItemData* itemData, EntityId item_id, EntityId user_id, EntityId target_id, uint8_t index)
{
    if (item_id == NO_ENTITY) return false;
    ItemTypes itemType = GetItemType(item_id);
    return UseBattleItem(hardware, memory, itemType, item_id, user_id, target_id, *itemData, index);
}
