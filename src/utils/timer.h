#ifndef UTIL_H
#define UTIL_H

#include <complex.h>
#include <sys/time.h>

/**
 * @brief Struct for a timer
 * 
 */
typedef struct {
    struct timeval startTime;
    struct timeval endTime;
} Timer;

void startTime(Timer* timer);
void stopTime(Timer* timer);
float elapsedTime(Timer timer);

#endif  // UTIL_H