#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <stdio.h>
#include <stdlib.h>

#include "../mandelbrot/mandelbrot.h"

void handleUserInput(int input, PlaneDimensions* dims, int* maxIter, int* running);

#endif  // INPUT_HANDLER_H