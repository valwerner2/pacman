//
// Created by valwe on 23/02/2024.
//
#include "collisionDetection.h"

int detectCollision(SDL_Rect *obj1, SDL_Rect *obj2)
{
    int collision = COLLISION_NONE;

    //UP DOWN collision
    if((obj1->x <= obj2->x+obj2->w) && (obj1->x + obj1->w >= obj2->x))
    {
        //UP collision
        if((obj1->y < obj2->y + obj2->h) && (obj1->y > obj2->y))
        {
            collision |= COLLISION_UP;
        }
        //DOWN collision
        else if((obj1->y + obj1->h > obj2->y) && (obj1->y < obj2->y))
        {
            collision |= COLLISION_DOWN;
        }
    }
    //LEFT RIGHT collision
    if((obj1->y <= obj2->y + obj2->h) && (obj1->y + obj1->h >= obj2->y))
    {
        //LEFT collision
        if((obj1->x < obj2->x+obj2->w) && (obj1->x > obj2->x))
        {
            collision |= COLLISION_LEFT;
        }
        //RIGHT collision
        else if((obj1->x + obj1->w >= obj2->x) && (obj1->x < obj2->x))
        {
            collision |= COLLISION_RIGHT;
        }
    }
    return collision;
}