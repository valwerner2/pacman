//
// Created by valwe on 27/02/2024.
//
#include "wall.h"

entityTextures *createWallTexture(SDL_Renderer *renderer)
{
    char *path = "../sprites/sheetWall.png";

    SDL_Rect rectIdle[44];
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 6; y++)
        {
            if(y == 5 && x > 3){break;}
            SDL_Rect temp = {POS(x), POS(y), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE};
            rectIdle[y*8 + x] = temp;
        }
    }

    int animationInformation[18] = {0};
    animationInformation[ANI_IDLE_COUNT] = 44;
    animationInformation[ANI_IDLE_CURR] = rand() % (animationInformation[ANI_IDLE_COUNT] - 1);


    return entityCreateTextures(path, renderer,
                                animationInformation,
                                80000,
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
wall *createWall(int startX, int startY, SDL_Renderer *renderer)
{
    wall *w = malloc(sizeof(wall));
    w->entity = malloc(sizeof(entity));

    time_t initTime;
    time(&initTime);

    w->entity->textures = createWallTexture(renderer);
    w->entity->state = ENTITY_IDLE;
    w->entity->direction = NONE;
    w->entity->posX = startX;
    w->entity->posY = startY;
    w->entity->hitBox.x = startX;
    w->entity->hitBox.y = startY;
    w->entity->hitBox.w = SPRITE_SIZE_SOURCE;
    w->entity->hitBox.h = SPRITE_SIZE_SOURCE;
    w->entity->lastActive = initTime;
    w->entity->pathFindingCollision = 1;

    return w;
}
void freeWall(wall* wall)
{
    entityDeleteTextures(wall->entity->textures);
    free(wall->entity);
    free(wall);
}