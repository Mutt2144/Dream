#ifndef HEADER_APP_H
#define HEADER_APP_H

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>

#include "types.h"
#include "window.h"
#include "graphics.h"

class APP {
private:
    WINDOW Window;

public:
    GRAPHICS Graphics;

    bool running = 1;

    bool init(int w, int h, const char* title);
    void quit();

    SDL_Event poll_events();

    SDL_Window* get_window();
};

#endif  // HEADER_APP_H