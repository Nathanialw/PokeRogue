//
// Created by nathanial on 2/23/26.
//

#include "map_movement.h"

#include "core_entities.h"
#include "lib_memory.h"
#include "lib_constants.h"

#include "core_utils.h"
#include "core_map.h"
#include "core_player.h"
#include "core_ram.h"
#include "lib_debugging.h"
#include "map_actions.h"

#include "map_ai.h"
#include "map_camera.h"
#include "map_collision.h"
#include "map_status_effects.h"
#include "map_entities.h"
#include "map_player.h"
#include "map_ram.h"


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
    UpdatePlayerPosition();

    // Trainers
    IntMax99* speed = GetCreatureSpeeds(TRAINER);
    uint8_t* onMap = GetEntitiesOnMap(TRAINER);
    uint8_t player_speed = speed[p_id].current; //awkwardly as my speed value decreases my speed goes 'up', I may need to rethink this

    for (uint16_t id = 0; id < MAX_ENTITY_TRAINER_COUNT; id++)
    {
        if (!GetBit(onMap, id)) continue; //need to make sure this only triggers for dynamic map entities
        if (id == p_id) continue;

        uint8_t max = speed[id].max;
        uint8_t cur = speed[id].current;

        if (cur + player_speed < max)
        {
            speed[id].current += player_speed;
            continue;
        }
#if defined(TEST_MAP)
        g_core.trainers.newPosition[id] = g_core.trainers.position[id];
#else
        CreatureAI(hardware, id, TRAINER);
#endif
        speed[id].current = player_speed - (max - cur);
    }

    // check for battle
    Position pos = g_core.trainers.newPosition[p_id];
    for (uint16_t id = 0; id < MAX_ENTITY_TRAINER_COUNT; id++)
    {
        if (!GetBit(onMap, id)) continue;
        if (id == p_id) continue;
        Position t_pos = g_core.trainers.newPosition[id];
        if (t_pos.x == pos.x && t_pos.y == pos.y)
            StartBattleTrainer(id);
    }


    // CREATURES
    speed = GetCreatureSpeeds(CREATURE);
    onMap = GetEntitiesOnMap(CREATURE);

    for (uint16_t id = 0; id < MAX_ENTITY_CREATURE_COUNT; id++)
    {
        if (!GetBit(onMap, id)) continue; //need to make sure this only triggers for dynamic map entities

        uint8_t max = speed[id].max;
        uint8_t cur = speed[id].current;

        if (cur + player_speed < max)
        {
            speed[id].current += player_speed;
            continue;
        }
#if defined(TEST_MAP)
        g_core.creatures.newPosition[id] = g_core.creatures.position[id];
#else
        CreatureAI(hardware, id, CREATURE);
#endif
        speed[id].current = player_speed - (max - cur);
    }

    // check for battle

    for (uint16_t id = 0; id < MAX_ENTITY_CREATURE_COUNT; id++)
    {
        if (!GetBit(onMap, id)) continue;
        Position t_pos = g_core.creatures.newPosition[id];
        if (t_pos.x == pos.x && t_pos.y == pos.y)
            StartBattleCreature(id);
    }


    return true;
}

