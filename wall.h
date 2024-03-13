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
    int type;
}wall;

enum typeWall
{
    WALL_TYPE_FRAME_CORNER,
    WALL_TYPE_FRAME_SIDES,
    WALL_TYPE_FRAME_SIDE,
    WALL_TYPE_FRAME_3SIDES,
    WALL_TYPE_FRAME_GEN,
    WALL_TYPE_FRAME_DOOR
};

entityTextures *createWallTexture(SDL_Renderer *renderer, int type);
wall *createWall(int type, int startX, int startY, SDL_Renderer *renderer, double angle, SDL_RendererFlip flip);
void freeWall(wall* w);

#endif //PACMAN_WALL_H
