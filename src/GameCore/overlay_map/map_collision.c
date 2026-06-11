//
// Created by nathanial on 2/21/26.
//

#include "map_collision.h"

#include "core_effects.h"
#include "lib_memory.h"

#include "core_player.h"
#include "core_ram.h"
#include "decl_tiles_TIleStepOff.inc"
#include "decl_tiles_TIleStepOn.inc"

#include "map_entities.h"


/**********************************************************************************************************************/
/*
 *  This file handles map tile interaction logic
 *
**********************************************************************************************************************/
typedef bool (*Interaction)(HardwareInterface hardware, MemoryInterface memory, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);


bool NoInteraction(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Wall(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool Pit(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);
bool CollisionFluidTile(EntityId id, ObjectsTypes type, uint8_t x, uint8_t y);


SET_MEMORY(".map.rodata")
const Interaction TileCollisionStepOn[TILE_COUNT] =
{
#include "funcs_tiles_TIleStepOn.inc"
};

SET_MEMORY(".map.rodata")
const Interaction TileCollisionStepOff[TILE_COUNT] =
{
#include "funcs_tiles_TIleStepOff.inc"

};


/**********************************************************************************************************************/
/** Main tile interaction entry point
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CheckInteractionStepOn(HardwareInterface hardware, MemoryInterface memory, uint8_t tile, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return TileCollisionStepOn[tile](hardware, memory, id, type, x, y);
}


/**********************************************************************************************************************/
/** Main tile interaction entry point
**********************************************************************************************************************/
SET_MEMORY(".map")
bool CheckInteractionStepOff(HardwareInterface hardware, MemoryInterface memory, uint8_t tile, EntityId id, ObjectsTypes type, uint8_t x, uint8_t y)
{
    return TileCollisionStepOff[tile](hardware, memory, id, type, x, y);
}

/**********************************************************************************************************************/
/** Triggers the battle state
**********************************************************************************************************************/
SET_MEMORY(".map")
void StartBattleTrainer(EntityId id)
{
    g_core.battleMode.enemy_trainer_id = id;

    g_core.battleMode.playerMonsterID = g_core.trainers.partyID[GetPlayerID()][0];
    g_core.battleMode.enemyMonsterID = g_core.trainers.partyID[id][0];

    g_core.state.overlay = OVERLAY_BATTLE;
}


/**********************************************************************************************************************/
/** Triggers the battle state
**********************************************************************************************************************/
SET_MEMORY(".map")
void StartBattleCreature(EntityId id)
{
    g_core.battleMode.enemy_trainer_id = NO_ENTITY;

    g_core.battleMode.playerMonsterID = g_core.trainers.partyID[GetPlayerID()][0];
    g_core.battleMode.enemyMonsterID = id;

    g_core.state.overlay = OVERLAY_BATTLE;
}
