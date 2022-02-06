#include "mandelbrotView.h"

#include "../utils/printUtils.h"

/**
 * @brief Get an integer value based on the provided iterations, maximum iterations and count.
 *
 * @param i Iterations
 * @param m Maximum iterations
 * @param c Count
 * @return int Generated value
 */
int getVal(int i, int m, int c) {
    if (i >= m) {
        return 0;
    } else {
        return 255u * (sin(0.1 * i + c) / 2.0 + 0.5);
    }
}

/**
 * @brief Generates and sets the print output to an RGB color based on the provided iterations and maximum iterations.
 *
 * @param i Iterations
 * @param m Maximum iterations
 */
void colorScale(int i, int m) {
    int c = 4;
    int r = getVal(i, m, c);
    c++;
    int g = getVal(i, m, c);
    c++;
    int b = getVal(i, m, c);
    setColor(r, g, b);
}

/**
 * @brief Generates and sets the print output to a grey scale value based on the provided iterations and maximum
 * iterations.
 *
 * @param i Iterations
 * @param m Maximum iterations
 */
void greyScale(int i, int maxIter) {
    double maxIterLog = log(maxIter);
    double per = log(i) / maxIterLog;
    int greyVal = per * 255;
    setGrayValue(greyVal);
}

/**
 * @brief Prints a pixel
 * 
 * @param type Color type of the pixel
 * @param i Iterations at this pixel
 * @param m Maximum iterations possible
 */
void outputPixel(int type, int i, int m) {
    switch (type) {
        case 0:
            greyScale(i, m);
            break;
        case 1:
            colorScale(i, m);
            break;
    }
    putchar(' ');
}

/**
 * @brief Prints the calculated Mandelbrot set.
 * 
 * @param iterPlane The calculated Mandelbrot set with the number of iterations at each index
 * @param maxIter Maximum number of iterations used
 * @param type Color type of the Mandelbrot set
 * @param dims Dimensions of the Mandelbrot set
 */
void displayMandelbrotSet(int** iterPlane, int maxIter, int type, PlaneDimensions dims) {
    for (int i = 0; i < dims.height; ++i) {
        for (int r = 0; r < dims.width; ++r) {
            outputPixel(type, iterPlane[i][r], maxIter);
        }
        resetColor();
        putchar('\n');
    }
}