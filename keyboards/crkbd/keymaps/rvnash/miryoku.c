#include QMK_KEYBOARD_H
#include "miryoku.h"

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = U_MACRO_VA_ARGS(LAYOUT_miryoku, COLEMAK_LAYER),
  [QWERTY]  = U_MACRO_VA_ARGS(LAYOUT_miryoku, QWERTY_LAYER),
  [NAV]     = U_MACRO_VA_ARGS(LAYOUT_miryoku, NAV_LAYER),
  [MOUSE]   = U_MACRO_VA_ARGS(LAYOUT_miryoku, MOUSE_LAYER),
  [MEDIA]   = U_MACRO_VA_ARGS(LAYOUT_miryoku, MEDIA_LAYER),
  [NUM]     = U_MACRO_VA_ARGS(LAYOUT_miryoku, NUM_LAYER),
  [SYM]     = U_MACRO_VA_ARGS(LAYOUT_miryoku, SYM_LAYER),
  [FUN]     = U_MACRO_VA_ARGS(LAYOUT_miryoku, FUN_LAYER),
  [BUTTON]  = U_MACRO_VA_ARGS(LAYOUT_miryoku, BUTTON_LAYER)
};

