/* Copyright 2022 rvnash
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// LED defines
#define DRIVER_LED_TOTAL 42 // How many RGB lights are present across all drivers
#define RGBLED_NUM 42 // How many LEDs are in the key backlighting (all of them)
#define RGB_DI_PIN GP14 // The pin to send out the pixels chain
#define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
#define WS2812_TRST_US 80 // These neopixels can support cycle times this fast

// OLED display
#define OLED_DISPLAY_128X64
#define I2C1_SCL_PIN        GP1
#define I2C1_SDA_PIN        GP0
#define I2C_DRIVER I2CD1
#define OLED_FONT_H "glcdfont.c"
