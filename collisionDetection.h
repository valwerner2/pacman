//
// Created by valwe on 23/02/2024.
//

#ifndef PACMAN_COLLISIONDETECTION_H
#define PACMAN_COLLISIONDETECTION_H
#include <SDL.h>

enum collision
{
    COLLISION_NONE  = 0b0000,
    COLLISION_UP    = 0b0001,
    COLLISION_DOWN  = 0b0010,
    COLLISION_LEFT  = 0b0100,
    COLLISION_RIGHT = 0b1000
};

int detectCollision(SDL_Rect *obj1, SDL_Rect *obj2);

#endif //PACMAN_COLLISIONDETECTION_H
