#include "oled.h"
#include "oled_logos.h"
#include "keymap.h"


// Note, 128x64 OLED is 21 characters x 8 lines, with the last 2 lines being yellow.

static bool resetting = false;
static bool screen_save = false;
static bool oled_on_user = false;
static int screen_saver_image = 0;
static uint32_t idle_timer;
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
  return OLED_ROTATION_180;
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

void oled_post_init_user(void)
{
    wait_ms(300); // Not sure why I need this, but the oled will not start in the on state without it
    oled_on();
    oled_on_user = true;
    idle_timer = timer_read32();
}

void oled_shutdown_user(void)
{
    resetting = true;
    oled_clear();
    oled_set_cursor(0, 3);
    oled_write("Entering BOOTLOADER", false);
    // Need to call oled_task() repeatedly to complete rendering. 100ms should be enough
    uint16_t timer_start = timer_read();
    while (timer_elapsed(timer_start) < 200) {
        oled_task();
    }
}

void screen_saver(bool start)
{
    static uint16_t logo_timer = 0;
    static int xpos = 0;
    static int ypos = 0;
    static int dir = 1;

    if (start) {
        logo_timer = timer_read();
        ypos = 64;
    }
    if (timer_elapsed(idle_timer) >= MY_OLED_TIMEOUT) {
        // The idle time is from the last screen update, so we need to turn it off manually
        oled_off();
        return;
    }
    if (timer_elapsed(logo_timer) > 20) {
        logo_timer = timer_read();
        xpos += dir;
        if (xpos <= 0) dir = 1;
        if (xpos >= 128-screen_saver_images[screen_saver_image].w ) dir = -1;
        if (ypos > 0) ypos--;
        oled_write_image(screen_saver_images[screen_saver_image], xpos, ypos, false, screen_saver_images[screen_saver_image].flip ? (dir > 0) : false, false);
    }
}

void mods(bool force)
{
    static int last_mods = -1;
    int mods = get_mods();
    if (force || last_mods != mods) {
        last_mods = mods;
        int highest_layer = get_highest_layer(layer_state|default_layer_state);
        oled_set_cursor(0, 1);
        oled_write("Mods: ", false);
        if (highest_layer < STD_QWERTY) {
            oled_write("C", (mods & MOD_BIT(KC_LCTL)));
            oled_write("A", (mods & MOD_BIT(KC_LALT)));
            oled_write("@", (mods & MOD_BIT(KC_LCMD)));
            oled_write("S", (mods & MOD_BIT(KC_LSFT)));
            oled_write("S", (mods & MOD_BIT(KC_RSFT)));
            oled_write("@", (mods & MOD_BIT(KC_RGUI)));
            oled_write("A", (mods & MOD_BIT(KC_RALT)));
            oled_write("C", (mods & MOD_BIT(KC_RCTL)));
        } else {
            oled_write("C", (mods & MOD_BIT(KC_LCTL)));
            oled_write("S", (mods & MOD_BIT(KC_LSFT)));
            oled_write("@", (mods & MOD_BIT(KC_LCMD)));
            oled_write("A", (mods & MOD_BIT(KC_RALT)));
            oled_write("    ", false);
        }
    }
}

void layer(bool force)
{
    static int last_layer = -1;
    int highest_layer = get_highest_layer(layer_state|default_layer_state);
    if (force || highest_layer != last_layer) {
        char buf[22];
        last_layer = highest_layer;
        snprintf(buf, sizeof(buf), "Mode: %-20s", layers_to_names[highest_layer]);
        oled_set_cursor(0, 0);
        oled_write(buf, false);
        mods(true);
    }
}

void led_state(bool force)
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
        snprintf(buf, sizeof(buf), "LED: %-20s", led_mode > 0 ? led_state_names[led_mode-1] : "Off");
        oled_set_cursor(0, 3);
        oled_write(buf, false);
        snprintf(buf, sizeof(buf), "HSVP: %3d,%3d,%3d:%3d", h, s, v, speed);
        oled_set_cursor(0, 4);
        oled_write(buf, false);
        snprintf(buf, sizeof(buf), "Display Bright: %3d", oled_v);
        oled_set_cursor(0, 5);
        oled_write(buf, false);
    }
}

void wpm(bool force)
{
#define SMOOTHING_FACT 0.0001
    static float smooth_wpm = 0.0;
    static int last_wpm = -1;
    smooth_wpm = SMOOTHING_FACT * get_current_wpm() + (1.0 - SMOOTHING_FACT) * smooth_wpm;
    int wpm = smooth_wpm;
    if (force || last_wpm != wpm) {
        char buf[22];
        last_wpm = wpm;
        oled_set_cursor(0, 2);
        snprintf(buf, sizeof(buf), "WPM: %3d                   ", wpm);
        oled_write(buf, false);
    }
}

void key(uint16_t keycode, keyrecord_t *record)
{
  char str[6];

  int row = record->event.key.row;
  int col = record->event.key.col;
  snprintf(str, sizeof(str), "%1d x%2d", row, col);
  oled_set_cursor(0, 6);
  oled_write(str, false);
}

void screen_save_off(void)
{
    if (oled_on_user && !is_oled_on()) oled_on();
    screen_save = false;
    oled_clear();
    layer(true);
    mods(true);
    wpm(true);
    led_state(true);
}

void screen_save_on(void)
{
    screen_save = true;
    oled_clear();
    screen_saver(true);
}

bool oled_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  idle_timer = timer_read32();
  if (screen_save) {
    screen_save_off();
  }
  if (record->event.pressed && oled_on_user) {
    key(keycode, record);
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
        oled_set_brightness(brightness);
      }
      return false;
    case OLED_TOG:
      if (record->event.pressed) {
        if (!is_oled_on()) {
            oled_on();
            uprint("on\n");
            oled_on_user = true;
        } else {
            oled_off();
            uprint("off\n");
            oled_on_user = false;
        }
      }
      return true;
    case OLED_LOGO:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            screen_saver_image -= 1;
            if (screen_saver_image < 0) screen_saver_image = num_screen_saver_images-1;
        } else {
            screen_saver_image += 1;
            if (screen_saver_image >= num_screen_saver_images) screen_saver_image = 0;
        }

      }
      return false;
    default:
      return true; // Process all other keycodes normally
  }
}

void check_screen_saver(void)
{
    if (timer_elapsed32(idle_timer) > OLED_SCREEN_SAVER_MS) {
        screen_save_on();
    }
}

void oled_housekeeping(void)
{
    if (!oled_on_user) {
       // if (is_oled_on()) oled_off(); // The OLED can keep trying to come on its own
        return;
    }
    if (screen_save) {
      screen_saver(false);
    } else {
      layer(false);
      mods(false);
      wpm(false);
      led_state(false);
      check_screen_saver();
    }
}

bool oled_task_user(void)
{
    if (resetting ) return false; // no more info if we are rebooting
    //oled_housekeeping();
    return false;
}


