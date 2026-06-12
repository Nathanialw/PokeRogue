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

#define MAX_DEAD_CREATURES_CACHED 16

typedef struct
{
    State state;
    uint8_t effect_animation_index;
    ObjectsTypes effect_type;
    EntityId dead_creatures[MAX_DEAD_CREATURES_CACHED]; // picked 16 arbitrarily, no sure how many slots will be needed yet
    bool enemy_captured;
    bool show_party;
    bool pass_turn;
} BattleRunState;

extern BattleRunState g_battle; // Declaration only


ActionOutcome Flash_GetSkillEffect(HardwareInterface hardware, MemoryInterface memory, uint8_t skillType, EntityId trainer_id, EntityId party_id, EntityId target_id, SkillData skillData);
ActionOutcome CastBattleSpell(HardwareInterface hardware, MemoryInterface memory, SpellId spell_id, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData);
ActionOutcome UseBattleItem(HardwareInterface hardware, MemoryInterface memory, uint8_t itemType, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index);
