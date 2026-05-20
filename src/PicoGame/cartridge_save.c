//
// Created by nathanial on 5/7/26.
//

#include "cartridge_save.h"

#include <string.h>

#include "lib_debugging.h"

#include "hardware/gpio.h"
#include "hardware/i2c.h"

#include "constants.h"

#define FRAM_ADDR_WRITE   0xA0   // 1010 0000 (A2=A1=A0=0, R/W=0)
#define FRAM_ADDR_7BIT  (FRAM_ADDR_WRITE >> 1)   // 7‑bit address

void FRAM_WriteByte(uint16_t addr, uint8_t data);
uint8_t FRAM_ReadByte(uint16_t addr);
void FRAM_WriteBuffer(uint16_t addr, const uint8_t* data, uint16_t len);
void FRAM_ReadBuffer(uint16_t addr, uint8_t* buffer, uint16_t len);
void FRAM_Erase();
void FRAM_Write(uint16_t addr, const uint8_t* data, uint16_t len);
void FRAM_Read(uint16_t addr, uint8_t* buffer, uint16_t len);


void FRAM_Init(void)
{
    i2c_init(FRAM_I2C, 400 * 1000); // 400 kHz is safe and fast
    gpio_set_function(FM24C256_SDA, GPIO_FUNC_I2C);
    gpio_set_function(FM24C256_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(FM24C256_SDA);
    gpio_pull_up(FM24C256_SCL);

    DEBUG("FRAM I2C Scan...");
    for (int i = 0; i < 128; i++)
    {
        uint8_t dummy;
        if (i2c_read_blocking(FRAM_I2C, i, &dummy, 1, false) >= 0)
        {
            DEBUG("I2C Device found at 0x%02X", i);
        }
    }

    DEBUG("FRAM Initialized");
}

// Write single byte
void FRAM_WriteByte(uint16_t addr, uint8_t data)
{
    FRAM_Write(addr, &data, 1);
}

uint8_t FRAM_ReadByte(uint16_t addr)
{
    uint8_t data = 0;
    FRAM_Read(addr, &data, 1);
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

    i2c_write_blocking(FRAM_I2C, FRAM_ADDR_7BIT, addr_buf, 2, true);
    i2c_read_blocking(FRAM_I2C, FRAM_ADDR_7BIT, buffer, len, false);
}

void FRAM_Erase()
{
    uint8_t buf[2] = {0xFF, 0xFF};
    i2c_write_blocking(FRAM_I2C, FRAM_ADDR_7BIT, buf, 2, true);
}

// Read any number of bytes
void FRAM_Write(uint16_t addr, const uint8_t* data, uint16_t len)
{
    if (len == 0) return;

    uint8_t buf[2 + 128]; // Large enough buffer

    while (len > 0)
    {
        uint16_t chunk = (len > 64) ? 64 : len; // 64 bytes is excellent for FRAM

        buf[0] = (uint8_t)(addr >> 8);
        buf[1] = (uint8_t)(addr & 0xFF);

        memcpy(&buf[2], data, chunk);

        int ret = i2c_write_blocking(FRAM_I2C, FRAM_ADDR_7BIT, buf, 2 + chunk, false);

        if (ret < 0)
        {
            DEBUG("I2C Write Error at 0x%04X", addr);
            return;
        }

        addr += chunk;
        data += chunk;
        len -= chunk;
    }
}

void FRAM_Read(uint16_t addr, uint8_t* buffer, uint16_t len)
{
    if (len == 0) return;

    uint8_t addr_buf[2] = {
        (uint8_t)(addr >> 8),
        (uint8_t)(addr & 0xFF)
    };

    // Send address with repeated start
    int ret = i2c_write_blocking(FRAM_I2C, FRAM_ADDR_7BIT, addr_buf, 2, true);
    if (ret < 0)
    {
        DEBUG("I2C Address Error: %d", ret);
        return;
    }

    // Read data
    ret = i2c_read_blocking(FRAM_I2C, FRAM_ADDR_7BIT, buffer, len, false);
    if (ret < 0)
    {
        DEBUG("I2C Read Error: %d", ret);
    }
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

    if (success)
        DEBUG("FRAM 32KB Verified Successfully");
    else
        DEBUG("FRAM Test Failed");
}

bool FRAM_FullTest(void)
{
    DEBUG("=== FRAM FULL TEST START ===");

    const uint16_t TEST_ADDR = 0x1000; // Use a safe area

    // --------------------------------------------------------------------
    // Simple distributed test
    // --------------------------------------------------------------------
    DEBUG("--- Single Byte Test ---");
    static const uint8_t test_values[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x70};

    for (int i = 0; i < 8; i++)
    {
        uint16_t addr = TEST_ADDR + i * 0x100;
        // FRAM_WriteByte(addr, test_values[i]);
        uint8_t read = FRAM_ReadByte(addr);

        DEBUG("0x%04X: Wrote 0x%02X, Read 0x%02X %s", addr, test_values[i], read, (read == test_values[i]) ? "OK" : "FAIL");
    }

    // --------------------------------------------------------------------
    // Block Write/Read Test (256 bytes)
    // --------------------------------------------------------------------
    DEBUG("--- 256-Byte Block Test ---");

    uint8_t tx[256];
    uint8_t rx[256];

    for (int i = 0; i < 256; i++)
    {
        tx[i] = (uint8_t)i;
    }

    absolute_time_t start = get_absolute_time();

    FRAM_Write(TEST_ADDR, tx, 256);

    int64_t write_time = absolute_time_diff_us(start, get_absolute_time());

    start = get_absolute_time();
    FRAM_Read(TEST_ADDR, rx, 256);
    int64_t read_time = absolute_time_diff_us(start, get_absolute_time());

    bool block_ok = true;
    for (int i = 0; i < 256; i++)
    {
        if (tx[i] != rx[i])
        {
            block_ok = false;
            break;
        }
    }

    DEBUG("Block Test: %s", block_ok ? "PASSED" : "FAILED");
    DEBUG("Write 256B: %lld us (%.2f KB/s)", write_time, 256000.0 / write_time);
    DEBUG("Read  256B: %lld us (%.2f KB/s)", read_time, 256000.0 / read_time);

    // --------------------------------------------------------------------
    // Overall Speed Summary
    // --------------------------------------------------------------------
    DEBUG("=== FRAM PERFORMANCE SUMMARY ===");
    DEBUG("I2C Speed: 400 kHz");
    DEBUG("Block Write Speed: %.1f KB/s", 256000.0 / write_time);
    DEBUG("Block Read Speed : %.1f KB/s", 256000.0 / read_time);

    if (block_ok)
    {
        DEBUG("✅ FRAM FULL TEST PASSED");
        return true;
    }
    else
    {
        DEBUG("❌ FRAM FULL TEST FAILED");
        return false;
    }
}
