#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "../structures/def.h"

// Background Colors
#define BCKB 40
#define REDB 41
#define GRNB 42
#define YELB 43

// Font Colors
#define BCK 30
#define WHT 37

// Functions headers
void createCanvas();
void print_pixel(PIXEL pixel);

// Creates canvas
CANVAS *canvas;

#endif
