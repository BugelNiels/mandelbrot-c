#ifndef MANDELBROT_VIEW_H
#define MANDELBROT_VIEW_H

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

#include "../mandelbrot/mandelbrot.h"

void displayMandelbrotSet(int** iterPlane, int maxIter, int type, PlaneDimensions dims);

#endif  // MANDELBROT_VIEW_H