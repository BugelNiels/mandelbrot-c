#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "interaction.h"

void resetColor() {
    printf("\033[37m");
    printf("\033[40m");

}

void greyScale(int val) {
	printf("\033[48;2;%d;%d;%dm", val, val, val);
	printf("\033[38;2;%d;%d;%dm", val, val, val);

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
	printf(" (1) Zoom in\n");
	printf(" (2) Zoom out\n");	
	printf(" (3) Left\n");
	printf(" (4) Right\n");
	printf(" (5) Up\n");
	printf(" (6) Down\n");
	printf(" (7) Increase iterations\n");
	printf(" (0) Exit\n");
}

void showIterPlane(int** iterPlane, int width, int height, int maxIter) {
	double maxIterLog = log(maxIter);
	for (int i = 0; i < height; ++i) {
		for (int r = 0; r < width; ++r) {
			double per = log(iterPlane[i][r]) / maxIterLog;
			int greyVal = per * 255;
			// printf("%lf, %d %d\n", per, greyVal, iterPlane[i][r]);
			greyScale(greyVal);
			putchar(' ');	
			// if(iterPlane[i][r] < maxIter) {
			// 	black();
			// 	putchar(' ');	
			// } else {		
			// 	white();
			// 	putchar('#');	
			// }
		}
		resetColor();
		putchar('\n');
	}
}