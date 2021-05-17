#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "interaction.h"

void resetColor() {
    printf("\033[37m");
    printf("\033[40m");

}

void greyScale(int i, int maxIter) {
	double maxIterLog = log(maxIter);
	double per = log(i) / maxIterLog;
	int greyVal = per * 255;
	printf("\033[48;2;%d;%d;%dm", greyVal, greyVal, greyVal);
}

int getVal(int i, int m, int* c) {
	if(i >= m) {
		return 0;
	} else {
		return 255u * (sin(0.1 * i + (*c)++) / 2.0 + 0.5);
	}
}

void colorScale(int i, int m) {
	int c = 4;
	printf("\033[48;2;%d;%d;%dm", getVal(i, m, &c), getVal(i, m, &c), getVal(i, m, &c));
}

void black() {
	printf("\033[48;2;0;0;0m");
    printf("\033[30m");
    printf("\033[40m");

}

void white() {
    printf("\033[37m");
    printf("\033[47m");

}

void zoomIn(PlaneDimension* dim) {
	double rDif = (dim->realEnd - dim->realStart) * 0.1;
	double iDif = (dim->imStart - dim->imEnd) * 0.1;
	dim->realStart += rDif;
	dim->realEnd -= rDif;
	dim->imStart -= iDif;
	dim->imEnd += iDif;
}


void zoomOut(PlaneDimension* dim) {
	double rDif = (dim->realEnd - dim->realStart) * 0.1;
	double iDif = (dim->imStart - dim->imEnd) * 0.1;
	dim->realStart -= rDif;
	dim->realEnd += rDif;
	dim->imStart += iDif;
	dim->imEnd -= iDif;

}

void moveLeft(PlaneDimension* dim) {
	double rDif = (dim->realEnd - dim->realStart) * 0.1;
	dim->realStart -= rDif;
	dim->realEnd -= rDif;

}

void moveRight(PlaneDimension* dim) {
	double rDif = (dim->realEnd - dim->realStart) * 0.1;
	dim->realStart += rDif;
	dim->realEnd += rDif;

}

void moveUp(PlaneDimension* dim) {
	double iDif = (dim->imStart - dim->imEnd) * 0.1;
	dim->imStart -= iDif;
	dim->imEnd -= iDif;
}

void moveDown(PlaneDimension* dim) {
	double iDif = (dim->imStart - dim->imEnd) * 0.1;
	dim->imStart += iDif;
	dim->imEnd += iDif;
}

void printMenu() {
	printf("What would you like to do?\n");
	printf(" (1) Zoom in\n");
	printf(" (2) Zoom out\n");	
	printf(" (3) Left\n");
	printf(" (4) Right\n");
	printf(" (5) Up\n");
	printf(" (6) Down\n");
	printf(" (7) Double iterations\n");
	printf(" (8) Halve iterations\n");
	printf(" (0) Exit\n");
}

void printColorMenu() {
	printf("Color scale?\n");
	printf(" (0) greyscale\n");
	printf(" (1) colorsss\n");	
}

void putElem(int type, int i, int m) {
	switch(type) {
		case 0: greyScale(i, m); break;
		case 1: colorScale(i, m); break;
	}
	putchar(' ');	
}

void showIterPlane(int** iterPlane, int width, int height, int maxIter, int type) {
	
	for (int i = 0; i < height; ++i) {
		for (int r = 0; r < width; ++r) {
			putElem(type, iterPlane[i][r], maxIter);
		}
		resetColor();
		putchar('\n');
	}
}