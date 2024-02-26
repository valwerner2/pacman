//
// Created by valwe on 24/02/2024.
//

#ifndef PACMAN_BIGCOIN_H
#define PACMAN_BIGCOIN_H



#include "entity.h"
#include "common.h"

typedef struct
{
    entity* entity;

}bigCoin;

entityTextures *createBigCoinTexture(SDL_Renderer *renderer);
bigCoin *createBigCoin(int startX, int startY, SDL_Renderer *renderer);

void freeBigCoin(bigCoin *bigCoin);

#endif //PACMAN_BIGCOIN_H
