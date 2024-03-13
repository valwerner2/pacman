//
// Created by valwe on 27/02/2024.
//
#include "wall.h"

entityTextures *createWallTexture(SDL_Renderer *renderer, int type)
{
    char *path;
    int amountSprites = 0;
    int animationSpeed = 80000;
    switch (type)
    {
        case WALL_TYPE_FRAME_CORNER:
            path = "../sprites/walls/sheetWallsSurrounding_corner.png";
            amountSprites = 8;
            break;
        case WALL_TYPE_FRAME_SIDES:
            path = "../sprites/walls/sheetWallsSurrounding_sides.png";
            amountSprites = 8;
            break;
        case WALL_TYPE_FRAME_SIDE:
            path = "../sprites/walls/sheetWallsSurrounding_side.png";
            amountSprites = 8;
            break;
        case WALL_TYPE_FRAME_3SIDES:
            path = "../sprites/walls/sheetWallsSurrounding_3sides.png";
            amountSprites = 8;
            break;
        case WALL_TYPE_FRAME_GEN:
            path = "../sprites/walls/sheetWall.png";
            amountSprites = 8;
            break;
        case WALL_TYPE_FRAME_DOOR:
            path = "../sprites/walls/sheetWallsDoor.png";
            amountSprites = 8;
            animationSpeed = 100000;
            break;

    }

    SDL_Rect rectIdle[44];
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; (y*8 + x) <= amountSprites; y++)
        {
            SDL_Rect temp = {POS(x), POS(y), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE};
            rectIdle[y*8 + x] = temp;
        }
    }

    int animationInformation[18] = {0};
    animationInformation[ANI_IDLE_COUNT] = amountSprites;
    animationInformation[ANI_IDLE_CURR] = 0;//rand() % (animationInformation[ANI_IDLE_COUNT] - 1);


    return entityCreateTextures(path, renderer,
                                animationInformation,
                                animationSpeed,
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
wall *createWall(int type, int startX, int startY, SDL_Renderer *renderer, double angle, SDL_RendererFlip flip)
{
    wall *w = malloc(sizeof(wall));
    w->entity = malloc(sizeof(entity));

    w->type = type;

    time_t initTime;
    time(&initTime);

    w->entity->textures = createWallTexture(renderer, type);
    w->entity->textures->flip = flip;
    w->entity->textures->center = NULL;
    w->entity->textures->angle = angle;

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