/**********************************************************************************************************************/
/**Iterates through all entities sets position to the queued position
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdateObjectCollision(MemoryInterface memory, HardwareInterface hardware)
{
    g_map.objectCollision = NO_OBJECT;
    g_map.itemCollision = NO_ITEM;
    if (g_core.update_right_text)
    {
        g_core.update_right_text = false;
        g_core.update_right_text_clear = true;
    }

    for (uint16_t e_id = 0; e_id < MAX_ENTITY_TRAINER_COUNT; e_id++)
    {
        for (uint16_t o_id = 0; o_id < MAX_ENTITY_OBJECT_COUNT; o_id++)
        {
            if (!GetBit(g_core.trainers.onMap, e_id) || !GetBit(g_core.trainers.active, e_id) || !GetBit(g_core.objects.active, o_id)) continue;
            Position cp = g_core.trainers.newPosition[e_id];
            Position op = g_core.objects.position[o_id];
            if (cp.x == op.x && cp.y == op.y)
            {
                InteractObjectStepOn(memory, hardware, o_id, e_id, TRAINER);
                if (e_id == GetPlayerID())
                {
                    if (GetBit(g_core.objects.interactable, o_id))
                    {
                        g_map.objectCollision = g_core.objects.types[o_id];
                    }
                }
            }
        }
    }

    for (uint16_t e_id = 0; e_id < MAX_ENTITY_CREATURE_COUNT; e_id++)
    {
        for (uint16_t o_id = 0; o_id < MAX_ENTITY_OBJECT_COUNT; o_id++)
        {
            if (!GetBit(g_core.creatures.onMap, e_id) || !GetBit(g_core.creatures.active, e_id) || !GetBit(g_core.objects.active, o_id)) continue;
            Position cp = g_core.creatures.newPosition[e_id];
            Position op = g_core.objects.position[o_id];
            if (cp.x == op.x && cp.y == op.y)
            {
                InteractObjectStepOn(memory, hardware, o_id, e_id, CREATURE);
            }
        }
    }

    for (uint16_t e_id = 0; e_id < MAX_ENTITY_TRAINER_COUNT; e_id++)
    {
        for (uint16_t o_id = 0; o_id < MAX_ENTITY_ENVIRONMENT_OBJECT_COUNT; o_id++)
        {
            if (!GetBit(g_core.trainers.onMap, e_id) || !GetBit(g_core.trainers.active, e_id) || !GetBit(g_core.environment_objects.active, o_id)) continue;
            Position cp = g_core.trainers.newPosition[e_id];
            Position op = g_core.environment_objects.position[o_id];
            if (cp.x == op.x && cp.y == op.y)
            {
                InteractEnvinronmentObjectStepOn(memory, hardware, o_id, e_id, TRAINER);
                if (e_id == GetPlayerID())
                {
                    if (GetBit(g_core.environment_objects.interactable, o_id))
                    {
                        g_map.objectCollision = g_core.environment_objects.types[o_id];
                    }
                }
            }
        }
    }

    for (uint16_t e_id = 0; e_id < MAX_ENTITY_CREATURE_COUNT; e_id++)
    {
        for (uint16_t o_id = 0; o_id < MAX_ENTITY_ENVIRONMENT_OBJECT_COUNT; o_id++)
        {
            if (!GetBit(g_core.creatures.onMap, e_id) || !GetBit(g_core.creatures.active, e_id) || !GetBit(g_core.environment_objects.active, o_id)) continue;
            Position cp = g_core.creatures.newPosition[e_id];
            Position op = g_core.environment_objects.position[o_id];
            if (cp.x == op.x && cp.y == op.y)
            {
                InteractEnvinronmentObjectStepOn(memory, hardware, o_id, e_id, CREATURE);
            }
        }
    }

    Position pos = GetPlayerPosition();
    for (uint16_t i_id = 0; i_id < MAX_ENTITY_ITEM_COUNT; i_id++)
    {
        if (!GetBit(g_core.items.onMap, i_id) || !GetBit(g_core.items.active, i_id)) continue;
        Position op = g_core.items.position[i_id];
        if (pos.x == op.x && pos.y == op.y)
        {
            g_map.itemCollision = g_core.items.types[i_id];
            break;
        }
    }
}


/**********************************************************************************************************************/
/**Iterates through all entities sets position to the queued position
**********************************************************************************************************************/
SET_MEMORY(".map")
void SetPositions(HardwareInterface hardware, MemoryInterface memory, AudioInterface audio)
{
    //  trainer
    uint8_t* onMap = GetEntitiesOnMap(TRAINER); //array is 256 bytes
    Position* position = GetEntityPositions(TRAINER); //array is 512 bytes
    Position* newPosition = GetEntityNewPositions(TRAINER); //array is 512 bytes
    uint8_t tileID;

    for (uint16_t id = 0; id < MAX_ENTITY_TRAINER_COUNT; id++)
    {
        if (!GetBit(onMap, id)) continue;

        Position pos = position[id];
        Position nPos = newPosition[id];

        uint8_t x = pos.x;
        uint8_t y = pos.y;

        uint8_t nx = nPos.x;
        uint8_t ny = nPos.y;

        //check current tile
        tileID = GetMapTile(x, y);
        if (!CheckInteractionStepOff(hardware, memory, audio, tileID, id, TRAINER, x, y))
            continue;

        //check next tile
        tileID = GetMapTile(nx, ny);
        if (CheckInteractionStepOn(hardware, memory, audio, tileID, id, TRAINER, nx, ny))
            SetEntityPosition(TRAINER, id, x, y, nx, ny);
    }

    //  creature
    onMap = GetEntitiesOnMap(CREATURE); //array is 256 bytes
    position = GetEntityPositions(CREATURE); //array is 512 bytes
    newPosition = GetEntityNewPositions(CREATURE); //array is 512 bytes

    for (uint16_t id = 0; id < MAX_ENTITY_CREATURE_COUNT; id++)
    {
        if (!GetBit(onMap, id)) continue;

        Position pos = position[id];
        Position nPos = newPosition[id];

        uint8_t x = pos.x;
        uint8_t y = pos.y;

        uint8_t nx = nPos.x;
        uint8_t ny = nPos.y;

        //check current tile
        tileID = GetMapTile(x, y);
        CheckInteractionStepOff(hardware, memory, audio, tileID, id, CREATURE, x, y);

        //check next tile
        tileID = GetMapTile(nx, ny);
        if (CheckInteractionStepOn(hardware, memory, audio, tileID, id, CREATURE, nx, ny))
            SetEntityPosition(CREATURE, id, x, y, nx, ny);
    }

    // DEBUG("Updating Object done");
}

