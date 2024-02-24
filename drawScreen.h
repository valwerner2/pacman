//
// Created by valwe on 22/02/2024.
//

#ifndef PACMAN_DRAWSCREEN_H
#define PACMAN_DRAWSCREEN_H

#include "entity.h"
#include "common.h"

typedef struct
{
    SDL_Renderer *renderer;
    entity **entities;
    unsigned long long entityCount;

}drawScreen_arguments;

void drawScreen(drawScreen_arguments *args);

#endif //PACMAN_DRAWSCREEN_H
