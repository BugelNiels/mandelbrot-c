#include "inputHandler.h"

#include "../utils/printUtils.h"
#include "actions.h"

/**
 * @brief Executes a certain action depending on the input of the user.
 *
 * @param input User input
 * @param dims Dimensions of the complex/iteration plane
 * @param maxIter Maximum number of iterations
 * @param running Whether the program should be runnning or not.
 */
void handleUserInput(int input, PlaneDimensions* dims, int* maxIter, int* running) {
    clearLine();
    switch (input) {
        case 0:
            prepareProgramExit(running);
            return;
        case 1:
            zoomIn(dims);
            break;
        case 2:
            zoomOut(dims);
            break;
        case 3:
            moveLeft(dims);
            break;
        case 4:
            moveRight(dims);
            break;
        case 5:
            moveUp(dims);
            break;
        case 6:
            moveDown(dims);
            break;
        case 7:
            increaseIterations(maxIter);
            break;
        case 8:
            decreaseIterations(maxIter);
            break;
        default:
            invalidInput();
    }
    printf("\n");
}