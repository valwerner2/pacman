#include <SDL.h>
#include "eventHandler.h"
#include "controller.h"

#define WINDOW_HIGHT 640
#define WINDOW_HEIGHT 480

int main(int argumentCount, char* arguments[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
    {
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
    }

    window = SDL_CreateWindow("Game Window",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_HIGHT,
                              WINDOW_HEIGHT,
                              0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    eventHandler_arguments_t eventHandlerArguments;

    eventHandlerArguments.controller[0] = controller_find();

    SDL_Rect rectangle = {0, 0, 200, 200};
    eventHandlerArguments.player1 = rectangle;
    eventHandlerArguments.player2 = rectangle;

    char running = 1;
    while(running)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
        SDL_RenderFillRect(renderer, &eventHandlerArguments.player1);

        SDL_RenderPresent(renderer);

        eventHandler_handler(&eventHandlerArguments);
    }
    return 0;
}
