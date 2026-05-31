//
// Created by nathanial on 2/21/26.
//

#include "map_collision.h"

#include "lib_memory.h"

#include "core_player.h"
#include "core_ram.h"

#include "map_entities.h"


/**********************************************************************************************************************/
/*
 *  This file handles map tile interaction logic
 *
**********************************************************************************************************************/
typedef bool (*Interaction)(EntityId, uint8_t x, uint8_t y);


bool NoInteraction(EntityId id, uint8_t x, uint8_t y);
bool Wall(EntityId id, uint8_t x, uint8_t y);
bool Foliage(EntityId id, uint8_t x, uint8_t y);
bool Water(EntityId id, uint8_t x, uint8_t y);
bool Lava(EntityId id, uint8_t x, uint8_t y);
bool Acid(EntityId id, uint8_t x, uint8_t y);

SET_MEMORY(".map.rodata")
const Interaction TileCollision[NUM_TILES] =
{
    Acid,
    NoInteraction,
    NoInteraction,
    NoInteraction,
    NoInteraction,
    Lava,
    NoInteraction,
    NoInteraction,
    NoInteraction,
    NoInteraction,
    Wall,
    Wall,
    Wall,
    Wall,
    Wall,
    Water,
};

/**********************************************************************************************************************/
/** Space is empty, free to move into
**********************************************************************************************************************/
SET_MEMORY(".map")
bool NoInteraction(EntityId id, uint8_t x, uint8_t y)
{
    return true;
}

/**********************************************************************************************************************/
/** Space is blocked, no movement
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Wall(EntityId id, uint8_t x, uint8_t y)
{
    // check current tile, cancel movement

    if (id == g_core.player.id)
    {
        g_core.player.scroll.x = 0;
        g_core.player.scroll.y = 0;
    }


    return false;
}

/**********************************************************************************************************************/
/** Space is blocked, no movement
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Foliage(EntityId id, uint8_t x, uint8_t y)
{
    // slow move speed, move speed not implemented yet
    return true;
}

/**********************************************************************************************************************/
/** Space is water
 *  TODO: add drift mechanics
 *  TODO: add drowning mechanics
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Water(EntityId id, uint8_t x, uint8_t y)
{
    // check for damage and position drift
    return true;
}

/**********************************************************************************************************************/
/** Space is lava
 *  TODO: add drift mechanics
 *  TODO: add flame damage mechanics
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Lava(EntityId id, uint8_t x, uint8_t y)
{
    // check for damage and position drift
    return true;
}

/**********************************************************************************************************************/
/** Space is acid
 *  TODO: add drift mechanics
 *  TODO: add Toxic damage mechanics
 *  TODO: add item melting mechanics
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Acid(EntityId id, uint8_t x, uint8_t y)
{
    // check for damage, item melting and position drift
    return true;
}

/**********************************************************************************************************************/
/** Main tile interaction entry point
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CheckInteraction(uint8_t tile, EntityId id, uint8_t x, uint8_t y)
{
    return TileCollision[tile](id, x, y);
}

/**********************************************************************************************************************/
/** Triggers the battle state
**********************************************************************************************************************/
SET_MEMORY(".map")
void StartBattle(EntityId id)
{
    EntityId p_ID = GetPlayerID();
    g_core.battleMode.playerMonsterID = g_core.trainers.partyID[p_ID][0];
    g_core.battleMode.enemyMonsterID = id;

    g_core.state.overlay = OVERLAY_BATTLE;
}
