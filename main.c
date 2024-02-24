#include <SDL.h>
#include <SDL_image.h>
#include <time.h>

#include "eventHandler.h"
#include "controller.h"
#include "entity.h"
#include "pacman.h"
#include "drawScreen.h"
#include "collisionDetection.h"
#include "ghost.h"
#include "common.h"

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

    pacman *pacman = createPacman(0, 0, renderer);

    ghost *ghost1 = createGhost(64, 64, 255, 255, 255, renderer);
    ghost *ghost2 = createGhost(96, 64, 150, 255, 255, renderer);
    ghost *ghost3 = createGhost(128, 64, 255, 150, 100, renderer);
    ghost *ghost4 = createGhost(160, 64, 255, 255, 150, renderer);
    ghost *ghost5 = createGhost(256, 64, 50, 50, 255, renderer);

    eventHandlerArguments.player1 = ghost1->entity;


    entity *entities[] = {pacman->entity,
                          ghost1->entity,
                          ghost2->entity,
                          ghost3->entity,
                          ghost4->entity,
                          ghost5->entity};

    drawScreen_arguments drawScreenArguments = {renderer, entities, 6};

    char running = 1;
    while(running)
    {
        eventHandler_handler(&eventHandlerArguments);
        drawScreen(&drawScreenArguments);
        SDL_Log("%u\n", detectCollision(&pacman->entity->hitBox, &ghost1->entity->hitBox));
        //SDL_Delay(100);
    }
}
