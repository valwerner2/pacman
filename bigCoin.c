//
// Created by valwe on 24/02/2024.
//
#include "bigCoin.h"
entityTextures *createBigCoinTexture(SDL_Renderer *renderer)
{
    char *path = "../sprites/sheetBigCoin.png";

    SDL_Rect rectIdle[] = { {POS(0), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(1), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(2), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(3), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(4), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(5), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(6), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};

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
bigCoin *createBigCoin(int startX, int startY, SDL_Renderer *renderer)
{
    bigCoin *bigC = malloc(sizeof(bigCoin));
    bigC->entity = malloc(sizeof(entity));

    time_t initTime;
    time(&initTime);


    bigC->entity->textures = createBigCoinTexture(renderer);
    bigC->entity->state = ENTITY_IDLE;
    bigC->entity->direction = NONE;
    bigC->entity->posX = startX;
    bigC->entity->posY = startY;
    bigC->entity->hitBox.x = startX;
    bigC->entity->hitBox.y = startY;
    bigC->entity->hitBox.w = SPRITE_SIZE_SOURCE;
    bigC->entity->hitBox.h = SPRITE_SIZE_SOURCE;
    bigC->entity->lastActive = initTime;
    bigC->entity->pathFindingCollision = 0;
    bigC->entity->visible = 1;

    bigC->entity->textures->flip = SDL_FLIP_NONE;
    bigC->entity->textures->center = NULL;
    bigC->entity->textures->angle = 0.;

    return bigC;
}
void freeBigCoin(bigCoin* bigCoin)
{
    entityDeleteTextures(bigCoin->entity->textures);
    free(bigCoin->entity);
    free(bigCoin);
}
