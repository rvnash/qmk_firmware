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

void oled_post_init_user(void);
void oled_shutdown_user(void);
void oled_housekeeping(void);
bool oled_process_record_user(uint16_t keycode, keyrecord_t *record);
bool is_oled_playing_asteroids(void);
void oled_render_all_data(bool force);
