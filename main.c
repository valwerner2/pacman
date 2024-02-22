#include <SDL.h>
#include <SDL_image.h>
#include <time.h>

#include "eventHandler.h"
#include "controller.h"
#include "entity.h"
#include "pacman.h"
#include "drawScreen.h"

#define WINDOW_HIGHT 640
#define WINDOW_HEIGHT 480

int main(int argumentCount, char* arguments[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
    }
    int i = 0;
    SDL_Window *window;
    SDL_Renderer *renderer;

    window = SDL_CreateWindow("Game Window",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_HIGHT,
                              WINDOW_HEIGHT,
                              0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    eventHandler_arguments eventHandlerArguments;
    eventHandlerArguments.controller[0] = controller_find();

    entityTextures pacmanTexture;
    createPacmanTexture(&pacmanTexture, renderer);
    eventHandlerArguments.player1Textures = &pacmanTexture;

    time_t initTime;
    time(&initTime);
    entity pacman = {&pacmanTexture, ENTITY_IDLE, NONE, 0, 0, initTime};
    eventHandlerArguments.player1 = &pacman;

    drawScreen_arguments drawScreenArguments = {&pacman, 1, renderer};

    char running = 1;
    while(running)
    {
        eventHandler_handler(&eventHandlerArguments);
        drawScreen(&drawScreenArguments);
        //SDL_Delay(100);
    }
}
