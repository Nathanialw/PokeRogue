//
// Created by nathanial on 5/19/26.
//

#include "core_state.h"

#include "core_ram.h"
#include "lib_enums.h"


/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
SET_MEMORY(".core")
State SetInputState(InputState state)
{
    g_core.state.inputState = state;
    return g_core.state;
}

