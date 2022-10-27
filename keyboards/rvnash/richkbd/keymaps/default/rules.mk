CONSOLE_ENABLE = yes        # Console for debug
CAPS_WORD_ENABLE = yes      # CAPS_WORD feature
MOUSEKEY_ENABLE = yes       # Keys to move the mouse, wheel, and buttons.
EXTRAKEY_ENABLE = yes       # Audio control and System control, for things like volume, mute, display brightness,...
WPM_ENABLE = yes

SRC += rgb_layers.c oled.c oled_logos.c persist.c asteroids/asteroids_main.c asteroids/asteroids.c asteroids/player.c asteroids/renderer.c asteroids/vector.c
