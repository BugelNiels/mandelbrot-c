#include <stdlib.h>
#include <stdio.h>

#include "util.h"

void startTime(Timer* timer) {
    gettimeofday(&(timer->startTime), NULL);
}

void stopTime(Timer* timer) {
    gettimeofday(&(timer->endTime), NULL);
}

float elapsedTime(Timer timer) {
    return ((float) ((timer.endTime.tv_sec - timer.startTime.tv_sec) \
                + (timer.endTime.tv_usec - timer.startTime.tv_usec)/1.0e6));
}

double complex** allocComplexPlane(int width, int height) {
	double complex** complexPlane = malloc(height*sizeof(double complex*));
	for (int i = 0; i < height; ++i)	{
		complexPlane[i] = malloc(width*sizeof(double complex));
	}
	return complexPlane;
}

int** allocIterPlane(int width, int height) {
	int** iterPlane = malloc(height*sizeof(int*));
	for (int i = 0; i < height; ++i)	{
		iterPlane[i] = calloc(width, sizeof(int));
	}
	return iterPlane;
}

void freeComplexMatrix(double complex** matrix, int height) {
	for (int i = 0; i < height; ++i) {
		free(matrix[i]);
	}
	free(matrix);
}

void freeIntMatrix(int** matrix, int height) {
	for (int i = 0; i < height; ++i) {
		free(matrix[i]);
	}
	free(matrix);
}

