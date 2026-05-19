//
// Created by nathanial on 5/19/26.
//
#include "core_ram.h"
#include "inc/decl_items.inc"
#include "inc/decl_spells.inc"


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


SET_MEMORY(".map_gen")
void GameRunInit()
{
    g_core.floor = 0;
    g_core.settings.fontSize = FONT8x8;

    g_core.btns.gameSpeed = 10; //200
    g_core.btns.defaultGameLoopRate = 12;
    g_core.btns.gameLoopRate = 12;

    g_core.menu.selectedMenu = MAIN_MENU;
    g_core.menu.displayedMenu = MENU_NONE;
    g_core.menu.visibleMenuOptions = MAIN_MENUS_SIZE;
    g_core.menu.forceRedraw = true;
    g_core.menu.lineHeight = 0;

    g_core.menu.gameMenu.open = false;
    g_core.menu.gameMenu.displayId = NO_CREATURE;
    g_core.menu.gameMenu.id = NO_CREATURE;
    g_core.menu.menuSleepTime = 200; //200

    g_core.music.master_volume = 32768;
}
