//
// Created by nathanial on 5/19/26.
//
#include "battle_ram.h"

#include "lib_memory.h"

#include "data_constants.inc"

#include "inc/decl_skills_Skill.inc"
#include "inc/decl_animation_items_attack.inc"
#include "inc/decl_animation_skills_attack.inc"
#include "inc/decl_animation_spells_attack.inc"
#include "inc/decl_animation_items_struck.inc"
#include "inc/decl_animation_skills_struck.inc"
#include "inc/decl_animation_spells_struck.inc"

#include "inc/decl_spells_CastBattle.inc"
#include "inc/decl_items_UseBattle.inc"

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
#include "inc/funcs_skills_Skill.inc"
};


SET_MEMORY(".battle.rodata")
const SpellEffect spellFunctionsBattle[SPELL_COUNT] = {
#include "inc/funcs_spells_CastBattle.inc"
};

SET_MEMORY(".battle.rodata")
const ItemEffect itemFunctionsBattle[ITEM_COUNT] = {
#include "inc/funcs_items_UseBattle.inc"
};


SET_MEMORY(".battle.data")
BattleRunState g_battle = {
    .effect_type = NO_OBJECT_TYPE,
};


/**********************************************************************************************************************/
/**     FUNCTIONS
**********************************************************************************************************************/
SET_MEMORY(".battle")
ActionOutcome Flash_GetSkillEffect(HardwareInterface hardware, MemoryInterface memory, uint8_t skillType, EntityId trainer_id, EntityId party_id, EntityId target_id, SkillData skillData)
{
    return abilityFunctions[skillType](hardware, memory, trainer_id, party_id, target_id, skillData);
}


SET_MEMORY(".battle")
ActionOutcome CastBattleSpell(HardwareInterface hardware, MemoryInterface memory, SpellId spell_id, EntityId caster_id, EntityId friendly_id, EntityId enemy_id, SpellData spellData)
{
    return spellFunctionsBattle[spell_id](hardware, memory, caster_id, friendly_id, enemy_id, spellData);
}


SET_MEMORY(".battle")
ActionOutcome UseBattleItem(HardwareInterface hardware, MemoryInterface memory, uint8_t itemType, EntityId item_id, EntityId user_id, EntityId target_id, ItemData itemData, uint8_t index)
{
    return itemFunctionsBattle[itemType](hardware, memory, item_id, user_id, target_id, itemData, index);
}
