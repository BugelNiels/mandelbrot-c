#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/timer.h"
#include "planes.h"

int getIterations(double complex c, int maxIter);
void calcMandelbrot(double complex** complexPlane, int** iterPlane, int maxIter, PlaneDimensions dims);

#endif  // MANDELBROT_H