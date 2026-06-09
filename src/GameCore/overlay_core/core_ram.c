//
// Created by nathanial on 5/19/26.
//
#include "core_ram.h"

#include "lib_memory.h"








SET_MEMORY(".core.data")
CoreRunState g_core = {
    .floor = 1,
    .initialized = false,
    .btns.defaultGameLoopRate = 10,
    .btns.gameLoopRate = 10,
    .player.vision_radius = 7,
    .state.running = 1,
    .player.id = NO_ENTITY,
};


