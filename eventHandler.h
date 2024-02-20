//
// Created by valwe on 18/02/2024.
//
#include <SDL.h>

#ifndef PACMAN_EVENTHANDLER_H
#define PACMAN_EVENTHANDLER_H

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_Rect player1;
    SDL_Rect player2;

    SDL_GameController *controller[2];
    int controllerAmount;
}eventHandler_arguments_t;

int eventHandler_handler(eventHandler_arguments_t* arguments);

#endif //PACMAN_EVENTHANDLER_H
