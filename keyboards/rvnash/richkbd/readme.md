# richkbd

![richkbd](https://github.com/rvnash/richkbd/raw/main/images/richkbd.jpg)

A 42 key ortholinear keyboard kit made as a single piece alternative to crkbd. Also uses the RP2040 Microcontroller. More info on the [hardware site](https://github.com/rvnash/richkbd) for this board.(https://qmk.fm/planck/)

* Keyboard Maintainer: [Richard Nash](https://github.com/rvnash)
* Hardware Supported: Just the richkbd
* Hardware Availability: None. The [Kicad files are open source](https://github.com/rvnash/richkbd) and there are instructions, so you can fabricate them yourself.

## Hardware Feature Supported

- RP2040 Microcontroler
- RGB Matrix lighting modes for the under-key leds
- An OLED display

See the [default keymap's readme file](keymaps/default/readme.md) for a lot more interesting information about what you can do with this keyboard.

Make example for this keyboard (after setting up your build environment):

    make rvnash/richkbd:default

Flash with

    qmk flash  -kb rvnash/richkbd -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

