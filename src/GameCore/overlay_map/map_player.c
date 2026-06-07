//
// Created by nathanial on 5/19/26.
//

#include "map_player.h"
#include "lib_memory.h"

#include "core_map.h"
#include "core_player.h"
#include "core_ram.h"

#include "map_actions.h"
#include "map_entities.h"


/*******************************************************************************************************************
*
**********************************************************************************************************************/

/*******************************************************************************************************************
** Returns the player position as map cell index
**********************************************************************************************************************/
SET_MEMORY(".map")
Position GetPlayerPosition(void)
{
    return GetEntityPosition(TRAINER, g_core.player.id);
}

/*******************************************************************************************************************
**Sets player Position value to NewPosition value
 * stores the player delta value into the scroll value
 * clears the player delta value
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdatePlayerPosition(void)
{
    Position pos = GetPlayerPosition();
    uint8_t x = pos.x + g_core.player.d.x;
    uint8_t y = pos.y + g_core.player.d.y;
    QueueObjectMovePosition(g_core.player.id, x, y);
    g_core.player.scroll.x = g_core.player.d.x;
    g_core.player.scroll.y = g_core.player.d.y;
    g_core.player.d.x = 0;
    g_core.player.d.y = 0;
}

/*******************************************************************************************************************
**Set the player movement delta
 * -1 or 0 or 1 for single cell movement
**********************************************************************************************************************/
SET_MEMORY(".map")
Delta SetPlayerDelta(Delta newDelta)
{
    g_core.player.d = newDelta;
    return g_core.player.d;
}



/*******************************************************************************************************************
*  interact with item in player's cell
*  interact with object in player's cell
**********************************************************************************************************************/
SET_MEMORY(".map")
void PlayerInteractItemInCell()
{
    Position pos = GetPlayerPosition();
    EntityId item_id = CheckTileForEntity(ITEM, g_core.player.id, pos);
    EntityId player_id = GetPlayerID();
    PlayerPickItem(player_id, item_id);
}

SET_MEMORY(".map")
void PlayerInteractObjectInCell(MemoryInterface memory, HardwareInterface hardware)
{
    Position pos = GetPlayerPosition();
    EntityId object_id = CheckTileForEntity(OBJECT, g_core.player.id, pos);
    EntityId p_ID = GetPlayerID();
    InteractObject(memory, hardware, object_id, g_core.trainers.partyID[p_ID][0]);
}
