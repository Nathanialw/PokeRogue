//
// Created by nathanial on 6/13/26.
//

#include "battle_effects.h"

#include "lib_memory.h"
#include "enums.h"

#include "battle_state.h"
#include "core_effects.h"
#include "core_ram.h"


/**********************************************************************************************************************
*  Ends Combat and moves player to an adjacent tile
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Flee()
{
    SetBattleState(BATTLE_FLEE);

    return ACTION_FAILED;
}


/**********************************************************************************************************************
*  Ends Combat and moves player to an adjacent tile
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Struggle(EntityId player_id, EntityId enemy_id)
{
    DoDamage(enemy_id, 8);
    DoDamage(player_id, 3);
    return ACTION_FAILED;
}
