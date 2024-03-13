//
// Created by valwe on 22/02/2024.
//

#ifndef PACMAN_DRAWSCREEN_H
#define PACMAN_DRAWSCREEN_H

#include "entity.h"
#include "common.h"
#include "pathFinding.h"

typedef struct
{
    signed long long z;
    entity **entities;
    unsigned long long entityCount;
}layer;

void drawScreen(SDL_Renderer *renderer, unsigned int layerCount, layer *layers);
int compareLayers(const void *a, const void *b);

#endif //PACMAN_DRAWSCREEN_H
