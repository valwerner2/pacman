//
// Created by valwe on 24/02/2024.
//
#include "ghost.h"

entityTextures *createGhostTexture(SDL_Renderer *renderer)
{
    char *path = "../sprites/sheetGhost.png";

    SDL_Rect rectIdle = {0, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE};
    SDL_Rect rectUp[] = {{POS(2), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                         {POS(3), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                         {POS(4), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                         {POS(5), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectDown[] = {{POS(7), 0,      SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(0), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(1), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(2), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectLeft[] = {{POS(1), POS(2), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(2), POS(2), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(3), POS(2), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(4), POS(2), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectRight[] = {{POS(4), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(5), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(6), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(7), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    int animationInformation[18] = {0};
    animationInformation[ANI_IDLE_COUNT] = 1;
    animationInformation[ANI_UP_COUNT] = 4;
    animationInformation[ANI_DOWN_COUNT] = 4;
    animationInformation[ANI_LEFT_COUNT] = 4;
    animationInformation[ANI_RIGHT_COUNT] = 4;

    animationInformation[ANI_IDLE_UP_COUNT]     = 1;
    animationInformation[ANI_IDLE_DOWN_COUNT]   = 1;
    animationInformation[ANI_IDLE_LEFT_COUNT]   = 1;
    animationInformation[ANI_IDLE_RIGHT_COUNT]  = 1;

    return entityCreateTextures(path, renderer,
                                animationInformation,
                                100000,
                                &rectIdle,
                                rectUp,
                                rectDown,
                                rectLeft,
                                rectRight,
                                rectUp,
                                rectDown,
                                rectLeft,
                                rectRight);
}
ghost *createGhost(int startX, int startY, unsigned char r, unsigned char g, unsigned char b, SDL_Renderer *renderer)
{
    ghost *gh = malloc(sizeof(ghost));
    gh->entity = malloc(sizeof(entity));

    time_t initTime;
    time(&initTime);

    gh->entity->textures = createGhostTexture(renderer);
    gh->entity->state = ENTITY_IDLE;
    gh->entity->direction = NONE;
    gh->entity->posX = startX;
    gh->entity->posY = startY;
    gh->entity->hitBox.x = startX + 5;
    gh->entity->hitBox.y = startY + 2;
    gh->entity->hitBox.w = SPRITE_SIZE_SOURCE - 5 * 2;
    gh->entity->hitBox.h = SPRITE_SIZE_SOURCE - 2 * 2 - 1;
    gh->entity->lastActive = initTime;
    gh->entity->pathFindingCollision = 1;


    SDL_SetTextureColorMod(gh->entity->textures->texture, r, g, b);
    return gh;
}
void freeGhost(ghost* ghost)
{
    entityDeleteTextures(ghost->entity->textures);
    free(ghost->entity);
    free(ghost);
}