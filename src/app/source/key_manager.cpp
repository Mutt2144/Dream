#include "../include/key_manager.h"

void KEY_MANAGER::check_key_down(SDL_Event e) {
    switch (e.key.keysym.sym) 
    {
    case SDLK_UP:
        keys[APP_UP]    = APP_TRUE;
        break;
    case SDLK_LEFT:
        keys[APP_LEFT]  = APP_TRUE;
        break;
    case SDLK_DOWN:
        keys[APP_DOWN]  = APP_TRUE;
        break;
    case SDLK_RIGHT:
        keys[APP_RIGHT] = APP_TRUE;
        break;
    
    case SDLK_z:
        keys[APP_Z]     = APP_TRUE;
        break;
    case SDLK_x:
        keys[APP_X]     = APP_TRUE;
        break;

    }
}

void KEY_MANAGER::check_key_up(SDL_Event e) {
    switch (e.key.keysym.sym) 
    {
    case SDLK_UP:
        keys[APP_UP]    = APP_FALSE;
        break;
    case SDLK_LEFT:
        keys[APP_LEFT]  = APP_FALSE;
        break;
    case SDLK_DOWN:
        keys[APP_DOWN]  = APP_FALSE;
        break;
    case SDLK_RIGHT:
        keys[APP_RIGHT] = APP_FALSE;
        break;
    
    case SDLK_z:
        keys[APP_Z]     = APP_FALSE;
        break;
    case SDLK_x:
        keys[APP_X]     = APP_FALSE;
        break;

    }
}