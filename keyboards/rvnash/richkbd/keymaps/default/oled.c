#include "oled.h"
#include "oled_logos.h"
#include "keymap.h"


// Note, 128x64 OLED is 21 characters x 8 lines, with the last 2 lines being yellow.

static bool resetting = false;
static bool screen_save = false;
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
    if (timer_elapsed(logo_timer) > 20) {
        logo_timer = timer_read();
        xpos += dir;
        if (xpos <= 0) dir = 1;
        if (xpos >= 95 ) dir = -1;
        if (ypos > 0) ypos--;
        oled_write_image(spurs_logo, xpos, ypos, false, (dir > 0), false);
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

#define SMOOTHING_FACT 0.0001
void wpm(bool force)
{
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

void screen_save_off(void)
{
    screen_save = false;
    oled_clear();
    layer(true);
    mods(true);
    wpm(true);
}

void screen_save_on(void)
{
    screen_save = true;
    oled_clear();
    screen_saver(true);
}

void oled_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  idle_timer = timer_read32();
  if (screen_save) {
    screen_save_off();
  }
}

void check_screen_saver(void)
{
    if (timer_elapsed32(idle_timer) > OLED_SCREEN_SAVER_MS) {
        screen_save_on();
    }
}

bool oled_task_user(void)
{
    if (resetting ) return false; // no more info if we are rebooting

    if (screen_save) {
      screen_saver(false);
    } else {
      layer(false);
      mods(false);
      wpm(false);
      check_screen_saver();
    }
   return false;
}


