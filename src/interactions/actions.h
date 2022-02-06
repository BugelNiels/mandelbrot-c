#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdio.h>
#include <stdlib.h>

#include "../mandelbrot/mandelbrot.h"

void zoomIn(PlaneDimensions* dim);
void zoomOut(PlaneDimensions* dim);
void moveLeft(PlaneDimensions* dim);
void moveRight(PlaneDimensions* dim);
void moveUp(PlaneDimensions* dim);
void moveDown(PlaneDimensions* dim);
void increaseIterations(int* maxIter);
void decreaseIterations(int* maxIter);
void prepareProgramExit(int* running);
void invalidInput();

#endif  // ACTIONS_H