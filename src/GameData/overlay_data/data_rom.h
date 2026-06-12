//
// Created by nathanial on 2/26/26.
//
#pragma once
#include "types.h"
#include "enums.h"
#include "data_constants.inc"

#define TOTAL_MUSIC_NOTES 815
#define MUSIC_COUNT 1


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
ASSERT_ALIGNED16(SPRITE_CREATURE_FRONT_BYTES_16);
ASSERT_ALIGNED16(SPRITE_CREATURE_BACK_BYTES_16);
ASSERT_ALIGNED16(SMALL_STRINGS);
ASSERT_ALIGNED16(LARGE_STRINGS);
_Static_assert(ITEM_COUNT <= 256, "MAX_ITEMS must Be less than or equal to 256");
_Static_assert(OBJECT_COUNT <= 256, "MAX_ITEMS must Be less than or equal to 256");
_Static_assert(CREATURE_COUNT <= 256, "CREATURE_COUNT must be less than or equal to 256");
_Static_assert(SPELL_COUNT <= 256, "TOTAL_SPELLS must be less than or equal to 256");
_Static_assert(ABILITY_COUNT <= 256, "TOTAL_ATTACKS must be less than or equal to 256");
_Static_assert(ENTITY_COUNT <= 256, "TOTAL_ATTACKS must be less than or equal to 256");
