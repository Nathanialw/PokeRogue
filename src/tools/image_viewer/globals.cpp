//
// Created by nathanial on 5/31/26.
//
#include "globals.h"


State::State()
{
    running = 1;
}

State g_sdl = State();


bool State::Running()
{
    return running;
}

void State::Close()
{
    running = 0;
}
