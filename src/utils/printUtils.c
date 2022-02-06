#include "printUtils.h"

/**
 * @brief Resets the foreground and background color of print statements.
 *
 */
void resetColor() {
    // set default foreground color
    printf("\033[37m");
    // set default background color
    printf("\033[40m");
}

/**
 * @brief Sets the background color of print statements.
 *
 * @param r Red
 * @param g Green
 * @param b Blue
 */
void setColor(int r, int g, int b) { printf("\033[48;2;%d;%d;%dm", r, g, b); }

/**
 * @brief Sets the background color of print statements.
 *
 * @param val Grey Value
 */
void setGrayValue(int val) { setColor(val, val, val); }

/**
 * @brief Clears the screen.
 *
 */
void clearScreen() { printf("\033[2J"); }

/**
 * @brief Moves the cursor up a number of lines.
 *
 * @param lines Number of lines to move the cursor up
 */
void moveCursorUp(int lines) { printf("\033[%dA", lines); }

/**
 * @brief Clears the line the cursor is at
 *
 */
void clearLine() { printf("\33[2K\r"); }
