#pragma once

#include QMK_KEYBOARD_H

oled_rotation_t oled_init_user(oled_rotation_t rotation);
void            oled_render_layer_state(layer_state_t state, bool is_caps_word);
void            oled_render_key(uint16_t keycode, keyrecord_t *record);
void            oled_render_led_state(void);
void            oled_render_logo(void);
void            oled_render_idle(uint32_t idle);
void            oled_render_scan_rate(uint32_t scan_rate);
