//
// Created by valwe on 21/02/2024.
//
#ifndef PACMAN_PLAYER_H
#define PACMAN_PLAYER_H

#define MOVE_AMOUNT 8

#include "common.h"

typedef struct
{
    SDL_Texture *texture;
    SDL_Rect *sourceIdle;
    SDL_Rect *sourceUp;
    SDL_Rect *sourceDown;
    SDL_Rect *sourceLeft;
    SDL_Rect *sourceRight;

    SDL_Rect *sourceIdleUp;
    SDL_Rect *sourceIdleDown;
    SDL_Rect *sourceIdleLeft;
    SDL_Rect *sourceIdleRight;

    SDL_Rect sourceCurrent;

    int animationInformation[18];

    double angle;
    SDL_Point *center;
    SDL_RendererFlip flip;
    struct timeval *lastAnimation;
    unsigned long long microsecondsAnimationTime;

}entityTextures;

enum animationInfo
{
    ANI_IDLE_COUNT,
    ANI_IDLE_CURR,
    ANI_UP_COUNT,
    ANI_UP_CURR,
    ANI_DOWN_COUNT,
    ANI_DOWN_CURR,
    ANI_LEFT_COUNT,
    ANI_LEFT_CURR,
    ANI_RIGHT_COUNT,
    ANI_RIGHT_CURR,

    ANI_IDLE_UP_COUNT,
    ANI_IDLE_UP_CURR,
    ANI_IDLE_DOWN_COUNT,
    ANI_IDLE_DOWN_CURR,
    ANI_IDLE_LEFT_COUNT,
    ANI_IDLE_LEFT_CURR,
    ANI_IDLE_RIGHT_COUNT,
    ANI_IDLE_RIGHT_CURR
};

typedef struct
{
    entityTextures* textures;
    int state;
    int direction;
    int posX, posY;
    SDL_Rect hitBox;


    char pathFindingCollision;
    time_t lastActive;
}entity;

enum entityState
{ ENTITY_IDLE, ENTITY_MOVING };

enum entityDirection
{ UP, DOWN, LEFT, RIGHT, NONE};


void updateEntity(entity *entity, int direction);
void updateEntitySet(entity *entity, int x, int y,int direction);
void updateTextureEntity(entity *entity);
entityTextures *entityCreateTextures(char* path, SDL_Renderer *renderer,
                                     int *animationInformation,
                                     unsigned long long animationSpeed,
                                     SDL_Rect *rectIdle,
                                     SDL_Rect *rectUp,
                                     SDL_Rect *rectDown,
                                     SDL_Rect *rectLeft,
                                     SDL_Rect *rectRight,
                                     SDL_Rect *rectIdleUp,
                                     SDL_Rect *rectIdleDown,
                                     SDL_Rect *rectIdleLeft,
                                     SDL_Rect *rectIdleRight);

void entityDeleteTextures(entityTextures* entityTextures);
unsigned long long getDistanceEntity(entity *e1, entity *e2);
#endif //PACMAN_PLAYER_H
