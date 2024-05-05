#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "../structures/def.h"

// Colors
#define CANVAS_BORDER_COLOR 250
#define CANVAS_FONT_COLOR 15

#define BCK 0
#define GRY1 237
#define GRY2 241
#define GRY3 250
#define RED1 160
#define RED2 124
#define RED3 88
#define RED4 52
#define GRN1 2
#define GRN2 120
#define GRN3 156
#define GRN4 192
#define YEL1 226
#define YEL2 227
#define YEL3 228
#define YEL4 229
#define BLU1 20
#define BLU2 33
#define BLU3 14
#define WHT 15

// Functions headers
void createCanvas();
void print_pixel(PIXEL pixel);

// Creates canvas
CANVAS *canvas;

#endif
