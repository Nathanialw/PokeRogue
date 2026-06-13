//
// Created by nathanial on 6/13/26.
//

#include "battle_effects.h"

#include "lib_memory.h"
#include "enums.h"

#include "battle_state.h"


/**********************************************************************************************************************
*  Ends Combat and moves player to an adjacent tile
**********************************************************************************************************************/
SET_MEMORY(".core")
ActionOutcome Flee()
{
    SetBattleState(BATTLE_FLEE);

    return ACTION_FAILED;
}
