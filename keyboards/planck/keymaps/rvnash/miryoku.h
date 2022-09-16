#pragma once

#include "mac_keys.h"

#define BASE_LAYER \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LCTL_T(KC_A),      LALT_T(KC_R),      LGUI_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              RSFT_T(KC_N),      LGUI_T(KC_E),      LALT_T(KC_I),      LCTL_T(KC_O),      \
LT(BUTTON, KC_Z),  KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            LT(BUTTON, KC_SLSH), \
                                      LT(MEDIA, KC_ESC), LT(NAV, KC_SPC),   LT(MOUSE, KC_TAB), LT(SYM, KC_ENT),   LT(NUM, KC_BSPC),  LT(FUN, KC_DEL)

#define NAV_LAYER \
RESET,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_NO,              KC_CAPS,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
                                      KC_NO,             KC_NO,             KC_SPC,             KC_NO,             KC_NO,              KC_NO

#define MOUSE_LAYER \
RESET,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_NO,              KC_NO,             KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,              KC_NO,             KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
                                      KC_NO,             KC_SPC,            KC_NO,              KC_BTN1,           KC_BTN3,           KC_BTN2

#define MEDIA_LAYER \
RESET,             KC_NO,             KC_NO,             KC_NO,             KC_NO,              RGB_TOG,           RGB_MOD,           RGB_HUI,            RGB_SAI,           RGB_VAI,           \
KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_NO,              OUT_AUTO,          KC_NO,             KC_NO,              KC_NO,             KC_BRIU,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,              KC_NO,             CHR_BACK,          CHR_FORWARD,        KC_NO,             KC_BRID,           \
                                      KC_NO,             KC_NO,             KC_NO,              KC_MUTE,           KC_VOLD,            KC_VOLU

#define NUM_LAYER \
KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           KC_NO,              KC_NO,              KC_NO,              KC_NO,             RESET,             \
KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            KC_NO,              KC_LSFT,            KC_LGUI,            KC_LALT,           KC_LCTL,           \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           KC_NO,              KC_NO,              KC_NO,              KC_ALGR,           KC_NO,              \
                                      KC_0,             KC_DOT,             KC_MINS,           KC_NO,              KC_NO,              KC_NO

#define SYM_LAYER \
KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           KC_NO,              KC_NO,             KC_NO,             KC_NO,             RESET,             \
KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           KC_NO,              KC_LSFT,           KC_LGUI,           KC_LALT,           KC_LCTL,           \
KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           KC_NO,              KC_NO,             KC_NO,             KC_ALGR,           KC_NO,              \
                                      KC_LPRN,           KC_RPRN,           KC_UNDS,           KC_NO,              KC_NO,             KC_NO

#define FUN_LAYER \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           KC_NO,              KC_NO,             KC_NO,             KC_NO,             RESET,             \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SLCK,           KC_NO,              KC_LSFT,           KC_LGUI,           KC_LALT,           KC_LCTL,           \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           KC_NO,              KC_NO,             KC_NO,             KC_ALGR,           KC_NO,              \
                                      KC_APP,            KC_SPC,            KC_TAB,            KC_NO,              KC_NO,             KC_NO

#define BUTTON_LAYER \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_NO,             KC_NO,             KC_LSFT,           KC_LGUI,           KC_LALT,           KC_LCTL,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
                                      KC_BTN2,           KC_BTN3,           KC_BTN1,           KC_BTN1,           KC_BTN3,           KC_BTN2


#define LAYOUT_miryoku(\
K00,   K01,   K02,   K03,   K04,                 K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,                 K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,                 K25,   K26,   K27,   K28,   K29,\
              K32,   K33,   K34,                 K35,   K36,   K37\
)\
LAYOUT_ortho_4x12(\
K00,   K01,   K02,   K03,   K04,   KC_NO, KC_NO, K05,   K06,   K07,   K08,   K09,\
K10,   K11,   K12,   K13,   K14,   KC_NO, KC_NO, K15,   K16,   K17,   K18,   K19,\
K20,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, K25,   K26,   K27,   K28,   K29,\
KC_NO, KC_NO, KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   KC_NO, KC_NO, KC_NO\
)

