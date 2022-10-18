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

 #include QMK_KEYBOARD_H

led_config_t g_led_config = { {
        // Key Matrix to LED Index
        { 5,      6,      11,     12, 17, 18, 23, 24, 29, 30,     35,     36 },
        { 4,      7,      10,     13, 16, 19, 22, 25, 28, 31,     34,     37 },
        { 3,      8,      9 ,     14, 15, 20, 21, 26, 27, 32,     33,     38 },
        { NO_LED, NO_LED, NO_LED, 2,  1,  0,  41, 40, 39, NO_LED, NO_LED, NO_LED }
    }, {
        // LED Index to Physical Position
        { 102, 64 }, { 81, 64 }, { 61, 64 }, { 0, 43 },  { 0, 21 }, { 0, 0 },
        { 20, 0 }, { 20, 21 }, { 20, 43 }, { 41, 43 }, { 41, 21 }, { 41, 0 },
        { 61, 0 }, { 61, 21 }, { 61, 43 }, { 81, 43 }, { 81, 21 }, {  81, 0 },
        { 102, 0 }, { 102, 21 }, { 102, 43 }, { 122, 43 }, { 122, 21 }, { 122, 0 },
        { 143, 0 }, { 143, 21 }, { 143, 43 }, { 163, 43 }, { 163, 21 }, { 163, 0 },
        { 183, 0 }, { 183, 21 }, { 183, 43 }, { 204, 43 }, { 204, 21 }, { 204, 0 },
        { 224, 0 }, { 224, 21 }, {  224, 43 }, { 163, 64 }, { 143, 64 }, { 122, 64 }
    }, {
        // LED Index to Flag
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04
    }
};
