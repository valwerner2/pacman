//
// Created by valwe on 18/02/2024.
//
#ifndef PACMAN_EVENTHANDLER_H
#define PACMAN_EVENTHANDLER_H

#include "ghost.h"
#include "collisionDetection.h"
#include "controller.h"
#include "pacman.h"

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    pacman *pac;

    entity **collisionEntities;
    unsigned long long collisionEntitiesCount;

    entity **bigCoins;
    int bigCoinCount;

    entity **smallCoins;
    int smallCoinCount;

    ghost **ghosts;

    SDL_GameController *controller[2];
    int controllerAmount;

    int level;
    struct timeval levelStartTime;
    int dotsLeft;
    struct timeval frightenedStartTime;
    unsigned int points;
    unsigned int ghostEatenMultiplier;
}eventHandler_arguments;

void coinCollection(eventHandler_arguments *args);
int eventHandler_handler(eventHandler_arguments* args);
void updateGhosts(eventHandler_arguments *args);

#endif //PACMAN_EVENTHANDLER_H
