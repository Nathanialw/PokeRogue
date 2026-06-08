//
// Created by nathanial on 2/21/26.
//

#include "map_collision.h"

#include "core_effects.h"
#include "core_entities.h"
#include "lib_memory.h"

#include "core_player.h"
#include "core_ram.h"
#include "core_stats.h"

#include "map_entities.h"
#include "map_player.h"


/**********************************************************************************************************************/
/*
 *  This file handles map tile interaction logic
 *
**********************************************************************************************************************/
typedef bool (*Interaction)(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);


bool NoInteraction(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Wall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Pit(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Foliage(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Water(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Lava(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Acid(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool PitLava(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool PitAcid(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool PitMinor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool PitSmall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool PitSnake(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool PitSpike(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool PitWater(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool PitWide(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);

SET_MEMORY(".map.rodata")
const Interaction TileCollisionStepOn[TILE_COUNT] =
{
    Acid, //ACID
    NoInteraction, //CRYSTAL
    NoInteraction, //FLOOR_CASTLE
    NoInteraction, //FLOOR_DIRT
    NoInteraction, //FLOOR_MEADOW
    NoInteraction, //FLOOR_SNOW
    NoInteraction, //FLOOR_VOLCANIC
    NoInteraction, //FLOOR_WOOD
    Lava, //LAVA
    PitAcid, //PIT_ACID
    PitLava, //PIT_LAVA
    PitMinor, //PIT_MINOR
    PitSmall, //PIT_SMALL
    PitSnake, //PIT_SNAKE
    PitSpike, //PIT_SPIKES
    NoInteraction, //PIT_WATER
    PitWide, //PIT_WIDE
    Wall, //RIVER_FROZEN
    Wall, //WALL_BRICK
    Wall, //WALL_CASTLE
    Wall, //WALL_ICE
    Wall, //WALL_STONE
    Wall, //WALL_WOOD
    NoInteraction, //WATER
};

SET_MEMORY(".map.rodata")
const Interaction TileCollisionStepOff[TILE_COUNT] =
{
    Acid, //ACID
    NoInteraction, //CRYSTAL
    NoInteraction, //FLOOR_CASTLE
    NoInteraction, //FLOOR_DIRT
    NoInteraction, //FLOOR_MEADOW
    NoInteraction, //FLOOR_SNOW
    NoInteraction, //FLOOR_VOLCANIC
    NoInteraction, //FLOOR_WOOD
    Lava, //LAVA
    PitAcid, //PIT_ACID
    PitLava, //PIT_LAVA
    PitMinor, //PIT_MINOR
    PitSmall, //PIT_SMALL
    PitSnake, //PIT_SNAKE
    PitSpike, //PIT_SPIKES
    PitWater, //PIT_WATER
    PitWide, //PIT_WIDE
    Wall, //RIVER_FROZEN
    Wall, //WALL_BRICK
    Wall, //WALL_CASTLE
    Wall, //WALL_ICE
    Wall, //WALL_STONE
    Wall, //WALL_WOOD
    Water, //WATER
};

/**********************************************************************************************************************/
/** Space is empty, free to move into
**********************************************************************************************************************/
SET_MEMORY(".map")
bool NoInteraction(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

/**********************************************************************************************************************/
/** Space is blocked, no movement
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Wall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
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
bool Pit(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
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
bool Foliage(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
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
bool Water(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    if (type == TRAINER)
    {
        if (g_core.creatures.status.waterWalk[id])
            return true;


        EntityId creature_id = g_core.trainers.partyID[id][0];
        DoDamage(creature_id, 3);
        bool dead = CheckCreatureDead(creature_id);
        if (dead)
        {
            DestroyCreature(creature_id);
            if (CheckGameLost())
                g_core.state.overlay = OVERLAY_TITLE_SCREEN;
        }
    }
    if (type == CREATURE)
    {

    }

    // check for damage and position drift
    return true;
}



SET_MEMORY(".map")
bool PitLava(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

SET_MEMORY(".map")
bool PitAcid(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

SET_MEMORY(".map")
bool PitMinor(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

SET_MEMORY(".map")
bool PitSmall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

SET_MEMORY(".map")
bool PitSnake(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

SET_MEMORY(".map")
bool PitSpike(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

SET_MEMORY(".map")
bool PitWater(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}

SET_MEMORY(".map")
bool PitWide(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return true;
}




/**********************************************************************************************************************/
/** Space is lava
 *  TODO: add drift mechanics
 *  TODO: add flame damage mechanics
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Lava(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
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
bool Acid(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    // check for damage, item melting and position drift
    return true;
}

/**********************************************************************************************************************/
/** Main tile interaction entry point
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CheckInteractionStepOn(uint8_t tile, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return TileCollisionStepOn[tile](id, type, x, y);
}


/**********************************************************************************************************************/
/** Main tile interaction entry point
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CheckInteractionStepOff(uint8_t tile, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return TileCollisionStepOn[tile](id, type, x, y);
}

/**********************************************************************************************************************/
/** Triggers the battle state
**********************************************************************************************************************/
SET_MEMORY(".map")
void StartBattle(EntityId id)
{
    g_core.battleMode.playerMonsterID = g_core.trainers.partyID[GetPlayerID()][0];
    g_core.battleMode.enemyMonsterID = id;

    g_core.state.overlay = OVERLAY_BATTLE;
}
