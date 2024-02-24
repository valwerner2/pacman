//
// Created by valwe on 22/02/2024.
//
#include "drawScreen.h"
void drawScreen(drawScreen_arguments *args)
{
    SDL_SetRenderDrawColor(args->renderer, 0, 0, 0, 255);
    SDL_RenderClear(args->renderer);

    SDL_Rect temp[args->entityCount];
    for(int i = 0; i < args->entityCount; i++)
    {
        entity *currEntity = args->entities[i];
        updateTextureEntity(currEntity);
        temp[i].w = SPRITE_SIZE;
        temp[i].h = SPRITE_SIZE;
        temp[i].x = currEntity->posX;
        temp[i].y = currEntity->posY;
        SDL_RenderCopy(args->renderer, currEntity->textures->texture, &currEntity->textures->sourceCurrent, &temp[i]);
    }
    SDL_RenderPresent(args->renderer);
}