//
// Created by nathanial on 2/20/26.
//
#pragma once
#include "common/types.h"
#include "lib_types.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
EntityId CheckCollision(EntityId id, ObjectsTypes type);

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
IntMax99* GetCreatureSpeeds(ObjectsTypes type);
Position* GetEntityPositions(ObjectsTypes type);
Position* GetEntityNewPositions(ObjectsTypes type);
uint8_t* GetEntitiesOnMap(ObjectsTypes type);
BitFieldUint8* GetCreaturesAlive(void);


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
Position GetEntityPosition(ObjectsTypes type, EntityId id);
Position SetEntityPosition(ObjectsTypes type, EntityId id, uint8_t x, uint8_t y, uint8_t nx, uint8_t ny);
Position QueueObjectMovePosition(EntityId id, uint8_t x, uint8_t y);
void ResetEntities(HardwareInterface hardware, MemoryInterface memory, bool copyPlayer);
bool InDetectionRange(EntityId id, EntityId targetID);

bool CheckCreatureDead(EntityId creature_id);