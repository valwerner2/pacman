//
// Created by valwe on 24/02/2024.
//

#ifndef PACMAN_SMALLCOIN_H
#define PACMAN_SMALLCOIN_H



#include "entity.h"
#include "common.h"

typedef struct
{
    entity* entity;

}smallCoin;

entityTextures *createSmallCoinTexture(SDL_Renderer *renderer);
smallCoin *createSmallCoin(int startX, int startY, SDL_Renderer *renderer);
entity **createSmallCoins(SDL_Renderer *renderer, int *smallCoinCount);

void freeSmallCoin(smallCoin *smallCoin);

#endif //PACMAN_SMALLCOIN_H
