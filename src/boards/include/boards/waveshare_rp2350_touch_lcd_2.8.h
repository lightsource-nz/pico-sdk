/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

// This header may be included by other board headers as "boards/waveshare_rp2350_touch_lcd_2.8.h"

// not (yet) an official pico-sdk board header -- authored locally, modeled on the (also
// locally-authored) waveshare_rp2350_touch_lcd_1.69.h sibling. Pin numbers are taken from
// the board's official schematic
// (https://files.waveshare.com/wiki/RP2350-Touch-LCD-2.8/RP2350-Touch-LCD-2.8-Schematic.pdf),
// cross-checked against two independent open-source drivers for this exact board, NOT yet
// against hardware -- no board is on hand at the time of writing

#ifndef _BOARDS_WAVESHARE_RP2350_TOUCH_LCD_2_8_H
#define _BOARDS_WAVESHARE_RP2350_TOUCH_LCD_2_8_H

pico_board_cmake_set(PICO_PLATFORM, rp2350)

// For board detection
#define WAVESHARE_RP2350_TOUCH_LCD_2_8

// --- RP2350 VARIANT ---
#define PICO_RP2350A 1

// --- UART ---
#ifndef PICO_DEFAULT_UART
#define PICO_DEFAULT_UART 0
#endif
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 0
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 1
#endif

// no PICO_DEFAULT_WS2812_PIN

// --- I2C --- (shared bus: touch controller, IMU, and RTC all sit on this one bus, and it
// is also what the J3/J4 expansion connectors break out)
#ifndef PICO_DEFAULT_I2C
#define PICO_DEFAULT_I2C 1
#endif
#ifndef PICO_DEFAULT_I2C_SDA_PIN
#define PICO_DEFAULT_I2C_SDA_PIN 6
#endif
#ifndef PICO_DEFAULT_I2C_SCL_PIN
#define PICO_DEFAULT_I2C_SCL_PIN 7
#endif

// --- SPI ---
// no PICO_DEFAULT_SPI: unlike the 1.69 board, nothing SPI-capable reaches a user-facing
// connector here. spi1 is consumed by the LCD, and the microSD slot's six lines are laid
// out for 4-bit PIO SDIO (its "SCK" is GP19, which muxes to SPI0 TX, not SCK -- hardware
// SPI cannot drive the card at all). The only free GPIOs are 28 and 29 on J4

// --- LCD (ST7789T3, 240x320) ---
// on real spi1 hardware: GPIO10/11 mux to SPI1 SCK/TX. GP12 is wired as SPI1 RX (the panel
// can be read) but the write-only convention every other board here follows applies
#ifndef WAVESHARE_LCD_SPI
#define WAVESHARE_LCD_SPI 1
#endif
#ifndef WAVESHARE_LCD_SCLK_PIN
#define WAVESHARE_LCD_SCLK_PIN 10
#endif
#ifndef WAVESHARE_LCD_TX_PIN
#define WAVESHARE_LCD_TX_PIN 11
#endif
#ifndef WAVESHARE_LCD_RX_PIN
#define WAVESHARE_LCD_RX_PIN 12
#endif
#ifndef WAVESHARE_LCD_CS_PIN
#define WAVESHARE_LCD_CS_PIN 13
#endif
#ifndef WAVESHARE_LCD_DC_PIN
#define WAVESHARE_LCD_DC_PIN 14
#endif
#ifndef WAVESHARE_LCD_RST_PIN
#define WAVESHARE_LCD_RST_PIN 15
#endif
#ifndef WAVESHARE_LCD_BL_PIN
#define WAVESHARE_LCD_BL_PIN 16
#endif

// --- Touch (CST328) ---
// its own reset net, unlike boards where the touch controller shares the LCD's reset line
#ifndef WAVESHARE_TP_RST_PIN
#define WAVESHARE_TP_RST_PIN 17
#endif
#ifndef WAVESHARE_TP_INT_PIN
#define WAVESHARE_TP_INT_PIN 18
#endif

// --- IMU (QMI8658C) ---
#ifndef WAVESHARE_IMU_INT1_PIN
#define WAVESHARE_IMU_INT1_PIN 8
#endif
#ifndef WAVESHARE_IMU_INT2_PIN
#define WAVESHARE_IMU_INT2_PIN 9
#endif

// --- RTC (PCF85063ATL) ---
#ifndef WAVESHARE_RTC_INT_PIN
#define WAVESHARE_RTC_INT_PIN 5
#endif

// --- I2S audio (PCM5101A DAC into an APA2068 amplifier) ---
#ifndef WAVESHARE_I2S_BCK_PIN
#define WAVESHARE_I2S_BCK_PIN 2
#endif
#ifndef WAVESHARE_I2S_LRCK_PIN
#define WAVESHARE_I2S_LRCK_PIN 3
#endif
#ifndef WAVESHARE_I2S_DIN_PIN
#define WAVESHARE_I2S_DIN_PIN 4
#endif

// --- microSD (wired for 4-bit SDIO; see the SPI note above) ---
#ifndef WAVESHARE_SD_SCK_PIN
#define WAVESHARE_SD_SCK_PIN 19
#endif
#ifndef WAVESHARE_SD_CMD_PIN
#define WAVESHARE_SD_CMD_PIN 20
#endif
#ifndef WAVESHARE_SD_D0_PIN
#define WAVESHARE_SD_D0_PIN 21
#endif

// --- Battery / power ---
// KEY_BAT is the power button (10k pull-up, reads low while pressed). BAT_EN is the
// battery power latch: on battery, firmware must drive it high early or releasing the
// power button cuts power. Irrelevant on USB, which feeds VSYS through its own diode
#ifndef WAVESHARE_KEY_BAT_PIN
#define WAVESHARE_KEY_BAT_PIN 25
#endif
#ifndef WAVESHARE_BAT_EN_PIN
#define WAVESHARE_BAT_EN_PIN 26
#endif

// --- ADC ---
// 200k/100k divider: VBAT = Vadc * 3
#ifndef WAVESHARE_BAT_ADC_PIN
#define WAVESHARE_BAT_ADC_PIN 27
#endif

// --- FLASH ---
// 16MB, per the product spec -- same boot-compatible command set as W25Q080, just larger
#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif

pico_board_cmake_set_default(PICO_FLASH_SIZE_BYTES, (16 * 1024 * 1024))
#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (16 * 1024 * 1024)
#endif

pico_board_cmake_set_default(PICO_RP2350_A2_SUPPORTED, 1)
#ifndef PICO_RP2350_A2_SUPPORTED
#define PICO_RP2350_A2_SUPPORTED 1
#endif

#endif
