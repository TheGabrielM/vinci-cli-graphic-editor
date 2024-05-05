#include <stdio.h>
#include <unistd.h>

#include "def.h"
#include "../../src/canvas/def.h"
#include "../../os/def.h"

// Infos
void showCursorAxis(POSITION axis){
     
     // Goes to the bottom of the console screen
     gotoxy(0, 30);
     
     // Sets background color to black
     printf("%d ", BCK);
     
     // Shows cursor xy position
     printf("x: %d y: %d   ", axis.x, axis.y);
     
     /*
        Improve info components placement     
     */
}

void showCanvasBorder(POSITION axis){

   // Border pixel
   PIXEL p;
   p.style.background_color = CANVAS_BORDER_COLOR;
   p.style.font_color = CANVAS_FONT_COLOR;
   p.style.text = 32; // Whitespace character
   p.axis.x = 0;
   p.axis.y = 0;

   // Creates border
   int i;
   for(i = 0; i <= axis.x; i++)
   {
      gotoxy(axis.x - i, axis.y + 1);
      print_pixel(p);
      sleep(0.5);
   }

   int j;
   for(j = 0; j <= axis.y; j++)
   {
      gotoxy(axis.x + 1, axis.y + 1 - j);
      print_pixel(p);
      sleep(0.5);
   }
} 
