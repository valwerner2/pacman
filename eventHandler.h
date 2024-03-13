//
// Created by valwe on 18/02/2024.
//
#ifndef PACMAN_EVENTHANDLER_H
#define PACMAN_EVENTHANDLER_H

#include "ghost.h"
#include "collisionDetection.h"
#include "controller.h"


typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    entity *player1;

    entity **collisionEntities;
    unsigned long long collisionEntitiesCount;

    ghost **ghosts;

    SDL_GameController *controller[2];
    int controllerAmount;
}eventHandler_arguments;

int eventHandler_handler(eventHandler_arguments* args);
void updateGhosts(eventHandler_arguments *args);
#endif //PACMAN_EVENTHANDLER_H
