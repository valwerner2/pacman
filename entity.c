//
// Created by valwe on 21/02/2024.
//

#include "entity.h"

void updateEntity(entity *entity, int direction)
{
    switch (direction)
    {
        case UP:
            entity->posY -= MOVE_AMOUNT;
            entity->hitBox.y -= MOVE_AMOUNT;
            break;
        case DOWN:
            entity->posY += MOVE_AMOUNT;
            entity->hitBox.y += MOVE_AMOUNT;
            break;
        case LEFT:
            entity->posX -= MOVE_AMOUNT;
            entity->hitBox.x -= MOVE_AMOUNT;
            break;
        case RIGHT:
            entity->posX += MOVE_AMOUNT;
            entity->hitBox.x += MOVE_AMOUNT;
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
    SDL_Rect *aniArray = entity->textures->sourceIdle;
    //SDL_Log("%s\n", entity->state == ENTITY_IDLE ? "IDLE" : "MOVING");
    struct timeval currTime;
    mingw_gettimeofday(&currTime, NULL);

    if (entity->textures->microsecondsAnimationTime < ((currTime.tv_sec - entity->textures->lastAnimation->tv_sec) * 1000000 + currTime.tv_usec - entity->textures->lastAnimation->tv_usec))
    {
        memcpy(entity->textures->lastAnimation, &currTime, sizeof(struct timeval));
        int i = 0;
        switch (entity->state)
        {
            case ENTITY_IDLE:
                switch (entity->direction)
                {
                    case UP:
                        temp_ani_curr = ANI_IDLE_UP_CURR;
                        temp_ani_count = ANI_IDLE_UP_COUNT;
                        aniArray = entity->textures->sourceIdleUp;
                        break;
                    case DOWN:
                        temp_ani_curr = ANI_IDLE_DOWN_CURR;
                        temp_ani_count = ANI_IDLE_DOWN_COUNT;
                        aniArray = entity->textures->sourceIdleDown;
                        break;
                    case LEFT:
                        temp_ani_curr = ANI_IDLE_LEFT_CURR;
                        temp_ani_count = ANI_IDLE_LEFT_COUNT;
                        aniArray = entity->textures->sourceIdleLeft;
                        break;
                    case RIGHT:
                        temp_ani_curr = ANI_IDLE_RIGHT_CURR;
                        temp_ani_count = ANI_IDLE_RIGHT_COUNT;
                        aniArray = entity->textures->sourceIdleRight;
                        break;
                    case NONE:
                        temp_ani_curr = ANI_IDLE_CURR;
                        temp_ani_count = ANI_IDLE_COUNT;
                        aniArray = entity->textures->sourceIdle;
                        break;
                }
                i =     (entity->textures->animationInformation[temp_ani_count] - 1)
                        > entity->textures->animationInformation[temp_ani_curr]
                        ? ++(entity->textures->animationInformation[temp_ani_curr])
                        : (entity->textures->animationInformation[temp_ani_curr] = 0);
                entity->textures->sourceCurrent = aniArray[i];
                break;
            case ENTITY_MOVING:
                switch (entity->direction)
                {
                    case UP:
                        temp_ani_count = ANI_UP_COUNT;
                        temp_ani_curr = ANI_UP_CURR;
                        aniArray = entity->textures->sourceUp;
                        break;
                    case DOWN:
                        temp_ani_count = ANI_DOWN_COUNT;
                        temp_ani_curr = ANI_DOWN_CURR;
                        aniArray = entity->textures->sourceDown;
                        break;
                    case LEFT:
                        temp_ani_count = ANI_LEFT_COUNT;
                        temp_ani_curr = ANI_LEFT_CURR;
                        aniArray = entity->textures->sourceLeft;
                        break;
                    case RIGHT:
                        temp_ani_count = ANI_RIGHT_COUNT;
                        temp_ani_curr = ANI_RIGHT_CURR;
                        aniArray = entity->textures->sourceRight;
                        break;
                }
                i =     (entity->textures->animationInformation[temp_ani_count] - 1)
                        > entity->textures->animationInformation[temp_ani_curr]
                        ? ++(entity->textures->animationInformation[temp_ani_curr])
                        : (entity->textures->animationInformation[temp_ani_curr] = 0);
                entity->textures->sourceCurrent = aniArray[i];
                break;
        };
    }
}
entityTextures *entityCreateTextures(char* path, SDL_Renderer *renderer,
                    int *animationInformation,
                    unsigned long long animationSpeed,
                    SDL_Rect *rectIdle,
                    SDL_Rect *rectUp,
                    SDL_Rect *rectDown,
                    SDL_Rect *rectLeft,
                    SDL_Rect *rectRight,
                    SDL_Rect *rectIdleUp,
                    SDL_Rect *rectIdleDown,
                    SDL_Rect *rectIdleLeft,
                    SDL_Rect *rectIdleRight)
{
    SDL_Surface *surfaceSpriteSheet;

    surfaceSpriteSheet = IMG_Load(path);
    if(surfaceSpriteSheet == NULL){SDL_Log("Error getting spriteSheet\n"); SDL_Quit();}
    SDL_Texture *textureSpriteSheet = SDL_CreateTextureFromSurface(renderer, surfaceSpriteSheet);
    if(textureSpriteSheet == NULL){ SDL_Log("Error making textures");}
    SDL_FreeSurface(surfaceSpriteSheet);

    entityTextures *newEntityTextures = malloc(sizeof(entityTextures));

    newEntityTextures->texture = textureSpriteSheet;

    memcpy(newEntityTextures->animationInformation, animationInformation, 18 * sizeof(int));

    newEntityTextures->sourceIdle = malloc(newEntityTextures->animationInformation[ANI_IDLE_COUNT] * sizeof(SDL_Rect));
    newEntityTextures->sourceUp = malloc(newEntityTextures->animationInformation[ANI_UP_COUNT] * sizeof(SDL_Rect));
    newEntityTextures->sourceDown = malloc(newEntityTextures->animationInformation[ANI_DOWN_COUNT] * sizeof(SDL_Rect));
    newEntityTextures->sourceLeft = malloc(newEntityTextures->animationInformation[ANI_LEFT_COUNT] * sizeof(SDL_Rect));
    newEntityTextures->sourceRight = malloc(newEntityTextures->animationInformation[ANI_RIGHT_COUNT] * sizeof(SDL_Rect));

    newEntityTextures->sourceIdleUp = malloc(newEntityTextures->animationInformation[ANI_IDLE_UP_COUNT] * sizeof(SDL_Rect));
    newEntityTextures->sourceIdleDown = malloc(newEntityTextures->animationInformation[ANI_IDLE_DOWN_COUNT] * sizeof(SDL_Rect));
    newEntityTextures->sourceIdleLeft = malloc(newEntityTextures->animationInformation[ANI_IDLE_LEFT_COUNT] * sizeof(SDL_Rect));
    newEntityTextures->sourceIdleRight = malloc(newEntityTextures->animationInformation[ANI_IDLE_RIGHT_COUNT] * sizeof(SDL_Rect));

    newEntityTextures->lastAnimation = malloc(sizeof(struct timeval));

    memcpy(newEntityTextures->sourceIdle, rectIdle, newEntityTextures->animationInformation[ANI_IDLE_COUNT] * sizeof(SDL_Rect));
    memcpy(newEntityTextures->sourceUp, rectUp, newEntityTextures->animationInformation[ANI_UP_COUNT] * sizeof(SDL_Rect));
    memcpy(newEntityTextures->sourceDown, rectDown, newEntityTextures->animationInformation[ANI_DOWN_COUNT] * sizeof(SDL_Rect));
    memcpy(newEntityTextures->sourceLeft, rectLeft, newEntityTextures->animationInformation[ANI_LEFT_COUNT] * sizeof(SDL_Rect));
    memcpy(newEntityTextures->sourceRight, rectRight, newEntityTextures->animationInformation[ANI_RIGHT_COUNT] * sizeof(SDL_Rect));

    memcpy(newEntityTextures->sourceIdleUp, rectIdleUp, newEntityTextures->animationInformation[ANI_IDLE_UP_COUNT] * sizeof(SDL_Rect));
    memcpy(newEntityTextures->sourceIdleDown, rectIdleDown, newEntityTextures->animationInformation[ANI_IDLE_DOWN_COUNT] * sizeof(SDL_Rect));
    memcpy(newEntityTextures->sourceIdleLeft, rectIdleLeft, newEntityTextures->animationInformation[ANI_IDLE_LEFT_COUNT] * sizeof(SDL_Rect));
    memcpy(newEntityTextures->sourceIdleRight, rectIdleRight, newEntityTextures->animationInformation[ANI_IDLE_RIGHT_COUNT] * sizeof(SDL_Rect));

    mingw_gettimeofday(newEntityTextures->lastAnimation, NULL);

    newEntityTextures->microsecondsAnimationTime = animationSpeed;

    newEntityTextures->sourceCurrent = newEntityTextures->sourceIdle[newEntityTextures->animationInformation[ANI_IDLE_CURR]];


    return newEntityTextures;
}
void entityDeleteTextures(entityTextures* entityTextures)
{
    free(entityTextures->lastAnimation);
    free(entityTextures->sourceIdle);
    free(entityTextures->sourceUp);
    free(entityTextures->sourceDown);
    free(entityTextures->sourceLeft);
    free(entityTextures->sourceRight);

    SDL_DestroyTexture(entityTextures->texture);
}