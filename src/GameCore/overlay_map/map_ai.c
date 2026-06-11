//
// Created by nathanial on 5/19/26.
//
#include "map_ai.h"

#include "core_player.h"
#include "types.h"
#include "lib_memory.h"

#include "core_ram.h"
#include "lib_debugging.h"

#include "map_entities.h"
#include "map_player.h"
#include "map_utils.h"

typedef void (*AIType)(HardwareInterface hardware, EntityId id, ObjectsTypes type);

/**********************************************************************************************************************/
/** Takes in an entity id
 *  chooses a random adjacent cell
 *  queues the cell position into the newPosition array for the given entity id
**********************************************************************************************************************/
SET_MEMORY(".map")
void RandomWalk(HardwareInterface hardware, EntityId id, ObjectsTypes type)
{
    Position pos = g_core.creatures.position[id];

    int8_t dx = hardware.GetRandom_uint8_t(0, 2);
    if (dx == 2) dx = -1;
    int8_t dy = hardware.GetRandom_uint8_t(0, 2);
    if (dy == 2) dy = -1;

    g_core.creatures.newPosition[id].x = pos.x + dx;
    g_core.creatures.newPosition[id].y = pos.y + dy;
};


/**********************************************************************************************************************/
/** Takes in an entity id
 *  Gets the player location
 *  Selects the closest adjacent cell to the given entity id to move closer to the player
 *  Queues the cell position into the newPosition array for the given entity id
 *  checks where the player is within range
 *  ON SUCCESS - execute function, return true
 *  ON FAIL - return false
**********************************************************************************************************************/
SET_MEMORY(".map")
bool TargetHoming(HardwareInterface hardware, EntityId id, ObjectsTypes type)
{
    Position* positions = NULL;
    Position* new_positions = NULL;

    if (type == CREATURE)
    {
        positions = g_core.creatures.position;
        new_positions = g_core.creatures.newPosition;
    }
    else if (type == TRAINER)
    {
        positions = g_core.trainers.position;
        new_positions = g_core.trainers.newPosition;
    }
    else if (!positions || !new_positions)
    {
        DEBUG("Position* or new_positions null");
        return false;
    }

    uint16_t p_id = GetPlayerID();
    Position player_pos = GetPlayerPosition();
    Position pos = positions[id];

    uint8_t player_x = player_pos.x;
    uint8_t player_y = player_pos.y;

    uint8_t pos_x = pos.x;
    uint8_t pos_y = pos.y;

    uint8_t nearby_range = 5;

    if (!WithinRange(pos_x, pos_y, player_x, player_y, nearby_range))
        return false;

    if (!InDetectionRange(id, p_id))
        return false;


    int16_t dx = player_x - pos_x;
    int16_t dy = player_y - pos_y;

    if (hardware.Abs(dx) > hardware.Abs(dy))
    {
        // Move horizontally
        if (dx > 0)
            pos_x++;
        else
            pos_x--;
    }
    else
    {
        // Move vertically
        if (dy > 0)
            pos_y++;
        else
            pos_y--;
    }


    Position newPos = {.x = pos_x, .y = pos_y};
    new_positions[id] = newPos;

    return true;
}

/**********************************************************************************************************************/
/** array of pointers to movement types functions
 *  TODO - WORK IN PROGRESS
**********************************************************************************************************************/
void Humanoid(HardwareInterface hardware, EntityId id, ObjectsTypes type);

//TODO eventually the key will be the creature id, but for now just one ai type
//TODO you know probably better to have maybe 16 ai types and store a key on the entity
SET_MEMORY(".map.rodata")
AIType aiActions[1] =
{
    Humanoid,
};

/**********************************************************************************************************************/
/** Runs the logic for humanoid movement
**********************************************************************************************************************/
SET_MEMORY(".map")
void Humanoid(HardwareInterface hardware, EntityId id, ObjectsTypes type)
{
    if (TargetHoming(hardware, id, type))
        return;
    RandomWalk(hardware, id, type);
};

/**********************************************************************************************************************/
/** Entry point for movement AI
**********************************************************************************************************************/
SET_MEMORY(".map")
void CreatureAI(HardwareInterface hardware, EntityId id, ObjectsTypes type)
{
    aiActions[0](hardware, id, type);
}
