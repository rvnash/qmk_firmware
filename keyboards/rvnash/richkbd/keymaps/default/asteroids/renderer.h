
//renderer.h

#include <stdint.h>
#include <math.h>

//Screen dimension constants
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

//assing a colour to a single pixel
int draw_pixel( int x, int y, uint8_t colour);

int draw_line(int x1, int y1, int x2, int y2, uint8_t colour);
