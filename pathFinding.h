//
// Created by valwe on 25/02/2024.
//
#include "collisionDetection.h"
#include "entity.h"

#ifndef PACMAN_PATHFINDING_H
#define PACMAN_PATHFINDING_H

typedef struct
{
    unsigned char topFree, bottomFree, leftFree, rightFree;
}pathFindingMap_Grid;

pathFindingMap_Grid **createPathFindingMap_Grid(SDL_Renderer *renderer,
                                                unsigned int fieldSize,
                                                entity **entities,
                                                unsigned int entityCount);
entity **pathFindingMapGridToEntities(pathFindingMap_Grid **grid,
                                      SDL_Renderer *renderer,
                                      unsigned int fieldSize,
                                      unsigned long long *entityCount);

#endif //PACMAN_PATHFINDING_H
