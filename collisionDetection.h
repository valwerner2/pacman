//
// Created by valwe on 23/02/2024.
//

#ifndef PACMAN_COLLISIONDETECTION_H
#define PACMAN_COLLISIONDETECTION_H

#include "common.h"
#include "ghost.h"

enum collision
{
    COLLISION_NONE  = 0b0000,
    COLLISION_UP    = 0b0001,
    COLLISION_DOWN  = 0b0010,
    COLLISION_LEFT  = 0b0100,
    COLLISION_RIGHT = 0b1000
};

int detectCollisionRect(SDL_Rect *obj1, SDL_Rect *obj2);
int detectCollisionEntity(entity *entity1, entity *entity2);
int detectCollisionEntityEntities(entity *e, entity **entities, unsigned long long entityCount);
int detectCollisionEntityDirectionEntities(entity *e, int  direction, entity **entities, unsigned long long entityCount);
void ghostChangeState(ghost *currGhost, struct timeval *gameTime, struct timeval *pullTime);
int ghostChaseNextDirection(ghost *chaserGhost, entity *target, entity **map, unsigned long long entityCountMap);
int detectCollisionEntityTeleportDirectional(entity *e, SDL_Rect *start, SDL_Rect *end, int newDirection);
int detectCollisionEntityTeleportBidirectional(entity *e, SDL_Rect *temp1, SDL_Rect *temp2, int directionT1, int directionT2);
int detectCollisionEntitiesTeleportBidirectional(entity **e, int entityCount, SDL_Rect *t1, SDL_Rect *t2, int directionT1, int directionT2);

#endif //PACMAN_COLLISIONDETECTION_H
