#include QMK_KEYBOARD_H
#ifdef OLED_ENABLE
#  include "oled.h"
#endif
#include "rgb_layers.h"
#include "miryoku.h"
#include "transactions.h"

// Keep local track of the amount of time since last keypress
static uint32_t idle_timer;
static uint32_t scan_count = 0;
static uint32_t scan_disp_timer;

#ifdef OLED_ENABLE
static uint8_t oled_brightness = OLED_BRIGHTNESS;

void sync_oled_brightness_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    oled_brightness = *(const uint8_t*)in_data;
}
#endif

void keyboard_post_init_user(void)
{
#ifdef OLED_ENABLE
  oled_on();
  oled_set_brightness(oled_brightness);
  if (is_keyboard_master()) {
    oled_render_layer_state(layer_state, is_caps_word_on());
  } else {
    oled_render_logo();
  }
  transaction_register_rpc(SYNC_OLED_BRIGHTNESS, sync_oled_brightness_slave_handler);
#endif
  idle_timer = timer_read32();
  scan_disp_timer = timer_read32();
  rgb_layers_init();
}

void matrix_scan_user(void)
{
    ++scan_count;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
#ifdef OLED_ENABLE
  if (record->event.pressed) {
    oled_render_key(keycode, record);
  }
#endif
  idle_timer = timer_read32();
  switch(keycode) {
      case OLED_BRIU:
        if (record->event.pressed) {
#ifdef OLED_ENABLE
            if (get_mods() & MOD_MASK_SHIFT) {
              if (oled_brightness - OLED_BRIGHTNESS_STEP < 0 )
                oled_brightness = 0;
              else
                oled_brightness -= OLED_BRIGHTNESS_STEP;
            } else {
              if (oled_brightness + OLED_BRIGHTNESS_STEP > 255 )
                oled_brightness = 255;
              else
                oled_brightness += OLED_BRIGHTNESS_STEP;
            }
            transaction_rpc_exec(SYNC_OLED_BRIGHTNESS, sizeof(oled_brightness), &oled_brightness, 0, NULL);
        }
        return false;
#endif
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
  if (is_keyboard_master()) {
    rgb_layer_set_leds(state);
#ifdef OLED_ENABLE
    oled_render_layer_state(state, is_caps_word_on());
#endif
  }
  return state;
}

void caps_word_set_user(bool active)
{
  if (is_keyboard_master()) {
    rgb_caps_word_set_leds(active);
#ifdef OLED_ENABLE
    oled_render_layer_state(layer_state, active);
#endif
  }
}

#ifdef OLED_ENABLE
uint32_t last_displayed_idle_secs = 99999;
#endif
bool rgb_was_on_and_timed_out = false;

void housekeeping_task_user(void)
{
  if (is_keyboard_master()) {
    uint32_t elapsed_idle_secs = timer_elapsed32(idle_timer) / 1000;
    uint32_t elapsed_scan_ms = timer_elapsed32(scan_disp_timer);
#ifdef OLED_ENABLE
    if (elapsed_idle_secs != last_displayed_idle_secs) {
      last_displayed_idle_secs = elapsed_idle_secs;
      if (elapsed_idle_secs < OLED_TIMEOUT_SECS) {
        oled_render_idle(OLED_TIMEOUT_SECS - elapsed_idle_secs);
      } else {
        // OLED timed out
        if (is_oled_on()) oled_off();
      }
    }
    oled_render_led_state();
    if (elapsed_scan_ms > 1000) {
        uint32_t scans_per_sec = (uint32_t)((float)scan_count/((float)elapsed_scan_ms/1000.0));
        if (is_oled_on()) oled_render_scan_rate(scans_per_sec);
        scan_count = 0;
        scan_disp_timer = timer_read32();
    }
#endif
    if (elapsed_idle_secs > RGB_TIMEOUT_SECS) {
      if (rgblight_is_enabled()) {
        rgblight_toggle();
        rgb_was_on_and_timed_out = true;
      }
    } else {
      // Turn the LEDs back on if they are off, and we previously turned them off
      if (rgb_was_on_and_timed_out && !rgblight_is_enabled()) {
        rgblight_toggle();
        rgb_was_on_and_timed_out = false;
      }
    }
  }
#ifdef OLED_ENABLE
  if (oled_brightness != oled_get_brightness()) {
    oled_set_brightness(oled_brightness);
  }
#endif
}
