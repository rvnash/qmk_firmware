#include "keymap.h"
#include "oled.h"

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)
// Define the layres
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = U_MACRO_VA_ARGS(LAYOUT_richkbd, COLEMAK_LAYER),
  [QWERTY]  = U_MACRO_VA_ARGS(LAYOUT_richkbd, QWERTY_LAYER),
  [NAV]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, NAV_LAYER),
  [MOUSE]   = U_MACRO_VA_ARGS(LAYOUT_richkbd, MOUSE_LAYER),
  [MEDIA]   = U_MACRO_VA_ARGS(LAYOUT_richkbd, MEDIA_LAYER),
  [NUM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, NUM_LAYER),
  [SYM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, SYM_LAYER),
  [FUN]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, FUN_LAYER),
  [STD_QWERTY]  = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_QWERTY_LAYER),
  [STD_COLEMAK] = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_COLEMAK_LAYER),
  [STD_NUM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_NUM_LAYER),
  [STD_SYM]     = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_SYM_LAYER),
  [STD_FUNCS]   = U_MACRO_VA_ARGS(LAYOUT_richkbd, STD_FUNCS_LAYER)
};

const char *layers_to_names[] = {"Miryoku/Colemak", "Miryoku/QWERTY","Navigation","Mouse","Media","Numbers","Symbols","Function",
                                 "Std/Colemak", "Std/QWERTY","Std/Numbers","Std/Symbols","Std/Functions"};


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
    return oled_process_record_user(keycode, record);
}

void housekeeping_task_user(void)
{
    oled_housekeeping();
}
