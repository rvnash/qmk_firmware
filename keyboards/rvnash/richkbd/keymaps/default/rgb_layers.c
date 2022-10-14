#include "rgb_layers.h"
#include "keymap.h"

// Implement layers of color for the different modes

typedef struct
{
  int start_x, start_y;
  int end_x, end_y;
  uint8_t red; uint8_t green; uint8_t blue;
} range_color;

int scale_val( int val )
{
    return (int)((float)val * (float)rgb_matrix_get_val() / 255.0 + 0.49);
}

void set_colors_by_ranges( range_color rc[])
{
  range_color cur;
  for (int i = 0; rc[i].start_x != -1; ++i) {
    cur = rc[i];
    int r = scale_val(cur.red);
    int g = scale_val(cur.green);
    int b = scale_val(cur.blue);
    for (int x = cur.start_x; x <= cur.end_x; ++x) {
        for ( int y = cur.start_y; y <= cur.end_y; ++y) {
            rgb_matrix_set_color(g_led_config.matrix_co[y][x], r, g, b);
        }
    }
  }
}

void rgb_matrix_indicators_kb()
{
    if (is_caps_word_on()) {
            range_color rc[] = {
                {1,0, 9,0,    RGB_WHITE}, // Top row letters
                {1,1, 10,1,    RGB_WHITE}, // Middle row letters
                {1,2, 7,2,    RGB_WHITE}, // Bottom row letters
                {-1,-1, -1,-1, -1,-1,-1}
                };
            set_colors_by_ranges( rc );

        return;
    }
    int highest_layer = get_highest_layer(layer_state|default_layer_state);
    switch (highest_layer) {
        case NUM:
            {
            range_color rc[] = {
                {0,0, 11,3,    RGB_BLACK}, // Black out the whole keyboard
                {2,0, 4,2,     RGB_GREEN}, // Number keys
                {3,3, 3,3,     RGB_GREEN}, // 0 key
                {1,0, 1,2,     RGB_BLUE}, // Symbols on the left of nums
                {5,0, 5,2,     RGB_BLUE},  // Symbols on the right of nums
                {4,3, 5,3,     RGB_BLUE},  // Symbols on thumb row
                {7,1, 10,1,     RGB_YELLOW}, // homerow mods active on the right
                {-1,-1, -1,-1, -1,-1,-1}
                };
            set_colors_by_ranges( rc );
            }
            break;
        case NAV:
            {
            range_color rc[] = {
                {0,0, 11,3,    RGB_BLACK}, // Black out the whole keyboard
                {6,1, 6,1,     RGB_WHITE}, // CAPS_WORD
                {7,1, 10,1,    RGB_GREEN}, // left, down, right, up
                {6,2, 6,2,     RGB_CYAN}, // INS
                {7,2, 10,2,    RGB_BLUE}, // home, pg down, pg up, end
                {1,1, 4,1,     RGB_YELLOW}, // homerow mods active on the left
                {0,0,  0,0,    RGB_RED},    // Bootloader
                {-1,-1, -1,-1, -1,-1,-1}
                };
            set_colors_by_ranges( rc );
            }
            break;
        case SYM:
            {
            range_color rc[] = {
                {0,0, 11,3,    RGB_BLACK}, // Black out the whole keyboard
                {1,0, 5,3,     RGB_BLUE}, // All of the keys on the left side are symbols´
                {-1,-1, -1,-1, -1,-1,-1}
                };
            set_colors_by_ranges( rc );
            }
            break;
        case MEDIA:
            {
            range_color rc[] = {
                {6,0, 10,0,    RGB_ORANGE}, // LED Control keys
                {9,1, 9,1,     RGB_ORANGE}, // OLED brightness key
                {4,1, 4,1,     RGB_YELLOW}, // Shift mod available
                {6,3, 8,3,     RGB_RED},    // mute, vol-, vol+
                {10,1, 10,2,   RGB_CHARTREUSE},    // Laptop display bright+, bright-
                {0,0,  0,0,    RGB_RED},    // Bootloader
                {-1,-1, -1,-1, -1,-1,-1}
                };
            set_colors_by_ranges( rc );
            }
            break;
        case FUN:
            {
            range_color rc[] = {
                {0,0, 11,3,    RGB_BLACK}, // Black out the whole keyboard
                {2,0, 4,2,     RGB_GREEN}, // F1-F9
                {1,0, 1,2,     RGB_CHARTREUSE},    // F10-F12
                {-1,-1, -1,-1, -1,-1,-1}
                };
            set_colors_by_ranges( rc );
            }
            break;
        case MOUSE:
            {
            range_color rc[] = {
                {0,0, 11,3,    RGB_BLACK}, // Black out the whole keyboard
                {7,1, 10,1,    RGB_GREEN}, // Mouse left, down, up, right
                {7,2, 10,2,    RGB_BLUE}, // Wheel left, down, up, right
                {6,3, 8,3,     RGB_CHARTREUSE}, // left, middle, right mouse button
                {1,1, 4,1,     RGB_YELLOW}, // homerow mods active on the left
                {0,0,  0,0,    RGB_RED},    // Bootloader
                {-1,-1, -1,-1, -1,-1,-1}
                };
            set_colors_by_ranges( rc );
            }
            break;
        default:
            break;
    }
}
