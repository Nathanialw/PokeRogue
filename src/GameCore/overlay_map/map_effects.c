//
// Created by nathanial on 5/19/26.
//

#include "map_effects.h"
#include "types.h"

#include "core_effects.h"
#include "core_entities.h"
#include "core_map.h"
#include "core_player.h"
#include "core_ram.h"
#include "core_stats.h"
#include "core_utils.h"

#include "lib_decl.h"
#include "lib_memory.h"

#include "map.h"
#include "map_camera.h"
#include "map_entities.h"
#include "map_player.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome MapDescend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    return GoNextLevel(MAP_LEVEL_DOWN);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome MapAscend(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    return GoNextLevel(MAP_LEVEL_UP);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome MapLateral(HardwareInterface hardware, MemoryInterface memory, EntityId e_id)
{
    return GoNextLevel(MAP_LEVEL_LATERAL);
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool RevealMap()
{
    SetMapFog(0xFF);
    return true;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool SetTilseAsFloor(Position position, MapTile type)
{
    SetMapTile(position.x, position.y, FLOOR_DIRT);
    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool SetSurroundingTils(Position position, MapTile type)
{
    uint8_t start_x = position.x - 1;
    uint8_t start_y = position.y - 1;

    for (uint8_t y = start_y; y < start_y + 3; y++)
    {
        if (y < 1 || y > MAP_W - 1) continue;
        for (uint8_t x = start_x; x < start_x + 3; x++)
        {
            if (x < 1 || x > MAP_H - 1) continue;
            SetMapTile(x, y, FLOOR_DIRT);
        }
    }

    return true;
}

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool ConvertSurroundingTiles(Position position, MapTile cur_type, MapTile new_type)
{
    uint8_t start_x = position.x - 1;
    uint8_t start_y = position.y - 1;

    for (uint8_t y = start_y; y < start_y + 3; y++)
    {
        if (y < 1 || y > MAP_W - 1) continue;
        for (uint8_t x = start_x; x < start_x + 3; x++)
        {
            if (x < 1 || x > MAP_H - 1) continue;
            MapTile tile = GetMapTile(x, y);
            if (tile == cur_type)
                SetMapTile(x, y, new_type);
        }
    }

    return true;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool Reposition(HardwareInterface hardware, EntityId e_id)
{
    Position random_tile_pos = GetRandomMapTile(hardware, TRAINER, true);
    g_core.trainers.position[GetPlayerID()] = random_tile_pos;
    SetCameraPlayer();
    return true;
}

/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool SacrificeCreature(HardwareInterface hardware, EntityId trainer_id, EntityId creature_id, uint16_t xp)
{
    uint8_t party_size = GetPlayerPartySize();
    if (party_size > 1)
    {
        Creature creature_type = GetCreatureType(creature_id);
        SetBit(g_core.player.sacrificedCreatures, creature_type, true);
        DestroyPartyCreature(trainer_id, creature_id);
        GainXP(trainer_id, xp, TRAINER);
        g_core.update_left_player = true;
        g_core.update_right_party = true;
        return ACTION_SUCCEEDED;
    }
    return true;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool SummonCreature(HardwareInterface hardware, MemoryInterface memory, EntityId object_id, CreatureID creature_type)
{
    uint8_t x = g_core.objects.position[object_id].x;
    uint8_t y = g_core.objects.position[object_id].y;
    uint8_t l = 1;
    SpawnEntity(hardware, memory, CREATURE, creature_type, x, y, l);
    return true;
}

CreatureID GetRandomUndead(HardwareInterface hardware)
{
    CreatureID types[] = {HAG, ZOMBIE};
    uint8_t random_index = hardware.GetRandom_uint8_t(0, sizeof(types) / sizeof(CreatureID) - 1);
    return random_index;
}

CreatureID GetRandomHag(HardwareInterface hardware)
{
    CreatureID types[] = {HAG, WITCH};
    uint8_t random_index = hardware.GetRandom_uint8_t(0, sizeof(types) / sizeof(CreatureID) - 1);
    return random_index;
}

CreatureID GetRandomDemon(HardwareInterface hardware)
{
    CreatureID types[] = {SUCCUBUS, DEMON};
    uint8_t random_index = hardware.GetRandom_uint8_t(0, sizeof(types) / sizeof(CreatureID) - 1);
    return random_index;
}


/**********************************************************************************************************************
*
**********************************************************************************************************************/
SET_MEMORY(".map")
ActionOutcome DamageCreature(CreatureID entity_id, uint8_t damage, ObjectsTypes entity_type)
{
    if (entity_type == CREATURE)
    {
        if (entity_id == NO_CREATURE) return ACTION_FAILED;
        if (damage == 0) return ACTION_FAILED;

        DoDamage(entity_id, damage);
        bool dead = CheckCreatureDead(entity_id);
        if (dead)
            DestroyCreature(entity_id);
    }
    else if (entity_type == TRAINER)
    {
        EntityId creature_id = g_core.trainers.partyID[entity_id][0];
        if (creature_id == NO_CREATURE) return ACTION_FAILED;
        if (damage == 0) return ACTION_FAILED;


        DoDamage(creature_id, damage);
        bool dead = CheckCreatureDead(creature_id);
        if (dead)
        {
            DestroyPartyCreature(entity_id, creature_id);
            EntityId new_creature = GetNextPartyCreature(entity_id);
            if (entity_id == GetPlayerID())
            {
                CheckGameLost();
            }
            else if (new_creature == NO_CREATURE)
            {
                DestroyTrainer(entity_id);
            }
        }
    }


    return ACTION_FAILED;
}

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
    if (type == TRAINER)
    {
        if (g_core.trainers.buffs[id].water_walk)
            return true;

        DamageCreature(id, g_core.floor, type);
    }
    if (type == CREATURE)
    {
        DamageCreature(id, g_core.floor, type);
    }

    return true;
}


/**********************************************************************************************************************/
/** Space is water
 *  TODO: add drift mechanics
 *  TODO: add drowning mechanics
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CollisionFluidTile(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    if (type == TRAINER)
    {
        if (g_core.trainers.buffs[id].water_walk)
            return true;

        DamageCreature(id, g_core.floor, type);
    }
    if (type == CREATURE)
    {
        DamageCreature(id, g_core.floor, type);
    }

    // check for damage and position drift
    return true;
}
