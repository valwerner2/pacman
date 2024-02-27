//
// Created by valwe on 18/02/2024.
//
#ifndef PACMAN_EVENTHANDLER_H
#define PACMAN_EVENTHANDLER_H

#include "entity.h"
#include "collisionDetection.h"

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    entity *player1;
    entity *player2;

    entity **collisionEntities;
    unsigned long long collisionEntitiesCount;

    SDL_GameController *controller[2];
    int controllerAmount;
}eventHandler_arguments;

int eventHandler_handler(eventHandler_arguments* args);

#endif //PACMAN_EVENTHANDLER_H
