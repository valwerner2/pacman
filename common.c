//
// Created by valwe on 28/02/2024.
//
#include "common.h"
int timeElapsed(unsigned long long microsecondsAnimationTime, struct timeval *oldTime)
{

    struct timeval currTime;
    mingw_gettimeofday(&currTime, NULL);

    if( microsecondsAnimationTime
        < ((currTime.tv_sec - oldTime->tv_sec) * 1000000llu
        + currTime.tv_usec - oldTime->tv_usec))
    {
        memcpy(oldTime, &currTime, sizeof(struct timeval));
        return true;
    }
    return false;
}
int timeElapsedNoUpdate(unsigned long long microsecondsAnimationTime, struct timeval *oldTime)
{

    struct timeval currTime;
    mingw_gettimeofday(&currTime, NULL);

    return microsecondsAnimationTime
        < ((currTime.tv_sec - oldTime->tv_sec) * 1000000llu
           + currTime.tv_usec - oldTime->tv_usec);
}