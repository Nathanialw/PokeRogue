//
// Created by nathanial on 5/31/26.
//

#pragma once

#include <string>

class State
{
    uint8_t running : 1;


public:
    State();
    bool Running();
    void Close();
};


extern State g_sdl;
