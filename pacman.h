//
// Created by valwe on 21/02/2024.
//
#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include <time.h>

#include "entity.h"
#include "common.h"

typedef struct
{
    entity* entity;

}pacman;

entityTextures *createPacmanTexture(SDL_Renderer *renderer);
pacman *createPacman(int startX, int startY, SDL_Renderer *renderer);
void freePacman(pacman* pacman);

#endif //PACMAN_PACMAN_H
