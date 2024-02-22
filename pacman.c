//
// Created by valwe on 21/02/2024.
//
#include "pacman.h"

void createPacmanTexture(entityTextures* pacman, SDL_Renderer *renderer)
{
    SDL_Surface *surfaceSpriteSheet;

    surfaceSpriteSheet = IMG_Load("../sprites/spriteSheet.png");
    if(surfaceSpriteSheet == NULL){SDL_Log("Error getting spriteSheet\n"); SDL_Quit();}
    SDL_Texture *textureSpriteSheet = SDL_CreateTextureFromSurface(renderer, surfaceSpriteSheet);
    if(textureSpriteSheet == NULL){ SDL_Log("Error making textures");}
    SDL_FreeSurface(surfaceSpriteSheet);

    pacman->texture = textureSpriteSheet;
    SDL_Rect rectIdle = {0, 0, 32, 32};
    SDL_Rect rectUP[] = {{32, 0, 32, 32}, {64, 0, 32, 32}};
    SDL_Rect rectDown[] = {{96, 0, 32, 32}, {128, 0, 32, 32}};
    SDL_Rect rectLeft[] = {{192, 0, 32, 32}, {160, 0, 32, 32}};
    SDL_Rect rectRight[] = {{0, 0, 32, 32}, {224, 0, 32, 32}};

    for(int i = 0; i < 10; i++)
    {
        pacman->animationInformation[i] = 0;
    }

    pacman->animationInformation[ANI_IDLE_COUNT] = 1;
    pacman->animationInformation[ANI_UP_COUNT] = 2;
    pacman->animationInformation[ANI_DOWN_COUNT] = 2;
    pacman->animationInformation[ANI_LEFT_COUNT] = 2;
    pacman->animationInformation[ANI_RIGHT_COUNT] = 2;


    pacman->sourceIDLE = malloc(pacman->animationInformation[ANI_IDLE_COUNT]* sizeof(SDL_Rect));
    pacman->sourceUP = malloc(pacman->animationInformation[ANI_UP_COUNT]* sizeof(SDL_Rect));
    pacman->sourceDOWN = malloc(pacman->animationInformation[ANI_DOWN_COUNT]* sizeof(SDL_Rect));
    pacman->sourceLEFT = malloc(pacman->animationInformation[ANI_LEFT_COUNT]* sizeof(SDL_Rect));
    pacman->sourceRIGHT = malloc(pacman->animationInformation[ANI_RIGHT_COUNT]* sizeof(SDL_Rect));

    memcpy(pacman->sourceIDLE, &rectIdle, pacman->animationInformation[ANI_IDLE_COUNT]* sizeof(SDL_Rect));
    memcpy(pacman->sourceUP, rectUP, pacman->animationInformation[ANI_UP_COUNT]* sizeof(SDL_Rect));
    memcpy(pacman->sourceDOWN, rectDown, pacman->animationInformation[ANI_DOWN_COUNT]* sizeof(SDL_Rect));
    memcpy(pacman->sourceLEFT, rectLeft, pacman->animationInformation[ANI_LEFT_COUNT]* sizeof(SDL_Rect));
    memcpy(pacman->sourceRIGHT, rectRight, pacman->animationInformation[ANI_RIGHT_COUNT]* sizeof(SDL_Rect));

    pacman->sourceCurrent = *pacman->sourceIDLE;
}
void deletePacmanTexture(entityTextures* pacman)
{
    free(pacman->sourceIDLE);
    free(pacman->sourceUP);
    free(pacman->sourceDOWN);
    free(pacman->sourceLEFT);
    free(pacman->sourceRIGHT);

    SDL_DestroyTexture(pacman->texture);
}