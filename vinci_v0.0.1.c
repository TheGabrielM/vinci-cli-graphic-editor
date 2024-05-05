#include <stdio.h>
#include <conio.h>

#include "src/commands/def.h"
#include "src/canvas/def.h"
#include "os/def.h"

// 
int main(){

    // Loads OS defitions
    loadOSDefinitions();
    
    // Creates cursor
    CURSOR cursor;
    
    // Sets default position
    cursor.axis.x = 0;
    cursor.axis.y = 0;      
    
    // Sets default color
    cursor.style.background_color = BCK;
    
    // Loads canvas
    createCanvas();
    
    // Moves cursor to initial position
    // moveCursor(&cursor, cursor.axis);
    
    // Show infos
    showColorBar(canvas->width + 1, canvas->height + 1); // Includes canvas border

    // Gets the user input
    while(1==1)
    {  
       // Executes input function
       FUNCTION_SIGNATURE *execute = get_command(&cursor);
       execute(&cursor);
    }
}
