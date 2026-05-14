//
// Created by nathanial on 5/12/26.
//

#include "sd_card.h"

#include <stdint.h>
#include "hardware/gpio.h"

#include "cartridge_rom.h"    // your EEPROM driver
#include "hardware.h"
#include "lib_debugging.h"
#include "pico_constants.h"


#define BUF_SIZE      512                 // read chunk size
static bool sd_sdhc = false; // false = SDSC (byte addr), true = SDHC/SDXC (block addr)

static inline uint8_t SPI_Transfer(uint8_t tx)
{
    uint8_t rx;
    spi_write_read_blocking(SPI0_A, &tx, &rx, 1);
    return rx;
}

static uint8_t SD_Command(uint8_t cmd, uint32_t arg, uint8_t crc)
{
    uint8_t buf[6] = {
        (uint8_t)(cmd | 0x40),
        (uint8_t)(arg >> 24), (uint8_t)(arg >> 16),
        (uint8_t)(arg >> 8), (uint8_t)(arg), crc
    };
    gpio_put(SD_CARD_CS, 0);
    SPI_Transfer(0xFF); // drain
    spi_write_blocking(SPI0_A, buf, 6);

    uint8_t r1;
    for (int i = 0; i < 100; i++)
    {
        r1 = SPI_Transfer(0xFF);
        if ((r1 & 0x80) == 0) return r1;
    }

    return r1; // timeout
}

void SDCard_Init()
{
    // SPI0 initted elsewhere
    gpio_init(SD_CARD_CS);
    gpio_set_dir(SD_CARD_CS, GPIO_OUT);
    gpio_put(SD_CARD_CS, 1);

    // 80 dummy clocks with CS high
    for (int i = 0; i < 10; i++) SPI_Transfer(0xFF);

    // CMD0 – reset to idle
    uint8_t r1;
    int retries = 10;
    do
    {
        r1 = SD_Command(0, 0, 0x95);
    }
    while (r1 != 0x01 && --retries);
    if (r1 != 0x01)
    {
        /* error */
    }
    gpio_put(SD_CARD_CS, 1); // ALWAYS release CS after a command

    // CMD8 – check voltage & SDHC support
    r1 = SD_Command(8, 0x000001AA, 0x87);
    if (r1 == 0x01)
    {
        uint32_t r7 = (SPI_Transfer(0xFF) << 24) |
            (SPI_Transfer(0xFF) << 16) |
            (SPI_Transfer(0xFF) << 8) |
            SPI_Transfer(0xFF);
        if ((r7 & 0xFF) == 0xAA) sd_sdhc = true; // tentative
    }
    gpio_put(SD_CARD_CS, 1); // release CS

    // ACMD41 – initialise card
    int acmd_retries = 2000;
    do
    {
        r1 = SD_Command(55, 0, 0x65);
        gpio_put(SD_CARD_CS, 1);
        r1 = SD_Command(41, sd_sdhc ? (1UL << 30) : 0, 0x65);
    }
    while (r1 == 0x01 && --acmd_retries);
    if (r1 != 0x00)
    {
        /* error */
    }
    gpio_put(SD_CARD_CS, 1);

    // Read OCR
    r1 = SD_Command(58, 0, 0x65);
    uint32_t ocr = (SPI_Transfer(0xFF) << 24) |
        (SPI_Transfer(0xFF) << 16) |
        (SPI_Transfer(0xFF) << 8) |
        SPI_Transfer(0xFF);
    gpio_put(SD_CARD_CS, 1);

    // Bit 30 = CCS; 1 = SDHC/SDXC, 0 = SDSC
    sd_sdhc = (ocr & (1UL << 30)) ? true : false;

    // Switch to full SPI speed (25 MHz)
    sleep_ms(5);
    spi_set_baudrate(SPI0_A, 25 * 1000 * 1000);
    DEBUG_INLINE("SDHC: %d\n", sd_sdhc);
}


void SDCard_ReInit(void)
{
    // Force EEPROM CS high
    gpio_put(EEPROM_CART_CS, 1);
    sleep_ms(10);

    // De-init and re-init SPI
    spi_deinit(SPI0_A);
    SPI0_Init(); // your function that sets 400 kHz, mode 0, pins

    // Fully re-init the SD card
    SDCard_Init();
}


