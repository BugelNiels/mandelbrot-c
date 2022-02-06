#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <stdio.h>
#include <stdlib.h>

void resetColor();
void setColor(int r, int g, int b);
void setGrayValue(int val);
void clearScreen();
void moveCursorUp(int lines);
void clearLine();

#endif  // PRINT_UTILS_H