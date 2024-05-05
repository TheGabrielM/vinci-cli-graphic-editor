#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "../structures/def.h"

// Colors
#define CANVAS_BORDER_COLOR 250
#define CANVAS_FONT_COLOR 15

#define BCK 0
#define RED 160
#define GRN 120
#define YEL 228
#define WHT 15

// Functions headers
void createCanvas();
void print_pixel(PIXEL pixel);

// Creates canvas
CANVAS *canvas;

#endif
