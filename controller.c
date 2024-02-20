//
// Created by valwe on 18/02/2024.
//
#include <SDL.h>

SDL_GameController *controller_find() {
    SDL_Log("con: %d\n", SDL_NumJoysticks());
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
        if (SDL_IsGameController(i)) {
            return SDL_GameControllerOpen(i);
        }
    }
    return nullptr;
}