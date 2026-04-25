//
// Created by nathanial on 3/25/26.
//
#pragma once

#include "hardware/i2c.h"

#define MAX_VOLUME  26500
#define MIN_VOLUME  500
#define I2C_PORT    i2c0

#define MODE_SPI
// #define MODE_8BIT
/**********************************************************************************************************************/
/**  battery status
**********************************************************************************************************************/
#define LED         25      // low battery light

/**********************************************************************************************************************/
/**  button inputs
**********************************************************************************************************************/
#define LEFTBTN         1
#define RIGHTBTN        2
#define DOWNBTN         3
#define UPBTN           4

#define DCLICKBTN   5
// #define JSCLICKBTN

#define WHITEBTN        8
#define BLUEBTN         6
#define REDBTN          7
#define GREENBTN        0

/**********************************************************************************************************************/
/**  analog
**********************************************************************************************************************/
#define JSX         26
#define JSY         27
#define BATTERY     28

/**********************************************************************************************************************/
/**  speaker controller
**********************************************************************************************************************/
#define DIN         17
#define BCLK        18
#define LRC         19

// ADS1115
#define ADS_SDA     20
#define ADS_SCL     21

#define BL_PWM     22


#if defined(MODE_8BIT)
// #define TFT_WR      20
#define TFT_RS      23
#define TFT_RST     24
#endif

//  ILI9341 lcd display
#if defined(MODE_8BIT)
#define TFT_D0      9
#define TFT_D1      10
#define TFT_D2      11
#define TFT_D3      12
#define TFT_D4      13
#define TFT_D5      14
#define TFT_D6      15
#define TFT_D7      16
#elif defined(MODE_SPI)
#define CS          9
#define SCK         10
#define MOSI        11
#define RST         12
#define DC          13
// #define UNUSED      14
// #define UNUSED      15
// #define UNUSED      16
// #define UNUSED      23
// #define UNUSED      24
#else
#error "Define MODE_8BIT or MODE_SPI"
#endif
