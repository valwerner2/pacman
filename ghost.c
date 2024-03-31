//
// Created by valwe on 24/02/2024.
//
#include "ghost.h"

entityTextures *createGhostTexture(SDL_Renderer *renderer, int type)
{
    char *path;
    switch (type)
    {
        case GHOST_TYPE_RED:
            path = "../sprites/ghosts/sheetGhostRed.png";
            break;
        case GHOST_TYPE_PURPLE:
            path = "../sprites/ghosts/sheetGhostPurple.png";
            break;
        case GHOST_TYPE_ORANGEN:
            path = "../sprites/ghosts/sheetGhostOrange.png";
            break;
        case GHOST_TYPE_CYAN:
            path = "../sprites/ghosts/sheetGhostCyan.png";
            break;
        case GHOST_TYPE_FRIGHTENED:
            path = "../sprites/ghosts/sheetGhostFrightened.png";
            break;
        case GHOST_TYPE_EATEN:
            path = "../sprites/ghosts/sheetGhostEaten.png";
            break;
    }

    SDL_Rect rectIdle = {0, 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE};
    SDL_Rect rectUp[] = {{POS(2), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                         {POS(3), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                         {POS(4), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                         {POS(5), 0, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectDown[] = {{POS(7), 0,      SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(0), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(1), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(2), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectLeft[] = {{POS(1), POS(2), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(2), POS(2), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(3), POS(2), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                           {POS(4), POS(2), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    SDL_Rect rectRight[] = {{POS(4), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(5), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(6), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE},
                            {POS(7), POS(1), SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE}};
    int animationInformation[18] = {0};
    animationInformation[ANI_IDLE_COUNT] = 1;
    animationInformation[ANI_UP_COUNT] = 4;
    animationInformation[ANI_DOWN_COUNT] = 4;
    animationInformation[ANI_LEFT_COUNT] = 4;
    animationInformation[ANI_RIGHT_COUNT] = 4;

    animationInformation[ANI_IDLE_UP_COUNT]     = 1;
    animationInformation[ANI_IDLE_DOWN_COUNT]   = 1;
    animationInformation[ANI_IDLE_LEFT_COUNT]   = 1;
    animationInformation[ANI_IDLE_RIGHT_COUNT]  = 1;

    return entityCreateTextures(path, renderer,
                                animationInformation,
                                100000,
                                &rectIdle,
                                rectUp,
                                rectDown,
                                rectLeft,
                                rectRight,
                                rectUp,
                                rectDown,
                                rectLeft,
                                rectRight);
}
ghost *createGhost(int startX, int startY, int type, SDL_Renderer *renderer)
{
    ghost *gh = malloc(sizeof(ghost));
    gh->entity = malloc(sizeof(entity));

    time_t initTime;
    time(&initTime);

    gh->texturesChaseScatter = createGhostTexture(renderer, type);
    gh->texturesFrightened = createGhostTexture(renderer, GHOST_TYPE_FRIGHTENED);
    gh->texturesEaten = createGhostTexture(renderer, GHOST_TYPE_EATEN);
    gh->type = type;
    gh->texturesChaseScatter->flip = SDL_FLIP_NONE;
    gh->texturesChaseScatter->center = NULL;
    gh->texturesChaseScatter->angle = 0.;

    gh->texturesFrightened->flip = SDL_FLIP_NONE;
    gh->texturesFrightened->center = NULL;
    gh->texturesFrightened->angle = 0.;

    gh->texturesEaten->flip = SDL_FLIP_NONE;
    gh->texturesEaten->center = NULL;
    gh->texturesEaten->angle = 0.;

    gh->entity->visible = 1;


    gh->movementDelay = 90000;
    mingw_gettimeofday(&gh->lastMoved, NULL);

    gh->entity->textures = gh->texturesChaseScatter;
    gh->entity->state = ENTITY_IDLE;
    gh->entity->direction = NONE;
    gh->entity->posX = startX;
    gh->entity->posY = startY;
    gh->entity->hitBox.x = startX + 5;
    gh->entity->hitBox.y = startY + 2;
    gh->entity->hitBox.w = SPRITE_SIZE_SOURCE - 5 * 2;
    gh->entity->hitBox.h = SPRITE_SIZE_SOURCE - 2 * 2 - 1;
    gh->entity->lastActive = initTime;
    gh->entity->pathFindingCollision = 1;

    switch (type)
    {
        case GHOST_TYPE_RED:
            gh->state = GHOST_CHASE;
            break;
        default:
            gh->state = GHOST_EATEN;
            break;
    }

    return gh;
}
void freeGhost(ghost* ghost)
{
    entityDeleteTextures(ghost->entity->textures);
    free(ghost->entity);
    free(ghost);
}
entity getGhostTarget(ghost *currGhost, ghost **ghosts, entity *pacman)
{
    int targetX = POS(9);
    int targetY = POS(10);

    switch (currGhost->state)
    {
        case(GHOST_CHASE):
            switch (currGhost->type)
            {
                case GHOST_TYPE_RED:
                    targetX = pacman->posX;
                    targetY = pacman->posY;
                    break;
                case GHOST_TYPE_PURPLE:
                    switch (pacman->direction)
                    {
                        case UP: targetX = pacman->posX - POS(4); targetY = pacman->posY - POS(4); break;
                        case DOWN: targetX = pacman->posX; targetY = pacman->posY + POS(4); break;
                        case LEFT: targetX = pacman->posX - POS(4); targetY = pacman->posY; break;
                        case RIGHT: targetX = pacman->posX + POS(4); targetY = pacman->posY; break;
                    }
                    break;
                case GHOST_TYPE_ORANGEN:
                    if(getDistanceEntity(currGhost->entity, pacman) > (8llu*8llu*SPRITE_SIZE_SOURCE*SPRITE_SIZE_SOURCE))
                    {targetX = pacman->posX; targetY = pacman->posY;}
                    else
                    {targetX = 0; targetY = POS(22);}
                    break;
                case GHOST_TYPE_CYAN:
                    switch (pacman->direction)
                    {
                        case UP: targetX = pacman->posX - POS(2); targetY = pacman->posY - POS(2); break;
                        case DOWN: targetX = pacman->posX; targetY = pacman->posY + POS(2); break;
                        case LEFT: targetX = pacman->posX - POS(2); targetY = pacman->posY; break;
                        case RIGHT: targetX = pacman->posX + POS(2); targetY = pacman->posY; break;
                    }
                    targetX -= ghosts[0]->entity->posX - targetX;
                    targetY -= ghosts[0]->entity->posX - targetY;
                    break;
            }
            break;
        case GHOST_EATEN:
            targetX = POS(9);
            targetY = POS(10);
            break;
        case GHOST_SCATTER:
            switch (currGhost->type)
            {
                case GHOST_TYPE_RED:
                    targetX = POS(18); targetY = POS(-1);
                    break;
                case GHOST_TYPE_PURPLE:
                    targetX = 0; targetY = POS(-1);
                    break;
                case GHOST_TYPE_CYAN:
                    targetX = POS(18); targetY = POS(22);
                    break;
                case GHOST_TYPE_ORANGEN:
                    targetX = 0; targetY = POS(22);
                    break;
            }
            break;
        case GHOST_LEAVE_PRISON:
            targetX = POS(8); targetY = POS(8);
            break;
    }

    entity target;
    SDL_Rect targetHitBox = {targetX, targetY, SPRITE_SIZE_SOURCE, SPRITE_SIZE_SOURCE};
    target.hitBox = targetHitBox;
    target.posX = targetX;
    target.posY = targetY;
    return target;
}
void ghostTextureSwitch(ghost *gh)
{
    entityTextures *pointerNew;
    switch (gh->state)
    {
        case GHOST_SCATTER:
        case GHOST_CHASE:
        case GHOST_LEAVE_PRISON:
            pointerNew = gh->texturesChaseScatter;
            break;
        case GHOST_EATEN:
            pointerNew = gh->texturesEaten;
            break;
        case GHOST_FRIGHTENED:
            pointerNew = gh->texturesFrightened;
            break;
    }
    gh->entity->textures = pointerNew;
}