#include "eventHandler.h"
#include "controller.h"
#include "entity.h"
#include "pacman.h"
#include "drawScreen.h"
#include "collisionDetection.h"
#include "ghost.h"
#include "common.h"
#include "bigCoin.h"
#include "smallCoin.h"
#include "pathFinding.h"

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

    ghost *ghost1 = createGhost(64, 128, 255, 255, 255, renderer);
    ghost *ghost2 = createGhost(96, 128, 150, 255, 255, renderer);
    ghost *ghost3 = createGhost(128, 128, 255, 150, 100, renderer);
    ghost *ghost4 = createGhost(160, 128, 255, 255, 150, renderer);
    ghost *ghost5 = createGhost(256, 128, 50, 50, 255, renderer);

    bigCoin *bigCoin1 = createBigCoin(64, 128, renderer);
    bigCoin *bigCoin2 = createBigCoin(128, 128, renderer);
    bigCoin *bigCoin3 = createBigCoin(64, 192, renderer);
    bigCoin *bigCoin4 = createBigCoin(128, 192, renderer);

    smallCoin *smallCoin1 = createSmallCoin(128 + 64, 128, renderer);
    smallCoin *smallCoin2 = createSmallCoin(128 + 128, 128, renderer);
    smallCoin *smallCoin3 = createSmallCoin(128 + 64, 192, renderer);
    smallCoin *smallCoin4 = createSmallCoin(128 + 128, 192, renderer);

    eventHandlerArguments.player1 = pacman->entity;


    entity *ghosts[] = {    ghost1->entity,
                            ghost2->entity,
                            ghost3->entity,
                            ghost4->entity,
                            ghost5->entity};
    entity *bigCoins[] = {  bigCoin1->entity,
                            bigCoin2->entity,
                            bigCoin3->entity,
                            bigCoin4->entity};
    entity *smallCoins[] = {smallCoin1->entity,
                            smallCoin2->entity,
                            smallCoin3->entity,
                            smallCoin4->entity};




    pathFindingMap_Grid **pathGrid = createPathFindingMap_Grid(renderer, 32, ghosts, 5);
    unsigned long long gridEntityCount = 0;
    entity **gridEntities = pathFindingMapGridToEntities(pathGrid, renderer, 32, &gridEntityCount);
    char running = 1;
    while(running)
    {
        eventHandler_handler(&eventHandlerArguments);
        //SDL_Log("%u\n", detectCollision(&pacman->entity->hitBox, &ghost1->entity->hitBox));
        drawScreen(renderer, 3, gridEntities, gridEntityCount , &pacman->entity, 1ll, ghosts, 5ll, bigCoins, 4ll, smallCoins, 4ll);
        //SDL_Delay(100);
    }
}
