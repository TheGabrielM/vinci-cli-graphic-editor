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
    cursor.axis.x = 1;
    cursor.axis.y = 1;
    
    // Sets default color
    cursor.style.background_color = REDB;
    
    // Loads canvas
    createCanvas();
    
    // Moves cursor to initial position
    // moveCursor(&cursor, cursor.axis);

    // Gets the user input
    while(1==1)
    {
       // Show infos
       showCursorAxis(cursor.axis);
       
       // Executes input function
       FUNCTION_SIGNATURE *execute = get_command(&cursor);
       execute(&cursor);
    }
}
