#include "keymap.h"
#include "oled.h"
#include "persist.h"

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)
// Define the layres
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = U_MACRO_VA_ARGS(LAYOUT_richkbd, COLEMAK_LAYER),
  [QWERTY]  = U_MACRO_VA_ARGS(LAYOUT_richkbd, QWERTY_LAYER),
  // set_single_persistent_default_layer needs the layers that it saves to be first in the list.
  [STD_QWERTY]  = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_QWERTY_LAYER),
  [STD_COLEMAK] = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_COLEMAK_LAYER),
  [NAV]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, NAV_LAYER),
  [MOUSE]   = U_MACRO_VA_ARGS(LAYOUT_richkbd, MOUSE_LAYER),
  [MEDIA]   = U_MACRO_VA_ARGS(LAYOUT_richkbd, MEDIA_LAYER),
  [NUM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, NUM_LAYER),
  [SYM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, SYM_LAYER),
  [FUN]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, FUN_LAYER),
  [STD_NUM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_NUM_LAYER),
  [STD_SYM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_SYM_LAYER),
  [STD_FUNCS]   = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_FUNCS_LAYER)
};

const char *layers_to_names[] = {"Miryoku/Colemak", "Miryoku/QWERTY",
                                 "Std/Colemak", "Std/QWERTY","Navigation",
                                 "Miryoku/Mouse","Miryoku/Media","Miryoku/Numbers","Miryoku/Symbols","Miryoku/Function",
                                 "Std/Numbers","Std/Symbols","Std/Functions"};


void keyboard_post_init_user(void)
{
    oled_post_init_user();
}

void shutdown_user(void)
{
    oled_shutdown_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (oled_process_record_user(keycode, record)) {
        switch (keycode) {
            case DF(QWERTY):
                if (record->event.pressed) {
    uprintf("saving layer %d\n", QWERTY);
                    set_single_persistent_default_layer(QWERTY);
                }
                return false;
                break;
            case DF(COLEMAK):
                if (record->event.pressed) {
    uprintf("saving layer %d\n", COLEMAK);
                    set_single_persistent_default_layer(COLEMAK);
                }
                return false;
                break;
            case DF(STD_COLEMAK):
                if (record->event.pressed) {
    uprintf("saving layer %d\n", STD_COLEMAK);
                    set_single_persistent_default_layer(STD_COLEMAK);
                }
                return false;
                break;
            case DF(STD_QWERTY):
                if (record->event.pressed) {
    uprintf("saving layer %d\n", STD_QWERTY);
                    set_single_persistent_default_layer(STD_QWERTY);
                }
                return false;
                break;
        }
    }
    return true;
}

void housekeeping_task_user(void)
{
    oled_housekeeping();
}
