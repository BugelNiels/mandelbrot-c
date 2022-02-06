#include "mandelbrot.h"

/**
 * @brief Calculate the number of iterations it takes for this complex value to escape the circle of radius 2.
 * 
 * @param c Complex value
 * @param maxIter Maximum number of iterations to test
 * @return int Number of iterations taken
 */
int getIterations(double complex c, int maxIter) {
    double rc = creal(c);
    double ic = cimag(c);
    double r2 = 0, i2 = 0, r = 0, i = 0;

    int iter = 0;
    while (r2 + i2 <= 4 && iter < maxIter) {
        i = 2 * r * i + ic;
        r = r2 - i2 + rc;
        r2 = r * r;
        i2 = i * i;
        iter++;
    }
    return iter;
}

/**
 * @brief Simple evaluation of whether the complex value is in the period 2 bulb.
 * 
 * @param c Complex value
 * @return int 1 if it is in the period 2 bulb; 0 otherwise
 */
int isInPeriod2Bulb(double complex c) {
    double rc = creal(c);
    double ic = cimag(c);
    return (rc + 1) * (rc + 1) + ic * ic < 1 / 16.0;
}

/**
 * @brief Simple evaluation of whether the complex value is in the main cardioid.
 * 
 * @param c Complex value
 * @return int 1 if it is in the main cardioid; 0 otherwise
 */
int isInMainCardioid(double complex c) {
    double rc = creal(c);
    double ic = cimag(c);
    double ic2 = ic * ic;
    double rc25 = rc - 0.25;
    double q = rc25 * rc25 + ic2;
    return q * (q + rc25) < 0.25 * ic2;
}

/**
 * @brief Evaluates the Mandelbrot set. 
 * 
 * @param complexPlane Complex plane
 * @param iterPlane Iteration plane in which to save the number of iterations it takes to determine whether the corresponding complex value escapes the circle of radius 2
 * @param maxIter Maximum number of iterations to use
 * @param dims Dimensions of the iteration and complex plane
 * @return float Number of seconds the execution took
 */
float mandelBrot(double complex** complexPlane, int** iterPlane, int maxIter, PlaneDimensions dims) {
    Timer timer;
    startTime(&timer);
#pragma omp parallel for
    for (int i = 0; i < dims.height; ++i) {
        for (int r = 0; r < dims.width; ++r) {
            double complex c = complexPlane[i][r];
            int iter;
            if (isInMainCardioid(c) || isInPeriod2Bulb(c)) {
                iter = maxIter;
            } else {
                iter = getIterations(complexPlane[i][r], maxIter);
            }
            iterPlane[i][r] = iter;
        }
    }
    stopTime(&timer);
    return elapsedTime(timer);
}

/**
 * @brief Initialises and calculates the Mandelbrot set. 
 * 
 * @param complexPlane Complex plane
 * @param iterPlane Iteration plane in which to save the number of iterations it takes to determine whether the corresponding complex value escapes the circle of radius 2
 * @param maxIter Maximum number of iterations to use
 * @param dims Dimensions of the iteration and complex plane
 */
void calcMandelbrot(double complex** complexPlane, int** iterPlane, int maxIter, PlaneDimensions dims) {
    initComplexPlane(complexPlane, dims);
    float secs = mandelBrot(complexPlane, iterPlane, maxIter, dims);
    printf("Calculated Mandelbrot set with %d iterations in %lf seconds\n", maxIter, secs);
}
