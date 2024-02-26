//
// Created by valwe on 21/02/2024.
//
#include "pacman.h"

entityTextures *createPacmanTexture(SDL_Renderer *renderer)
{
    char *path = "../sprites/sheetPacman.png";

    SDL_Rect rectIdle = {0, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE};
    SDL_Rect rectUp[] = {{SPRITE_SIZE_SOURCE, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}, {64, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectDown[] = {{96, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}, {128, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectLeft[] = {{192, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}, {160, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectRight[] = {{0, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}, {224, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    int animationInformation[18] = {0};
    animationInformation[ANI_IDLE_COUNT]        = 1;
    animationInformation[ANI_UP_COUNT]          = 2;
    animationInformation[ANI_DOWN_COUNT]        = 2;
    animationInformation[ANI_LEFT_COUNT]        = 2;
    animationInformation[ANI_RIGHT_COUNT]       = 2;

    animationInformation[ANI_IDLE_UP_COUNT]     = 1;
    animationInformation[ANI_IDLE_DOWN_COUNT]   = 1;
    animationInformation[ANI_IDLE_LEFT_COUNT]   = 1;
    animationInformation[ANI_IDLE_RIGHT_COUNT]  = 1;

    return entityCreateTextures(path, renderer,
                                animationInformation,
                                40000,
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
pacman *createPacman(int startX, int startY, SDL_Renderer *renderer)
{
    pacman *pac = malloc(sizeof(pacman));
    pac->entity = malloc(sizeof(entity));

    time_t initTime;
    time(&initTime);

    pac->entity->textures = createPacmanTexture(renderer);
    pac->entity->state = ENTITY_IDLE;
    pac->entity->direction = NONE;
    pac->entity->posX = startX;
    pac->entity->posY = startY;
    pac->entity->hitBox.x = startX;
    pac->entity->hitBox.y = startY;
    pac->entity->hitBox.w = SPRITE_SIZE_SOURCE;
    pac->entity->hitBox.h = SPRITE_SIZE_SOURCE;
    pac->entity->lastActive = initTime;
    pac->entity->pathFindingCollision = 1;

    return pac;
}
void freePacman(pacman* pacman)
{
    entityDeleteTextures(pacman->entity->textures);
    free(pacman->entity);
    free(pacman);
}