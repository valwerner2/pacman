//
// Created by valwe on 21/02/2024.
//
#include <time.h>
#include "entity.h"

void updateEntity(entity *entity, int direction)
{
    switch (direction)
    {
        case UP:
            entity->posY -= MOVE_AMOUNT;
            break;
        case DOWN:
            entity->posY += MOVE_AMOUNT;
            break;
        case LEFT:
            entity->posX -= MOVE_AMOUNT;
            break;
        case RIGHT:
            entity->posX += MOVE_AMOUNT;
            break;
        case NONE:
            entity->state = ENTITY_IDLE;
            return;
    }
    entity->direction = direction;
    entity->state = ENTITY_MOVING;
    time(&entity->lastActive);
}
void updateTextureEntity(entity *entity)
{
    int temp_ani_count = 0;
    int temp_ani_curr = 0;
    SDL_Rect *aniArray = entity->textures->sourceIDLE;
    //SDL_Log("%s\n", entity->state == ENTITY_IDLE ? "IDLE" : "MOVING");
    switch (entity->state)
    {
        case ENTITY_IDLE:
            switch (entity->direction)
            {
                case UP:
                    temp_ani_curr = ANI_UP_CURR;
                    aniArray = entity->textures->sourceUP;
                    break;
                case DOWN:
                    temp_ani_curr = ANI_DOWN_CURR;
                    aniArray = entity->textures->sourceDOWN;
                    break;
                case LEFT:
                    temp_ani_curr = ANI_LEFT_CURR;
                    aniArray = entity->textures->sourceLEFT;
                    break;
                case RIGHT:
                    temp_ani_curr = ANI_RIGHT_CURR;
                    aniArray = entity->textures->sourceRIGHT;
                    break;
            }
            entity->textures->animationInformation[temp_ani_curr] = 0;
            entity->textures->sourceCurrent = aniArray[0];
            break;
        case ENTITY_MOVING:
            switch (entity->direction)
            {
                case UP:
                    temp_ani_count = ANI_UP_COUNT;
                    temp_ani_curr = ANI_UP_CURR;
                    aniArray = entity->textures->sourceUP;
                    break;
                case DOWN:
                    temp_ani_count = ANI_DOWN_COUNT;
                    temp_ani_curr = ANI_DOWN_CURR;
                    aniArray = entity->textures->sourceDOWN;
                    break;
                case LEFT:
                    temp_ani_count = ANI_LEFT_COUNT;
                    temp_ani_curr = ANI_LEFT_CURR;
                    aniArray = entity->textures->sourceLEFT;
                    break;
                case RIGHT:
                    temp_ani_count = ANI_RIGHT_COUNT;
                    temp_ani_curr = ANI_RIGHT_CURR;
                    aniArray = entity->textures->sourceRIGHT;
                    break;
            }
            int i = (entity->textures->animationInformation[temp_ani_count] - 1) > entity->textures->animationInformation[temp_ani_curr]
                    ? ++(entity->textures->animationInformation[temp_ani_curr])
                    : (entity->textures->animationInformation[temp_ani_curr] = 0);
            entity->textures->sourceCurrent = aniArray[i];
            break;
    };
}