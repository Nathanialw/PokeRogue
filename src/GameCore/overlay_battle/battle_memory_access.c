//
// Created by nathanial on 5/19/26.
//

#include "battle_memory_access.h"
#include "lib_memory.h"

#include "lib_decl.h"
#include "types.h"
#include "data_constants_memory.inc"


#include "battle_ram.h"


const char text99[] = "0%2x ";
const char new_line1[] = "\n";


/**********************************************************************************************************************/
/*      ANIMATIONS
**********************************************************************************************************************/
// TODO:
SET_MEMORY(".battle")
void Flash_BattlerAttackAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, EntityId id, ObjectsTypes type, bool player)
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
        itemsAttack[id](graphics, hardware, memory, player);
    else if (type == SKILL)
        skillsAttack[id](graphics, hardware, memory, player);
    else if (type == SPELL)
        spellsAttack[id](graphics, hardware, memory, player);

#endif
}

// TODO:
SET_MEMORY(".battle")
void Flash_BattlerStruckAnimation(GraphicsInterface graphics, HardwareInterface hardware, MemoryInterface memory, EntityId id, ObjectsTypes type, bool player)
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
        itemsStruck[id](graphics, hardware, memory, player);
    else if (type == SKILL)
        skillsStruck[id](graphics, hardware, memory, player);
    else if (type == SPELL)
        spellsStruck[id](graphics, hardware, memory, player);

#endif
}






SET_MEMORY(".battle")
void Flash_GetBattleMenuList(MemoryInterface memory, uint8_t* text, uint8_t idx)
{
#ifdef STANDALONE
    return g_gameFlash.text.menus.battleMenu[idx];
#else
    memory.GetRom(STRINGS_MENU_BATTLE_POSITION + (SMALL_STRINGS * idx), text, SMALL_STRINGS);


#endif
}

