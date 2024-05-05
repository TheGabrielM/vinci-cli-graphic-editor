#include <stdio.h>

#include "def.h"
#include "../canvas/def.h"
#include "../../os/def.h"
#include "../../utils/arrays/def.h"

// Command functions
void *get_command(CURSOR *cursor){

    // Command function variable to be returned
    void *command = NULL;

    // User input variable
    char input;

    // Sets default specs for each command

    // CURSOR_UP
    int CURSOR_UP_KEYS[] = { DEFAULT_CURSOR_UP };
    size_t CURSOR_UP_SIZE = ARRAY_SIZE(CURSOR_UP_KEYS);
    
    COMMAND *CURSOR_UP = malloc(sizeof *CURSOR_UP + CURSOR_UP_SIZE * sizeof *CURSOR_UP->keys); // Alocate storage
    
    CURSOR_UP->length = CURSOR_UP_SIZE; // Assigns length

    size_t k = 0;
    for (k; k < CURSOR_UP_SIZE; k++)  // Assigns addresses to structs
        CURSOR_UP->keys[k] = &CURSOR_UP_KEYS[k];

    /*
        REMEMBER TO FREE MALLOC!!!
    */
    
    // CURSOR_DOWN
    int CURSOR_DOWN_KEYS[] = { DEFAULT_CURSOR_DOWN };
    size_t CURSOR_DOWN_SIZE = ARRAY_SIZE(CURSOR_DOWN_KEYS);

    COMMAND *CURSOR_DOWN = malloc(sizeof *CURSOR_DOWN + CURSOR_DOWN_SIZE + sizeof *CURSOR_DOWN->keys); // Alocate storage 

    CURSOR_DOWN->length = CURSOR_DOWN_SIZE; // Assigns length

    size_t k2 = 0;
    for(k2; k2 < CURSOR_DOWN_SIZE; k2++)  // Assigns addresses to structs  
        CURSOR_DOWN->keys[k2] = &CURSOR_DOWN_KEYS[k2];
    
    // CURSOR_LEFT
    int CURSOR_LEFT_KEYS[] = { DEFAULT_CURSOR_LEFT };
    size_t CURSOR_LEFT_SIZE = ARRAY_SIZE(CURSOR_LEFT_KEYS);

    COMMAND *CURSOR_LEFT = malloc(sizeof *CURSOR_LEFT + CURSOR_LEFT_SIZE + sizeof *CURSOR_LEFT->keys); // Alocate storage 

    CURSOR_LEFT->length = CURSOR_LEFT_SIZE; // Assigns length

    size_t k3 = 0;
    for(k3; k3 < CURSOR_LEFT_SIZE; k3++)  // Assigns addresses to structs  
        CURSOR_LEFT->keys[k3] = &CURSOR_LEFT_KEYS[k3];

    // CURSOR_RIGHT
    int CURSOR_RIGHT_KEYS[] = { DEFAULT_CURSOR_RIGHT };
    size_t CURSOR_RIGHT_SIZE = ARRAY_SIZE(CURSOR_RIGHT_KEYS);

    COMMAND *CURSOR_RIGHT = malloc(sizeof *CURSOR_RIGHT + CURSOR_RIGHT_SIZE + sizeof *CURSOR_RIGHT->keys); // Alocate storage 

    CURSOR_RIGHT->length = CURSOR_RIGHT_SIZE; // Assigns length

    size_t k4 = 0;
    for(k4; k4 < CURSOR_RIGHT_SIZE; k4++)  // Assigns addresses to structs  
        CURSOR_RIGHT->keys[k4] = &CURSOR_RIGHT_KEYS[k4];
        
    // CHANGE_COLORS
    int CHANGE_COLORS_KEYS[] = { DEFAULT_CHANGE_COLORS };
    size_t CHANGE_COLORS_SIZE = ARRAY_SIZE(CHANGE_COLORS_KEYS);

    COMMAND *CHANGE_COLORS = malloc(sizeof *CHANGE_COLORS + CHANGE_COLORS_SIZE + sizeof *CHANGE_COLORS->keys); // Alocate storage 

    CHANGE_COLORS->length = CHANGE_COLORS_SIZE; // Assigns length

    size_t k5 = 0;
    for(k5; k5 < CHANGE_COLORS_SIZE; k5++)  // Assigns addresses to structs  
        CHANGE_COLORS->keys[k5] = &CHANGE_COLORS_KEYS[k5];

    // Sets specs for custom commands


    // Creates matrix to count the number of commands available
    COMMAND *ALL_COMMANDS[] = {
            CURSOR_UP,
            CURSOR_DOWN,
            CURSOR_RIGHT,
            CURSOR_LEFT,
            CHANGE_COLORS
    };

    // Auxiliary variable for ALL_COMMANDS size
    int ALL_COMMANDS_SIZE = 0;
    int COMMAND_SIZE[2] = {0, 0};

    // Tests which command should run 
    while(input = getInput(cursor))
    {
        // Invalid input entries
        if(input == -1)
          continue;
        
        // Finds the command array
        int i;
        
        for(i = 0; i < (sizeof(ALL_COMMANDS) / sizeof(*ALL_COMMANDS)); i++)
        {
            // Sets aux size variables
            ALL_COMMANDS_SIZE = ALL_COMMANDS[i]->length;
            COMMAND_SIZE[0] = ALL_COMMANDS_SIZE;
            
            // Looks through the ALL_COMMANDS array
            if(int_array_check(input, ALL_COMMANDS[i]->keys, ALL_COMMANDS_SIZE) == -1)
                continue;

            // Identifies which function matched with input0
            
            // CURSOR_UP
            COMMAND_SIZE[1] = CURSOR_UP->length;
            
            if(int_array_compare(ALL_COMMANDS[i]->keys, CURSOR_UP->keys, COMMAND_SIZE) == 1)
            {
                command = fn_cursor_up;
                return command;
            }
            
            // CURSOR_DOWN
            COMMAND_SIZE[1] = CURSOR_DOWN->length;
            
            if(int_array_compare(ALL_COMMANDS[i]->keys, CURSOR_DOWN->keys, COMMAND_SIZE) == 1)
            {
                command = fn_cursor_down;
                return command;
            }

            // CURSOR_LEFT
            COMMAND_SIZE[1] = CURSOR_LEFT->length;
            
            if(int_array_compare(ALL_COMMANDS[i]->keys, CURSOR_LEFT->keys, COMMAND_SIZE) == 1)
            {
                command = fn_cursor_left;
                return command;
            }

            // CURSOR_RIGHT
            COMMAND_SIZE[1] = CURSOR_RIGHT->length;
            
            if(int_array_compare(ALL_COMMANDS[i]->keys, CURSOR_RIGHT->keys, COMMAND_SIZE) == 1)
            {
                command = fn_cursor_right;
                return command;
            }
            
            // CHANGE_COLORS
            COMMAND_SIZE[1] = CHANGE_COLORS->length;
            
            if(int_array_compare(ALL_COMMANDS[i]->keys, CHANGE_COLORS->keys, COMMAND_SIZE) == 1)
            {
                command = fn_change_colors;
                return command;
            }
        }

        // Frees memory
        free(CURSOR_UP);
        free(CURSOR_DOWN);
        free(CURSOR_RIGHT);
        free(CURSOR_LEFT);
        free(CHANGE_COLORS);
        
        // Resets keyboard cache
        fflush(stdin);

        // Command not found
        if(command == NULL)
          printf("%s\n", COMMAND_NOT_FOUND);
    }
}

