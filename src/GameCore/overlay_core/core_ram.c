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

    // .player.currentSpellbookSize = 0,
    // .player.currentSpellbookMaxSize = DEFAULT_SPELLBOOK_SIZE,
    .player.vision_radius = DEFAULT_LIGHT_RADIUS,

    // .player.occupiedBagSlots = 0,
    // .player.currentBagMaxSize = DEFAULT_BAG_SIZE,

    .state.running = 1,
    .player.id = NO_ENTITY,
    .battleMode.enemy_trainer_id = NO_ENTITY,
};
