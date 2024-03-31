//
// Created by valwe on 24/02/2024.
//
#include "smallCoin.h"

entityTextures *createSmallCoinTexture(SDL_Renderer *renderer)
{
    char *path = "../sprites/sheetSmallCoin.png";

    SDL_Rect rectIdle[] = { {POS(0), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(1), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(2), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(3), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(4), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(5), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(6), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(7), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};

    int animationInformation[18] = {0};
    animationInformation[ANI_IDLE_COUNT] = 7;
    animationInformation[ANI_IDLE_CURR] = rand() % (animationInformation[ANI_IDLE_COUNT] - 1);

    return entityCreateTextures(path, renderer,
                                animationInformation,
                                100000,
                                rectIdle,
                                NULL,
                                NULL,
                                NULL,
                                NULL,
                                NULL,
                                NULL,
                                NULL,
                                NULL);
}
smallCoin *createSmallCoin(int startX, int startY, SDL_Renderer *renderer)
{
    smallCoin *smallC = malloc(sizeof(smallCoin));
    smallC->entity = malloc(sizeof(entity));

    time_t initTime;
    time(&initTime);

    smallC->entity->textures = createSmallCoinTexture(renderer);
    smallC->entity->state = ENTITY_IDLE;
    smallC->entity->direction = NONE;
    smallC->entity->posX = startX;
    smallC->entity->posY = startY;
    smallC->entity->hitBox.x = startX + 10;
    smallC->entity->hitBox.y = startY + 10;
    smallC->entity->hitBox.w = SPRITE_SIZE_SOURCE - 2 * 10;
    smallC->entity->hitBox.h = SPRITE_SIZE_SOURCE - 2 * 10;
    smallC->entity->lastActive = initTime;
    smallC->entity->pathFindingCollision = 0;
    smallC->entity->visible = 1;

    smallC->entity->textures->flip = SDL_FLIP_NONE;
    smallC->entity->textures->center = NULL;
    smallC->entity->textures->angle = 0.;

    return smallC;
}
void freeSmallCoin(smallCoin* smallCoin)
{
    entityDeleteTextures(smallCoin->entity->textures);
    free(smallCoin->entity);
    free(smallCoin);
}
entity **createSmallCoins(SDL_Renderer *renderer, int *smallCoinCount)
{
    entity **returnCoins = malloc(sizeof(entity*) * 240);
    *smallCoinCount = 0;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 0, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 1, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 2, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 3, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 4, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 0, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 1, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 2, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 3, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 4, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 5, POS(1), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 0, POS(1), renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1), POS(1) + 24 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(1) + 24 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8), POS(1) + 24 * 1, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(1) + 24 * 2, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8), POS(1) + 24 * 2, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1), POS(1) + 24 * 3, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(1) + 24 * 3, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8), POS(1) + 24 * 3, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 0, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 1, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 2, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 3, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 4, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 0, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 1, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 2, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 3, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 4, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 5, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 0, POS(4), renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1), POS(4) + 22 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(4) + 22 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(6), POS(4) + 22 * 1, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1), POS(4) + 22 * 2, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(4) + 22 * 2, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(6), POS(4) + 22 * 2, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 0, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 1, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 2, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 3, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 4, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 0, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 3, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 4, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 5, POS(6), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 0, POS(6), renderer)->entity;

    for(int i = 1; i <= 11; i++)
    {
        returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(6) + 21 * i, renderer)->entity;
    }

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 0, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 1, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 2, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 3, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 4, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 0, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 1, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 2, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 3, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 4, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 5, POS(14), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 0, POS(14), renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1), POS(14) + 20 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(14) + 21 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8), POS(14) + 21 * 1, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1), POS(14) + 20 * 2, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(14) + 21 * 2, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8), POS(14) + 21 * 2, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 22 * 1, POS(16), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 2, POS(16), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 0, POS(16), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 1, POS(16), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 2, POS(16), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 3, POS(16), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 4, POS(16), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 5, POS(16), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 0, POS(16), renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(2), POS(16) + 21 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(16) + 21 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(6), POS(16) + 21 * 1, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(2), POS(16) + 21 * 2, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4), POS(16) + 21 * 2, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(6), POS(16) + 21 * 2, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 0, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 1, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 2, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 3, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 4, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 0, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 3, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 4, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 5, POS(18), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 0, POS(18), renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1), POS(18) + 21 * 1, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8), POS(18) + 21 * 1, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1), POS(18) + 21 * 2, renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8), POS(18) + 21 * 2, renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 0, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 1, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 2, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 3, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(1) + 19 * 4, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 0, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 1, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 2, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 3, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 4, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(4) + 21 * 5, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 0, POS(20), renderer)->entity;

    int indexOfCopy = *smallCoinCount;
    for(int i = 0; i < indexOfCopy; i++)
    {
        int newX = 9*SPRITE_SIZE_SOURCE + (9*SPRITE_SIZE_SOURCE - returnCoins[i]->posX);
        int newY = returnCoins[i]->posY;

        returnCoins[indexOfCopy + i] = createSmallCoin(newX, newY, renderer)->entity;

        (*smallCoinCount)++;
    }

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 1, POS(4), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 2, POS(4), renderer)->entity;

    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 1, POS(20), renderer)->entity;
    returnCoins[(*smallCoinCount)++] = createSmallCoin(POS(8) + 21 * 2, POS(20), renderer)->entity;


    SDL_Log("small dots: %d", *smallCoinCount);

    return returnCoins;
}