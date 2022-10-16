#pragma once
#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    uint8_t oled_brightness;
    int8_t screensaver_logo;
    bool oled_on;
  };
} PersistedConfig;

PersistedConfig persist_read_state(void);
void persist_update_state(PersistedConfig pc);
void persist_update_oled_brightness(uint8_t oled_brightness);
void persist_update_screensaver_logo(int8_t screensaver_logo);
void persist_update_oled_on(bool oled_on);
