#include <SDL.h>
#include <SDL_image.h>

#include "eventHandler.h"
#include "controller.h"

#define WINDOW_HIGHT 640
#define WINDOW_HEIGHT 480

int main(int argumentCount, char* arguments[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
    }

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surfaceSpriteSheet;

    window = SDL_CreateWindow("Game Window",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_HIGHT,
                              WINDOW_HEIGHT,
                              0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    surfaceSpriteSheet = IMG_Load("../sprites/spriteSheet.png");
    if(surfaceSpriteSheet == NULL){SDL_Log("Error getting spriteSheet\n"); SDL_Quit();}
    SDL_Texture *textureSpriteSheet = SDL_CreateTextureFromSurface(renderer, surfaceSpriteSheet);
    if(textureSpriteSheet == NULL){ SDL_Log("Error making texture");}
    SDL_FreeSurface(surfaceSpriteSheet);

    eventHandler_arguments_t eventHandlerArguments;

    eventHandlerArguments.controller[0] = controller_find();

    SDL_Rect rectangle = {0, 0, 200, 200};
    SDL_Rect pacmanRectangle = {0, 0, 200, 200};

    eventHandlerArguments.player1 = pacmanRectangle;
    //eventHandlerArguments.player2 = rectangle;

    char running = 1;
    while(running)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
        SDL_RenderCopy(renderer, textureSpriteSheet,NULL , &eventHandlerArguments.player1);

        SDL_RenderPresent(renderer);

        eventHandler_handler(&eventHandlerArguments);
    }
    return 0;
}
