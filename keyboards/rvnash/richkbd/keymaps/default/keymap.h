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

enum layers { COLEMAK, QWERTY, STD_QWERTY, STD_COLEMAK, NAV, MOUSE, MEDIA, NUM, SYM, FUN, STD_NUM, STD_SYM, STD_FUNCS, NUM_LAYERS };
const char *layers_to_names[NUM_LAYERS];

enum keyboard_keycodes {
 OLED_BRIU = SAFE_RANGE,
 OLED_TOG,
 OLED_LOGO,
 ASTROIDS,
 NEW_SAFE_RANGE // Important!
};


// Layers are defined in 'LAYOUT_richkbd' format.

// ---------------------------------------------------------------------
// LAYOUT for the "miryoku" similar style that Rich prefers.
// Except CTRL and GUI are swapped on the home row mods and alot
// of the duplicate ways at getting at things are removed.
// ---------------------------------------------------------------------
#define COLEMAK_LAYER \
LSFT(LGUI(KC_4)), KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, LSFT(LGUI(KC_A)), \
LCTL_T(KC_Q), LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), KC_T, KC_G, KC_M, KC_N, RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O), LSFT(LGUI(KC_V)), \
KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
LT(MEDIA, KC_ESC), LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), LT(SYM, KC_ENT), LT(NUM, KC_BSPC), LT(FUN, KC_DEL)

#define QWERTY_LAYER \
LSFT(LGUI(KC_4)), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LSFT(LGUI(KC_A)), \
LCTL_T(KC_Q), LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), KC_F, KC_G, KC_H, KC_J, RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_QUOT), LSFT(LGUI(KC_V)), \
KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
LT(MEDIA, KC_ESC), LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), LT(SYM, KC_ENT), LT(NUM, KC_BSPC), LT(FUN, KC_DEL)

#define NAV_LAYER \
QK_BOOTLOADER, DF(COLEMAK), DF(QWERTY), DF(STD_COLEMAK), DF(STD_QWERTY), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, CAPS_WORD, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, \
LCTL(KC_LEFT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, LCTL(KC_RIGHT), \
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define MOUSE_LAYER \
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, \
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, \
KC_NO, KC_NO, KC_NO, KC_BTN1, KC_BTN3, KC_BTN2

#define MEDIA_LAYER \
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, \
KC_NO, ASTROIDS, KC_NO, KC_NO, KC_LSFT, KC_NO, OLED_TOG, OLED_LOGO, KC_NO, OLED_BRIU, KC_BRIU, KC_NO, \
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_NO, \
KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU

#define NUM_LAYER \
KC_NO, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
KC_NO, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, \
LALT(LGUI(KC_LEFT)), KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(LGUI(KC_RIGHT)), \
KC_0, KC_DOT, KC_MINS, KC_NO, KC_NO, KC_NO

#define SYM_LAYER \
KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
KC_NO, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, KC_NO, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, \
LGUI(KC_LBRC), KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_RBRC), \
KC_LPRN, KC_RPRN, KC_UNDS, KC_NO, KC_NO, KC_NO

#define FUN_LAYER \
KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOTLOADER, KC_NO, \
KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCK, KC_NO, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, \
KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, KC_NO, KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO, \
KC_APP, KC_SPC, KC_TAB, KC_NO, KC_NO, KC_NO

// ---------------------------------------------------------------------
// LAYOUT for the style most similar to the crnkbd default
// ---------------------------------------------------------------------
#define STD_COLEMAK_LAYER \
KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_COLN, KC_BSPC, \
KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, \
KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, \
KC_LGUI, MO(STD_NUM), KC_SPC, KC_ENT, MO(STD_SYM), KC_RALT

#define STD_QWERTY_LAYER \
KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, \
KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, \
KC_LGUI, MO(STD_NUM), KC_SPC, KC_ENT, MO(STD_SYM), KC_RALT


#define STD_NUM_LAYER \
KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, \
KC_LCTL, ASTROIDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT, KC_NO, \
KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
KC_LGUI, KC_NO, KC_SPC, KC_ENT, MO(STD_FUNCS), KC_RALT

#define STD_SYM_LAYER \
KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
KC_LCTL, ASTROIDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, \
KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, \
KC_LGUI, MO(STD_FUNCS), KC_SPC, KC_ENT, KC_NO, KC_RALT

#define STD_FUNCS_LAYER \
QK_BOOTLOADER, DF(COLEMAK), DF(QWERTY), DF(STD_COLEMAK), DF(STD_QWERTY), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
KC_NO, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, OLED_TOG, OLED_LOGO, KC_NO, OLED_BRIU, KC_BRIU, KC_NO, \
KC_LSFT, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_BRID, KC_NO, \
KC_LGUI, KC_NO, KC_SPC, KC_ENT, KC_NO, KC_RALT