void fn_cursor_up(CURSOR *cursor){

    // Sets new coordinates
    POSITION next;
    next.x = cursor->axis.x;
    next.y = cursor->axis.y - 1;

    // Moves cursor
    moveCursor(cursor, next);
}

void fn_cursor_down(CURSOR *cursor){

    // Sets new coordinates
    POSITION next;
    next.x = cursor->axis.x;
    next.y = cursor->axis.y + 1;

    // Moves cursor
    moveCursor(cursor, next);
}

void fn_cursor_left(CURSOR *cursor){

    // Sets new coordinates
    POSITION next;
    next.x = cursor->axis.x - 1;
    next.y = cursor->axis.y;

    // Moves cursor
    moveCursor(cursor, next);
}

void fn_cursor_right(CURSOR *cursor){

    // Sets new coordinates
    POSITION next;
    next.x = cursor->axis.x + 1;
    next.y = cursor->axis.y;

    // Moves cursor
    moveCursor(cursor, next);
}

void moveCursor(CURSOR *cursor, POSITION next){

    // Limits canvas area
    if(next.x > DEFAULT_CANVAS_WIDTH || next.y > DEFAULT_CANVAS_HEIGHT)
        return;
    
    // Re-creates previous cursor position pixel
    PIXEL previous_pixel = canvas->last_updated;
            
    // Re-renders previous cursor position pixel
    gotoxy(cursor->axis.x, cursor->axis.y);
    
    print_pixel(previous_pixel);
    
    // Moves cursor
    cursor->axis.x = next.x;
    cursor->axis.y = next.y;
    
    // Creates new pixel to render
    PIXEL pixel;
    pixel.style.background_color = cursor->style.background_color ? cursor->style.background_color : REDB; // ANSI color code
    pixel.style.font_color = cursor->style.font_color ? cursor->style.font_color : WHT; // ANSI color code
    pixel.style.text = cursor->style.text ? cursor->style.text : ' '; // Spacebar code;
    pixel.axis.x = cursor->axis.x;
    pixel.axis.y = cursor->axis.y;
    
    // Renders pixel
    gotoxy(next.x, next.y);

    print_pixel(pixel);
}

void fn_change_colors(CURSOR *cursor){
     
     // Changes cursor color
     cursor->style.background_color = 102;
     
     // Moves cursor to the same place
     moveCursor(cursor, cursor->axis);
}

void fn_mouse_click(CURSOR *cursor, POSITION next){

    // Re-creates previous cursor position pixel
    PIXEL previous_pixel = canvas->last_updated;
            
    // Re-renders previous cursor position pixel
    gotoxy(cursor->axis.x, cursor->axis.y);
    
    print_pixel(previous_pixel);

    // Moves cursor to the next place
    moveCursor(cursor, next);
}
