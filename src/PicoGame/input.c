//
// Created by nathanial on 2/19/26.
//
#include <stdlib.h>
#include "stdbool.h"

#include "pico/bootrom.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "input.h"

#include "types.h"
#include "camera.h"
#include "game_state.h"
#include "memory_ram.h"
#include "pico_constants.h"
#include "rendering.h"

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/

#define DEADZONE 600

/**********************************************************************************************************************/
/**  Debounce check
**********************************************************************************************************************/
bool Pico_ButtonDownStable(uint8_t btn)
{
    if (gpio_get(btn) != 0) return false;
    sleep_ms(15);
    return gpio_get(btn) == 0;
}

/**********************************************************************************************************************/
/**  Triggers reset pin on the Pico
**********************************************************************************************************************/
bool Pico_Reset(void)
{
    reset_usb_boot(0, 0);
    return true;
}

/**********************************************************************************************************************/
/**  Checks for an action button pressed
**********************************************************************************************************************/
bool Pico_CheckBtn(uint16_t btn, uint16_t pressDuration)
{
    if (Pico_ButtonDownStable(btn))
    {
        // pressed
        sleep_ms(pressDuration);
        if (Pico_ButtonDownStable(btn)) // still pressed
        {
            return true;
        }
    }
    return false;
}


/****************************************************************************************************************/
/**  checks for analog stick input
 *  ON SUCCESS - return true
 *  ON FAIL - return false
**********************************************************************************************************************/
bool Pico_InputDelta(void)
{
    Delta d = {0, 0};
    int8_t joy_dx = 0;
    int8_t joy_dy = 0;

    adc_select_input(0);
    sleep_us(5);
    uint16_t jy = adc_read();
    if (jy < 2048 - DEADZONE) joy_dy = -1;
    else if (jy > 2048 + DEADZONE) joy_dy = 1;

    adc_select_input(1);
    sleep_us(5);
    uint16_t jx = adc_read();
    if (jx < 2048 - DEADZONE) joy_dx = 1;
    else if (jx > 2048 + DEADZONE) joy_dx = -1;

    if (abs(joy_dx) > abs(joy_dy))
    {
        d.x = joy_dx;
        d.y = 0;
    }
    else
    {
        d.x = 0;
        d.y = joy_dy;
    }

    if (d.x == 0 && d.y == 0) return false;

    SetDelta(d);

    return true;
}

/**********************************************************************************************************************/
/**  Reads input from the D pad
 *  ON SUCCESS - return true
 *  ON FAIL - return false
**********************************************************************************************************************/
bool Pico_InputDeltaDPad(void)
{
    Delta d = {0, 0};
    int8_t dx = 0;
    int8_t dy = 0;

    if (Pico_CheckBtn(UPBTN, 0)) dy = -1;
    else if (Pico_CheckBtn(DOWNBTN, 0)) dy = 1;
    else if (Pico_CheckBtn(LEFTBTN, 0)) dx = -1;
    else if (Pico_CheckBtn(RIGHTBTN, 0)) dx = 1;
    if (dx == 0 && dy == 0) return false;
    d.x = dx;
    d.y = dy;

    SetDelta(d);
    return true;
}

/**********************************************************************************************************************/
/**  Loop polls for input
 *  if input found update button state
 *  pass to main state control switch
**********************************************************************************************************************/
State HandleInput(State state)
{
    while (1)
    {
        sleep_ms(g_run.btns.sleepTime); //sleep between key queries

        g_run.btns.sleepTime = g_run.btns.defaultSleepTime;
        g_run.btns.d.x = 0;
        g_run.btns.d.y = 0;

        bool UpClick_Pressed = g_run.btns.Up_Pressed;
        bool DownClick_Pressed = g_run.btns.Down_Pressed;
        bool LeftClick_Pressed = g_run.btns.Left_Pressed;
        bool RightClick_Pressed = g_run.btns.Right_Pressed;

        bool WhiteClick_Pressed = g_run.btns.WhiteClick_Pressed;
        bool GreenClick_Pressed = g_run.btns.GreenClick_Pressed;
        bool RedClick_Pressed = g_run.btns.RedClick_Pressed;
        bool BlueClick_Pressed = g_run.btns.BlueClick_Pressed;

        bool JSClick_Pressed = g_run.btns.JSClick_Pressed;

        g_run.btns.DPad_Pressed = Pico_InputDeltaDPad();
        g_run.btns.JS_Pressed = Pico_InputDelta();

        g_run.btns.WhiteClick_Pressed = Pico_CheckBtn(WHITEBTN, 0);
        g_run.btns.RedClick_Pressed = Pico_CheckBtn(REDBTN, 0);
        g_run.btns.BlueClick_Pressed = Pico_CheckBtn(BLUEBTN, 0);
        g_run.btns.GreenClick_Pressed = Pico_CheckBtn(GREENBTN, 0);

        // g_run.btns.JSClick_Pressed = Pico_CheckBtn(JSCLICKBTN, 0);
        g_run.btns.JSClick_Pressed = Pico_CheckBtn(DCLICKBTN, 0);


        if (g_run.btns.DPad_Pressed)
            break;
        if (g_run.btns.JS_Pressed)
            break;

        if (UpClick_Pressed != g_run.btns.Up_Pressed)
            break;
        if (DownClick_Pressed != g_run.btns.Down_Pressed)
            break;
        if (LeftClick_Pressed != g_run.btns.Left_Pressed)
            break;
        if (RightClick_Pressed != g_run.btns.Right_Pressed)
            break;

        if (WhiteClick_Pressed != g_run.btns.WhiteClick_Pressed)
            break;
        if (GreenClick_Pressed != g_run.btns.GreenClick_Pressed)
            break;
        if (RedClick_Pressed != g_run.btns.RedClick_Pressed)
            break;
        if (BlueClick_Pressed != g_run.btns.BlueClick_Pressed)
            break;
        if (JSClick_Pressed != g_run.btns.JSClick_Pressed)
            break;

        sleep_ms(g_run.btns.defaultSleepTime); //extra sleep when nothing is happening
    }

    State prevState = state;

    state = UpdateGameState(state);

    if (state.inputState == REBOOT)
    {
        if (Pico_CheckBtn(REDBTN, 1000))
            Pico_Reset();
        else
            state.inputState = MOVING;
    }


    if ((prevState.inputState == MENU || prevState.inputState == BATTLE) && state.inputState == MOVING)
        FullRedraw();

    if (state.inputState == MENU)
        g_run.btns.sleepTime = g_run.btns.menuSleepTime;


    return state;
}
