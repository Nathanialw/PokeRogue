//
// Created by nathanial on 5/19/26.
//

#include "generate_map_state.h"

#include "core_map.h"
#include "lib_memory.h"
#include "lib_decl.h"

#include "core_ram.h"

#include "generate_map.h"
#include "generate_map_entities.h"
#include "generate_map_river.h"
#include "map_entities.h"


SET_MEMORY(".map_gen")
void GameRunInit(HardwareInterface hardware, MemoryInterface memory)
{
    g_core.floor = 1;
    g_core.settings.fontSize = FONT16x16;

    g_core.btns.gameSpeed = 10; //200
    g_core.btns.defaultGameLoopRate = 12;
    g_core.btns.gameLoopRate = 12;

    g_core.menu.selectedMenu = MAIN_MENU;
    g_core.menu.displayedMenu = MENU_NONE;
    g_core.menu.max_visible_menu_options = MAIN_MENUS_SIZE;
    g_core.menu.forceRedraw = true;
    g_core.menu.lineHeight = 0;

    g_core.menu.gameMenu.open = false;
    g_core.menu.gameMenu.displayId = NO_CREATURE;

    g_core.menu.gameMenu.id = NO_CREATURE;
    g_core.menu.menuSleepTime = 200; //200
    g_core.player.currentPartySize = 1; //1
    g_core.battleMode.enemy_trainer_id = NO_ENTITY; //1

    g_core.music.master_volume = 32768;

    g_core.initialized = true;

    ResetEntities(hardware, memory, false);
}


SET_MEMORY(".map_gen")
void InitGame(HardwareInterface hardware, MemoryInterface memory)
{
    InitMap(hardware);
    GenerateLake(hardware, 30, 30, 10, FLUID_WATER);
    SetMapBorder();
}


SET_MEMORY(".map_gen_entry")
uint8_t OverlayMapGenEntry(GameInterface* spi)
{
    if (!g_core.initialized) GameRunInit(spi->hardware, spi->memory);
    else ResetEntities(spi->hardware, spi->memory, true);

    InitGame(spi->hardware, spi->memory);
    GenerateEntities(spi);
    SetMapFog(0);


    g_core.state.overlay = OVERLAY_MAP;
    return OVERLAY_MAP;;
}
