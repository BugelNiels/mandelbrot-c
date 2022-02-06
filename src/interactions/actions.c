#include "actions.h"

#define ZOOM_STRENGTH 0.1
#define MOVE_STRENGTH 0.1

/**
 * @brief Changes the dimensions to obtain a zoomed in view.
 * 
 * @param dim Dimensions of the complex/iteration plane
 */
void zoomIn(PlaneDimensions* dim) {
    double rDif = (dim->realEnd - dim->realStart) * ZOOM_STRENGTH;
    double iDif = (dim->imStart - dim->imEnd) * ZOOM_STRENGTH;
    dim->realStart += rDif;
    dim->realEnd -= rDif;
    dim->imStart -= iDif;
    dim->imEnd += iDif;
}

/**
 * @brief Changes the dimensions to obtain a zoomed out view.
 * 
 * @param dim Dimensions of the complex/iteration plane
 */
void zoomOut(PlaneDimensions* dim) {
    double rDif = (dim->realEnd - dim->realStart) * ZOOM_STRENGTH;
    double iDif = (dim->imStart - dim->imEnd) * ZOOM_STRENGTH;
    dim->realStart -= rDif;
    dim->realEnd += rDif;
    dim->imStart += iDif;
    dim->imEnd -= iDif;
}

/**
 * @brief Changes the dimensions to obtain a view that is moved slightly to the left.
 * 
 * @param dim Dimensions of the complex/iteration plane
 */
void moveLeft(PlaneDimensions* dim) {
    double rDif = (dim->realEnd - dim->realStart) * MOVE_STRENGTH;
    dim->realStart -= rDif;
    dim->realEnd -= rDif;
}

/**
 * @brief Changes the dimensions to obtain a view that is moved slightly to the right.
 * 
 * @param dim Dimensions of the complex/iteration plane
 */
void moveRight(PlaneDimensions* dim) {
    double rDif = (dim->realEnd - dim->realStart) * MOVE_STRENGTH;
    dim->realStart += rDif;
    dim->realEnd += rDif;
}

/**
 * @brief Changes the dimensions to obtain a view that is moved slightly up.
 * 
 * @param dim Dimensions of the complex/iteration plane
 */
void moveUp(PlaneDimensions* dim) {
    double iDif = (dim->imStart - dim->imEnd) * MOVE_STRENGTH;
    dim->imStart -= iDif;
    dim->imEnd -= iDif;
}

/**
 * @brief Changes the dimensions to obtain a view that is moved slightly down.
 * 
 * @param dim Dimensions of the complex/iteration plane
 */
void moveDown(PlaneDimensions* dim) {
    double iDif = (dim->imStart - dim->imEnd) * MOVE_STRENGTH;
    dim->imStart += iDif;
    dim->imEnd += iDif;
}

/**
 * @brief Doubles the number of maximum iterations.
 * 
 * @param maxIter Maximum number of iterations
 */
void increaseIterations(int* maxIter) {
    *maxIter *= 2;
}

/**
 * @brief Halves the number of maximum iterations.
 * 
 * @param maxIter Maximum number of iterations
 */
void decreaseIterations(int* maxIter) {
    *maxIter /= 2;
}

/**
 * @brief Sets the running flag to indicate that the program should stop.
 * 
 * @param running Indication of the program should be running or not
 */
void prepareProgramExit(int* running) {
    *running = 0;
}

/**
 * @brief Outputs a message indicating an invalid input
 * 
 */
void invalidInput() {
    printf("Invalid action");
}