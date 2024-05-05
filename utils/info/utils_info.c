#include <stdio.h>

#include "def.h"
#include "../../src/canvas/def.h"
#include "../../os/def.h"

// Infos
void showCursorAxis(POSITION axis){
     
     // Goes to the bottom of the console screen
     gotoxy(0, 30);
     
     // Sets background color to black
     printf("%d ", BCKB);
     
     // Shows cursor xy position
     printf("x: %d y: %d   ", axis.x, axis.y);
     
     /*
        Improve info components placement     
     */
}
