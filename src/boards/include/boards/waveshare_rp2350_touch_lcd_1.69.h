/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

// This header may be included by other board headers as "boards/waveshare_rp2350_touch_lcd_1.69.h"

// not (yet) an official pico-sdk board header -- authored locally, modeled closely on
// the upstream waveshare_rp2350_touch_lcd_1.28.h sibling (same board family, same
// baseboard design), with pin numbers taken from this board's own schematic + wiki pin
// table rather than assumed from the sibling

#ifndef _BOARDS_WAVESHARE_RP2350_TOUCH_LCD_1_69_H
#define _BOARDS_WAVESHARE_RP2350_TOUCH_LCD_1_69_H

pico_board_cmake_set(PICO_PLATFORM, rp2350)

// For board detection
#define WAVESHARE_RP2350_TOUCH_LCD_1_69

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

// --- I2C --- (shared bus: touch controller, IMU, and RTC all sit on this one bus)
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
#ifndef PICO_DEFAULT_SPI
#define PICO_DEFAULT_SPI 0
#endif
#ifndef PICO_DEFAULT_SPI_SCK_PIN
#define PICO_DEFAULT_SPI_SCK_PIN 18
#endif
#ifndef PICO_DEFAULT_SPI_TX_PIN
#define PICO_DEFAULT_SPI_TX_PIN 19
#endif
#ifndef PICO_DEFAULT_SPI_CSN_PIN
#define PICO_DEFAULT_SPI_CSN_PIN 17
#endif

// --- LCD (ST7789-family, 240x280) ---
// GPIO8-11 mux to SPI1 hardware (not SPI0) on RP2350 -- same pin group crossfire's PO13
// display uses on spi1
#ifndef WAVESHARE_LCD_SPI
#define WAVESHARE_LCD_SPI 1
#endif
#ifndef WAVESHARE_LCD_DC_PIN
#define WAVESHARE_LCD_DC_PIN 8
#endif
#ifndef WAVESHARE_LCD_CS_PIN
#define WAVESHARE_LCD_CS_PIN 9
#endif
#ifndef WAVESHARE_LCD_SCLK_PIN
#define WAVESHARE_LCD_SCLK_PIN 10
#endif
#ifndef WAVESHARE_LCD_TX_PIN
#define WAVESHARE_LCD_TX_PIN 11
#endif
#ifndef WAVESHARE_LCD_RST_PIN
#define WAVESHARE_LCD_RST_PIN 13
#endif
#ifndef WAVESHARE_LCD_BL_PIN
#define WAVESHARE_LCD_BL_PIN 25
#endif

// --- Touch (CST816T) ---
#ifndef WAVESHARE_TP_INT_PIN
#define WAVESHARE_TP_INT_PIN 21
#endif
#ifndef WAVESHARE_TP_RST_PIN
#define WAVESHARE_TP_RST_PIN 22
#endif

// --- IMU (QMI8658C) ---
#ifndef WAVESHARE_IMU_INT1_PIN
#define WAVESHARE_IMU_INT1_PIN 23
#endif
#ifndef WAVESHARE_IMU_INT2_PIN
#define WAVESHARE_IMU_INT2_PIN 24
#endif

// --- ADC ---
#ifndef WAVESHARE_BAT_ADC_PIN
#define WAVESHARE_BAT_ADC_PIN 29
#endif

// --- FLASH ---
// W25Q128JVSIQ (16MB) -- same boot-compatible command set as W25Q080, just larger
#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif

pico_board_cmake_set_default(PICO_FLASH_SIZE_BYTES, (16 * 1024 * 1024))
#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (16 * 1024 * 1024)
#endif

// unlike the 1.28" sibling, this board doesn't wire GPIO23 to SMPS mode select -- that
// pin is IMU_INT1 here, so PICO_SMPS_MODE_PIN is deliberately left unset (default SMPS
// behavior applies)

pico_board_cmake_set_default(PICO_RP2350_A2_SUPPORTED, 1)
#ifndef PICO_RP2350_A2_SUPPORTED
#define PICO_RP2350_A2_SUPPORTED 1
#endif

#endif
