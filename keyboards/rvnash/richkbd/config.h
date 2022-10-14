// LED defines
#define DRIVER_LED_TOTAL 42 // How many RGB lights are present across all drivers
#define RGBLED_NUM 42 // How many LEDs are in the key backlighting (all of them)
#define RGB_DI_PIN GP14 // The pin to send out the pixels chain
#define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
#define WS2812_TRST_US 80 // These neopixels can support cycle times this fast

// OLED display
#define OLED_DISPLAY_128X64
#define I2C1_SCL_PIN        GP1
#define I2C1_SDA_PIN        GP0
#define I2C_DRIVER I2CD1
#define OLED_FONT_H "glcdfont.c"
