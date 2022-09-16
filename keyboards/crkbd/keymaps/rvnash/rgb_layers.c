#include "rgb_layers.h"
#include "miryoku.h"

// Mapping to led numbers
// Note that all of these definitions and ranges are specific to the
// way the corne (crkbd) led's are connected in a snaking sequence

#define NUM_LEDS 54
#define BACKLIGHT_LEFT 0, 6
#define BACKLIGHT_RIGHT 27, 6

// Row_Col, left to right accross left half
#define D_0_0 24
#define D_1_0 25
#define D_2_0 26

#define D_0_1 23
#define D_1_1 22
#define D_2_1 21

#define D_0_2 18
#define D_1_2 19
#define D_2_2 20

#define D_0_3 17
#define D_1_3 16
#define D_2_3 15
#define D_3_3 14

#define D_0_4 10
#define D_1_4 11
#define D_2_4 12
#define D_3_4 13

#define D_0_5 9
#define D_1_5 8
#define D_2_5 7
#define D_3_5 6

#define LEFT_KEYS D_3_5, (D_2_0 - D_3_5 + 1)

// Row_Col, left to right accross right half
#define D_0_6 36
#define D_1_6 35
#define D_2_6 34
#define D_3_6 33

#define D_0_7 37
#define D_1_7 38
#define D_2_7 39
#define D_3_7 40

#define D_0_8 44
#define D_1_8 43
#define D_2_8 42
#define D_3_8 41

#define D_0_9 45
#define D_1_9 46
#define D_2_9 47

#define D_0_10 50
#define D_1_10 49
#define D_2_10 48

#define D_0_11 51
#define D_1_11 52
#define D_2_11 53
#define RIGHT_KEYS D_3_6, (D_2_11 - D_3_6 + 1)

const rgblight_segment_t PROGMEM rgb_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{ start index, number of leds to light, color }
    {LEFT_KEYS, HSV_BLACK}, {RIGHT_KEYS, HSV_BLACK}, {D_0_4, D_2_2 - D_0_4 + 1, HSV_GREEN}, // The numbers
    {D_2_1, D_0_1 - D_2_1 + 1, HSV_BLUE},                                                   // Symbols
    {D_3_5, D_0_5 - D_3_5 + 1, HSV_BLUE},                                                   // Symbols
    {D_3_4, 1, HSV_BLUE}                                                                    // Symbols
);

const rgblight_segment_t PROGMEM rgb_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{ start index, number of leds to light, color }
    {LEFT_KEYS, HSV_BLACK}, {RIGHT_KEYS, HSV_BLACK}, {D_1_6, 1, HSV_WHITE}, // CAPS_WORD
    {D_1_7, 1, HSV_GREEN},                                                  // left
    {D_1_8, 1, HSV_GREEN},                                                  // down
    {D_1_9, 1, HSV_GREEN},                                                  // up
    {D_1_10, 1, HSV_GREEN},                                                 // right
    {D_2_7, 1, HSV_BLUE},                                                   // home
    {D_2_8, 1, HSV_BLUE},                                                   // pg down
    {D_2_9, 1, HSV_BLUE},                                                   // pg up
    {D_2_10, 1, HSV_BLUE}                                                   // end
);

const rgblight_segment_t PROGMEM rgb_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{ start index, number of leds to light, color }
    {LEFT_KEYS, HSV_BLACK}, {RIGHT_KEYS, HSV_BLACK}, {D_3_5, (D_0_1 - D_3_5 + 1), HSV_BLUE} // All the active keys on the left hand are symbols
);

