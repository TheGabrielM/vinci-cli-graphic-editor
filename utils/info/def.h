#ifndef __UTILS_INFO_H__
#define __UTILS_INFO_H__

#include "../../src/structures/def.h"
#include "../../src/canvas/def.h"

// Function Headers
void showCursorAxis(POSITION axis);
void showCanvasBorder(POSITION axis);
void showColorBar(POSITION axis);
int onColorBar(POSITION axis);

// Color Bar
#define COLOR_BAR_ROWS 7
#define COLOR_BAR_COLS 4

int colorBar[COLOR_BAR_ROWS][COLOR_BAR_COLS] = {
                                                    { BCK, RED1, GRN1, YEL1, },
                                                    { GRY1, RED2, GRN2, YEL2, },
                                                    { GRY2, RED3, GRN3, YEL3, },
                                                    { GRY3, RED4, GRN4, YEL4, },
                                                    { BLU1, RED1, GRN1, YEL1, },
                                                    { BLU2, RED2, GRN2, YEL2, },
                                                    { BLU3, RED3, GRN3, YEL3, },
                                                };

#endif
