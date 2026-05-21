//
// Created by nathanial on 5/19/26.
//

#include "generate_map_state.h"

#include "lib_memory.h"
#include "lib_decl.h"

#include "core_ram.h"

#include "generate_map.h"





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


SET_MEMORY(".map_gen")
void InitGame(HardwareInterface hardware, MemoryInterface memory)
{
    GameRunInit();
    InitMap(hardware);
}


SET_MEMORY(".map_gen_entry")
uint8_t MapGenEntry(GameInterface* spi)
{
    InitGame(spi->hardware, spi->memory);

    g_core.state.overlay = OVERLAY_MAP;
    return OVERLAY_MAP;;
}

