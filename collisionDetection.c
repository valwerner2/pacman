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
void ghostChangeState(ghost *currGhost, struct timeval *gameTime, struct timeval *pullTime)
{
    switch (currGhost->state)
    {
        case GHOST_LEAVE_PRISON:
        {
            SDL_Rect hitBoxPrisonLeft = {POS(8), POS(8), 32, 32};
            if (detectCollisionRect(&currGhost->entity->hitBox, &hitBoxPrisonLeft))
            {
                currGhost->state = GHOST_CHASE;
            }
        }
            break;
        case GHOST_EATEN:
        {
            SDL_Rect hitBoxEnteredLeft = {POS(8), POS(10), 32, 32};
            if (detectCollisionRect(&currGhost->entity->hitBox, &hitBoxEnteredLeft) && (rand() % 100) >= 85)
            {
                currGhost->state = GHOST_LEAVE_PRISON;
            }
        }
            break;
    }
}
int ghostChaseNextDirection(ghost *chaserGhost, entity *target, entity **map, unsigned long long entityCountMap)
{
    unsigned long long distance[] = {1, 1, 1, 1, 1};

    int turnAroundDir = NONE;

    switch (chaserGhost->entity->direction)
    {
        case UP:
            distance[DOWN] = 0;
            turnAroundDir = DOWN;
            break;
        case DOWN:
            distance[UP] = 0;
            turnAroundDir = UP;
            break;
        case LEFT:
            distance[RIGHT] = 0;
            turnAroundDir = RIGHT;
            break;
        case RIGHT:
            distance[LEFT] = 0;
            turnAroundDir = LEFT;
            break;
    }
    int nearest = UP;
    for(int currDir = 0; currDir < 4; currDir++)
    {
        if(distance[currDir])
        {
            if(!detectCollisionEntityDirectionEntities(chaserGhost->entity, currDir, map, entityCountMap))
            {
                entity temp = *chaserGhost->entity;
                updateEntity(&temp, currDir);
                distance[currDir] = getDistanceEntity(&temp, target);
                nearest = currDir;
            }
            else
            {
                distance[currDir] = 0;
            }
        }
    }
    if(chaserGhost->state == GHOST_FRIGHTENED)
    {
        int countPossible = 0;
        for (int currDir = 0; currDir < 4; currDir++)
        {
            if (distance[currDir]){ countPossible++; }
        }
        if(countPossible)
        {
            int possibleDirNum = rand() % countPossible;
            for (int currDir = 0; possibleDirNum; currDir++)
            {
                if (distance[currDir])
                {
                    possibleDirNum--;
                    nearest = currDir;
                }
            }
        }
    }
    else
    {
        for (int currDir = 0; currDir < 4; currDir++)
        {
            if (distance[currDir] > 0 && (distance[currDir] < distance[nearest]))
            { 
                nearest = currDir; 
            }
        }

        if (distance[nearest] == distance[RIGHT]){ nearest = RIGHT; }
        if (distance[nearest] == distance[DOWN]){ nearest = DOWN; }
        if (distance[nearest] == distance[LEFT]){ nearest = LEFT; }
        if (distance[nearest] == distance[UP]){ nearest = UP; }
    }
    char dirAvailable = 0;
    for (int currDir = 0; currDir < 4; currDir++)
    {
        if (distance[currDir] > 0){ dirAvailable = 1; continue;}
    }
    if(!dirAvailable){nearest = turnAroundDir;}
    //SDL_Log("%5s %5s %5s %5s", "UP", "DOWN", "LEFT", "RIGHT");
    //SDL_Log("%5d %5d %5d %5d", distance[UP], distance[DOWN], distance[LEFT], distance[RIGHT]);
    //SDL_Log("Nearest: %d\n", nearest);
    return nearest;
}

int detectCollisionEntityTeleportDirectional(entity *e, SDL_Rect *start, SDL_Rect *end, int newDirection)
{
    int coll = detectCollisionRect(&e->hitBox, start);
    if(coll)
    {
        updateEntitySet(e, end->x, end->y, newDirection);
    }
    return coll;
}
int detectCollisionEntityTeleportBidirectional(entity *e, SDL_Rect *t1, SDL_Rect *t2, int directionT1, int directionT2)
{
    int coll = detectCollisionRect(&e->hitBox, t1);
    if(coll)
    {

        SDL_Rect temp2 = *t2;
        switch (directionT2)
        {
            case UP:
                temp2.y -= SPRITE_SIZE_SOURCE;
                break;
            case DOWN:
                temp2.y += SPRITE_SIZE_SOURCE;
                break;
            case LEFT:
                temp2.x -= SPRITE_SIZE_SOURCE;
                break;
            case RIGHT:
                temp2.x += SPRITE_SIZE_SOURCE;
                break;
        }
        detectCollisionEntityTeleportDirectional(e, t1, &temp2, directionT2);
        return coll;
    }
    coll = detectCollisionRect(&e->hitBox, t2);
    if(coll)
    {
        SDL_Rect temp1 = *t1;
        switch (directionT1)
        {
            case UP:
                temp1.y -= SPRITE_SIZE_SOURCE;
                break;
            case DOWN:
                temp1.y += SPRITE_SIZE_SOURCE;
                break;
            case LEFT:
                temp1.x -= SPRITE_SIZE_SOURCE;
                break;
            case RIGHT:
                temp1.x += SPRITE_SIZE_SOURCE;
                break;
        }
        detectCollisionEntityTeleportDirectional(e, t2, &temp1, directionT1);
        return coll;
    }
}
int detectCollisionEntitiesTeleportBidirectional(entity **e, int entityCount, SDL_Rect *t1, SDL_Rect *t2, int directionT1, int directionT2)
{
    int col = COLLISION_NONE;
    for(int i = 0; i < entityCount; i++){col |= detectCollisionEntityTeleportBidirectional(e[i], t1, t2, directionT1, directionT2);}
    return col;
}