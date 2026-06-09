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
bool Flash_GetSkillEffect(HardwareInterface hardware, MemoryInterface memory, uint8_t skillType, EntityId id, EntityId target_id, SkillData skillData)
{
    return abilityFunctions[skillType](hardware, memory, id, target_id, skillData);
}


SET_MEMORY(".battle")
bool CastBattleSpell(HardwareInterface hardware, MemoryInterface memory, uint8_t spellType, EntityId id, EntityId target_id, SpellData spellData)
{
    return spellFunctionsBattle[spellType](hardware, memory, id, target_id, spellData);
}


SET_MEMORY(".battle")
bool UseBattleItem(HardwareInterface hardware, MemoryInterface memory, uint8_t itemType, EntityId item_id, EntityId id, ItemData itemData)
{
    return itemFunctionsBattle[itemType](hardware, memory, item_id, id, itemData);
}
