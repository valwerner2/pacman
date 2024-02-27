//
// Created by valwe on 27/02/2024.
//
#include "maze.h"

#define WALL_COUNT 500
entity **createMaze(SDL_Renderer *renderer, unsigned long long *amountWalls)
{
    entity **maze = malloc(sizeof(entity*)*WALL_COUNT);
    wall *walls[WALL_COUNT];
    unsigned long long currentAmountWalls = 0;
    *amountWalls = 0;

    for(int i = 0; i < 10; i++)
    {
        walls[i] = createWall(POS(i), POS(0), renderer);
        (*amountWalls)++;
        walls[i + 10] = createWall(POS(i), POS(21), renderer);
        (*amountWalls)++;
    }
    currentAmountWalls = *amountWalls;
    for(int i = 0; i < 6; i++)
    {
        walls[currentAmountWalls + i] = createWall(POS(0), POS(1 + i), renderer);
        (*amountWalls)++;
        walls[currentAmountWalls + i + 6] = createWall(POS(0), POS(19 - i), renderer);
        (*amountWalls)++;
    }
    currentAmountWalls = *amountWalls;
    for(int i = 0; i < 4; i++)
    {
        walls[currentAmountWalls + i] = createWall(POS(i), POS(7), renderer);
        (*amountWalls)++;
        walls[currentAmountWalls + i + 4] = createWall(POS(i), POS(9), renderer);
        (*amountWalls)++;
        walls[currentAmountWalls + i + 8] = createWall(POS(i), POS(11), renderer);
        (*amountWalls)++;
        walls[currentAmountWalls + i + 12] = createWall(POS(i), POS(13), renderer);
        (*amountWalls)++;
    }
    walls[(*amountWalls)++] = createWall(POS(3), POS(8), renderer);
    walls[(*amountWalls)++] = createWall(POS(3), POS(12), renderer);

    walls[(*amountWalls)++] = createWall(POS(9), POS(1), renderer);
    walls[(*amountWalls)++] = createWall(POS(2), POS(2), renderer);
    walls[(*amountWalls)++] = createWall(POS(3), POS(2), renderer);
    walls[(*amountWalls)++] = createWall(POS(5), POS(2), renderer);
    walls[(*amountWalls)++] = createWall(POS(6), POS(2), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(2), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(2), renderer);

    walls[(*amountWalls)++] = createWall(POS(2), POS(3), renderer);
    walls[(*amountWalls)++] = createWall(POS(3), POS(3), renderer);
    walls[(*amountWalls)++] = createWall(POS(5), POS(3), renderer);
    walls[(*amountWalls)++] = createWall(POS(6), POS(3), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(3), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(3), renderer);

    walls[(*amountWalls)++] = createWall(POS(2), POS(5), renderer);
    walls[(*amountWalls)++] = createWall(POS(3), POS(5), renderer);
    walls[(*amountWalls)++] = createWall(POS(5), POS(5), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(5), renderer);
    walls[(*amountWalls)++] = createWall(POS(8), POS(5), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(5), renderer);

    walls[(*amountWalls)++] = createWall(POS(5), POS(6), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(6), renderer);

    walls[(*amountWalls)++] = createWall(POS(5), POS(7), renderer);
    walls[(*amountWalls)++] = createWall(POS(6), POS(7), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(7), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(7), renderer);

    walls[(*amountWalls)++] = createWall(POS(5), POS(8), renderer);

    walls[(*amountWalls)++] = createWall(POS(5), POS(9), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(9), renderer);
    walls[(*amountWalls)++] = createWall(POS(8), POS(9), renderer);

    walls[(*amountWalls)++] = createWall(POS(7), POS(10), renderer);

    walls[(*amountWalls)++] = createWall(POS(5), POS(11), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(11), renderer);
    walls[(*amountWalls)++] = createWall(POS(8), POS(11), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(11), renderer);

    walls[(*amountWalls)++] = createWall(POS(5), POS(12), renderer);

    walls[(*amountWalls)++] = createWall(POS(5), POS(13), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(13), renderer);
    walls[(*amountWalls)++] = createWall(POS(8), POS(13), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(13), renderer);

    walls[(*amountWalls)++] = createWall(POS(9), POS(14), renderer);

    walls[(*amountWalls)++] = createWall(POS(2), POS(15), renderer);
    walls[(*amountWalls)++] = createWall(POS(3), POS(15), renderer);
    walls[(*amountWalls)++] = createWall(POS(5), POS(15), renderer);
    walls[(*amountWalls)++] = createWall(POS(6), POS(15), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(15), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(15), renderer);

    walls[(*amountWalls)++] = createWall(POS(3), POS(16), renderer);

    walls[(*amountWalls)++] = createWall(POS(1), POS(17), renderer);
    walls[(*amountWalls)++] = createWall(POS(3), POS(17), renderer);
    walls[(*amountWalls)++] = createWall(POS(5), POS(17), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(17), renderer);
    walls[(*amountWalls)++] = createWall(POS(8), POS(17), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(17), renderer);

    walls[(*amountWalls)++] = createWall(POS(5), POS(18), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(18), renderer);

    walls[(*amountWalls)++] = createWall(POS(2), POS(19), renderer);
    walls[(*amountWalls)++] = createWall(POS(3), POS(19), renderer);
    walls[(*amountWalls)++] = createWall(POS(4), POS(19), renderer);
    walls[(*amountWalls)++] = createWall(POS(5), POS(19), renderer);
    walls[(*amountWalls)++] = createWall(POS(6), POS(19), renderer);
    walls[(*amountWalls)++] = createWall(POS(7), POS(19), renderer);
    walls[(*amountWalls)++] = createWall(POS(9), POS(19), renderer);

    walls[(*amountWalls)++] = createWall(POS(0), POS(20), renderer);

    currentAmountWalls = *amountWalls;
    for(int i = 0; i < currentAmountWalls; i++)
    {
        int newX = 9 + (9 - (walls[i]->entity->posX)/SPRITE_SIZE_SOURCE);
        int newY = walls[i]->entity->posY;
        walls[currentAmountWalls + i] = createWall(POS(newX), newY, renderer);
        (*amountWalls)++;
    }

    for(int i = 0; i < (*amountWalls); i++)
    {
        maze[i] = walls[i]->entity;
    }
    return maze;
}