#ifndef APP_KEY_MANAGER_H
#define APP_KEY_MANAGER_H

#include <SDL2/SDL_events.h>

#include "types.h"

enum KEY_CODES {
    APP_UP,
    APP_LEFT,
    APP_DOWN,
    APP_RIGHT,

    APP_Z,
    APP_X,
    APP_ESCAPE,
    APP_ENTER,
    APP_BACKSPACE,
};

class KEY_MANAGER {
public:
    bool keys[256];

    void check_key_down(SDL_Event e);
    void check_key_up(SDL_Event e);
};

#endif  // APP_KEY_MANAGER_H