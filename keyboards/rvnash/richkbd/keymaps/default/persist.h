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

#pragma once
#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    uint8_t oled_brightness;
    int8_t screensaver_logo;
    bool oled_on;
  };
} PersistedConfig;

PersistedConfig persist_read_state(void);
void persist_update_state(PersistedConfig pc);
void persist_update_oled_brightness(uint8_t oled_brightness);
void persist_update_screensaver_logo(int8_t screensaver_logo);
void persist_update_oled_on(bool oled_on);
