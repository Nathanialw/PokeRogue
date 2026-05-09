//
// Created by nathanial on 5/7/26.
//

#include "cartridge_rom.h"

#include "lib_debugging.h"
#include "pico_constants.h"
#include "hardware/gpio.h"


/**********************************************************************************************************************/
/**  Pico cartridge SPI
/**********************************************************************************************************************/
// Release from Power-down + Read ID
// Best JEDEC Read
// Call this once after InitCart()
void EEPROM_WakeUp(void)
{
    uint8_t cmd = 0xAB;
    gpio_put(CART_CS_EEPROM, 0);
    sleep_us(20);
    spi_write_blocking(SPI_CART, &cmd, 1);
    gpio_put(CART_CS_EEPROM, 1);
    sleep_ms(20);
}

void EEPROM_ReadJEDEC(void)
{
    uint8_t tx[4] = {0x9F, 0x00, 0x00, 0x00};
    uint8_t rx[4] = {0};

    gpio_put(CART_CS_EEPROM, 0);
    sleep_us(30);
    spi_write_read_blocking(SPI_CART, tx, rx, 4);
    gpio_put(CART_CS_EEPROM, 1);

    DEBUG("JEDEC: %02X %02X %02X", rx[1], rx[2], rx[3]);
}

// Read single byte
uint8_t EEPROM_ReadByte(uint32_t addr)
{
    uint8_t tx[4] = {0x03, (addr>>16)&0xFF, (addr>>8)&0xFF, addr&0xFF};
    uint8_t rx[5] = {0};

    gpio_put(CART_CS_EEPROM, 0);
    sleep_us(5);
    spi_write_read_blocking(SPI_CART, tx, rx, 5);
    gpio_put(CART_CS_EEPROM, 1);
    return rx[4];
}

// Read multiple bytes (recommended)
void EEPROM_ReadBuffer(uint32_t addr, uint8_t *buffer, uint16_t length)
{
    uint8_t tx[4] = {
        0x03,
        (uint8_t)(addr >> 16),
        (uint8_t)(addr >> 8),
        (uint8_t)addr
    };

    gpio_put(CART_CS_EEPROM, 0);
    sleep_us(20);                    // generous setup time

    spi_write_blocking(SPI_CART, tx, 4);
    spi_read_blocking(SPI_CART, 0x00, buffer, length);

    gpio_put(CART_CS_EEPROM, 1);
}
// ============== WRITE / ERASE ==============

// Enable Write
void EEPROM_WriteEnable(void)
{
    uint8_t cmd = 0x06;
    gpio_put(CART_CS_EEPROM, 0);
    spi_write_blocking(SPI_CART, &cmd, 1);
    gpio_put(CART_CS_EEPROM, 1);
}

// Check if busy
bool EEPROM_IsBusy(void)
{
    uint8_t cmd = 0x05;
    uint8_t status = 0;

    gpio_put(CART_CS_EEPROM, 0);
    spi_write_blocking(SPI_CART, &cmd, 1);
    spi_read_blocking(SPI_CART, 0x00, &status, 1);
    gpio_put(CART_CS_EEPROM, 1);

    return (status & 0x01);  // BUSY bit
}

// Page Program (up to 256 bytes)
void EEPROM_PageProgram(uint32_t addr, const uint8_t *data, uint16_t length)
{
    if (length > 256) length = 256;

    EEPROM_WriteEnable();

    uint8_t tx[4] = {0x02, (addr>>16)&0xFF, (addr>>8)&0xFF, addr&0xFF};

    gpio_put(CART_CS_EEPROM, 0);
    spi_write_blocking(SPI_CART, tx, 4);
    spi_write_blocking(SPI_CART, data, length);
    gpio_put(CART_CS_EEPROM, 1);

    // Wait for completion
    while (EEPROM_IsBusy()) sleep_ms(1);
}

// Sector Erase (4KB)
void EEPROM_EraseSector(uint32_t addr)
{
    EEPROM_WriteEnable();
    uint8_t tx[4] = {0x20, (addr>>16)&0xFF, (addr>>8)&0xFF, addr&0xFF};

    gpio_put(CART_CS_EEPROM, 0);
    spi_write_blocking(SPI_CART, tx, 4);
    gpio_put(CART_CS_EEPROM, 1);

    while (EEPROM_IsBusy()) sleep_ms(1);
}

void EEPROM_Read(
    uint32_t addr,
    uint8_t *data,
    size_t len
)
{
    uint8_t header[4];

    header[0] = 0x03;

    header[1] = (addr >> 16) & 0xFF;
    header[2] = (addr >> 8) & 0xFF;
    header[3] = addr & 0xFF;

    gpio_put(CART_CS_EEPROM, 0);

    spi_write_blocking(SPI_CART, header, 4);
    spi_read_blocking(SPI_CART, 0x00, data, len);

    gpio_put(CART_CS_EEPROM, 1);
}


/**********************************************************************************************************************/
/**  utils
**********************************************************************************************************************/

uint8_t EEPROM_ReadHighAddress(void)
{
    uint32_t high_addr = 0xFFF000;     // near the end of 16MB
    uint8_t tx[4] = {0x03,
                     (high_addr >> 16) & 0xFF,
                     (high_addr >> 8) & 0xFF,
                     high_addr & 0xFF};
    uint8_t rx[5] = {0};

    gpio_put(CART_CS_EEPROM, 0);
    sleep_us(10);
    spi_write_read_blocking(SPI_CART, tx, rx, 5);
    gpio_put(CART_CS_EEPROM, 1);

    return rx[4];
}

