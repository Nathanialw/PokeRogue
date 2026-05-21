//
// Created by nathanial on 2/23/26.
//

#include "map_movement.h"

#include "lib_memory.h"
#include "lib_constants.h"

#include "core_utils.h"
#include "core_map.h"
#include "core_memory_access.h"
#include "core_ram.h"
#include "lib_enums.h"

#include "map_ai.h"
#include "map_camera.h"
#include "map_collision.h"
#include "map_status_effects.h"
#include "map_entities.h"
#include "map_player.h"


/**********************************************************************************************************************/
/** Runs All game init functions in order
 *      -> Sets entities to default state
 *      -> Clears the map
 *      -> Creates the map
 *      -> creates map entities
 *      -> sets camera to player position
**********************************************************************************************************************/
//  Generate a new map and objects, set camera
void NewMap(void)
{
    // DEBUG("new map");
    // ResetEntities(false);
    // InitMap();
    // PopulateLevelCreatures();
    // SetCameraPlayer();
}

/**********************************************************************************************************************/
/** Initializes title screen data
 *  TODO: NOT YET IMPLEMENTED
**********************************************************************************************************************/
void InitTitleScreen(void)
{
}

/**********************************************************************************************************************/
/** Updates player position first
 *  Checks for battle
 *  Iterates through all entities, run the AI function to update their position
**********************************************************************************************************************/
SET_MEMORY(".map")
bool UpdatePositions(HardwareInterface hardware)
{
    EntityId p_id = GetPlayerID();
    IntMax99* speed = GetCreatureSpeeds();
    EntityId combat_id = NO_ENTITY;
    uint8_t player_speed = speed[p_id].current; //awkwardly as my speed value decreases my speed goes 'up', I may need to rethink this
    uint8_t* onMap = GetEntitiesOnMap(CREATURE);

    for (uint16_t id = 0; id < ENTITY_COUNT; ++id)
    {
        if (!GetBit(onMap, id)) continue; //need to make sure this only triggers for dynamic map entities
        if (id == p_id) continue;

        uint8_t max = speed[id].max;
        uint8_t cur = speed[id].current;

        if (cur + player_speed < max)
        {
            speed[id].current += player_speed;
            g_core.creatures.newPosition[id] = g_core.creatures.position[id];
            continue;
        }

        speed[id].current = player_speed - (max - cur);
        CreatureAI(hardware, id);
    }


    for (uint16_t id = 0; id < ENTITY_COUNT; ++id)
    {
        if (!GetBit(onMap, id)) continue;
        if (id == p_id) continue;
        EntityId collision_id = CheckCollision(id);
        if (collision_id == p_id) combat_id = id;
    }

    if (combat_id != NO_ENTITY)
    {
        ObjectCollision(combat_id);
        return false;
    }

    UpdatePlayerPosition();
    uint8_t creature_id = CheckCollision(p_id);
    if (creature_id != NO_ENTITY && creature_id != p_id)
    {
        ObjectCollision(creature_id);
        return false;
    }

    return true;
}

/**********************************************************************************************************************/
/**Iterates through all entities sets position to the queued position
**********************************************************************************************************************/
SET_MEMORY(".map")
void SetPositions(void)
{
    uint8_t* onMap = GetEntitiesOnMap(CREATURE); //array is 256 bytes
    Position* position = GetEntityPositions(CREATURE); //array is 512 bytes
    Position* newPosition = GetEntityNewPositions(); //array is 512 bytes

    // DEBUG("Updating Object Positions");

    for (uint16_t id = 0; id < ENTITY_COUNT; ++id)
    {
        if (!GetBit(onMap, id)) continue;

        Position pos = position[id];
        Position nPos = newPosition[id];

        uint8_t x = pos.x;
        uint8_t y = pos.y;

        uint8_t nx = nPos.x;
        uint8_t ny = nPos.y;

        //check current tile
        uint8_t tileID = GetMapTile(x, y);
        CheckInteraction(tileID, id, x, y);

        //check next tile
        tileID = GetMapTile(nx, ny);
        if (CheckInteraction(tileID, id, nx, ny))
            SetEntityPosition(CREATURE, id, x, y, nx, ny);
    }

    // DEBUG("Updating Object done");
}


/**********************************************************************************************************************/
/** Main update
 *  call every frame
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdateGame(HardwareInterface hardware)
{
    if (g_core.state.inputState == INPUT_ACTING) g_core.turn_count++;
    UpdateObjectStatusEffects(hardware);
    if (UpdatePositions(hardware))
    {
        SetPositions();
    }
    SetCameraPlayer();
}
