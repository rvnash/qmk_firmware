#pragma once
#include QMK_KEYBOARD_H

enum layers { COLEMAK, QWERTY, BUTTON, NAV, MOUSE, MEDIA, NUM, SYM, FUN, NUM_LAYERS };

enum keyboard_keycodes {
    OLED_BRIU = SAFE_RANGE,
    NEW_SAFE_RANGE  // Important!
};
