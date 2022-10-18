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

#include "persist.h"

void eeconfig_init_user(void) {  // EEPROM is getting reset!
    PersistedConfig pc;
    pc.raw = 0;
    pc.oled_brightness = OLED_BRIGHTNESS;
    pc.screensaver_logo = 0;
    pc.oled_on = true;
    uprint("Initializing EEPROM state\n");
    persist_update_state(pc);
}

PersistedConfig persist_read_state(void)
{
    PersistedConfig pc;
    pc.raw = eeconfig_read_user();
    uprintf("Read EEPROM state Oled brightness: %d, logo: %d, oled on: %s\n",
            pc.oled_brightness,
            pc.screensaver_logo,
            pc.oled_on ? "ON" : "OFF");
    return pc;
}

void persist_update_state(PersistedConfig pc)
{
    uprintf("Update EEPROM state Oled brightness: %d, logo: %d, oled on: %s\n",
            pc.oled_brightness,
            pc.screensaver_logo,
            pc.oled_on ? "ON" : "OFF");
    eeconfig_update_user(pc.raw);
}

void persist_update_oled_brightness(uint8_t oled_brightness)
{
    PersistedConfig pc = persist_read_state();
    pc.oled_brightness = oled_brightness;
    persist_update_state(pc);
}

void persist_update_screensaver_logo(int8_t screensaver_logo)
{
    PersistedConfig pc = persist_read_state();
    pc.screensaver_logo = screensaver_logo;
    persist_update_state(pc);
}

void persist_update_oled_on(bool oled_on)
{
    PersistedConfig pc = persist_read_state();
    pc.oled_on = oled_on;
    persist_update_state(pc);
}
