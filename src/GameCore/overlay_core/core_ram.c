//
// Created by nathanial on 5/19/26.
//
#include "core_ram.h"
#include "inc/decl_items.inc"
#include "inc/decl_spells.inc"
#include "lib_memory.h"


SET_MEMORY(".core.rodata")
const SpellEffect spellFunctions[SPELL_COUNT] = {
#include "inc/funcs_spells.inc"
};

SET_MEMORY(".core.rodata")
const ItemEffect itemFunctions[ITEM_COUNT] = {
#include "inc/funcs_items.inc"
};


SET_MEMORY(".core.data")
CoreRunState g_core = {0};

