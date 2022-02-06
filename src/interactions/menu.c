#include "menu.h"

#include "../utils/printUtils.h"

/**
 * @brief Print the options for the interactive menu.
 *
 */
void showInteractiveMenu() {
    printf("What would you like to do?\n");
    printf("\t(1) Zoom in\n");
    printf("\t(2) Zoom out\n");
    printf("\t(3) Left\n");
    printf("\t(4) Right\n");
    printf("\t(5) Up\n");
    printf("\t(6) Down\n");
    printf("\t(7) Double iterations\n");
    printf("\t(8) Halve iterations\n");
    printf("\t(0) Exit\n");
}

/**
 * @brief Reads an integer from the user input. If the input is not an integer, this function will keep repeating until
 * an integer is entered.
 *
 * @return int Integer from the user input
 */
int readInteger() {
    int userInput;
    int inputItems = -1;
    while (inputItems <= 0) {
        clearLine();
        inputItems = scanf("%d", &userInput);
        if (inputItems <= 0) {
            clearLine();
            printf("Invalid input\n");
            // remove invalid input
            scanf("%*s");
            moveCursorUp(2);
            clearLine();
        }
    }
    char c = getchar();
    printf("%c", c);
    return userInput;
}

/**
 * @brief Executes the menu for asking the user for the maximum number of iterations.
 *
 * @return int Maximum number of iterations the user wants to use for the calculation of the Mandelbrot set
 */
int maxIterationsMenu() {
    printf("Maximum number of iterations:\n");
    return readInteger();
}

/**
 * @brief Prints a menu with each of the color map options.
 *
 */
void printColorMenu() {
    printf("Color scale?\n");
    printf("\t(0) Grey Scale\n");
    printf("\t(1) Fancy Colors\n");
}

/**
 * @brief Executes the menu for asking the user for a specific color map
 *
 * @return int The color map to use
 */
int colorMenu() {
    printColorMenu();
    int userInput = -1;
    while (userInput < 0 || userInput > 1) {
        userInput = readInteger();
        if (userInput < 0 || userInput > 1) {
            clearLine();
            printf("Invalid input\n");
            moveCursorUp(3);
            clearLine();
        }
    }
    return userInput;
}