SET_MEMORY(".map")
void PlayerMovementSoundEffect(AudioInterface audio)
{
    Position p = GetPlayerPosition();
    uint8_t tileID = GetMapTile(p.x, p.y);
    uint16_t sound_id = GetTileSoundId(tileID);
    audio.PlaySoundEffect(sound_id);
}


SET_MEMORY(".map")
void UpdateEnvironmentObjects(HardwareInterface hardware)
{
    for (uint16_t i = 0; i < MAX_ENTITY_ENVIRONMENT_OBJECT_COUNT; i++)
    {
        if (!GetBit(g_core.environment_objects.onMap, i)) continue;
        if (!GetBit(g_core.environment_objects.active, i)) continue;

        uint8_t random = hardware.GetRandom_uint8_t(1, 100);
        if (random > 10) continue;

        DestroyEnvironmentObject(i);
    }
}

/**********************************************************************************************************************/
/** //execute passive tile effect
    //acid clouds from acid tiles and pits
    //smoke clouds from lava tiles and pits
    //mist clouds from water
**********************************************************************************************************************/
SET_MEMORY(".map")
void CheckTileForEffect(MemoryInterface memory, HardwareInterface hardware, uint8_t x, uint8_t y, uint8_t environment_object_type)
{
    uint8_t n = 0;
    Position pos[8] = {0};

    MapTile tile_N = GetMapTile(x, y - 1);
    MapTile tile_S = GetMapTile(x, y + 1);
    MapTile tile_W = GetMapTile(x - 1, y);
    MapTile tile_E = GetMapTile(x + 1, y);
    // MapTile tile_NW = GetMapTile(x - 1, y - 1);
    // MapTile tile_NE = GetMapTile(x + 1, y - 1);
    // MapTile tile_SE = GetMapTile(x + 1, y + 1);
    // MapTile tile_SW = GetMapTile(x - 1, y + 1);

    if (tile_N == FLOOR_DIRT)
        pos[n++] = (Position){x, y - 1};
    if (tile_S == FLOOR_DIRT)
        pos[n++] = (Position){x, y + 1};
    if (tile_W == FLOOR_DIRT)
        pos[n++] = (Position){x - 1, y};
    if (tile_E == FLOOR_DIRT)
        pos[n++] = (Position){x + 1, y};

    // if (tile_NW == FLOOR_DIRT)
    //     pos[n++] = (Position){x - 1, y - 1};
    // if (tile_NE == FLOOR_DIRT)
    //     pos[n++] = (Position){x + 1, y - 1};
    // if (tile_SE == FLOOR_DIRT)
    //     pos[n++] = (Position){x + 1, y + 1};
    // if (tile_SW == FLOOR_DIRT)
    //     pos[n++] = (Position){x - 1, y + 1};


    if (n > 0)
    {
        uint8_t g = (n - 1) + 8;
        uint8_t random = hardware.GetRandom_uint8_t(0, g);
        if (random < (n - 1)) return;
        random = random - 8;
        Position p = pos[random];
        if (GetMapTile(pos[random].x, pos[random].y) == FLUID_WATER)
            DEBUG("water");

        if (CheckTileForEntity(ENVIRONMENT_OBJECT, NO_ENTITY, p))
            SpawnEntity(hardware, memory, ENVIRONMENT_OBJECT, environment_object_type, p.x, p.y, g_core.floor);
    }
}


SET_MEMORY(".map")
void UpdateTileEffects(MemoryInterface memory, HardwareInterface hardware)
{
    for (uint16_t y = 0; y < MAP_H; y++)
    {
        for (uint16_t x = 0; x < MAP_W; x++)
        {
            MapTile tile = GetMapTile(x, y);
            switch (tile)
            {
            case FLUID_LAVA:
                {
                    CheckTileForEffect(memory, hardware, x, y, CLOUD_SMOKE);
                    break;
                }
            case FLUID_WATER:
                {
                    CheckTileForEffect(memory, hardware, x, y, CLOUD_ACID);
                    break;
                }
            case FLUID_ACID:
                {
                    CheckTileForEffect(memory, hardware, x, y, CLOUD_ACID);
                    break;
                }
            default:
                {
                    break;
                }
            }
        }
    }
}


/**********************************************************************************************************************/
/** Main update
 *  call every frame
**********************************************************************************************************************/
SET_MEMORY(".map")
void UpdateGame(MemoryInterface memory, HardwareInterface hardware, AudioInterface audio)
{
    UpdateTileEffects(memory, hardware);
    UpdateEnvironmentObjects(hardware);
    UpdateObjectStatusEffects(hardware);
    UpdatePositions(hardware);
    UpdateObjectCollision(memory, hardware);
    SetPositions(hardware, memory, audio);
    PlayerMovementSoundEffect(audio);
    SetCameraPlayer();
}
