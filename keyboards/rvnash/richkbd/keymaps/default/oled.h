#pragma once
#include QMK_KEYBOARD_H

void oled_post_init_user(void);
void oled_shutdown_user(void);
void oled_housekeeping(void);
bool oled_process_record_user(uint16_t keycode, keyrecord_t *record);

