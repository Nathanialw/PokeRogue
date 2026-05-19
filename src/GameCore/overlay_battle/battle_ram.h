//
// Created by nathanial on 5/19/26.
//
#pragma once
#include "data_constants.inc"
#include "lib_types.h"
#include "types.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
extern const Battle_Animation itemsAttack[ITEM_COUNT];
extern const Battle_Animation itemsStruck[ITEM_COUNT];
extern const Battle_Animation spellsAttack[SPELL_COUNT];
extern const Battle_Animation spellsStruck[SPELL_COUNT];
extern const Battle_Animation skillsAttack[ABILITY_COUNT];
extern const Battle_Animation skillsStruck[ABILITY_COUNT];

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
extern const SkillEffect abilityFunctions[ABILITY_COUNT];

typedef struct
{
    State state;
} BattleRunState;

extern BattleRunState g_battle; // Declaration only
