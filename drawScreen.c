//
// Created by valwe on 22/02/2024.
//
#include "drawScreen.h"
void drawScreen(drawScreen_arguments *args)
{
    SDL_SetRenderDrawColor(args->renderer, 0, 0, 255, 255);
    SDL_RenderClear(args->renderer);

    SDL_Rect temp[args->entityCount];
    for(int i = 0; i < args->entityCount; i++)
    {
        updateTextureEntity(&args->entities[i]);
        temp[i].w = 32;
        temp[i].h = 32;
        temp[i].x = args->entities[i].posX;
        temp[i].y = args->entities[i].posY;
        SDL_RenderCopy(args->renderer, args->entities[i].textures->texture, &args->entities[i].textures->sourceCurrent, &temp);
    }

    SDL_RenderPresent(args->renderer);
}