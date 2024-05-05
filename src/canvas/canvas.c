#include <stdio.h>

#include "def.h"
#include "../../os/def.h"

// Canvas
void createCanvas(){
     
    // Determines canvas' size
    size_t canvas_SIZE = DEFAULT_CANVAS_WIDTH * DEFAULT_CANVAS_HEIGHT * sizeof(PIXEL);
     
    // Allocates memory for canvas' pixels
    canvas = malloc(sizeof *canvas + canvas_SIZE * sizeof *canvas->body);
     
    // Sets canvas' width and length
    canvas->width = DEFAULT_CANVAS_WIDTH;
    canvas->height = DEFAULT_CANVAS_HEIGHT;
    
    // Sets canvas total pixels
    canvas->total_pixels = canvas_SIZE;

    // Creates empty pixel
    PIXEL pixel;

    // Fills canvas' body matrix
    int i;
    int j;
    
    // Rows
    for(i = 0; i < canvas->height; i++)
    {
        // Columns
        for(j = 0; j < canvas->width; j++)
        {
            // Assigns empty pixel default specs
            pixel.axis.x = j;
            pixel.axis.y = i;

            pixel.style.background_color = WHT;
            pixel.style.font_color = WHT;
            pixel.style.text = 32;

            // Renders pixel
            gotoxy(j + 1, i + 1);
            print_pixel(pixel);
        }
    }   

    // Shows the canvas' border
    POSITION border = { .x=j, .y=i };

    showCanvasBorder(border);
}
     
void print_pixel(PIXEL pixel){
     
    // Renders pixel on terminal screen
    printf(DEFAULT_PIXEL_RENDERING_STRING, (pixel.style.background_color), (pixel.style.font_color), (pixel.style.text));
                            

    // Pixel rendering outside the canvas (interface graphics) should not be counted
    if(pixel.axis.x = 0 && pixel.axis.y == 0)
        return;

    // Assigns new rendered pixel to canvas
    canvas->last_updated = canvas->body[pixel.axis.y][pixel.axis.x];
    canvas->body[pixel.axis.y][pixel.axis.x] = pixel;
}       
