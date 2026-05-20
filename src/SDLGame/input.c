//
// Created by nathanial on 5/20/26.
//

#include "input.h"

#include "lib_decl.h"


// TODO:
void HandleInput(void)
{
}


// TODO:
void SetInputPollingRate(uint16_t time)
{
}


// TODO:
void SetInputPollingDefault(void)
{
}

// TODO:
KeyState GetInputKeyState(void)
{
}

// TODO:
bool GetButtonA(void)
{
}

// TODO:
bool GetButtonB(void)
{
}


//TODO
bool GetButtonY(void)
{
    return false;
}

//TODO
bool GetButtonX(void)
{
    return false;
}

//TODO
bool GetButtonSelect(void)
{
    return false;
}

//TODO
bool GetButtonStart(void)
{
    return false;
}

//TODO
bool GetButtonUp(void)
{
    return false;
}

//TODO
bool GetButtonDown(void)
{
    return false;
}

//TODO
bool GetButtonLeft(void)
{
    return false;
}

//TODO
bool GetButtonRight(void)
{
    return false;
}

//TODO
bool GetButtonJSClick(void)
{
    return false;
}

//TODO
bool GetButtonDPClick(void)
{
    return false;
}

//TODO
bool GetJSPressed(void)
{
    return false;
}

//TODO
bool GetDPPressed(void)
{
    return false;
}

InputInterface InputInterfaceInit()
{
    InputInterface inputInterface = {
        .HandleInput = HandleInput,
        .SetInputPollingRate = SetInputPollingRate,
        .SetInputPollingDefault = SetInputPollingDefault,
        .GetInputKeyState = GetInputKeyState,
        .GetButtonA = GetButtonA,
        .GetButtonB = GetButtonB,
        .GetButtonY = GetButtonY,
        .GetButtonX = GetButtonX,
        .GetButtonSelect = GetButtonSelect,
        .GetButtonStart = GetButtonStart,
        .GetButtonUp = GetButtonUp,
        .GetButtonDown = GetButtonDown,
        .GetButtonLeft = GetButtonLeft,
        .GetButtonRight = GetButtonRight,
        .GetButtonJSClick = GetButtonJSClick,
        .GetButtonDPClick = GetButtonDPClick,
        .GetJSPressed = GetJSPressed,
        .GetDPPressed = GetDPPressed,
        // .GetButtonUnused1 = GetButtonUnused1,
        // .GetButtonUnused2 = GetButtonUnused2,
        // .GetButtonUnused3 = GetButtonUnused3,
        // .GetButtonUnused4 = GetButtonUnused4,
    };

    return inputInterface;
}
