//
// Created by nathanial on 5/19/26.
//
#include "map_ram.h"
#include "lib_memory.h"

#include "inc/decl_objects.inc"



SET_MEMORY(".map.rodata")
const ObjectEffect objectFunctions[OBJECT_COUNT] = {
#include "inc/funcs_objects.inc"
};


SET_MEMORY(".map.data")
MapRunState g_map = {
    .power = "Powr:\0",
    .rarity = "Rare:\0",

    .objectCollision = NO_OBJECT,
    .itemCollision = NO_ITEM,
    .clearTooltip = false,
};
