//
// Created by nathanial on 4/13/26.
//

#include "battle_actions.h"

#include "lib_debugging.h"

#include "core_ram.h"
#include "core_memory_access.h"

#include "battle_memory_access.h"


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
        g_core.battleMode.combatLog[0][0] = '\0';
        ability = g_core.creatures.attacks[player_creature_id][g_core.menu.sel->y];
        SkillData ability_data;
        Flash_GetSkillData(memory, &ability_data, ability);
        Flash_GetSkillEffect(memory, ability, player_creature_id, ai_creature_id, ability_data);
    }
    else
    {
        g_core.battleMode.combatLog[1][0] = '\0';
        uint8_t num_abilities = 0;
        for (uint8_t i = 0; i < MAX_ABILITIES; ++i)
            if (g_core.creatures.attacks[ai_creature_id][i] != NO_ABILITY)
                num_abilities++;
        if (num_abilities == 0) return false;
        uint8_t idx = hardware.GetRandom_uint8_t(0, num_abilities);
        ability = g_core.creatures.attacks[ai_creature_id][idx];
        SkillData ability_data;
        Flash_GetSkillData(memory, &ability_data, ability);
        Flash_GetSkillEffect(memory, ability, ai_creature_id, player_creature_id, ability_data);
    }

    //  set move animation cache
    g_core.battleMode.moveID.AbilityId = ability;
    g_core.battleMode.moveType = SKILL;
    return true;
}
