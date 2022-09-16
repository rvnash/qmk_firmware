#pragma once

#include QMK_KEYBOARD_H

void rgb_layers_init(void);
void rgb_layer_set_leds(layer_state_t state);
void rgb_caps_word_set_leds(bool active);
