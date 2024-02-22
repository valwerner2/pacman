//
// Created by valwe on 21/02/2024.
//

#include <SDL_image.h>

#include "entity.h"

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

void createPacmanTexture(entityTextures* pacman, SDL_Renderer *renderer);
void deletePacmanTexture(entityTextures* pacman);


#endif //PACMAN_PACMAN_H
