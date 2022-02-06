#include <complex.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include "interactions/inputHandler.h"
#include "interactions/menu.h"
#include "mandelbrot/mandelbrot.h"
#include "utils/printUtils.h"
#include "view/mandelbrotView.h"

/**
 * @brief Interactive Mandelbrot Program. Draws the menu and the Mandelbrot set
 * 
 * @param complexPlane Complex Plane
 * @param iterPlane Iteration Plane
 * @param dims Dimensions of the image and complex plane
 */
void runInteractiveProgram(double complex** complexPlane, int** iterPlane, PlaneDimensions dims) {
    int skipLines = dims.height + 4;
    int colorType = colorMenu();
    int maxIter = maxIterationsMenu();

    int running = 1;
    showInteractiveMenu();
    while (running > 0) {
        calcMandelbrot(complexPlane, iterPlane, maxIter, dims);
        displayMandelbrotSet(iterPlane, maxIter, colorType, dims);

        int userInput = readInteger();
        handleUserInput(userInput, &dims, &maxIter, &running);
        moveCursorUp(skipLines);
    }
}

/**
 * @brief Entry point of the program. Starts an interactive menu to set up the Mandelbrot calculations.
 * 
 * @param argc Argument count
 * @param argv Arguments
 * @return int Exit code
 */
int main(int argc, char* argv[]) {
    clearScreen();
    PlaneDimensions dims = initDefaultPlaneDimensions();
    omp_set_num_threads(8);
    double complex** complexPlane = allocComplexPlane(dims);
    int** iterPlane = allocIterPlane(dims);

    runInteractiveProgram(complexPlane, iterPlane, dims);

    freeComplexMatrix(complexPlane, dims.height);
    freeIntMatrix(iterPlane, dims.height);
    clearScreen();
    printf("Exiting program\n");
    return 0;
}