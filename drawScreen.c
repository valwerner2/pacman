//
// Created by valwe on 22/02/2024.
//
#include "drawScreen.h"
void drawScreen(SDL_Renderer *renderer, unsigned int layerCount, ...)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    va_list varList;
    va_start(varList, layerCount);
    for(int layer = 0; layer < layerCount; layer++)
    {
        entity **currEntities = va_arg(varList, entity**);
        unsigned long long entityCount = va_arg(varList, unsigned long long);
        SDL_Rect temp[entityCount];
        for (int currentEntity = 0; currentEntity < entityCount; currentEntity++)
        {
            entity *currEntity = currEntities[currentEntity];
            updateTextureEntity(currEntity);
            temp[currentEntity].w = SPRITE_SIZE_RENDER;
            temp[currentEntity].h = SPRITE_SIZE_RENDER;
            temp[currentEntity].x = currEntity->posX * SPRITE_SIZE_RENDER / SPRITE_SIZE_SOURCE;
            temp[currentEntity].y = currEntity->posY * SPRITE_SIZE_RENDER / SPRITE_SIZE_SOURCE;
            SDL_RenderCopy(renderer, currEntity->textures->texture, &currEntity->textures->sourceCurrent,
                           &temp[currentEntity]);
        }
    }
    SDL_RenderPresent(renderer);
    va_end(varList);
}