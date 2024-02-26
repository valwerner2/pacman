//
// Created by valwe on 24/02/2024.
//
#include "smallCoin.h"

#define POS(x) x*SPRITE_SIZE_SOURCE

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
    smallC->entity->hitBox.w = SPRITE_SIZE_SOURCE - 2 * 20;
    smallC->entity->hitBox.h = SPRITE_SIZE_SOURCE - 2 * 20;
    smallC->entity->lastActive = initTime;
    smallC->entity->pathFindingCollision = 0;


    return smallC;
}
void freeSmallCoin(smallCoin* smallCoin)
{
    entityDeleteTextures(smallCoin->entity->textures);
    free(smallCoin->entity);
    free(smallCoin);
}