#pragma once

typedef struct
{
    uint8_t w, h;
    bool flip;
    const uint8_t *img;
} Image;

extern int num_screen_saver_images;
extern const Image screen_saver_images[];
