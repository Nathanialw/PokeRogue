//
// Created by nathanial on 2/21/26.
//
#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "types.h"


bool CheckInteraction(uint8_t tile, EntityId id, uint8_t x, uint8_t y);
void ObjectCollision(EntityId id);

