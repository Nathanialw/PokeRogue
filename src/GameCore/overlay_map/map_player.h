//
// Created by nathanial on 5/19/26.
//

#pragma once
#include "lib_decl.h"
#include "types.h"


void InitPlayer(HardwareInterface hardware, MemoryInterface memory);
EntityId CachePlayerCreatureData(HardwareInterface hardware);
EntityId CachePlayerItemData();
Position GetPlayerPosition(void);
void UpdatePlayerPosition(void);
Delta SetPlayerDelta(Delta newDelta);
void PlacePlayerOnMap(HardwareInterface hardware);
void PlayerInteractItemInCell();
void PlayerInteractObjectInCell(MemoryInterface memory, HardwareInterface hardware);
