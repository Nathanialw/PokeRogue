//
// Created by nathanial on 5/19/26.
//

#include "splash_state.h"

#include "lib_decl.h"
#include "enums.h"



#define TITLE_RATE_DELAY 500


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".splash")
void TitleRateDelay(HardwareInterface hardware)
{
    hardware.SleepMS(TITLE_RATE_DELAY);
}



SET_MEMORY(".splash")
bool UpdateGameTitleState(InputInterface input)
{
    if (input.GetButtonA())
    {
        return true;
    }
    if (input.GetButtonB())
    {
    }

    if (input.GetButtonX())
    {
    }

    if (input.GetButtonY())
    {
    }

    if (input.GetButtonStart())
    {
    }

    if (input.GetButtonSelect())
    {
    }

    if (input.GetButtonJSClick())
    {
    }

    if (input.GetButtonDPClick())
    {
    }

    if (input.GetJSPressed())
    {
    }

    if (input.GetDPPressed())
    {
    }


    return false;
}




SET_MEMORY(".splash.rodata")
const char str_splash_exit[] = "Exiting splash_entry, Going to map_gen_entry";

SET_MEMORY(".splash.rodata")
const char str_splash_entry[] = "Going to splash_entry";


/**********************************************************************************************************************/
/**  main game state update loop
**********************************************************************************************************************/
SET_MEMORY(".splash_entry")
uint8_t GameLoopTitleScreen(GameInterface* spi)
{
    spi->hardware.Print(str_splash_entry);
    int start = 0;
    while (start == 0)
    {
        spi->input.HandleInput();
        start = UpdateGameTitleState(spi->input);
        TitleRateDelay(spi->hardware);
    }

    spi->hardware.Print(str_splash_exit);
    return GAME_MAP_GEN;
}
