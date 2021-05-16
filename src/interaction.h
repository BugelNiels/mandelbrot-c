#include <stdlib.h>
#include <stdio.h>

#include <complex.h>
#include "mandelbrot.h"

void resetColor();
void greyScale(int val);
void black();
void white();
void zoomIn(PlaneDimension* dim);
void zoomOut(PlaneDimension* dim);
void moveLeft(PlaneDimension* dim);
void moveRight(PlaneDimension* dim);
void moveUp(PlaneDimension* dim);
void moveDown(PlaneDimension* dim);
void printMenu();
void showIterPlane(int** iterPlane, int width, int height, int maxIter);