//
// Created by valwe on 18/02/2024.
//
#include "eventHandler.h"
#include "controller.h"

void eventHandler_cleanUpOnClose(eventHandler_arguments *args);
void eventHandler_keyDown(eventHandler_arguments *args);
void eventHandler_controllerButtonDown(eventHandler_arguments *args);
void eventHandler_keyUp(eventHandler_arguments *args);

int eventHandler_handler(eventHandler_arguments *args)
{
    if(!SDL_PollEvent(&args->event)){return 0;}

    switch (args->event.type)
    {
        case SDL_CONTROLLERDEVICEADDED:
            SDL_Log("controller added\n");
            if(!args->controller[0]){ args->controller[0] = SDL_GameControllerOpen(args->event.cdevice.which);}
            break;
        case SDL_CONTROLLERDEVICEREMOVED:
            SDL_Log("controller removed\n");
            if(args->controller[0]
               && args->event.cdevice.which
                  == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(args->controller[0])))
            {
                SDL_GameControllerClose(args->controller[0]);
                args->controller[0] = controller_find();
            }
            break;
        case SDL_WINDOWEVENT_CLOSE:
            eventHandler_cleanUpOnClose(args);
            break;
        case SDL_QUIT:
            eventHandler_cleanUpOnClose(args);
            break;
        case SDL_CONTROLLERBUTTONDOWN:
            eventHandler_controllerButtonDown(args);
            break;
        case SDL_KEYDOWN:
            eventHandler_keyDown(args);
            break;
        case SDL_KEYUP:
            eventHandler_keyUp(args);
            break;
    }
    return 1;
}
void eventHandler_cleanUpOnClose(eventHandler_arguments *args)
{
    SDL_DestroyWindow(args->window);
    SDL_Quit();
    exit(0);
}
void eventHandler_keyDown(eventHandler_arguments* args)
{
    int direction = NONE;
    switch(args->event.key.keysym.sym)
    {
        case SDLK_UP:
            direction = UP;
            break;
        case SDLK_DOWN:
            direction = DOWN;
            break;
        case SDLK_LEFT:
            direction = LEFT;
            break;
        case SDLK_RIGHT:
            direction = RIGHT;
            break;
    }
    updateEntity(args->player1, direction);
}
void eventHandler_keyUp(eventHandler_arguments *args)
{
    switch(args->event.key.keysym.sym)
    {
        case SDLK_UP:
            args->player1->direction = UP;
            updateEntity(args->player1, NONE);
            break;
        case SDLK_DOWN:
            args->player1->direction = DOWN;
            updateEntity(args->player1, NONE);
            break;
        case SDLK_LEFT:
            args->player1->direction = LEFT;
            updateEntity(args->player1, NONE);
            break;
        case SDLK_RIGHT:
            args->player1->direction = RIGHT;
            updateEntity(args->player1, NONE);
            break;
    }
}

void eventHandler_controllerButtonDown(eventHandler_arguments *args)
{
    int direction = NONE;
    if(args->controller[0]
       && args->event.cdevice.which
          == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(args->controller[0])))
    {
        switch (args->event.cbutton.button)
        {
            case SDL_CONTROLLER_BUTTON_DPAD_UP:
                direction = UP;
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                direction = DOWN;
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                direction = LEFT;
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                direction = RIGHT;
                break;
        }
    }
    updateEntity(args->player1, direction);
}

