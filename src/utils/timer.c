#include "timer.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Starts the timer
 *
 * @param timer The timer to start
 */
void startTime(Timer* timer) { gettimeofday(&(timer->startTime), NULL); }

/**
 * @brief Stops the timer
 *
 * @param timer The timer to stop
 */
void stopTime(Timer* timer) { gettimeofday(&(timer->endTime), NULL); }

/**
 * @brief Returns the number of seconds passed in the timer
 * 
 * @param timer The timer to print the elapsed time of
 * @return float Number of seconds elapsed
 */
float elapsedTime(Timer timer) {
    float secDifference = timer.endTime.tv_sec - timer.startTime.tv_sec;
    float uSecDifference = (timer.endTime.tv_usec - timer.startTime.tv_usec) / 1.0e6;
    return secDifference + uSecDifference;
}
