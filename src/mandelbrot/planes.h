#ifndef PLANES_H
#define PLANES_H

#include <complex.h>
#include <stdlib.h>

/**
 * @brief Contains information about the dimensions of the image and complex plane
 * 
 */
typedef struct PlaneDimensions {
    double realStart;
    double realEnd;
    double imStart;
    double imEnd;
    int width;
    int height;
} PlaneDimensions;

PlaneDimensions initDefaultPlaneDimensions();
void initComplexPlane(double complex** complexPlane, PlaneDimensions dims);

double complex** allocComplexPlane(PlaneDimensions dims);
int** allocIterPlane(PlaneDimensions dims);
void freeComplexMatrix(double complex** matrix, int height);
void freeIntMatrix(int** matrix, int height);

#endif  // PLANES_H