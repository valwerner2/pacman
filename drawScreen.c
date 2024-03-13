//
// Created by valwe on 22/02/2024.
//
#include "drawScreen.h"
void drawScreen(SDL_Renderer *renderer, unsigned int layerCount, layer *layers)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    qsort(layers, layerCount, sizeof(layer), compareLayers);

    for(int currentLayer = 0; currentLayer < layerCount; currentLayer++)
    {
        SDL_Rect temp[layers[currentLayer].entityCount];
        for (int currentEntity = 0; currentEntity < layers[currentLayer].entityCount; currentEntity++)
        {
            entity *currEntity = layers[currentLayer].entities[currentEntity];
            updateTextureEntity(currEntity);
            temp[currentEntity].w = SPRITE_SIZE_RENDER;
            temp[currentEntity].h = SPRITE_SIZE_RENDER;
            temp[currentEntity].x = currEntity->posX * SPRITE_SIZE_RENDER / SPRITE_SIZE_SOURCE;
            temp[currentEntity].y = currEntity->posY * SPRITE_SIZE_RENDER / SPRITE_SIZE_SOURCE;
            SDL_RenderCopyEx(renderer, currEntity->textures->texture, &currEntity->textures->sourceCurrent,
                           &temp[currentEntity], currEntity->textures->angle, currEntity->textures->center, currEntity->textures->flip);
        }
    }
    SDL_RenderPresent(renderer);
}
int compareLayers(const void *a, const void *b)
{
    signed long long z1 = ((layer*)a)->z;
    signed long long z2 = ((layer*)b)->z;

    if(z1 < z2){return -1;}
    else if (z1 == z2){return 0;}
    return 1;
}