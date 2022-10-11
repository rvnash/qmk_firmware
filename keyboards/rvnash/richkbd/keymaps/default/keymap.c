#include "keymap.h"

// Layers are defined in 'LAYOUT_richkbd' format.
#define COLEMAK_LAYER \
TO(QWERTY),        KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,             KC_NO, \
KC_NO,             LCTL_T(KC_A),      LALT_T(KC_R),      LGUI_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              RSFT_T(KC_N),      LGUI_T(KC_E),      LALT_T(KC_I),      LCTL_T(KC_O),        KC_NO,\
LCTL(KC_LEFT),     LT(BUTTON, KC_Z),  KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            LT(BUTTON, KC_SLSH), LCTL(KC_RIGHT), \
                                      LT(MEDIA, KC_ESC), LT(NAV, KC_SPC),   LT(MOUSE, KC_TAB), LT(SYM, KC_ENT),   LT(NUM, KC_BSPC),  LT(FUN, KC_DEL)

#define QWERTY_LAYER \
TO(COLEMAK),       KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                KC_NO, \
KC_NO,             LCTL_T(KC_A),      LALT_T(KC_S),      LGUI_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              RSFT_T(KC_J),      LGUI_T(KC_K),      LALT_T(KC_L),      LCTL_T(KC_QUOT),     KC_NO,\
LCTL(KC_LEFT),     LT(BUTTON, KC_Z),  KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            LT(BUTTON, KC_SLSH), LCTL(KC_RIGHT), \
                                      LT(MEDIA, KC_ESC), LT(NAV, KC_SPC),   LT(MOUSE, KC_TAB), LT(SYM, KC_ENT),   LT(NUM, KC_BSPC),  LT(FUN, KC_DEL)

#define NAV_LAYER \
QK_BOOTLOADER,     KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,           KC_NO,             \
KC_NO,             KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_NO,              CAPS_WORD,         KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,         KC_NO,           \
KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,          KC_NO,            \
                                                         KC_NO,             KC_NO,             KC_NO,              KC_NO,              KC_NO,             KC_NO

#define MOUSE_LAYER \
QK_BOOTLOADER,     KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,           KC_NO,             \
KC_NO,             KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_NO,              KC_NO,             KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,         KC_NO,           \
KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              KC_NO,             KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,         KC_NO,           \
                                                         KC_NO,             KC_NO,             KC_NO,             KC_BTN1,            KC_BTN3,           KC_BTN2

#define MEDIA_LAYER \
QK_BOOTLOADER,     KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              RGB_TOG,           RGB_MOD,           RGB_HUI,            RGB_SAI,           RGB_VAI,        KC_NO,           \
KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_LSFT,           KC_NO,              KC_NO,             KC_NO,             KC_NO,              OLED_BRIU,         KC_BRIU,        KC_NO,           \
KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              KC_NO,             KC_NO,             KC_NO,              KC_NO,             KC_BRID,        KC_NO,           \
                                                         KC_NO,             KC_NO,             KC_NO,             KC_MUTE,            KC_VOLD,           KC_VOLU

#define NUM_LAYER \
KC_NO,             KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           KC_NO,              KC_NO,              KC_NO,              KC_NO,             KC_NO,         KC_NO,             \
KC_NO,             KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            KC_NO,              KC_LSFT,            KC_LGUI,            KC_LALT,           KC_LCTL,       KC_NO,           \
KC_NO,             KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           KC_NO,              KC_NO,              KC_NO,              KC_NO,             KC_NO,         KC_NO,              \
                                                         KC_0,             KC_DOT,             KC_MINS,           KC_NO,              KC_NO,              KC_NO

#define SYM_LAYER \
KC_NO,             KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           KC_NO,              KC_NO,             KC_NO,             KC_NO,             KC_NO,           KC_NO,             \
KC_NO,             KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           KC_NO,              KC_LSFT,           KC_LGUI,           KC_LALT,           KC_LCTL,         KC_NO,           \
KC_NO,             KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           KC_NO,              KC_NO,             KC_NO,             KC_NO,             KC_NO,           KC_NO,              \
                                                         KC_LPRN,           KC_RPRN,           KC_UNDS,           KC_NO,              KC_NO,             KC_NO

#define FUN_LAYER \
KC_NO,             KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           KC_NO,              KC_NO,             KC_NO,             KC_NO,             QK_BOOTLOADER,   KC_NO,             \
KC_NO,             KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SLCK,           KC_NO,              KC_LSFT,           KC_LGUI,           KC_LALT,           KC_LCTL,         KC_NO,           \
KC_NO,             KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           KC_NO,              KC_NO,             KC_NO,             KC_ALGR,           KC_NO,           KC_NO,              \
                                                         KC_APP,            KC_SPC,            KC_TAB,            KC_NO,             KC_NO,              KC_NO

#define BUTTON_LAYER \
KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,            KC_NO,             \
KC_NO,             KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_NO,             KC_NO,             KC_LSFT,           KC_LGUI,           KC_LALT,           KC_LCTL,          KC_NO,           \
KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,            KC_NO,             \
                                                         KC_BTN2,           KC_BTN3,           KC_BTN1,           KC_BTN1,           KC_BTN3,           KC_BTN2

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
