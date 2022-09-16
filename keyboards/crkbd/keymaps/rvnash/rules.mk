BOOTLOADER = atmel-dfu

CAPS_WORD_ENABLE = yes
MOUSEKEY_ENABLE = yes
RGBLIGHT_ENABLE = yes
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes

COMMAND_ENABLE = no
CONSOLE_ENABLE = no
BOOTMAGIC_ENABLE = no

INTROSPECTION_KEYMAP_C = miryoku.h # keymaps

SRC += miryoku.c oled.c rgb_layers.c
