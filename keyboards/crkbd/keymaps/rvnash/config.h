#pragma once

#define MASTER_LEFT

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 250

// Mod-tap settings
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// permissive hold activates the modifier when another key is pressed and released while the mod-tap is held, regardless of the tapping term.
#define PERMISSIVE_HOLD

// releasing the key without pressing another will send the original keycode even if it is outside the tapping term.
// #define RETRO_TAPPING

// CAPS WORD settings
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

#define RGBLIGHT_LAYERS

#ifdef RGBLIGHT_ENABLE
//    #define RGBLIGHT_EFFECT_BREATHING
//    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//    #define RGBLIGHT_EFFECT_SNAKE
//    #define RGBLIGHT_EFFECT_KNIGHT
//    #define RGBLIGHT_EFFECT_CHRISTMAS
#  define RGBLIGHT_EFFECT_STATIC_GRADIENT
//    #define RGBLIGHT_EFFECT_RGB_TEST
//    #define RGBLIGHT_EFFECT_ALTERNATING
//    #define RGBLIGHT_EFFECT_TWINKLE
#  define RGBLIGHT_LIMIT_VAL 150
#  define RGBLIGHT_HUE_STEP 10
#  define RGBLIGHT_SAT_STEP 17
#  define RGBLIGHT_VAL_STEP 17
#endif

#define RGB_TIMEOUT_SECS 1200
#define OLED_TIMEOUT_SECS 100
#define OLED_BRIGHTNESS 20
#define OLED_BRIGHTNESS_STEP 20

#define SPLIT_OLED_ENABLE

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define SPLIT_TRANSACTION_IDS_USER SYNC_OLED_BRIGHTNESS
