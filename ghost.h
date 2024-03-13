//
// Created by valwe on 24/02/2024.
//

#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H



#include "entity.h"
#include "common.h"

typedef struct
{
    entity* entity;
    entityTextures *texturesChaseScatter;
    entityTextures *texturesFrightened;
    entityTextures *texturesEaten;
    int type;
    int state;

    struct timeval lastMoved;
    unsigned long long movementDelay;
}ghost;

enum ghostState
{
    GHOST_CHASE,
    GHOST_SCATTER,
    GHOST_FRIGHTENED,
    GHOST_EATEN,
    GHOST_LEAVE_PRISON
};
enum ghostType
{
    GHOST_TYPE_RED,
    GHOST_TYPE_PURPLE,
    GHOST_TYPE_ORANGEN,
    GHOST_TYPE_CYAN,

    GHOST_TYPE_FRIGHTENED,
    GHOST_TYPE_EATEN
};


entityTextures *createGhostTexture(SDL_Renderer *renderer, int type);
ghost *createGhost(int startX, int startY, int type, SDL_Renderer *renderer);
entity getGhostTarget(ghost *currGhost, ghost **ghosts, entity *pacman);
void freeGhost(ghost *ghost);
void ghostTextureSwitch(ghost *gh);

#endif //PACMAN_GHOST_H
