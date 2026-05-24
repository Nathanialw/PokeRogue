//
// Created by nathanial on 5/19/26.
//

#include "battle_player.h"
#include "lib_memory.h"

#include "types.h"

#include "core_entities.h"
#include "core_ram.h"

#include "battle_entities.h"
#include "core_player.h"


/**********************************************************************************************************************/
/**Checks if the player has lost the game (you have now lost the game)
 * ON SUCCESS -
 * ON FAIL -
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool PlayerDefeated(void)
{
    if (CheckAlive(g_core.battleMode.playerMonsterID))
        return false;

    EntityId p_ID = GetPlayerID();

    for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
    {
        uint8_t e_id = g_core.trainers.partyID[p_ID][i];
        if (GetCreatureType(e_id) != NO_CREATURE && CheckAlive(e_id))
        {
            g_core.battleMode.playerMonsterID = e_id;
            return false;
        }
    }

    return true;
}



/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CheckBattleEnd(EntityId attackerID, EntityId defenderID)
{
    uint8_t hp = Int999GetCurrent(&g_core.creatures.hp[defenderID]);
    if (hp == 0)
    {
        return false;
    }
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CheckPlayerAttackOutcome()
{
    EntityId player_creature_id = g_core.battleMode.playerMonsterID;
    EntityId ai_creature_id = g_core.battleMode.enemyMonsterID;
    return CheckBattleEnd(player_creature_id, ai_creature_id);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CheckEnemyAttackOutcome()
{
    EntityId player_creature_id = g_core.battleMode.playerMonsterID;
    EntityId ai_creature_id = g_core.battleMode.enemyMonsterID;
    CheckBattleEnd(ai_creature_id, player_creature_id);
    return PlayerDefeated();
}


/**********************************************************************************************************************/
/**Checks if the given entity id is currently in the played party array
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool IsInParty(EntityId id)
{
    EntityId p_ID = GetPlayerID();
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        if (g_core.trainers.partyID[p_ID][i] == id)
            return true;
    return false;
}
