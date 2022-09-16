#include "oled.h"
#include "oled_logos.h"
#include "miryoku.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
  return OLED_ROTATION_270;
}

void oled_render_layer_state(layer_state_t state, bool is_caps_word)
{
  oled_set_cursor(0, 0);
  const char *str;
  switch (get_highest_layer(state)) {
    case COLEMAK:
      str = PSTR("COLMK");
      break;
    case QWERTY:
      str = PSTR("QWRTY");
      break;
    case BUTTON:
      str = PSTR("But  ");
      break;
    case NAV:
      str = PSTR("Nav  ");
      break;
    case MOUSE:
      str = PSTR("Mouse");
      break;
    case MEDIA:
      str = PSTR("Media");
      break;
    case NUM:
      str = PSTR("Num  ");
      break;
    case SYM:
      str = PSTR("Sym  ");
      break;
    case FUN:
      str = PSTR("Func ");
      break;
    default:
      str = PSTR("unk  ");
      break;
  }
  oled_write_P(str, is_caps_word);
}

void oled_render_key(uint16_t keycode, keyrecord_t *record)
{
  char str[6];

  int row = record->event.key.row;
  int col = record->event.key.col;
  if (row > 3) { // Right hand keyboard
    row = row - 4;
    col = 11 - col;
  }
  snprintf(str, sizeof(str), "%1d x%2d", row, col);
  oled_set_cursor(0, 2);
  oled_write(str, false);
}

uint8_t last_mode=0xff, last_hue=0xff, last_sat=0xff, last_val=0xff, last_brightness=0xff;
void oled_render_led_state()
{
  char str[6];
  uint8_t mode = rgblight_get_mode();
  uint8_t hue = rgblight_get_hue();
  uint8_t sat = rgblight_get_sat();
  uint8_t val = rgblight_get_val();
  uint8_t brightness = oled_get_brightness();
  if (mode == last_mode &&
      hue == last_hue &&
      sat == last_sat &&
      val == last_val &&
      brightness == last_brightness)
        return;
  last_mode = mode;
  last_hue = hue;
  last_sat = sat;
  last_val = val;
  last_brightness = brightness;
  snprintf(str, sizeof(str), "LED%2d", mode);
  oled_set_cursor(0, 4);
  oled_write(str, false);
  snprintf(str, sizeof(str), "H %3d", hue);
  oled_set_cursor(0, 5);
  oled_write(str, false);
  snprintf(str, sizeof(str), "S %3d", sat);
  oled_set_cursor(0, 6);
  oled_write(str, false);
  snprintf(str, sizeof(str), "V %3d", val);
  oled_set_cursor(0, 7);
  oled_write(str, false);
  snprintf(str, sizeof(str), "O %3d", brightness);
  oled_set_cursor(0, 8);
  oled_write(str, false);
}

void oled_render_logo(void)
{
  oled_clear();
  oled_set_cursor(0, 1);
  oled_write_P(PSTR("COYS"), false);
  oled_set_cursor(0, 3);
  oled_write_raw_P(spurs_logo, sizeof(spurs_logo));
  oled_set_cursor(0, 14);
  oled_write_P(PSTR("1882"), false);
}

void oled_render_idle(uint32_t idle)
{
  char str[6];
  snprintf(str, sizeof(str), "IDL%2ld", idle);
  oled_set_cursor(0, 14);
  oled_write(str, false);
}

void oled_render_scan_rate(uint32_t scan_rate)
{
  char str[6];
  snprintf(str, sizeof(str), "S%4ld", scan_rate);
  oled_set_cursor(0, 13);
  oled_write(str, false);
}
