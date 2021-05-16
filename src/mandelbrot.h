#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include "util.h"

typedef struct PlaneDimension {
	double realStart;
	double realEnd; 
	double imStart;
	double imEnd;
} PlaneDimension;

void initComplexPlane(double complex** complexPlane, int width, int height, PlaneDimension dim);
int getIterations(double complex c, int maxIter);
void mandelBrot(int** iterPlane, double complex** complexPlane, int width, int height, int maxIter);
void calcMandelbrot(double complex** complexPlane, int** iterPlane, int width, int height, int maxIter, PlaneDimension dim);
