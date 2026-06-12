//
// Created by nathanial on 5/19/26.
//

#include "battle_player.h"
#include "lib_memory.h"

#include "types.h"

#include "core_entities.h"
#include "core_ram.h"
#include "core_utils.h"

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
bool UpdateBattleCreature()
{
    g_core.battleMode.enemyMonsterID = GetNextPartyCreature(g_core.battleMode.enemy_trainer_id);
    if (g_core.battleMode.enemyMonsterID == NO_ENTITY)
        return false;
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool EnemyDefeated()
{
    if (g_core.battleMode.enemy_trainer_id != NO_ENTITY)
        if (g_core.battleMode.enemyMonsterID == NO_ENTITY)
            return true;

    EntityId creature_id = g_core.battleMode.enemyMonsterID;
    uint8_t hp = Int999GetCurrent(&g_core.creatures.hp[creature_id]);
    if (hp == 0)
        return true;

    return false;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CheckPlayerAttackOutcome()
{
    return EnemyDefeated();
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool CheckEnemyAttackOutcome()
{
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
