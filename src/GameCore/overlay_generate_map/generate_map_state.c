//
// Created by nathanial on 5/19/26.
//

#include "generate_map_state.h"

#include "core_ram.h"
#include "generate_map.h"
#include "lib_decl.h"


SET_MEMORY(".map_gen.rodata")
static const char str_map_gen_entry_entry[] = "Going to map_gen_entry";



SET_MEMORY(".map_gen")
void InitGame(HardwareInterface hardware, MemoryInterface memory)
{
    GameRunInit();
    InitMap(hardware);
}


SET_MEMORY(".map_gen_entry")
uint8_t GameLoopEntry(GameInterface* spi)
{
    spi->graphics.FillScreen(0x000F); // TODO: update to real title screen
    spi->hardware.Print(str_map_gen_entry_entry);

    InitGame(spi->hardware, spi->memory);
    return GAME_MAP;;
}

