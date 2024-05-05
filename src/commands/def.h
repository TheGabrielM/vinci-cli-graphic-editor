#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "../structures/def.h"

// Commands
#define DEFAULT_CURSOR_UP 87, 119
#define DEFAULT_CURSOR_DOWN 83, 115
#define DEFAULT_CURSOR_LEFT 65, 97
#define DEFAULT_CURSOR_RIGHT 68, 100
#define DEFAULT_CHANGE_COLORS 32

// Messages
#define COMMAND_NOT_FOUND "This command is unknown"

// Generic function signature
typedef void FUNCTION_SIGNATURE(CURSOR *cursor);

// Function headers
void *get_command(CURSOR *cursor);

void fn_cursor_up(CURSOR *cursor);
void fn_cursor_down(CURSOR *cursor);
void fn_cursor_left(CURSOR *cursor);
void fn_cursor_right(CURSOR *cursor);

void fn_change_colors(CURSOR *cursor);

void fn_mouse_click(CURSOR *cursor, POSITION next);

void moveCursor(CURSOR *cursor, POSITION next);

#endif
