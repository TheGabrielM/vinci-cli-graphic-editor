#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

// Canvas
#define DEFAULT_CANVAS_WIDTH 120
#define DEFAULT_CANVAS_HEIGHT 29

// Custom data types
typedef struct POSITION {
    int x;
    int y;
} POSITION;

typedef struct STYLE {
    int background_color; // ANSI color code
    char font_color; // ANSI color code
    char text;
} STYLE;

typedef struct CURSOR {
    POSITION axis;
    STYLE style;
} CURSOR;

typedef struct COMMAND {
    int length;
    int *keys[];
} COMMAND;

typedef struct PIXEL {
    POSITION axis;
    STYLE style;
} PIXEL;

typedef struct CANVAS {
    int width;
    int height;
    int total_pixels;
    PIXEL last_updated;
    PIXEL body[DEFAULT_CANVAS_HEIGHT][DEFAULT_CANVAS_WIDTH];
} CANVAS;

#endif
