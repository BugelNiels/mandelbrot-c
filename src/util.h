#include <sys/time.h>
#include <complex.h>

typedef struct {
    struct timeval startTime;
    struct timeval endTime;
} Timer;

void startTime(Timer* timer);
void stopTime(Timer* timer);
float elapsedTime(Timer timer);

double complex** allocComplexPlane(int width, int height);
int** allocIterPlane(int width, int height);
void freeComplexMatrix(double complex** matrix, int height);
void freeIntMatrix(int** matrix, int height);