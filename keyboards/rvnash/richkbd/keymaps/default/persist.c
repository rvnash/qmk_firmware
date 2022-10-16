#include "persist.h"

void eeconfig_init_user(void) {  // EEPROM is getting reset!
    PersistedConfig pc;
    pc.raw = 0;
    pc.oled_brightness = OLED_BRIGHTNESS;
    pc.screensaver_logo = 0;
    pc.oled_on = true;
    uprint("Initializing EEPROM state\n");
    persist_update_state(pc);
}

PersistedConfig persist_read_state(void)
{
    PersistedConfig pc;
    pc.raw = eeconfig_read_user();
    uprintf("Read EEPROM state Oled brightness: %d, logo: %d, oled on: %s\n",
            pc.oled_brightness,
            pc.screensaver_logo,
            pc.oled_on ? "ON" : "OFF");
    return pc;
}

void persist_update_state(PersistedConfig pc)
{
    uprintf("Update EEPROM state Oled brightness: %d, logo: %d, oled on: %s\n",
            pc.oled_brightness,
            pc.screensaver_logo,
            pc.oled_on ? "ON" : "OFF");
    eeconfig_update_user(pc.raw);
}

void persist_update_oled_brightness(uint8_t oled_brightness)
{
    PersistedConfig pc = persist_read_state();
    pc.oled_brightness = oled_brightness;
    persist_update_state(pc);
}

void persist_update_screensaver_logo(int8_t screensaver_logo)
{
    PersistedConfig pc = persist_read_state();
    pc.screensaver_logo = screensaver_logo;
    persist_update_state(pc);
}

void persist_update_oled_on(bool oled_on)
{
    PersistedConfig pc = persist_read_state();
    pc.oled_on = oled_on;
    persist_update_state(pc);
}