const rgblight_segment_t PROGMEM rgb_media_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{ start index, number of leds to light, color }
    {D_0_6, 1, HSV_PINK},        // led toggle on/off
    {D_0_7, 1, HSV_PINK},        // led mode
    {D_0_8, 1, HSV_PINK},        // led hue
    {D_0_9, 1, HSV_PINK},        // led saturation
    {D_0_10, 1, HSV_PINK},       // led intensity
    {D_1_9, 1, HSV_PINK},        // oled intensity
    {D_3_6, 1, HSV_RED},         // mute
    {D_3_7, 1, HSV_RED},         // vol-
    {D_3_8, 1, HSV_RED},         // vol+
    {D_1_10, 1, HSV_CHARTREUSE}, // bright+
    {D_2_10, 1, HSV_CHARTREUSE}  // bright-
);

const rgblight_segment_t PROGMEM rgb_func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{ start index, number of leds to light, color }
    {LEFT_KEYS, HSV_BLACK}, {RIGHT_KEYS, HSV_BLACK}, {D_0_4, D_2_4 - D_0_4 + 1, HSV_GREEN}, // F9, F6, F3
    {D_2_3, D_2_2 - D_2_3 + 1, HSV_GREEN},                                                  // F2, F5, F8, F1, F4, F7
    {D_2_1, D_0_1 - D_2_1 + 1, HSV_CHARTREUSE}                                              // F10 - F12
);

const rgblight_segment_t PROGMEM rgb_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{ start index, number of leds to light, color }
    {LEFT_KEYS, HSV_BLACK}, {RIGHT_KEYS, HSV_BLACK}, {D_1_7, 1, HSV_GREEN}, // left
    {D_1_8, 1, HSV_GREEN},                                                  // down
    {D_1_9, 1, HSV_GREEN},                                                  // up
    {D_1_10, 1, HSV_GREEN},                                                 // right
    {D_3_6, 1, HSV_YELLOW},                                                 // left button
    {D_3_7, 1, HSV_YELLOW},                                                 // middle button
    {D_3_8, 1, HSV_YELLOW}                                                  // right button
);

const rgblight_segment_t PROGMEM rgb_caps_word_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{ start index, number of leds to light, color }
    {D_2_5, 6, HSV_WHITE}, // vgbptd
    {D_2_3, 9, HSV_WHITE}, // csfwrxzaq
    {D_2_6, 6, HSV_WHITE}, // kmjlnh
    {D_1_8, 4, HSV_WHITE}, // euyi
    {D_1_10, 1, HSV_WHITE} // o
);

#define RGB_NUM_LAYER 0
#define RGB_NAV_LAYER 1
#define RGB_SYM_LAYER 2
#define RGB_MEDIA_LAYER 3
#define RGB_FUNC_LAYER 4
#define RGB_MOUSE_LAYER 5
#define RGB_CAPS_WORD_LAYER 6
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(rgb_num_layer,      // 0
                                                                               rgb_nav_layer,      // 1
                                                                               rgb_sym_layer,      // 2
                                                                               rgb_media_layer,    // 3
                                                                               rgb_func_layer,     // 4
                                                                               rgb_mouse_layer,    // 5
                                                                               rgb_caps_word_layer // 6
);

void rgb_layers_init(void)
{
  // Enable the LED layers
  rgblight_layers = my_rgb_layers;
}

void rgb_layer_set_leds(layer_state_t state)
{
  rgblight_set_layer_state(RGB_NUM_LAYER, layer_state_cmp(state, NUM));
  rgblight_set_layer_state(RGB_NAV_LAYER, layer_state_cmp(state, NAV));
  rgblight_set_layer_state(RGB_SYM_LAYER, layer_state_cmp(state, SYM));
  rgblight_set_layer_state(RGB_MEDIA_LAYER, layer_state_cmp(state, MEDIA));
  rgblight_set_layer_state(RGB_FUNC_LAYER, layer_state_cmp(state, FUN));
  rgblight_set_layer_state(RGB_MOUSE_LAYER, layer_state_cmp(state, MOUSE));
}

void rgb_caps_word_set_leds(bool active)
{
  rgblight_set_layer_state(RGB_CAPS_WORD_LAYER, active);
}
