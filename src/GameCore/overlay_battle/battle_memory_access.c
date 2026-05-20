//
// Created by nathanial on 5/19/26.
//

#include "battle_memory_access.h"
#include "lib_memory.h"

#include "lib_decl.h"
#include "types.h"
#include "memory_constants.inc"

#include "battle_ram.h"



//TODO:
SET_MEMORY(".battle")
SpriteLayout Flash_GetBattlerLayout(MemoryInterface memory, uint8_t creatureType, bool front)
{
#ifdef STANDALONE
    if (front)
        return g_gameFlash.spriteData.battlers.frontLayout[creatureType];
    else
        return g_gameFlash.spriteData.battlers.backLayout[creatureType];
#else
    SpriteLayout l = {0};
    return l;
#endif
}

//TODO:
SET_MEMORY(".battle")
const uint8_t* Flash_GetBattlerArray(MemoryInterface memory, bool front)
{
#ifdef STANDALONE
    if (front)
        return g_gameFlash.spriteData.battlers.front;
    else
        return g_gameFlash.spriteData.battlers.back;
#else
    return NULL;
#endif
}



/**********************************************************************************************************************/
/*      ANIMATIONS
**********************************************************************************************************************/
// TODO:
SET_MEMORY(".battle")
void Flash_BattlerAttackAnimation(MemoryInterface memory, EntityId id, ObjectsTypes type, bool player)
{
#ifdef STANDALONE
    if (type == ITEM)
        g_gameFlash.animation.itemsAttack[id](player);
    else if (type == SKILL)
        g_gameFlash.animation.skillsAttack[id](player);
    else if (type == SPELL)
        g_gameFlash.animation.spellsAttack[id](player);
#else
    if (type == ITEM)
        itemsAttack[id](player);
    else if (type == SKILL)
        skillsAttack[id](player);
    else if (type == SPELL)
        spellsAttack[id](player);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(ObjectsTypes); i++)
        memory.Print(str_spawn_creature_type);
    memory.Print(new_line);
#endif
#endif
}

// TODO:
SET_MEMORY(".battle")
void Flash_BattlerStruckAnimation(MemoryInterface memory, EntityId id, ObjectsTypes type, bool player)
{
#ifdef STANDALONE
    if (type == ITEM)
        g_gameFlash.animation.itemsStruck[id](player);
    else if (type == SKILL)
        g_gameFlash.animation.skillsStruck[id](player);
    else if (type == SPELL)
        g_gameFlash.animation.spellsStruck[id](player);
#else
    if (type == ITEM)
        itemsStruck[id](player);
    else if (type == SKILL)
        skillsStruck[id](player);
    else if (type == SPELL)
        spellsStruck[id](player);

#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < sizeof(ObjectsTypes); i++)
        memory.Print(str_spawn_creature_type);
    memory.Print(new_line);
#endif
#endif
}




/**********************************************************************************************************************/
/**     FUNCTIONS
**********************************************************************************************************************/
SET_MEMORY(".battle")
bool Flash_GetSkillEffect(MemoryInterface memory, uint8_t skillType, EntityId id, EntityId target_id, SkillData skillData)
{
#ifdef STANDALONE
    return g_gameFlash.funcs.abilityFunctions[skillType](id, target_id, skillData);
#else
    return abilityFunctions[skillType](id, target_id, skillData);
#endif
}




SET_MEMORY(".battle")
void Flash_GetBattleMenuList(MemoryInterface memory, uint8_t* text, uint8_t idx)
{
#ifdef STANDALONE
    return g_gameFlash.text.menus.battleMenu[idx];
#else
    memory.GetRom(STRINGS_MENU_BATTLE_POSITION + (SMALL_STRINGS * idx), text, SMALL_STRINGS);


#if defined(MEMORY_PRINT)
    for (uint8_t i = 0; i < SMALL_STRINGS; i++)
        memory.Print(str_spawn_creature_type, text[i]);
    memory.Print(new_line);
#endif
#endif
}

