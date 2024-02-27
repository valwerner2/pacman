//
// Created by valwe on 25/02/2024.
//
#include "pathFinding.h"
#include "bigCoin.h"
#include "smallCoin.h"

pathFindingMap_Grid **createPathFindingMap_Grid(SDL_Renderer *renderer,
                                               unsigned int fieldSize,
                                               entity **entities,
                                               unsigned int entityCount)
{
    unsigned int renderWight = 0;
    unsigned int renderHeight = 0;
    SDL_GetRendererOutputSize(renderer, &renderWight, &renderHeight);

    unsigned int sizeGridX = renderWight / fieldSize;
    unsigned int sizeGridY = renderHeight / fieldSize;

    pathFindingMap_Grid **grid = calloc(sizeGridX, sizeof(pathFindingMap_Grid*));;
    for(int i = 0; i < sizeGridX; i++)
    {
        grid[i] = calloc(sizeGridY, sizeof(pathFindingMap_Grid));
    }
    for(int y = 0; y < sizeGridY; y++)
    {
        for(int x = 0; x < sizeGridX; x++)
        {
            grid[x][y].topFree = 0;
            grid[x][y].bottomFree = 0;
            grid[x][y].leftFree = 0;
            grid[x][y].rightFree = 0;
            if((y - 1) >= 0)        {grid[x][y].topFree = 1;}
            if((y + 1) < sizeGridY) {grid[x][y].bottomFree = 1;}
            if((x - 1) >= 0)        {grid[x][y].leftFree = 1;}
            if((x + 1) < sizeGridX) {grid[x][y].rightFree = 1;}
        }
    }
    for(int y = 0; y < sizeGridY; y++)
    {
        for(int x = 0; x < sizeGridX; x++)
        {
            //no need to check fields you can not go to
            if(grid[x][y].topFree || grid[x][y].bottomFree || grid[x][y].leftFree || grid[x][y].rightFree)
            {
                for (int e = 0; e < entityCount; e++)
                {
                    //collision condition
                    if(entities[e]->pathFindingCollision)
                    {
                        SDL_Rect temp = {x * fieldSize, y * fieldSize, fieldSize, fieldSize};
                        if (detectCollisionRect(&entities[e]->hitBox, &temp))
                        {
                            SDL_Log("HERE");
                            if (grid[x][y].topFree)     { grid[x][y - 1].bottomFree = 0; }
                            if (grid[x][y].bottomFree)  { grid[x][y + 1].topFree = 0; }
                            if (grid[x][y].leftFree)    { grid[x - 1][y].rightFree = 0; }
                            if (grid[x][y].rightFree)   { grid[x + 1][y].leftFree = 0; }
                            grid[x][y].topFree = 0;
                            grid[x][y].bottomFree = 0;
                            grid[x][y].leftFree = 0;
                            grid[x][y].rightFree = 0;
                        }
                    }
                }
            }
        }
    }
    return grid;
}
entity **pathFindingMapGridToEntities(pathFindingMap_Grid **grid,
                                      SDL_Renderer *renderer,
                                      unsigned int fieldSize,
                                      unsigned long long *entityCount)
{
    unsigned int renderWight = 0;
    unsigned int renderHeight = 0;
    SDL_GetRendererOutputSize(renderer, &renderWight, &renderHeight);

    unsigned int sizeGridX = renderWight / fieldSize;
    unsigned int sizeGridY = renderHeight / fieldSize;

    *entityCount = sizeGridX*sizeGridY;

    entity **entities = malloc(sizeof(entity*)*(*entityCount));

    for(int y = 0; y < sizeGridY; y++)
    {
        for(int x = 0; x < sizeGridX; x++)
        {
            if(!grid[x][y].topFree || !grid[x][y].bottomFree || !grid[x][y].leftFree || !grid[x][y].rightFree)
            {
                entities[y*sizeGridX + x] = createBigCoin(x*fieldSize, y*fieldSize, renderer)->entity;
            }
            else
            {
                entities[y*sizeGridX + x] = createSmallCoin(x*fieldSize, y*fieldSize, renderer)->entity;
            }
        }
    }
    return entities;
}