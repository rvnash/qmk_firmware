# MCU name
MCU = RP2040
BOOTLOADER = rp2040
BOARD = GENERIC_RP_RP2040

# Build Options - https://docs.qmk.fm/#/config_options?id=feature-options
#   change yes to no to disable
#
LTO_ENABLE = yes            # This link time optimization makes ~10% difference in code size, and takes ~25% more compile time
NKRO_ENABLE = yes

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = vendor

OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
