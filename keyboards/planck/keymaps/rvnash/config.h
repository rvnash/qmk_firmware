#pragma once

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
    #define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.


// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)
