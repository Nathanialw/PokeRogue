//
// Created by nathanial on 5/19/26.
//
#include "map_ram.h"

#include "inc/decl_objects.inc"


SET_MEMORY(".map.rodata")
const ObjectEffect objectFunctions[OBJECT_COUNT] = {
#include "inc/funcs_objects.inc"
};


SET_MEMORY(".map.data")
MapRunState g_map = {0};