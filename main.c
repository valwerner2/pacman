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
#include "wall.h"
#include "maze.h"

#define WINDOW_HIGHT 1080
#define WINDOW_HEIGHT 720

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
                              30,
                              WINDOW_HIGHT,
                              WINDOW_HEIGHT,
                              0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    eventHandler_arguments eventHandlerArguments;
    eventHandlerArguments.controller[0] = controller_find();

    pacman *pacman = createPacman(POS(9), POS(16), renderer);

    ghost *ghostRed = createGhost(POS(9), POS(8), GHOST_TYPE_RED, renderer);
    ghost *ghostPurple = createGhost(POS(9), POS(10), GHOST_TYPE_PURPLE, renderer);
    ghost *ghostOrange = createGhost(POS(8), POS(10), GHOST_TYPE_ORANGEN, renderer);
    ghost *ghostCyan = createGhost(POS(10), POS(10), GHOST_TYPE_CYAN, renderer);



    bigCoin *bigCoin1 = createBigCoin(64, 128, renderer);
    bigCoin *bigCoin2 = createBigCoin(128, 128, renderer);
    bigCoin *bigCoin3 = createBigCoin(64, 192, renderer);
    bigCoin *bigCoin4 = createBigCoin(128, 192, renderer);

    smallCoin *smallCoin1 = createSmallCoin(128 + 64, 128, renderer);
    smallCoin *smallCoin2 = createSmallCoin(128 + 128, 128, renderer);
    smallCoin *smallCoin3 = createSmallCoin(128 + 64, 192, renderer);
    smallCoin *smallCoin4 = createSmallCoin(128 + 128, 192, renderer);


    eventHandlerArguments.player1 = pacman->entity;

    ghost *ghosts[] = {ghostRed,
                                ghostPurple,
                                ghostOrange,
                                ghostCyan};

    entity *ghostsEntities[] = {ghostRed->entity,
                                ghostPurple->entity,
                                ghostOrange->entity,
                                ghostCyan->entity};
    entity *bigCoins[] = {  bigCoin1->entity,
                            bigCoin2->entity,
                            bigCoin3->entity,
                            bigCoin4->entity};
    entity *smallCoins[] = {smallCoin1->entity,
                            smallCoin2->entity,
                            smallCoin3->entity,
                            smallCoin4->entity};
    unsigned long long wallAmount = 0;
    entity **walls = createMaze(renderer, &wallAmount);

    eventHandlerArguments.collisionEntities = walls;
    eventHandlerArguments.collisionEntitiesCount = wallAmount;
    eventHandlerArguments.ghosts = ghosts;

    pathFindingMap_Grid **pathGrid = createPathFindingMap_Grid(renderer, 32, walls, wallAmount);
    unsigned long long gridEntityCount = 0;
    entity **gridEntities = pathFindingMapGridToEntities(pathGrid, renderer, 32, &gridEntityCount);

    entity *teleportable[] = {ghostRed->entity,
                              ghostPurple->entity,
                              ghostOrange->entity,
                              ghostCyan->entity,
                              pacman->entity};
    SDL_Rect teleportLeft = {POS(0), POS(10), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE};
    SDL_Rect teleportRight = {POS(18), POS(10), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE};

    layer layers[] = {{0, walls, wallAmount},
                      {1, &pacman->entity, 1},
                      {2, ghostsEntities, 4}};

    char running = 1;
    while(running)
    {
        detectCollisionEntitiesTeleportBidirectional(teleportable, 5, &teleportLeft, &teleportRight, RIGHT, LEFT);
        eventHandler_handler(&eventHandlerArguments);
        updateGhosts(&eventHandlerArguments);
        //SDL_Log("%u\n", detectCollisionRect(&pacman->entity->hitBox, &ghostRed->entity->hitBox));
        drawScreen(renderer, 3, layers);
        //SDL_Delay(100);
    }
}
