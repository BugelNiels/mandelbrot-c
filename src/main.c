#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include "interaction.h"

void runInteractiveProgram(double complex** complexPlane, int** iterPlane, int width, int height) {
	int maxIter;
	int skipLines = height + 15;
	printf("Maximum number of iterations:\n");
	scanf("%d", &maxIter);
	PlaneDimension dim = {-2.2, 1.0, 1.0, -1.0};

	int userInput = 1;
	int inputItems = 1;
	while(userInput > 0 && inputItems > 0) {
		printMenu();
		printf("Calculating Mandelbrot set with %d iterations...\n", maxIter);
		calcMandelbrot(complexPlane, iterPlane, width, height, maxIter, dim);

		showIterPlane(iterPlane, width, height, maxIter);
		inputItems = scanf("%d", &userInput);
		char c = getchar();
		printf("%c\n", c);


		switch(userInput) {
			case 0: return;
			case 1: zoomIn(&dim); break;
			case 2: zoomOut(&dim); break;
			case 3: moveLeft(&dim); break;
			case 4: moveRight(&dim); break;
			case 5: moveUp(&dim); break;
			case 6: moveDown(&dim); break;
			case 7: maxIter *= 2; break;
			default: printf("Invalid command");
		}
		printf("\n");
		printf("\033[2J");
		printf("\033[%dA", skipLines);
		// move up 39 lines; TODO: make dynamic
	}
}

int main(int argc, char *argv[]) {
	int width = 80, height = 30;
	omp_set_num_threads(8);
	double complex** complexPlane = allocComplexPlane(width, height);
	int** iterPlane = allocIterPlane(width, height);
	
	runInteractiveProgram(complexPlane, iterPlane, width, height);
	
	freeComplexMatrix(complexPlane, height);
	freeIntMatrix(iterPlane, height);
	printf("\033[2J");
	printf("Exiting program\n");
    return 0;
}