//
// Created by valwe on 27/02/2024.
//

#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H

#include "entity.h"
#include "common.h"

typedef struct
{
    entity* entity;
}wall;

entityTextures *createWallTexture(SDL_Renderer *renderer);
wall *createWall(int startX, int startY, SDL_Renderer *renderer);
void freeWall(wall* w);

#endif //PACMAN_WALL_H