// Minimal: read a single BUF_SIZE‑byte sector
void SDCARD_ReadSector(uint32_t sector, uint8_t* buf)
{
start:
    gpio_put(SD_CARD_CS, 0);

    // *** SEND DUMMY BYTE (required by SD spec) ***
    SPI_Transfer(0xFF);

    uint32_t addr = sd_sdhc ? sector : (sector * BUF_SIZE);
    uint8_t cmd[6] = {
        0x51, // CMD17
        (addr >> 24) & 0xFF,
        (addr >> 16) & 0xFF,
        (addr >> 8) & 0xFF,
        addr & 0xFF,
        0xFF // CRC (ignored in SPI mode)
    };
    spi_write_blocking(SPI0_A, cmd, 6);

    // Wait for R1 response (exit on non‑0xFF)
    uint32_t wait = 10000;
    uint8_t r1;
    while ((r1 = SPI_Transfer(0xFF)) == 0xFF && --wait);
    if (r1 != 0x00)
    {
        DEBUG("SDCARD_ReadSector Failed r1 != 0x00 --- r1 = %d", r1);
        gpio_put(SD_CARD_CS, 1);
        sleep_ms(1000);
        SDCard_ReInit();
        goto start;
    }

    // Wait for data start token (0xFE)
    uint32_t timeout = 100000;
    while (SPI_Transfer(0xFF) != 0xFE && --timeout);
    if (!timeout)
    {
        DEBUG("SDCARD_ReadSector Failed timed out");
        gpio_put(SD_CARD_CS, 1);
        sleep_ms(1000);
        SDCard_ReInit();
        goto start;
    }

    // Read the 512‑byte sector
    spi_read_blocking(SPI0_A, 0x00, buf, BUF_SIZE);

    // Discard 2‑byte CRC
    SPI_Transfer(0xFF);
    SPI_Transfer(0xFF);

    gpio_put(SD_CARD_CS, 1);
    DEBUG("SDCARD_ReadSector SUCCESS! ");
}


void SDCard_ProgramCartridge(uint32_t chip_size)
{
    uint8_t buf1[BUF_SIZE] = {0};
    uint8_t buf2[BUF_SIZE] = {0};
    uint8_t buf3[BUF_SIZE] = {0};

    uint32_t total_sectors = chip_size / BUF_SIZE; // e.g., 16 MB = 32768 sectors
    DEBUG("COPYING SDCard_ProgramCartridge 512 bytes per sector");

    DEBUG("Attempting Sector 0");
    SDCARD_ReadSector(0, buf1);
    sleep_ms(10);
    EEPROM_PrintBuffer(0, buf1, BUF_SIZE);
    sleep_ms(10);
    // EEPROM_WriteAny(0 * BUF_SIZE, buf1, BUF_SIZE);
    sleep_ms(2000);

    DEBUG("Attempting Sector 1");
    SDCARD_ReadSector(1, buf2);
    sleep_ms(10);
    EEPROM_PrintBuffer(2, buf2, BUF_SIZE);
    sleep_ms(10);
    // EEPROM_WriteAny(2 * BUF_SIZE, buf2, BUF_SIZE);
    sleep_ms(2000);

    DEBUG("Attempting Sector 3");
    SDCARD_ReadSector(3, buf3);
    sleep_ms(10);
    // EEPROM_PrintBuffer(3, buf3, BUF_SIZE);
    sleep_ms(10);
    EEPROM_WriteAny(3 * BUF_SIZE, buf3, BUF_SIZE, false);
}

// uint32_t sec = 0;
// while (sec < total_sectors)
// {
//     SDCARD_ReadSector(sec, buf);
//     sleep_ms(10);
//     EEPROM_PrintBuffer(sec, buf, BUF_SIZE);
//     sleep_ms(10);
//     EEPROM_WriteAny(sec * BUF_SIZE, buf, BUF_SIZE);
//
//     if (sec == 2) break;
//     sec++;
// }

bool Test_CSD(void)
{
    uint8_t csd[16];
    uint8_t r1 = SD_Command(9, 0, 0x65); // CMD9
    if (r1 != 0x00)
    {
        DEBUG("CMD9 error: 0x%02X\n", r1);
        gpio_put(SD_CARD_CS, 1);
        return false;
    }
    // Wait for data token 0xFE
    uint32_t timeout = 100000;
    while (SPI_Transfer(0xFF) != 0xFE && --timeout);
    if (!timeout)
    {
        DEBUG("token timeout\n");
        gpio_put(SD_CARD_CS, 1);
        return false;
    }
    for (int i = 0; i < 16; i++) csd[i] = SPI_Transfer(0xFF);
    (void)SPI_Transfer(0xFF);
    (void)SPI_Transfer(0xFF); // CRC
    gpio_put(SD_CARD_CS, 1);

    DEBUG("CSD: ");
    for (int i = 0; i < 16; i++)
        DEBUG("%02X ", csd[i]);
    DEBUG("\n");

    return true;
}
