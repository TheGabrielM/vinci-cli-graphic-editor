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
      sleep(0.25);
   }

   int j;
   for(j = 0; j <= axis.y; j++)
   {
      gotoxy(axis.x + 1, axis.y + 1 - j);
      print_pixel(p);
      sleep(0.25);
   }
} 

PIXEL p[COLOR_BAR_ROWS][COLOR_BAR_COLS];
void showColorBar(POSITION axis){

   // Defines colors to show
   memset( p, 0, COLOR_BAR_ROWS * COLOR_BAR_COLS * sizeof(PIXEL) );

   int i;
   int j;
   for(i = 0; i < COLOR_BAR_COLS; i++)
   {
      for(j = 0; j < COLOR_BAR_ROWS; j++)
      {
         p[i][j].style.background_color = colorBar[i][j];
         p[i][j].style.font_color = WHT;
         p[i][j].style.text = 32;
      }
   }

   // Shows colors options
   for(i = 0; i < COLOR_BAR_COLS; i++)
   {
      for(j = 0; j < COLOR_BAR_ROWS; j++)
      {   
         // Places it next to the canvas (+2)
         p[i][j].axis.x = axis.x + 2 + i;
         p[i][j].axis.y = j + 1;

         gotoxy(p[i][j].axis.x, p[i][j].axis.y);

         print_pixel(p[i][j]);
      }
   }
}

int onColorBar(POSITION axis){
    
    int i;
    int j;
    for(i = 0; i < COLOR_BAR_ROWS; i++)
    {
      for(j = 0; j < COLOR_BAR_COLS; j++)
      {
         if(p[i][j].axis.x == axis.x && p[i][j].axis.y == axis.y)
            return p[i][j].style.background_color;
      }
    }

    return -1;
}
