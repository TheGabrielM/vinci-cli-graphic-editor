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
    
    // Rows
    int i = 0;
    for(i; i < canvas->height; i++)
    {
        // Columns
        int j = 0;
        for(j; j < canvas->width; j++)
        {
            // Assigns empty pixel default specs
            pixel.axis.x = j;
            pixel.axis.y = i;

            pixel.style.background_color = YELB;
            pixel.style.font_color = WHT;
            pixel.style.text = 32;

            // Renders pixel
            gotoxy(j + 1, i + 1);
            print_pixel(pixel);
        }
    }   

    // Displays total pixels in canvas
    // gotoxy(15, 30);
    // printf("%d", canvas_SIZE);
}
     
void print_pixel(PIXEL pixel){
     
    // Renders pixel on terminal screen
    printf(DEFAULT_PIXEL_RENDERING_STRING, (pixel.style.background_color), (pixel.style.font_color), (pixel.style.text));
                            
    // Assigns new rendered pixel to canvas
    canvas->last_updated = canvas->body[pixel.axis.y][pixel.axis.x];
    canvas->body[pixel.axis.y][pixel.axis.x] = pixel;
}       
