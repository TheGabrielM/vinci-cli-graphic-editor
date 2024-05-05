#include <stdio.h>

#include "def.h"
#include "../../os/def.h"

void loadOSDefinitions(){

    // Gets the standard input handle.
    hStdin = GetStdHandle(STD_INPUT_HANDLE);

    if (hStdin == INVALID_HANDLE_VALUE)
        printf("error-hStdin");
        
    // Enables mouse input events.
    fdwMode = ENABLE_EXTENDED_FLAGS | ((ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT) & ~ENABLE_QUICK_EDIT_MODE);

    if (!SetConsoleMode(hStdin, fdwMode) )
        printf("error-enabling-window");

    // Sets window size
    //
}

int getInput(CURSOR *cursor){
    
    // Listens for inputs
    if(!ReadConsoleInput(hStdin, irInBuf, _WIN32_INPUT_BUFFER, &cNumRead))
       printf("error-ReadConsoleInput");
       
    // Returns input based on type
             
    POSITION next;
            
    switch(irInBuf[0].EventType)
    {
        case KEY_EVENT:
            // Returns converted keyboard input
            if(irInBuf[0].Event.KeyEvent.bKeyDown)
               return irInBuf[0].Event.KeyEvent.uChar.UnicodeChar;
            
            return -1;
        
        case MOUSE_EVENT:
            // If left click
            if(irInBuf[0].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                // Updates cursor position
                next.x = irInBuf[0].Event.MouseEvent.dwMousePosition.X + 1;
                next.y = irInBuf[0].Event.MouseEvent.dwMousePosition.Y + 1;
                
                fn_mouse_click(cursor, next);
            }
            
            return -1;
            
        case FOCUS_EVENT:  // Disregards focus events
        case MENU_EVENT:   // Disregards menu events
        default:
            return -1;
    }
}
