//
// Created by valwe on 24/02/2024.
//

#ifndef PACMAN_COMMON_H
#define PACMAN_COMMON_H

#include <SDL.h>
#include <SDL_image.h>
#include <time.h>

#define SPRITE_SIZE_SOURCE 32
#define SPRITE_SIZE_RENDER 32

#define POS(x) (x)*SPRITE_SIZE_SOURCE

typedef struct{unsigned long long x; unsigned long long y;} vecUnsigned;
typedef struct{signed long long x; signed long long y;} vecSigned;

int timeElapsed(unsigned long long microsecondsAnimationTime, struct timeval *oldTime);
int timeElapsedNoUpdate(unsigned long long microsecondsAnimationTime, struct timeval *oldTime);

#endif //PACMAN_COMMON_H
