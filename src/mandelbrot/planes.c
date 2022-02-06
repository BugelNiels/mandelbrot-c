#include "planes.h"

#define IMAGE_WIDTH 80
#define IMAGE_HEIGHT 30

/**
 * @brief Initialises a PlaneDimensions struct with default values.
 *
 * @return PlaneDimensions a PlaneDimensions struct with default values
 */
PlaneDimensions initDefaultPlaneDimensions() {
    PlaneDimensions dims = {-2.2, 1.0, 1.0, -1.0, IMAGE_WIDTH, IMAGE_HEIGHT};
    return dims;
}

/**
 * @brief Initialises the complex plane with at each index the correct complex value.
 *
 * @param complexPlane The complex plane to initialise
 * @param dims Dimensions of the complex plane
 */
void initComplexPlane(double complex** complexPlane, PlaneDimensions dims) {
    double complex z = dims.realStart + dims.imEnd * I;

    // imaginary numbers: "start" to "end" (since top left is 0,0)
    double imStep = (dims.imStart - dims.imEnd) / (double)dims.height;
    // real numbers: "end" to "start"
    double realStep = (dims.realEnd - dims.realStart) / (double)dims.width;
    for (int i = 0; i < dims.height; ++i) {
        for (int r = 0; r < dims.width; ++r) {
            complexPlane[i][r] = z;
            z += realStep;
        }
        z = dims.realStart + cimag(z) * I + imStep * I;
    }
}

/**
 * @brief Allocates memory for a complex plane.
 *
 * @param dims Dimensions of the complex plane
 * @return double** A newly allocated, empty complex plane
 */
double complex** allocComplexPlane(PlaneDimensions dims) {
    double complex** complexPlane = malloc(dims.height * sizeof(double complex*));
    for (int i = 0; i < dims.height; ++i) {
        complexPlane[i] = malloc(dims.width * sizeof(double complex));
    }
    return complexPlane;
}

/**
 * @brief Allocates memory for an iteration plane.
 *
 * @param dims Dimensions of the iteration plane/image
 * @return int** A newly allocated empty iteration plane/image
 */
int** allocIterPlane(PlaneDimensions dims) {
    int** iterPlane = malloc(dims.height * sizeof(int*));
    for (int i = 0; i < dims.height; ++i) {
        iterPlane[i] = calloc(dims.width, sizeof(int));
    }
    return iterPlane;
}

/**
 * @brief Frees memory of a complex matrix.
 *
 * @param matrix Matrix to free
 * @param height Height of the matrix
 */
void freeComplexMatrix(double complex** matrix, int height) {
    for (int i = 0; i < height; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

/**
 * @brief Frees memory of an integer matrix.
 *
 * @param matrix Matrix to free
 * @param height Height of the matrix
 */
void freeIntMatrix(int** matrix, int height) {
    for (int i = 0; i < height; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}
