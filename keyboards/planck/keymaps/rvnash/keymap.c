#include QMK_KEYBOARD_H
#include <stdint.h>

#include "print.h"
#include "config.h"
#include "color.h"
#include "miryoku.h"

enum layers { BASE, BUTTON, NAV, MOUSE, MEDIA, NUM, SYM, FUN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE]   = U_MACRO_VA_ARGS(LAYOUT_miryoku, BASE_LAYER),
  [NAV]    = U_MACRO_VA_ARGS(LAYOUT_miryoku, NAV_LAYER),
  [MOUSE]  = U_MACRO_VA_ARGS(LAYOUT_miryoku, MOUSE_LAYER),
  [MEDIA]  = U_MACRO_VA_ARGS(LAYOUT_miryoku, MEDIA_LAYER),
  [NUM]    = U_MACRO_VA_ARGS(LAYOUT_miryoku, NUM_LAYER),
  [SYM]    = U_MACRO_VA_ARGS(LAYOUT_miryoku, SYM_LAYER),
  [FUN]    = U_MACRO_VA_ARGS(LAYOUT_miryoku, FUN_LAYER),
  [BUTTON] = U_MACRO_VA_ARGS(LAYOUT_miryoku, BUTTON_LAYER)
};
