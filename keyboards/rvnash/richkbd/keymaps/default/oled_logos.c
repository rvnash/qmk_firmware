#include "oled_logos.h"

// The format of these images is like this in pixel space
//
// B0[0],B1[0] ... up to the width of the image
// B0[1],B1[1]
// B0[2],B1[2]
// B0[3],B1[3]
// B0[4],B1[4]
// B0[5],B1[5]
// B0[6],B1[6]
// B0[7],B1[7]
// The height must always be divisible by 8

 static const uint8_t spurs_img[] = {
    0x00, 0x00, 0x00, 0x10,
    0x30, 0x30, 0x78, 0xf8,
    0xd8, 0x10, 0x30, 0xe0,
    0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0xc0, 0x7f,
    0x0f, 0x00, 0x00, 0xc0,
    0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0xf8, 0xfc,
    0xff, 0xff, 0xff, 0xfe,
    0xfc, 0xf8, 0xf8, 0xff,
    0xe3, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0xe0, 0xf0,
    0xf0, 0xf8, 0xfc, 0xfc,
    0xdc, 0xc0, 0x00, 0x00,
    0x00, 0x01, 0x1f, 0x3f,
    0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0xfc,
    0xf8, 0xf0, 0xf0, 0xf0,
    0xfe, 0xff, 0xff, 0x7f,
    0x7f, 0x3f, 0x3f, 0x1f,
    0x1f, 0x1f, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x03,
    0x07, 0x0f, 0x0f, 0x1f,
    0x3f, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0x3f, 0x0f,
    0x03, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x83, 0xff,
    0x7f, 0x3b, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xc0,
    0xc0, 0xe0, 0xe0, 0xf0,
    0xf8, 0xfc, 0xff, 0xc3,
    0xc3, 0x83, 0x83, 0x01,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0xf8, 0xec,
    0xde, 0xde, 0xef, 0xff,
    0xf7, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff,
    0xfe, 0xf8, 0xf0, 0xc0,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x3f, 0xfd, 0xf1,
    0x9e, 0x7e, 0xff, 0xfd,
    0xff, 0xfb, 0xff, 0xff,
    0xf7, 0xff, 0xef, 0xe7,
    0x7b, 0xcf, 0xcf, 0xdb,
    0xdb, 0x97, 0x1f, 0x1f,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01,
    0x03, 0x06, 0x0d, 0x0b,
    0x1f, 0x0f, 0x0f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x0f, 0x0e, 0x06,
    0x03, 0x01, 0x00, 0x00
  };
const Image spurs_logo = {
  32,
  78,
  spurs_img
};