// Test multiple high addresses
void EEPROM_TestCapacity(void)
{
    DEBUG("=== Capacity Test ===");

    // Test several addresses near the top
    uint32_t addresses[] = {
        0x000000,      // beginning
        0x0FFFF0,      // ~1MB
        0x7FF000,      // ~8MB
        0xFFF000,      // near end (16MB)
        0xFFFFFF       // absolute last byte
    };

    for (int i = 0; i < 5; i++) {
        uint32_t addr = addresses[i];
        uint8_t val = EEPROM_ReadByte(addr);   // reuse your existing function
        DEBUG("Addr 0x%06X = 0x%02X", addr, val);
    }
}

void EEPROM_DumpBeginning(void)
{
    DEBUG("Dumping first 32 bytes:");
    for (int i = 0; i < 32; i += 8) {
        DEBUG("%02X %02X %02X %02X %02X %02X %02X %02X",
            EEPROM_ReadByte(i),   EEPROM_ReadByte(i+1),
            EEPROM_ReadByte(i+2), EEPROM_ReadByte(i+3),
            EEPROM_ReadByte(i+4), EEPROM_ReadByte(i+5),
            EEPROM_ReadByte(i+6), EEPROM_ReadByte(i+7));
    }
}

// Fast Read version
uint8_t EEPROM_FastReadByte(uint32_t addr)
{
    uint8_t tx[5] = {
        0x0B,
        (uint8_t)(addr >> 16),
        (uint8_t)(addr >> 8),
        (uint8_t)addr,
        0x00   // dummy
    };
    uint8_t rx[6] = {0};

    gpio_put(CART_CS_EEPROM, 0);
    sleep_us(5);

    spi_write_read_blocking(SPI_CART, tx, rx, 6);

    gpio_put(CART_CS_EEPROM, 1);

    return rx[5];
}


void InitCart(void)
{
    spi_init(SPI_CART, 40 * 1000 * 1000);     // 40 MHz
    spi_set_format(SPI_CART, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);

    gpio_set_function(CART_SCK, GPIO_FUNC_SPI);
    gpio_set_function(CART_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(CART_MISO, GPIO_FUNC_SPI);

    // CS pins
    gpio_init(CART_CS_EEPROM);
    gpio_set_dir(CART_CS_EEPROM, GPIO_OUT);
    gpio_put(CART_CS_EEPROM, 1);

    // Optional: drive HOLD and WP high if they are accessible
    // gpio_init(HOLD_PIN); gpio_set_dir(HOLD_PIN, GPIO_OUT); gpio_put(HOLD_PIN, 1);
    // gpio_init(WP_PIN);   gpio_set_dir(WP_PIN, GPIO_OUT);   gpio_put(WP_PIN, 1);

    // Add this once after InitCart()

    // EEPROM_WakeUp();
    // EEPROM_ReadJEDEC();
    //
    // uint8_t buf[64];
    // EEPROM_ReadBuffer(0x000000, buf, 64);
    //
    // DEBUG("First 64 bytes:");
    // for (int i = 0; i < 64; i += 8) {
    //     DEBUG("%02X %02X %02X %02X %02X %02X %02X %02X",
    //         buf[i], buf[i+1], buf[i+2], buf[i+3],
    //         buf[i+4], buf[i+5], buf[i+6], buf[i+7]);
    // }
    //
    // EEPROM_TestCapacity();
}


/**********************************************************************************************************************/
/**  tests
**********************************************************************************************************************/
bool EEPROM_FullTest()
{
    DEBUG("=== EEPROM FULL TEST START ===");

    // --------------------------------------------------------------------
    // JEDEC
    // --------------------------------------------------------------------

    EEPROM_ReadJEDEC();

    // --------------------------------------------------------------------
    // Read distribution test
    // --------------------------------------------------------------------

    uint32_t test_addrs[] =
    {
        0x000000,
        0x000100,
        0x001000,
        0x010000,
        0x100000,
        0x700000,
        0xFFFFFF
    };

    for (size_t i = 0; i < count_of(test_addrs); i++)
    {
        uint8_t value =
            EEPROM_ReadByte(test_addrs[i]);

        DEBUG(
            "ADDR 0x%06X = 0x%02X",
            test_addrs[i],
            value
        );
    }

    // --------------------------------------------------------------------
    // Sequential read test
    // --------------------------------------------------------------------

    DEBUG("=== EEPROM BLOCK READ TEST ===");

    uint8_t buffer[256];

    EEPROM_Read(
        0x000000,
        buffer,
        sizeof(buffer)
    );

    for (int i = 0; i < 32; i++)
    {
        DEBUG(
            "%02X %02X %02X %02X %02X %02X %02X %02X",
            buffer[i * 8 + 0],
            buffer[i * 8 + 1],
            buffer[i * 8 + 2],
            buffer[i * 8 + 3],
            buffer[i * 8 + 4],
            buffer[i * 8 + 5],
            buffer[i * 8 + 6],
            buffer[i * 8 + 7]
        );
    }

    // --------------------------------------------------------------------
    // Read speed test
    // --------------------------------------------------------------------

    DEBUG("=== EEPROM SPEED TEST ===");

    absolute_time_t start =
        get_absolute_time();

    for (int i = 0; i < 1000; i++)
    {
        EEPROM_Read(
            0x000000,
            buffer,
            sizeof(buffer)
        );
    }

    int64_t elapsed_us =
        absolute_time_diff_us(
            start,
            get_absolute_time()
        );

    DEBUG(
        "256KB READ TIME: %lld us",
        elapsed_us
    );

    double mb_per_sec =
        (256.0 / 1024.0) /
        ((double)elapsed_us / 1000000.0);

    DEBUG(
        "READ SPEED: %.2f MB/s",
        mb_per_sec
    );

    DEBUG("=== EEPROM FULL TEST PASSED ===");

    return true;
}