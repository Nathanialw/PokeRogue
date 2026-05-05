//
// Created by nathanial on 2/19/26.
//
#include "input.h"

#include <stdlib.h>
#include "stdbool.h"

#include "pico/bootrom.h"
#include "hardware/adc.h"

#include "lib_debugging.h"
#include "lib_decl.h"
#include "lib_types.h"

#include "pico_constants.h"
#include "pico_ram.h"

#define DEADZONE 600

/**********************************************************************************************************************/
/*
**********************************************************************************************************************/
KeyState GetInputKeyState()
{
    return g_pico_ram.input.keyState;
}


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
Delta Pico_InputDelta(void)
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

    // if (d.x == 0 && d.y == 0) return false;


    return d;
}

/**********************************************************************************************************************/
/**  Reads input from the D pad
 *  ON SUCCESS - return true
 *  ON FAIL - return false
**********************************************************************************************************************/
Delta Pico_InputDeltaDPad(void)
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


uint8_t SN74HC165N_ReadShiftRegister()
{
    uint8_t data = 0;
    gpio_put(SN74HC165N_SH_LD, 0);
    busy_wait_us(1);
    gpio_put(SN74HC165N_SH_LD, 1);
    busy_wait_us(10); // <-- extra delay for first bt to stabilise
    spi_read_blocking(SPI_BUTTONS, 0, &data, 1);
    return data;
}


uint16_t SN74HC165N_BitBangShiftRegister()
{
    gpio_put(SN74HC165N_SH_LD, 0);
    busy_wait_us(1);
    gpio_put(SN74HC165N_SH_LD, 1);
    busy_wait_us(1);

    uint16_t data = 0;
    for (int i = 0; i < 16; i++)
    {
        data = (data << 1) | gpio_get(SN74HC165N_MISO);
        gpio_put(SN74HC165N_SCLK, 1);
        busy_wait_us(1);
        gpio_put(SN74HC165N_SCLK, 0);
        busy_wait_us(1);
    }
    return data;
}

void PrintInput(uint16_t n, char* binary)
{
    for (int i = 16 - 1; i >= 0; i--)
    {
        binary[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    binary[16] = '\0';
}


inline bool GetButtonUp(void) { return !(g_pico_ram.input.keyState.buttons >> 0 & 1); }
inline bool GetButtonDown(void) { return !(g_pico_ram.input.keyState.buttons >> 1 & 1); }
inline bool GetButtonLeft(void) { return !(g_pico_ram.input.keyState.buttons >> 2 & 1); }
inline bool GetButtonRight(void) { return !(g_pico_ram.input.keyState.buttons >> 3 & 1); }
inline bool GetButtonA(void) { return !(g_pico_ram.input.keyState.buttons >> 4 & 1); }
inline bool GetButtonB(void) { return !(g_pico_ram.input.keyState.buttons >> 5 & 1); }
inline bool GetButtonY(void) { return !(g_pico_ram.input.keyState.buttons >> 6 & 1); }
inline bool GetButtonX(void) { return !(g_pico_ram.input.keyState.buttons >> 7 & 1); }

inline bool GetButtonStart(void) { return !(g_pico_ram.input.keyState.buttons >> 8 & 1); }
inline bool GetButtonSelect(void) { return !(g_pico_ram.input.keyState.buttons >> 9 & 1); }
inline bool GetButtonJSClick(void) { return !(g_pico_ram.input.keyState.buttons >> 10 & 1); }
inline bool GetButtonDPClick(void) { return !(g_pico_ram.input.keyState.buttons >> 11 & 1); }

inline bool GetButtonUnused1(void) { return !(g_pico_ram.input.keyState.buttons >> 12 & 1); }   //L1
inline bool GetButtonUnused2(void) { return !(g_pico_ram.input.keyState.buttons >> 13 & 1); }   //L2
inline bool GetButtonUnused3(void) { return !(g_pico_ram.input.keyState.buttons >> 14 & 1); }   //R1
inline bool GetButtonUnused4(void) { return !(g_pico_ram.input.keyState.buttons >> 15 & 1); }   //R2


inline bool GetJSPressed(void) { return g_pico_ram.input.keyState.d.x != 0 || g_pico_ram.input.keyState.d.y != 0; }
inline bool GetDPPressed(void) { return g_pico_ram.input.keyState.d.x != 0 || g_pico_ram.input.keyState.d.y != 0; }

inline void SetInputPollingRate(uint16_t time) { g_pico_ram.input.pollingRate = time; }
inline void SetInputPollingDefault() { g_pico_ram.input.pollingRate = g_pico_ram.input.defaultPollingRate; }
void HardwareReset(void) { Pico_Reset(); }

/**********************************************************************************************************************/
/**  Loop polls for input
 *  if input found update button state
 *  pass to main state control switch
**********************************************************************************************************************/
void HandleInput()
{
    while (1)
    {
        g_pico_ram.input.keyState.d.x = 0;
        g_pico_ram.input.keyState.d.y = 0;
        const uint16_t tmp = SN74HC165N_BitBangShiftRegister();
        Delta d1 = Pico_InputDelta();
        Delta d2 = Pico_InputDeltaDPad();
        if (tmp == g_pico_ram.input.keyState.buttons && d1.x == 0 && d1.y == 0 && d2.x == 0 && d2.y == 0)
        {
            sleep_ms(g_pico_ram.input.pollingRate); //sleep between key queries
            continue;
        }
        g_pico_ram.input.keyState.buttons = tmp;

        if (d1.x != 0 || d1.y != 0) g_pico_ram.input.keyState.d = d1;
        else if (d2.x != 0 || d2.y != 0) g_pico_ram.input.keyState.d = d2;

        char binary[16 + 1];
        PrintInput(g_pico_ram.input.keyState.buttons, binary);
        DEBUG("Buttons: 0b%s %d %d %d %d", binary, d1.x, d1.y, d2.x, d2.y);

        if (GetButtonX())
        {
            DEBUG("RESET");
            HardwareReset();
        }

        break;
    }
}
