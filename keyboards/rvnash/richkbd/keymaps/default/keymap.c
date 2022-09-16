#include QMK_KEYBOARD_H
#include "keymap.h"

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = U_MACRO_VA_ARGS(LAYOUT_richkbd, COLEMAK_LAYER),
  [QWERTY]  = U_MACRO_VA_ARGS(LAYOUT_richkbd, QWERTY_LAYER),
  [NAV]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, NAV_LAYER),
  [MOUSE]   = U_MACRO_VA_ARGS(LAYOUT_richkbd, MOUSE_LAYER),
  [MEDIA]   = U_MACRO_VA_ARGS(LAYOUT_richkbd, MEDIA_LAYER),
  [NUM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, NUM_LAYER),
  [SYM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, SYM_LAYER),
  [FUN]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, FUN_LAYER),
  [BUTTON]  = U_MACRO_VA_ARGS(LAYOUT_richkbd, BUTTON_LAYER)
};

