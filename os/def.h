#ifndef __OS_H__
#define __OS_H__

#include "../src/structures/def.h"

// OS
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

#define DEFAULT_PIXEL_RENDERING_STRING "\033[48;5;%dm\033[38;5;%dm%c\033[0;0m"

#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#define ARRAY_SIZE_2D(x) (sizeof((x)[0]) / sizeof((x)[0][0]))                 

#define DEFAULT_BYTE_ALLOCATION 64       
#define ANSI_COLOR_CODE_LENGTH 9

void loadOSDefinitions();

int getInput(CURSOR *cursor);

#endif
