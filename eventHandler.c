//
// Created by valwe on 18/02/2024.
//
#include "eventHandler.h"
#include "controller.h"
#include <SDL.h>

void eventHandler_cleanUpOnClose(eventHandler_arguments_t *arguments);
void eventHandler_keyDown(eventHandler_arguments_t *arguments);
void eventHandler_controllerButtonDown(eventHandler_arguments_t *arguments);

int eventHandler_handler(eventHandler_arguments_t *arguments)
{
    if(!SDL_PollEvent(&arguments->event)){return 0;}


    switch (arguments->event.type)
    {
        case SDL_CONTROLLERDEVICEADDED:
            SDL_Log("controller added\n");
            if(!arguments->controller[0]){arguments->controller[0] = SDL_GameControllerOpen(arguments->event.cdevice.which);}
            break;
        case SDL_CONTROLLERDEVICEREMOVED:
            SDL_Log("controller removed\n");
            if( arguments->controller[0]
                && arguments->event.cdevice.which
                == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(arguments->controller[0])))
            {
                SDL_GameControllerClose(arguments->controller[0]);
                arguments->controller[0] = controller_find();
            }
            break;
        case SDL_WINDOWEVENT_CLOSE:
            eventHandler_cleanUpOnClose(arguments);
            break;
        case SDL_QUIT:
            eventHandler_cleanUpOnClose(arguments);
            break;
        case SDL_CONTROLLERBUTTONDOWN:
            eventHandler_controllerButtonDown(arguments);
            break;
        case SDL_KEYDOWN:
            eventHandler_keyDown(arguments);
            break;
    }
    return 1;
}
void eventHandler_cleanUpOnClose(eventHandler_arguments_t *arguments)
{
    SDL_DestroyWindow(arguments->window);
    SDL_DestroyRenderer(arguments->renderer);
    SDL_Quit();
    exit(0);
}
void eventHandler_keyDown(eventHandler_arguments_t* arguments)
{
    switch(arguments->event.key.keysym.sym)
    {
        case SDLK_UP:
            arguments->player1.y -= 10;
            break;
        case SDLK_LEFT:
            arguments->player1.x -= 10;
            break;
        case SDLK_DOWN:
            arguments->player1.y += 10;
            break;
        case SDLK_RIGHT:
            arguments->player1.x += 10;
            break;
    }
}
void eventHandler_controllerButtonDown(eventHandler_arguments_t *arguments)
{
    SDL_Log("xbox\n");
    if(arguments->controller[0]
       && arguments->event.cdevice.which
       == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(arguments->controller[0])))
    {
        switch (arguments->event.cbutton.button)
        {
            case SDL_CONTROLLER_BUTTON_DPAD_UP:
                arguments->player1.y -= 10;
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                arguments->player1.x -= 10;
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                arguments->player1.y += 10;
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                arguments->player1.x += 10;
                break;
        }
    }
}

