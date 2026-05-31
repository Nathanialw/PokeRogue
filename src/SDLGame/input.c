//
// Created by nathanial on 5/20/26.
//

#include "input.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_timer.h>

#include "core_ram.h"
#include "lib_debugging.h"
#include "lib_decl.h"
#include "ram.h"


Delta InputDeltaDPad();


uint16_t ProcessInput(void)
{
    KeyState s_currentKeys = {0};
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_KEY_DOWN:
            {
            }
        case SDL_EVENT_KEY_UP:
            {
                int pressed = (event.type == SDL_EVENT_KEY_DOWN);
                switch (event.key.key)
                {
                case SDLK_UP: s_currentKeys.up = pressed;
                    break;
                case SDLK_DOWN: s_currentKeys.down = pressed;
                    break;
                case SDLK_LEFT: s_currentKeys.left = pressed;
                    break;
                case SDLK_RIGHT: s_currentKeys.right = pressed;
                    break;

                case SDLK_W: s_currentKeys.up = pressed;
                    break;
                case SDLK_S: s_currentKeys.down = pressed;
                    break;
                case SDLK_A: s_currentKeys.left = pressed;
                    break;
                case SDLK_D: s_currentKeys.right = pressed;
                    break;

                case SDLK_E: s_currentKeys.a = pressed;
                    break;
                case SDLK_Q: s_currentKeys.b = pressed;
                    break;
                case SDLK_R: s_currentKeys.x = pressed;
                    break;
                case SDLK_F: s_currentKeys.y = pressed;
                    break;

                case SDLK_RETURN: s_currentKeys.start = pressed;
                    break;
                case SDLK_ESCAPE:
                    {
                        s_currentKeys.select = pressed;
                        g_core.state.running = 0;
                        break;
                    }

                    // Add more mappings (Start, Select, etc.) as needed.
                }
                break;
            }

        case SDL_EVENT_QUIT:
            // handle quit, set a flag, etc.
            break;
        }
    }

    return
        s_currentKeys
        .
        buttons;
}


// TODO:
void HandleInput(void)
{
    while (1)
    {
        g_ramState.keys.dp.x = 0;
        g_ramState.keys.dp.y = 0;
        g_ramState.keys.js.x = 0;
        g_ramState.keys.js.y = 0;
        const uint16_t key_state = ProcessInput();
        Delta d1 = InputDeltaDPad();
        if (key_state == g_ramState.keys.buttons && d1.x == 0 && d1.y == 0)
        {
            SDL_Delay(20);
            continue;
        }

        g_ramState.keys.buttons = key_state;
        g_ramState.keys.dp = d1;
        break;
    }
}

//TODO
void SetInputPollingRate(uint16_t time)
{
}

//TODO
void SetInputPollingDefault(void)
{
}

//TODO
KeyState GetInputKeyState(void)
{
    return g_ramState.keys;
}

bool GetButtonA(void)
{
    return g_ramState.keys.a;
}

bool GetButtonB(void)
{
    return g_ramState.keys.b;
}

bool GetButtonY(void)
{
    return g_ramState.keys.y;
}

bool GetButtonX(void)
{
    return g_ramState.keys.x;
}

bool GetButtonSelect(void)
{
    return g_ramState.keys.select;
}

bool GetButtonStart(void)
{
    return g_ramState.keys.start;
}

bool GetButtonUp(void)
{
    return g_ramState.keys.up;
}

bool GetButtonDown(void)
{
    return g_ramState.keys.down;
}

bool GetButtonLeft(void)
{
    return g_ramState.keys.left;
}

bool GetButtonRight(void)
{
    return g_ramState.keys.right;
}

bool GetButtonJSClick(void)
{
    return g_ramState.keys.js_click;
}

bool GetButtonDPClick(void)
{
    return g_ramState.keys.dp_click;
}

//TODO
bool GetJSPressed(void)
{
    return false;
}

bool GetDPPressed(void) { return g_ramState.keys.dp.x != 0 || g_ramState.keys.dp.y != 0; }


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


Delta InputDeltaDPad()
{
    Delta d = {0, 0};
    int8_t dx = 0;
    int8_t dy = 0;

    if (GetButtonUp()) dy = -1;
    else if (GetButtonDown()) dy = 1;
    else if (GetButtonLeft()) dx = -1;
    else if (GetButtonRight()) dx = 1;
    d.x = dx;
    d.y = dy;


    return d;
}
