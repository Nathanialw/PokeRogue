//
// Created by nathanial on 5/7/26.
//

#include "cartridge_ram.h"


#include "lib_debugging.h"
#include "pico_constants.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#define FRAM_ADDR   0xA0   // 1010 0000 (A2=A1=A0=0, R/W=0)

void FRAM_Init(void)
{
    i2c_init(FRAM_I2C, 400 * 1000); // 400 kHz is safe and fast
    gpio_set_function(FM24C256_SDA, GPIO_FUNC_I2C);
    gpio_set_function(FM24C256_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(FM24C256_SDA);
    gpio_pull_up(FM24C256_SCL);

    DEBUG("FRAM Initialized");
}

// Write single byte
void FRAM_WriteByte(uint16_t addr, uint8_t data)
{
    uint8_t buf[3] = {(addr >> 8) & 0xFF, addr & 0xFF, data};
    i2c_write_blocking(FRAM_I2C, FRAM_ADDR >> 1, buf, 3, false);
}

// Read single byte
uint8_t FRAM_ReadByte(uint16_t addr)
{
    uint8_t addr_buf[2] = {(addr >> 8) & 0xFF, addr & 0xFF};
    uint8_t data = 0;

    i2c_write_blocking(FRAM_I2C, FRAM_ADDR >> 1, addr_buf, 2, true);
    i2c_read_blocking(FRAM_I2C, FRAM_ADDR >> 1, &data, 1, false);

    return data;
}

// Write buffer (any length)
void FRAM_WriteBuffer(uint16_t addr, const uint8_t* data, uint16_t len)
{
    // For simplicity and reliability, we can write in small chunks
    for (uint16_t i = 0; i < len; i++)
    {
        FRAM_WriteByte(addr + i, data[i]);
    }
}

// Read buffer (recommended)
void FRAM_ReadBuffer(uint16_t addr, uint8_t* buffer, uint16_t len)
{
    uint8_t addr_buf[2] = {(addr >> 8) & 0xFF, addr & 0xFF};

    i2c_write_blocking(FRAM_I2C, FRAM_ADDR >> 1, addr_buf, 2, true);
    i2c_read_blocking(FRAM_I2C, FRAM_ADDR >> 1, buffer, len, false);
}


/**********************************************************************************************************************/
/**  tests
**********************************************************************************************************************/

void FRAM_Test(void)
{
    FRAM_WriteByte(0x0000, 0xAA);
    FRAM_WriteByte(0x0001, 0x55);

    uint8_t val1 = FRAM_ReadByte(0x0000);
    uint8_t val2 = FRAM_ReadByte(0x0001);

    DEBUG("FRAM[0x0000] = 0x%02X, FRAM[0x0001] = 0x%02X", val1, val2);
    // uint8_t buf[2] = { 0xFF, 0xFF };
    // i2c_write_blocking(i2c0, FRAM_ADDR >> 1, buf, 2, true);
}

void CartridgeRAM_Test(void)
{
    FRAM_WriteBuffer(0x0000, (uint8_t*)"PokeRogue Save Test!", 20);

    uint8_t buf[32] = {0};
    FRAM_ReadBuffer(0x0000, buf, 32);

    DEBUG("FRAM Read: %s", buf);
}

void FRAM_SizeTest(void)
{
    DEBUG("=== FRAM Full Size Test ===");

    uint8_t test_val = 0x55;
    bool success = true;

    // Test several points across the full 32KB
    uint16_t test_addresses[] = {0x0000, 0x1000, 0x4000, 0x7FF0};

    for (int i = 0; i < 4; i++)
    {
        uint16_t addr = test_addresses[i];
        uint8_t orig = FRAM_ReadByte(addr);

        FRAM_WriteByte(addr, test_val);
        uint8_t read = FRAM_ReadByte(addr);

        if (read != test_val)
        {
            DEBUG("FAIL at 0x%04X", addr);
            success = false;
        }
        else
        {
            DEBUG("OK at 0x%04X", addr);
        }

        FRAM_WriteByte(addr, orig); // restore
    }

    DEBUG(success ? "FRAM 32KB Verified Successfully" : "FRAM Test Failed");
}
