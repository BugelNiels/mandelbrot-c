#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include "mandelbrot.h"


void initComplexPlane(double complex** complexPlane, int width, int height, PlaneDimension dim) {
	double complex z = dim.realStart + dim.imEnd * I;

	// imaginary numbers: start > end (since top left is 0,0)
	double imStep = (dim.imStart - dim.imEnd ) / (double) height;
	// real numbers: end > start
	double realStep = (dim.realEnd - dim.realStart) / (double) width;
	for (int i = 0; i < height; ++i)
	{
		for (int r = 0; r < width; ++r)
		{
			complexPlane[i][r] = z;
			z += realStep;
		}
		z = dim.realStart + cimag(z) * I + imStep * I;
	}
}

int getIterationsNaive(double complex c, int maxIter) {
	double complex z = 0;
	for (int i = 0; i < maxIter; ++i) {
		if(creal(z)*creal(z)+cimag(z)*cimag(z) > 4) {
			return i;
		}
		z = z * z + c;
	}
	return maxIter;
}

int getIterations(double complex c, int maxIter) {
	double rc = creal(c);
	double ic = cimag(c);
	double r2 = 0, i2 = 0, r = 0, i = 0;
	
	int iter = 0;
	while(r2 + i2 <= 4 && iter < maxIter) {
		i = 2 * r * i + ic;
		r = r2 - i2 + rc;
		r2 = r * r;
		i2 = i * i;
		iter++;
	}
	return iter;
}

void mandelBrot(int** iterPlane, double complex** complexPlane, int width, int height, int maxIter) {
	Timer timer;
	startTime(&timer);
	#pragma omp parallel for
	for (int i = 0; i < height; ++i) {
		for (int r = 0; r < width; ++r) {
			iterPlane[i][r] = getIterations(complexPlane[i][r], maxIter);
		}
	}
	stopTime(&timer); 
	printf("%f s\n\n", elapsedTime(timer));

}

void calcMandelbrot(double complex** complexPlane, int** iterPlane, int width, int height, int maxIter, PlaneDimension dim) {
	initComplexPlane(complexPlane, width, height, dim);
	mandelBrot(iterPlane, complexPlane, width, height, maxIter);
}
