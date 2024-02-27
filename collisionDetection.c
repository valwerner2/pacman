//
// Created by valwe on 23/02/2024.
//
#include "collisionDetection.h"

int detectCollisionRect(SDL_Rect *obj1, SDL_Rect *obj2)
{
    int collision = COLLISION_NONE;

    //UP DOWN collision
    if((obj1->x < obj2->x+obj2->w) && (obj1->x + obj1->w > obj2->x))
    {
        //UP collision
        if((obj1->y < obj2->y + obj2->h) && (obj1->y >= obj2->y))
        {
            collision |= COLLISION_UP;
        }
        //DOWN collision
        else if((obj1->y + obj1->h > obj2->y) && (obj1->y <= obj2->y))
        {
            collision |= COLLISION_DOWN;
        }
    }
    //LEFT RIGHT collision
    if((obj1->y < obj2->y + obj2->h) && (obj1->y + obj1->h > obj2->y))
    {
        //LEFT collision
        if((obj1->x < obj2->x+obj2->w) && (obj1->x >= obj2->x))
        {
            collision |= COLLISION_LEFT;
        }
        //RIGHT collision
        else if((obj1->x + obj1->w > obj2->x) && (obj1->x <= obj2->x))
        {
            collision |= COLLISION_RIGHT;
        }
    }
    return collision;
}
int detectCollisionEntity(entity *entity1, entity *entity2)
{
    return detectCollisionRect(&entity1->hitBox, &entity2->hitBox);
}
int detectCollisionEntityEntities(entity *e, entity **entities, unsigned long long entityCount)
{
    int returnVal = COLLISION_NONE;
    for(int i = 0; i < entityCount; i++)
    {
        returnVal |= detectCollisionEntity(e, entities[i]);
    }
    return returnVal;
}
int detectCollisionEntityDirectionEntities(entity *e, int  direction, entity **entities, unsigned long long entityCount)
{
    entity temp = *e;
    updateEntity(&temp, direction);
    return detectCollisionEntityEntities(&temp, entities, entityCount);
}