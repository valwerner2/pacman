//
// Created by valwe on 27/02/2024.
//
#include "maze.h"

#define WALL_COUNT_TEMP 500
entity **createMaze(SDL_Renderer *renderer, unsigned long long *amountWalls)
{
    entity **maze = malloc(sizeof(entity*) * WALL_COUNT_TEMP);
    wall *walls[WALL_COUNT_TEMP];
    unsigned long long currentAmountWalls = 0;
    *amountWalls = 0;

    for(int i = 0; i < 8; i++)
    {
        walls[i] = createWall(WALL_TYPE_FRAME_SIDE, POS(i + 1), POS(0), renderer, 270., SDL_FLIP_NONE);
        (*amountWalls)++;
        walls[i + 8] = createWall(WALL_TYPE_FRAME_SIDE, POS(i + 1), POS(21), renderer, 90., SDL_FLIP_NONE);
        (*amountWalls)++;
    }
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(9), POS(21), renderer, 90., SDL_FLIP_NONE);
    currentAmountWalls = *amountWalls;
    int codeAndFixNOTokay = 0;
    for(int i = 0; i < 6; i++)
    {
        walls[currentAmountWalls + i] = createWall(WALL_TYPE_FRAME_SIDE, POS(0), POS(1 + i), renderer, 180., SDL_FLIP_NONE);
        (*amountWalls)++;
        if(i == 2){codeAndFixNOTokay = 1; continue;}
        walls[currentAmountWalls + i + 6 - codeAndFixNOTokay] = createWall(WALL_TYPE_FRAME_SIDE, POS(0), POS(19 - i), renderer, 180., SDL_FLIP_NONE);
        (*amountWalls)++;
    }
    currentAmountWalls = *amountWalls;
    for(int i = 0; i < 2; i++)
    {
        walls[currentAmountWalls + i] = createWall(WALL_TYPE_FRAME_SIDE, POS(i + 1), POS(7), renderer, 90., SDL_FLIP_NONE);
        (*amountWalls)++;
        walls[currentAmountWalls + i + 2] = createWall(WALL_TYPE_FRAME_SIDE, POS(i + 1), POS(9), renderer, 270., SDL_FLIP_NONE);
        (*amountWalls)++;
        walls[currentAmountWalls + i + 4] = createWall(WALL_TYPE_FRAME_SIDE, POS(i + 1), POS(11), renderer, 90., SDL_FLIP_NONE);
        (*amountWalls)++;
        walls[currentAmountWalls + i + 6] = createWall(WALL_TYPE_FRAME_SIDE, POS(i + 1), POS(13), renderer, 270., SDL_FLIP_NONE);
        (*amountWalls)++;
    }
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(3), POS(7), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(3), POS(9), renderer, 180., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(3), POS(11), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(3), POS(13), renderer, 180., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(3), POS(8), renderer, 180., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(3), POS(12), renderer, 180., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(9), POS(1), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(2), POS(2), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(3), POS(2), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(5), POS(2), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(6), POS(2), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(7), POS(2), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(9), POS(2), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(2), POS(3), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(3), POS(3), renderer, 180., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(5), POS(3), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(6), POS(3), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(7), POS(3), renderer, 180., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(9), POS(3), renderer, 180., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(2), POS(5), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(3), POS(5), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(5), POS(5), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(7), POS(5), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(8), POS(5), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(9), POS(5), renderer, 90., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(5), POS(6), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(9), POS(6), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(5), POS(7), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(6), POS(7), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(7), POS(7), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(9), POS(7), renderer, 180., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(5), POS(8), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(5), POS(9), renderer, 180., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(7), POS(9), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(8), POS(9), renderer, 90., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(7), POS(10), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(5), POS(11), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(7), POS(11), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(8), POS(11), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(9), POS(11), renderer, 90., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(5), POS(12), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(5), POS(13), renderer, 180., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(7), POS(13), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(8), POS(13), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(9), POS(13), renderer, 90., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(9), POS(14), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(2), POS(15), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_CORNER, POS(3), POS(15), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(5), POS(15), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(6), POS(15), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(7), POS(15), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(9), POS(15), renderer, 180., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(3), POS(16), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(1), POS(17), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(3), POS(17), renderer, 180., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(5), POS(17), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(7), POS(17), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(8), POS(17), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(9), POS(17), renderer, 90., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(5), POS(18), renderer, 0., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(9), POS(18), renderer, 0., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(2), POS(19), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(3), POS(19), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(4), POS(19), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(5), POS(19), renderer, 270., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDES, POS(6), POS(19), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(7), POS(19), renderer, 90., SDL_FLIP_NONE);
    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_3SIDES, POS(9), POS(19), renderer, 180., SDL_FLIP_NONE);

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_SIDE, POS(0), POS(20), renderer, 180., SDL_FLIP_NONE);
    int wallsAtNine = 0;
    currentAmountWalls = *amountWalls;
    for(int i = 0; i < currentAmountWalls; i++)
    {
        if(walls[i]->entity->posX != POS(9))
        {
            int newX = 9 + (9 - (walls[i]->entity->posX) / SPRITE_SIZE_SOURCE);
            int newY = walls[i]->entity->posY;

            double angle = 0.;
            int oldAngle = (int)walls[i]->entity->textures->angle;
            int flip = SDL_FLIP_NONE;

            switch (walls[i]->type)
            {
                case WALL_TYPE_FRAME_CORNER:
                    switch (oldAngle)
                    {
                        case 0:
                            angle = 90.;
                            break;
                        case 90:
                            angle = 0.;
                            break;
                        case 180:
                            angle = 270.;
                            break;
                        case 270:
                            angle = 180.;
                            break;
                    }
                    break;
                case WALL_TYPE_FRAME_SIDE:
                    switch (oldAngle)
                    {
                        case 0:
                            angle = 180.;
                            break;
                        case 90:
                            angle = 90.;
                            break;
                        case 180:
                            angle = 0.;
                            break;
                        case 270:
                            angle = 270.;
                            break;
                    }
                    break;
                case WALL_TYPE_FRAME_SIDES:
                    angle = walls[i]->entity->textures->angle;
                    break;
                case WALL_TYPE_FRAME_3SIDES:
                    switch (oldAngle)
                    {
                        case 0:
                            angle = 0.;
                            break;
                        case 90:
                            angle = 270.;
                            break;
                        case 180:
                            angle = 180.;
                            break;
                        case 270:
                            angle = 90.;
                            break;
                    }
                    break;

            }
            walls[currentAmountWalls + i - wallsAtNine] = createWall(walls[i]->type ,POS(newX), newY, renderer, angle, flip);
            (*amountWalls)++;
        }
        else{wallsAtNine++;}
    }

    walls[(*amountWalls)++] = createWall(WALL_TYPE_FRAME_DOOR, POS(9), POS(9), renderer, 0, SDL_FLIP_NONE);

    for(int i = 0; i < (*amountWalls); i++)
    {
        maze[i] = walls[i]->entity;
    }
    //maze[*amountWalls + 1] = createWall(WALL_TYPE_FRAME_GEN, POS(9), POS(9), renderer, 180., SDL_FLIP_NONE)->entity;

    return maze;
}