//
// Created by nathanial on 5/19/26.
//
#include "battle_ram.h"

#include "lib_memory.h"

#include "data_constants.inc"
#include "inc/decl_skills.inc"
#include "inc/decl_animation_items_attack.inc"
#include "inc/decl_animation_skills_attack.inc"
#include "inc/decl_animation_spells_attack.inc"
#include "inc/decl_animation_items_struck.inc"
#include "inc/decl_animation_skills_struck.inc"
#include "inc/decl_animation_spells_struck.inc"

#include "types.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle.rodata")
const Battle_Animation itemsAttack[ITEM_COUNT] = {
#include "inc/funcs_animation_items_attack.inc"
};
SET_MEMORY(".battle.rodata")
const Battle_Animation itemsStruck[ITEM_COUNT] = {
#include "inc/funcs_animation_items_struck.inc"
};
SET_MEMORY(".battle.rodata")
const Battle_Animation spellsAttack[SPELL_COUNT] = {
#include "inc/funcs_animation_spells_attack.inc"
};
SET_MEMORY(".battle.rodata")
const Battle_Animation spellsStruck[SPELL_COUNT] = {
#include "inc/funcs_animation_spells_struck.inc"
};
SET_MEMORY(".battle.rodata")
const Battle_Animation skillsAttack[ABILITY_COUNT] = {
#include "inc/funcs_animation_skills_attack.inc"
};
SET_MEMORY(".battle.rodata")
const Battle_Animation skillsStruck[ABILITY_COUNT] = {
#include "inc/funcs_animation_skills_struck.inc"
};

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".battle.rodata")
const SkillEffect abilityFunctions[ABILITY_COUNT] = {
#include "inc/funcs_skills.inc"
};



SET_MEMORY(".battle.data")
BattleRunState g_battle = {0};

