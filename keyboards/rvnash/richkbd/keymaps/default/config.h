#pragma once

#define DEBUG_MATRIX_SCAN_RATE
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 250

// Mod-tap settings
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// permissive hold activates the modifier when another key is pressed and released while the mod-tap is held, regardless of the tapping term.
#define PERMISSIVE_HOLD

// releasing the key without pressing another will send the original keycode even if it is outside the tapping term.
// #define RETRO_TAPPING

// CAPS WORD settings
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

// RGB MATRIX options.
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#define RGB_DISABLE_TIMEOUT 600000 // number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended

// RGB MATRIX effects to include.
// Since we have lots of flash memory, all are included.
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects

#define ENABLE_RGB_MATRIX_SOLID_COLOR     // Static single hue, no speed support
#define ENABLE_RGB_MATRIX_ALPHAS_MODS         // Static dual hue, speed is hue for secondary hue
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_BREATHING           // Single hue brightness cycling animation
#define ENABLE_RGB_MATRIX_BAND_SAT        // Single hue band fading saturation scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_VAL        // Single hue band fading brightness scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT   // Single hue 3 blade spinning pinwheel fades saturation
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL   // Single hue 3 blade spinning pinwheel fades brightness
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT     // Single hue spinning spiral fades saturation
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
#define ENABLE_RGB_MATRIX_CYCLE_ALL           // Full keyboard solid hue cycling through full gradient
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT    // Full gradient scrolling left to right
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN       // Full gradient scrolling top to bottom
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN        // Full gradient scrolling out to in
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL   // Full dual gradients scrolling out to in
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradent Chevron shapped scrolling left to right
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL      // Full gradient spinning pinwheel around center of keyboard
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL        // Full gradient spinning spiral around center of keyboard
#define ENABLE_RGB_MATRIX_DUAL_BEACON         // Full gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON      // Full tighter gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS   // Full dual gradients spinning two halfs of keyboard
#define ENABLE_RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
#define ENABLE_RGB_MATRIX_HUE_BREATHING       // Hue shifts up a slight ammount at the same time, then shifts back
#define ENABLE_RGB_MATRIX_HUE_PENDULUM        // Hue shifts up a slight ammount in a wave to the right, then back to the left
#define ENABLE_RGB_MATRIX_HUE_WAVE            // Hue shifts up a slight ammount and then back down in a wave to the right
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL       // Single hue fractal filled keys pulsing horizontally out to edges
#define ENABLE_RGB_MATRIX_PIXEL_FLOW          // Pulsing RGB flow along LED wiring with random hues
#define ENABLE_RGB_MATRIX_PIXEL_RAIN          // Randomly light keys with random hues
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP      // How hot is your WPM!
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN        // That famous computer simulation
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE   // Pulses keys hit to hue & value then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE      // Static single hue, pulses keys hit to shifted hue then fades to current hue
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SPLASH              // Full gradient & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_MULTISPLASH         // Full gradient & value pulse away from multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_SPLASH        // Hue & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH   // Hue & value pulse away from multiple key hits then fades value out

// Need to keep this in sync with the selections above
#define RGB_MATRIX_NAMES {"Solid", "Alphas Mods", "Gradient Vertical", "Gradient Horizontal", "Breathing", "Band Saturation", "Band Bright", "Pinwheel Saturation", "Pinwheel Bright", \
                          "Spiral Saturation", "Spiral Bright", "Cycle All", "Cycle Horizontal", "Cycle Vertical", "Cycle In/Out", "Cycle Dual", "Rainbow Chevron", \
                          "Cycle Pinwheel", "Cycle Spiral", "Dual Beacon", "Rainbow Beacon", "Rainbow Pinwheel", "Raindrops", "Jellybean", "Hue Breathing", \
                          "Hue Pendulum", "Hue Wave", "Fractal", "Flow", "Rain", "Heatmap", "Digital Rain", "Reactive", "Reactive Pulses", "Reactive Wide", "Reactive Wide+", \
                          "Reactive Cross", "Reactive Cross+", "Reactive Nexus", "Reactive Nexus+", "Splash", "Splash+", "Splash Solid", "Splash Solid+"}

// OLED options
#define OLED_TIMEOUT 0 // The driver's timeout doesn't play well with my screen saver and on/off button
#define MY_OLED_TIMEOUT 600000
#define OLED_SCREEN_SAVER_MS 30000
#define OLED_BRIGHTNESS 128
#define OLED_BRIGHTNESS_STEP 20
