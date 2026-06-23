//
// Created by nathanial on 5/19/26.
//

#include "core_player.h"
#include "lib_memory.h"

#include "core_entities.h"
#include "core_ram.h"
#include "core_stats.h"
#include "core_utils.h"


/**********************************************************************************************************************/
/** Searches the party to find an open slot to capture a creature
 *  ON SUCCESS - adds creature id to the party array
 *             - sets xp for the creature
*   ON FAIL - TODO - add a fail state (creature cannot be captured)
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId PlayerCaptureMonster(EntityId e_id)
{
    EntityId player_id = GetPlayerID();
    for (uint8_t i = 0; i < MAX_PARTY_SIZE; ++i)
        if (g_core.trainers.partyID[player_id][i] == NO_ENTITY)
        {
            g_core.trainers.partyID[player_id][i] = CaptureMonster(e_id);
            g_core.player.cur_xp[i] = 0;
            g_core.player.tar_xp[i] = 100; //TODO: calculate needed xp to level
            return e_id;
        }

    return e_id;
}


/**********************************************************************************************************************/
/** Drops item and frees bag slot
 *  removes any passive effect the item had
 *  ON SUCCESS - removes item id to the bag array
*   ON FAIL - TODO - add a fail state (item cannot be dropped)
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId DropItem(EntityId trainer_id, EntityId item_id)
{
    //  drop item
    //  remove passive item effect

    return item_id;
}


/**********************************************************************************************************************/
/**Returns the player's party array
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId* GetPlayerMonsterIDs(void)
{
    EntityId p_ID = GetPlayerID();
    return g_core.trainers.partyID[p_ID];
}

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId* GetPlayerInventory(void)
{
    EntityId p_ID = GetPlayerID();
    return g_core.trainers.itemID[p_ID];
}

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
SET_MEMORY(".core")
BagData GetPlayerBagData(void)
{
    EntityId p_ID = GetPlayerID();
    return g_core.trainers.bag[p_ID];
}


/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
SET_MEMORY(".core")
SpellBook* GetPlayerSpellbook(void)
{
    EntityId player_id = GetPlayerID();
    return &g_core.trainers.spellbook[player_id];
}


/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
SET_MEMORY(".core")
void DestroyPlayerCreature(HardwareInterface hardware)
{
    EntityId player_creature_id = g_core.battleMode.playerMonsterID;
    EntityId ai_creature_id = g_core.battleMode.enemyMonsterID;
    GainXPFromKill(player_creature_id, ai_creature_id);
    DestroyCreature(ai_creature_id);
}

/**********************************************************************************************************************/
/**
**********************************************************************************************************************/
SET_MEMORY(".core")
void DestroyEnemyCreature(HardwareInterface hardware)
{
    EntityId player_creature_id = g_core.battleMode.playerMonsterID;
    EntityId ai_creature_id = g_core.battleMode.enemyMonsterID;
    GainXPFromKill(player_creature_id, ai_creature_id);
    DestroyCreature(ai_creature_id);
}


/**********************************************************************************************************************/
/**Destroys the item entity
 * Sets the bag index of the item to NO_ITEM
**********************************************************************************************************************/
SET_MEMORY(".core")
void ConsumeItem1(uint8_t idx, EntityId e_id)
{
    DestroyItem(e_id);
    EntityId player_id = GetPlayerID();
    g_core.trainers.itemID[player_id][idx] = NO_ENTITY;
    for (uint8_t i = idx; i < MAX_BAG_SIZE - 1; ++i)
    {
        g_core.trainers.itemID[player_id][i] = g_core.trainers.itemID[player_id][i + 1];
        g_core.trainers.itemID[player_id][i + 1] = NO_ENTITY;
        g_core.trainers.bag[player_id].occupied_slots--;
    }
}


/**********************************************************************************************************************/
/**Destroys the item entity
 * Sets the bag index of the item to NO_ITEM
**********************************************************************************************************************/
SET_MEMORY(".core")
void ConsumeItem(EntityId trainer_id, uint8_t idx, EntityId e_id)
{
    DestroyItem(e_id);
    g_core.trainers.itemID[trainer_id][idx] = NO_ENTITY;
    g_core.trainers.bag[trainer_id].occupied_slots--;
    for (uint8_t i = idx; i < MAX_BAG_SIZE - 1; ++i)
    {
        g_core.trainers.itemID[trainer_id][i] = g_core.trainers.itemID[trainer_id][i + 1];
        g_core.trainers.itemID[trainer_id][i + 1] = NO_ENTITY;
    }
}

/**********************************************************************************************************************/
/**Returns the player ID
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId GetPlayerID(void)
{
    return g_core.player.id;
}

/**********************************************************************************************************************/
/**Returns the player ID
**********************************************************************************************************************/
SET_MEMORY(".core")
uint99* GetPlayerLevel(void)
{
    return &g_core.trainers.level[g_core.player.id];
}

/**********************************************************************************************************************/
/**Returns the player ID
**********************************************************************************************************************/
SET_MEMORY(".core")
uint8_t GetPlayerPartySize(void)
{
    return g_core.trainers.currentPartySize[GetPlayerID()];

}
/**********************************************************************************************************************/
/**Returns the player ID
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId* GetPlayerParty(void)
{
    return g_core.trainers.partyID[GetPlayerID()];

}

/**********************************************************************************************************************/
/**Returns the player ID
**********************************************************************************************************************/
SET_MEMORY(".core")
EntityId GetPlayerEffects(PlayerEffects playerEffect)
{
    return GetBit(g_core.player.effects, playerEffect);
}
