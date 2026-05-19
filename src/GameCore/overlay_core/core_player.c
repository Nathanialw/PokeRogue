//
// Created by nathanial on 5/19/26.
//

#include "core_player.h"

#include "core_entities.h"
#include "core_ram.h"
#include "core_stats.h"


/**********************************************************************************************************************/
/** Searches the party to find an open slot to capture a creature
 *  ON SUCCESS - adds creature id to the party array
 *             - sets xp for the creature
*   ON FAIL - TODO - add a fail state (creature cannot be captured)
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId PlayerCaptureMonster(EntityId e_id)
{
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        if (g_core.player.partyID[i] == NO_ENTITY)
        {
            g_core.player.partyID[i] = CaptureMonster(e_id);
            g_core.player.cur_xp[i] = 0;
            g_core.player.tar_xp[i] = 100; //TODO: calculate needed xp to level
            return e_id;
        }

    return e_id;
}

/**********************************************************************************************************************/
/** Searches the bag to find an open slot to pick up an item
 *  ON SUCCESS - adds item id to the party array
*   ON FAIL - TODO - add a fail state (item cannot be picked up)
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId PlayerPickItem(EntityId e_id)
{
    if (e_id == NO_ENTITY) return e_id;
    for (uint8_t i = 0; i < MAX_BAG_SIZE; ++i)
        if (g_core.player.itemID[i] == NO_ENTITY)
        {
            g_core.player.itemID[i] = PickItem(e_id);
            return e_id;
        }

    return e_id;
}



/**********************************************************************************************************************/
/**Returns the player's party array
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId* GetPlayerMonsterIDs(void)
{
    return g_core.player.partyID;
}


/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
SET_MEMORY(".core")
void DestroyPlayerCreature(HardwareInterface hardware)
{
    EntityId player_creature_id = g_core.battleMode.playerMonsterID;
    EntityId ai_creature_id = g_core.battleMode.enemyMonsterID;
    GainXP(player_creature_id, ai_creature_id);
    // DestroyCreature(hardware, ai_creature_id);
}

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
SET_MEMORY(".core")
void DestroyEnemyCreature(HardwareInterface hardware)
{
    EntityId player_creature_id = g_core.battleMode.playerMonsterID;
    EntityId ai_creature_id = g_core.battleMode.enemyMonsterID;
    GainXP(player_creature_id, ai_creature_id);
    // DestroyCreature(hardware, ai_creature_id);
}