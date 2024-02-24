//
// Created by valwe on 24/02/2024.
//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H

#include <time.h>

#include "entity.h"
#include "common.h"

typedef struct
{
    entity* entity;

}ghost;

entityTextures *createGhostTexture(SDL_Renderer *renderer);
ghost *createGhost(int startX, int startY, unsigned char r, unsigned char g, unsigned char b, SDL_Renderer *renderer);

void freeGhost(ghost *ghost);

#endif //PACMAN_GHOST_H
