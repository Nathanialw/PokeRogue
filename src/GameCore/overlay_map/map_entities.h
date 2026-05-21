//
// Created by nathanial on 2/20/26.
//
#pragma once
#include "common/types.h"
#include "lib_types.h"



/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
uint8_t CheckCollision(EntityId id);
EntityId CheckTileForEntity(ObjectsTypes type, EntityId e_id, Position pos);

EntityId SpawnEntity(HardwareInterface hardware, MemoryInterface memory, ObjectsTypes type, uint8_t t, uint8_t x, uint8_t y, uint8_t l);

void CopyCreature(HardwareInterface hardware, EntityId src_id, EntityId target_id);
void DestroyObject(EntityId id);
void CopyItem(EntityId src_id, EntityId target_id);
void CopyObject(EntityId src_id, EntityId target_id);
void PopulateLevelCreatures(HardwareInterface hardware, MemoryInterface memory);
void PopulateLevelItems(HardwareInterface hardware, MemoryInterface memory);
void PopulateLevelObjects(HardwareInterface hardware, MemoryInterface memory);


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
IntMax99* GetCreatureSpeeds(void);
Position* GetEntityPositions(ObjectsTypes type);
Position* GetEntityNewPositions(void);
uint8_t* GetEntitiesOnMap(ObjectsTypes type);
BitFieldUint8* GetCreaturesAlive(void);



/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
Position GetEntityPosition(ObjectsTypes type, EntityId id);
Position SetEntityPosition(ObjectsTypes type, EntityId id, uint8_t x, uint8_t y, uint8_t nx, uint8_t ny);
Position QueueObjectMovePosition(EntityId id, uint8_t x, uint8_t y);
void ResetEntities(HardwareInterface hardware, MemoryInterface memory, bool copyPlayer);
EntityId GetPlayerID(void);
bool InDetectionRange(EntityId id, EntityId targetID);