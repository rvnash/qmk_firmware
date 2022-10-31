/* Copyright 2022 rvnash
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "oled.h"
#include "oled_logos.h"
#include "keymap.h"
#include "persist.h"
#include "asteroids/asteroids_main.h"

static bool is_resetting = false;
static bool is_oled_in_on_mode = false;
static bool is_in_screen_timed_out_state = false;
static bool is_running_astroids = false;

static bool is_screen_saver_on = false;
static int chosen_screen_saver_image = 0;
static int active_screen_saver_image = 0;

static uint32_t idle_timer;

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
  return OLED_ROTATION_180;
}

void oled_post_init_user(void)
{
    wait_ms(300); // Not sure why I need this, but the oled will not start in the on state without it
    PersistedConfig pc = persist_read_state();
    chosen_screen_saver_image = pc.screensaver_logo;
    is_oled_in_on_mode = pc.oled_on;
    is_oled_in_on_mode ? oled_on() : oled_off();
    oled_set_brightness(pc.oled_brightness);
    idle_timer = timer_read32();
    is_in_screen_timed_out_state = false;
}

void oled_flush(void)
{
    // Need to call oled_task() repeatedly for a while to complete rendering
    uint16_t timer_start = timer_read();
    while (timer_elapsed(timer_start) < 200) {
        oled_task();
    }
}

void oled_shutdown_user(void)
{
    is_resetting = true;
    oled_clear();
    oled_set_cursor(0, 3);
    oled_write("Entering BOOTLOADER", false);
    oled_flush();
}

uint8_t getPix(const uint8_t *img, uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
   if (x >= w || y >= h ) return 0;
   uint16_t byte = ((y/8) * w) + x;
   uint8_t bit = (y % 8);
  return (img[byte] >> bit) & 0x1;
}

void oled_write_image(Image image, uint8_t x_screen, uint8_t y_screen, bool transparent, bool flipX, bool flipY )
{
    uint8_t w = image.w;
    uint8_t h = image.h;
    const uint8_t *img = image.img;
    uint8_t iX, iY;
    for (uint8_t y = y_screen; y < y_screen + h; y++) {
        if (flipY) iY = h-(y-y_screen);
        else       iY = y-y_screen;
        for (uint8_t x = x_screen; x < x_screen + w; x++) {
            if (flipX) iX = w-(x-x_screen);
            else       iX = x-x_screen;
            bool pix = getPix(img, iX, iY, w, h);
            if (!transparent || pix) oled_write_pixel( x,  y, pix );
        }
    }
}

void render_screen_saver(bool start)
{
    static uint16_t logo_timer = 0;
#define SWITCH_IMAGE_INTERVAL 30000
    static uint16_t random_timer = 0;
    static int xpos = 0;
    static int ypos = 0;
    static int dir = 1;

    if (start) {
        logo_timer = timer_read();
        random_timer = timer_read();
        ypos = 64;
    }
    if (chosen_screen_saver_image < 0 && timer_elapsed(random_timer) >= SWITCH_IMAGE_INTERVAL) {
        random_timer = timer_read();
        active_screen_saver_image = random() % num_screen_saver_images;
        oled_clear();
    }
    if (timer_elapsed(logo_timer) > 20) {
        logo_timer = timer_read();
        xpos += dir;
        if (xpos <= 0) dir = 1;
        if (xpos >= 128-screen_saver_images[active_screen_saver_image].w ) dir = -1;
        if (ypos > 0) ypos--;
        oled_write_image(screen_saver_images[active_screen_saver_image], xpos, ypos,
                         false, screen_saver_images[active_screen_saver_image].flip ? (dir > 0) : false, false);
    }
}

void render_mods(bool force)
{
    static int last_mods = -1;
    int mods = get_mods();
    if (force || last_mods != mods) {
        last_mods = mods;
        int highest_layer = get_highest_layer(layer_state|default_layer_state);
        oled_set_cursor(6, 6);
        if (highest_layer < STD_QWERTY) {
            oled_write((mods & MOD_BIT(KC_LCTL)) ? "C" : " ", (mods & MOD_BIT(KC_LCTL)) );
            oled_write((mods & MOD_BIT(KC_LALT)) ? "A" : " ", (mods & MOD_BIT(KC_LALT)) );
            oled_write((mods & MOD_BIT(KC_LCMD)) ? "@" : " ", (mods & MOD_BIT(KC_LCMD)) );
            oled_write((mods & MOD_BIT(KC_LSFT)) ? "S" : " ", (mods & MOD_BIT(KC_LSFT)) );
            oled_write((mods & MOD_BIT(KC_RSFT)) ? "S" : " ", (mods & MOD_BIT(KC_RSFT)) );
            oled_write((mods & MOD_BIT(KC_RGUI)) ? "@" : " ", (mods & MOD_BIT(KC_RGUI)) );
            oled_write((mods & MOD_BIT(KC_RALT)) ? "A" : " ", (mods & MOD_BIT(KC_RALT)) );
            oled_write((mods & MOD_BIT(KC_RCTL)) ? "C" : " ", (mods & MOD_BIT(KC_RCTL)) );
        } else {
            oled_write((mods & MOD_BIT(KC_LCTL)) ? "C" : " ", (mods & MOD_BIT(KC_LCTL)) );
            oled_write((mods & MOD_BIT(KC_LSFT)) ? "S" : " ", (mods & MOD_BIT(KC_LSFT)) );
            oled_write((mods & MOD_BIT(KC_LCMD)) ? "@" : " ", (mods & MOD_BIT(KC_LCMD)) );
            oled_write((mods & MOD_BIT(KC_RALT)) ? "A" : " ", (mods & MOD_BIT(KC_RALT)) );
            oled_write("    ", false);
        }
    }
}

void render_layer(bool force)
{
    static int last_layer = -1;
    int highest_layer = get_highest_layer(layer_state|default_layer_state);
    if (force || highest_layer != last_layer) {
        char buf[22];
        last_layer = highest_layer;
        snprintf(buf, sizeof(buf), "Mode: %-20s", layers_to_names[highest_layer]);
        oled_set_cursor(0, 0);
        oled_write(buf, false);
        render_mods(true); // Changing the layer can effect the mods format.
    }
}

void render_led_state(bool force)
{
    static int last_led_mode = -1;
    static int last_h=0, last_s=0, last_v=0, last_oled_v = 0, last_speed = 0;
    static char *led_state_names[] = RGB_MATRIX_NAMES;

    int led_mode = rgb_matrix_is_enabled() ? rgb_matrix_get_mode() : -1;
    int h = rgb_matrix_get_hue();
    int s = rgb_matrix_get_sat();
    int v = rgb_matrix_get_val();
    int speed = rgb_matrix_get_speed();
    int oled_v = oled_get_brightness();
    if (force || led_mode != last_led_mode || h != last_h || s != last_s || v != last_v || oled_v != last_oled_v || speed != last_speed) {
        char buf[22];
        last_led_mode = led_mode;
        last_h = h;
        last_s = s;
        last_v = v;
        last_speed = speed;
        last_oled_v = oled_v;
        snprintf(buf, sizeof(buf), "LED : %-20s", led_mode > 0 ? led_state_names[led_mode-1] : "Off");
        oled_set_cursor(0, 1);
        oled_write(buf, false);
        snprintf(buf, sizeof(buf), "HSVP: %3d,%3d,%3d:%3d", h, s, v, speed);
        oled_set_cursor(0, 2);
        oled_write(buf, false);
        snprintf(buf, sizeof(buf), "OLED: %3d", oled_v);
        oled_set_cursor(0, 4);
        oled_write(buf, false);
    }
}

void render_wpm(bool force)
{
    static int last_wpm = -1;
    int wpm = get_current_wpm();
    if (force || last_wpm != wpm) {
        char buf[22];
        last_wpm = wpm;
        oled_set_cursor(14, 6);
        snprintf(buf, sizeof(buf), "%3d", wpm);
        oled_write(buf, false);
    }
}

void render_key(uint16_t keycode, keyrecord_t *record)
{
  char str[6];

  int row = record->event.key.row;
  int col = record->event.key.col;
  snprintf(str, sizeof(str), "%1d x%2d", row, col);
  oled_set_cursor(0, 6);
  oled_write(str, false);
}

void render_all_data(bool force)
{
    render_layer(force);
    render_mods(force);
    render_wpm(force);
    render_led_state(force);
}

void render_image(void)
{
    if (!is_in_screen_timed_out_state && is_oled_in_on_mode) {
        oled_clear();
        if (chosen_screen_saver_image < 0) {
            oled_set_cursor(7, 3);
            oled_write("Random", false);
        } else {
            oled_write_image(screen_saver_images[chosen_screen_saver_image], (128-screen_saver_images[chosen_screen_saver_image].w)/2, 0, false, false, false);
        }
    }
}

void turn_screen_saver_off(void)
{
    uprintf("Screen Saver off\n");
    is_screen_saver_on = false;
    if (is_oled_in_on_mode) {
        oled_clear();
        render_all_data(true);
    }
}

void turn_screen_saver_on(void)
{
    uprintf("Screen Saver on\n");
    is_screen_saver_on = true;
    if (chosen_screen_saver_image < 0) {
        srand(timer_read32());
        active_screen_saver_image = random() % num_screen_saver_images;
    } else {
        active_screen_saver_image = chosen_screen_saver_image;
    }
    if (!is_in_screen_timed_out_state && is_oled_in_on_mode) {
        oled_clear();
        render_screen_saver(true);
    }
}

bool oled_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  idle_timer = timer_read32();
  if (is_in_screen_timed_out_state) {
    is_in_screen_timed_out_state = false;
    if (is_oled_in_on_mode) {
        uprintf("TURN ON LED\n");
        oled_on();
    }
  }
  if (is_screen_saver_on) {
    turn_screen_saver_off();
  }
  if (is_running_astroids) {
    if (record->event.key.col == 1 && record->event.key.row == 1 && record->event.pressed) {
        is_running_astroids = false;
        oled_clear();
        render_all_data(true);
    } else {
        asteroids_process_record_user(keycode, record);
    }
    // Doing ASTROIDS takes over the keyboard and no keys get through
    return false;
  }
  if (record->event.pressed && is_oled_in_on_mode) {
    render_key(keycode, record);
  }
  switch (keycode) {
    case OLED_BRIU:
      if (record->event.pressed) {
        int brightness = oled_get_brightness();
        if (get_mods() & MOD_MASK_SHIFT) {
            brightness -= OLED_BRIGHTNESS_STEP;
            if (brightness < 0) brightness = 0;
        } else {
            brightness += OLED_BRIGHTNESS_STEP;
            if (brightness > 255) brightness = 255;
        }
        if (is_oled_in_on_mode) {
            oled_set_brightness(brightness);
        }
        persist_update_oled_brightness(brightness);
      }
      return false;
    case OLED_TOG:
      if (record->event.pressed) {
        if (!is_oled_in_on_mode) {
            is_oled_in_on_mode = true;
            oled_on();
        } else {
            is_oled_in_on_mode = false;
            oled_flush();
            oled_off();
        }
        persist_update_oled_on(is_oled_in_on_mode);
      }
      return false;
    case OLED_LOGO:
      if (record->event.pressed) {
          if (get_mods() & MOD_MASK_SHIFT) {
              chosen_screen_saver_image -= 1;
              if (chosen_screen_saver_image < -1) chosen_screen_saver_image = num_screen_saver_images-1;
          } else {
             chosen_screen_saver_image += 1;
             if (chosen_screen_saver_image >= num_screen_saver_images) chosen_screen_saver_image = -1;
          }
          render_image();
          persist_update_screensaver_logo(chosen_screen_saver_image);
      } else {
          if (is_oled_in_on_mode) {
              oled_clear();
              render_all_data(true);
          }
      }
      return false;
    case ASTROIDS:
      if (record->event.pressed) {
        if (is_oled_in_on_mode) {
            is_running_astroids = true;
            oled_clear();
            layer_clear();
            asteroids_init();
        }
      }
      return false;
    default:
      return true; // Process all other keycodes normally
  }
}

void check_oled_timeout(void)
{
    if (is_oled_in_on_mode && !is_in_screen_timed_out_state && timer_elapsed32(idle_timer) >= MY_OLED_TIMEOUT) {
        // The idle time is from the last screen update, so we need to turn it off manually
uprintf("TIMEOUT Turn OLED OFF\n");
        is_running_astroids = false;
        oled_flush();
        oled_off();
        is_in_screen_timed_out_state = true;
        return;
    }

}

void check_screen_saver(void)
{
    if (timer_elapsed32(idle_timer) > OLED_SCREEN_SAVER_MS) {
        turn_screen_saver_on();
    }
}

void oled_housekeeping(void)
{
    check_oled_timeout();
    if (is_running_astroids) {
        asteroids_pump();
        return;
    }
    if (!is_resetting && is_oled_in_on_mode && !is_in_screen_timed_out_state) {
        if (is_screen_saver_on) {
            render_screen_saver(false);
        } else {
            render_all_data(false);
            check_screen_saver();
        }
    }
}

bool is_oled_playing_asteroids(void)
{
    return is_running_astroids;
}
