//
// Created by nathanial on 5/19/26.
//

#include "map_entities.h"

#include "lib_types.h"
#include "lib_memory.h"

#include "core_entities.h"
#include "core_map.h"
#include "core_ram.h"
#include "core_utils.h"


/**********************************************************************************************************************/
/**Takes in an entity ID
*   checks the queued positino for an entity
*   ON SUCCESS - returns the entity id of the entity in the new tile
*   ON FAIL - returns NO_OBJECT
**********************************************************************************************************************/
SET_MEMORY(".map")
EntityId CheckCollision(EntityId id, ObjectsTypes type)
{
    Position pos = {0};
    if (type == CREATURE)
        pos = g_core.creatures.newPosition[id];
    else if (type == TRAINER)
        pos = g_core.trainers.newPosition[id];
    else
        return NO_OBJECT;

    EntityId creature_id = CheckTileForEntity(type, id, pos);
    return creature_id;
};


/**********************************************************************************************************************/
/** saves the new position coords into the newPosition array for the gven entity id
**********************************************************************************************************************/
SET_MEMORY(".map")
Position QueueObjectMovePosition(EntityId id, uint8_t x, uint8_t y)
{
    Position pos = {.x = x, .y = y};
    g_core.trainers.newPosition[id] = pos;
    return g_core.trainers.newPosition[id];
}


/**********************************************************************************************************************/
/**sets the current position as the newPosition value of the given entity id
**********************************************************************************************************************/
SET_MEMORY(".map")
Position SetEntityPosition(ObjectsTypes type, EntityId id, uint8_t x, uint8_t y, uint8_t nx, uint8_t ny)
{
    Position pos = {.x = nx, .y = ny};
    if (type == CREATURE)
    {
        g_core.creatures.position[id] = pos;
        return g_core.creatures.position[id];
    }
    if (type == ITEM)
    {
        g_core.items.position[id] = pos;
        return g_core.items.position[id];
    }
    if (type == OBJECT)
    {
        g_core.objects.position[id] = pos;
        return g_core.objects.position[id];
    }
    if (type == TRAINER)
    {
        g_core.trainers.position[id] = pos;
        return g_core.trainers.position[id];
    }
   if (type == ENVIRONMENT_OBJECT)
    {
        g_core.trainers.position[id] = pos;
        return g_core.environment_objects.position[id];
    }

    return pos;
}

/**********************************************************************************************************************/
/**Returns the position of a given entity ID
**********************************************************************************************************************/
SET_MEMORY(".map")
Position GetEntityPosition(ObjectsTypes type, EntityId id)
{
    if (type == CREATURE)
        return g_core.creatures.position[id];
    if (type == ITEM)
        return g_core.items.position[id];
    if (type == OBJECT)
        return g_core.objects.position[id];
    if (type == TRAINER)
        return g_core.trainers.position[id];
    if (type == ENVIRONMENT_OBJECT)
        return g_core.environment_objects.position[id];
    Position p = {0};
    return p;
}


/**********************************************************************************************************************/
/**Returns the array of entities alive status
**********************************************************************************************************************/
BitFieldUint8* GetCreaturesAlive(void)
{
    return &g_core.creatures.alive;
}

/**********************************************************************************************************************/
/**Returns the array of entity speeds
**********************************************************************************************************************/
SET_MEMORY(".map")
IntMax99* GetCreatureSpeeds(ObjectsTypes type)
{
    if (type == CREATURE)
        return g_core.creatures.speed;
    if (type == TRAINER)
        return g_core.trainers.speed;
    return NULL;
}

/**********************************************************************************************************************/
/**Returns the array of entity positions
**********************************************************************************************************************/
SET_MEMORY(".map")
Position* GetEntityPositions(ObjectsTypes type)
{
    if (type == CREATURE)
        return g_core.creatures.position;
    if (type == ITEM)
        return g_core.items.position;
    if (type == OBJECT)
        return g_core.objects.position;
    if (type == TRAINER)
        return g_core.trainers.position;
    if (type == ENVIRONMENT_OBJECT)
        return g_core.environment_objects.position;

    return NULL;
}

/**********************************************************************************************************************/
/**Returns the array of entity NEW positions
**********************************************************************************************************************/
SET_MEMORY(".map")
Position* GetEntityNewPositions(ObjectsTypes type)
{
    if (type == CREATURE)
        return g_core.creatures.newPosition;
    if (type == TRAINER)
        return g_core.trainers.newPosition;
    return NULL;
}


/**********************************************************************************************************************/
/** Checks whether is given entity ID can detect the target entity ID
 * ON SUCCESS - returns true
 * ON FAIL - returns false
**********************************************************************************************************************/
SET_MEMORY(".map")
bool InDetectionRange(EntityId id, EntityId targetID)
{
    uint8_t smell = g_core.creatures.senses[id].smell;
    uint8_t smell_stealth = g_core.creatures.stealth[targetID].smell;

    if (smell > smell_stealth)
        return true;

    uint8_t sound = g_core.creatures.senses[id].sound;
    uint8_t sound_stealth = g_core.creatures.stealth[targetID].sound;

    if (sound > sound_stealth)
        return true;

    uint8_t sight = g_core.creatures.senses[id].sight;
    uint8_t sight_stealth = g_core.creatures.stealth[targetID].sight;

    if (sight > sight_stealth)
        return true;

    return false;
}


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CheckCreatureDead(EntityId creature_id)
{
    uint8_t hp = Int999GetCurrent(&g_core.creatures.hp[creature_id]);
    if (hp == 0)
    {
        return true;
    }
    return false;
}
