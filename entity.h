//
// Created by valwe on 21/02/2024.
//
#include <SDL.h>
#include <SDL_image.h>
#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H

#define MOVE_AMOUNT 1

typedef struct
{
    SDL_Texture *texture;
    SDL_Rect *sourceIDLE;
    SDL_Rect *sourceUP;
    SDL_Rect *sourceDOWN;
    SDL_Rect *sourceLEFT;
    SDL_Rect *sourceRIGHT;
    SDL_Rect sourceCurrent;

    int animationInformation[10];
}entityTextures;

enum animationInfo
{
    ANI_IDLE_COUNT,
    ANI_UP_COUNT,
    ANI_DOWN_COUNT,
    ANI_LEFT_COUNT,
    ANI_RIGHT_COUNT,

    ANI_IDLE_CURR,
    ANI_UP_CURR,
    ANI_DOWN_CURR,
    ANI_LEFT_CURR,
    ANI_RIGHT_CURR
};

typedef struct
{
    entityTextures* textures;
    int state;
    int direction;
    int posX, posY;
    SDL_Rect hitBox;

    time_t lastActive;
}entity;

enum entityState
{ ENTITY_IDLE, ENTITY_MOVING };

enum entityDirection
{ UP, DOWN, LEFT, RIGHT, NONE};


void updateEntity(entity *entity, int direction);
void updateTextureEntity(entity *entity);
entityTextures *entityCreateTextures(char* path, SDL_Renderer *renderer, int *animationInformation,
                          SDL_Rect *rectIdle,
                          SDL_Rect *rectUP,
                          SDL_Rect *rectDown,
                          SDL_Rect *rectLeft,
                          SDL_Rect *rectRight);
void entityDeleteTextures(entityTextures* entityTextures);
#endif //PACMAN_PLAYER_H
