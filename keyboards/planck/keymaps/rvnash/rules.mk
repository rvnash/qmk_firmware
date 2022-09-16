CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
AUDIO_ENABLE = yes           # Audio output on
MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control

# Pimoroni trackball device
# SRC += pimoroni_trackball.c

#POINTING_DEVICE_ENABLE = yes
#POINTING_DEVICE_DRIVER = custom
QUANTUM_LIB_SRC += i2c_master.c
CONSOLE_ENABLE=yes
