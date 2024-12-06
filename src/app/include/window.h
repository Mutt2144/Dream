#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "types.h"

class WINDOW {
private:
    SDL_Window* window;
    SDL_GLContext glContext;

    int width;
    int height;
    const char* title;

public:
    bool create_window(int w, int h, const char* title);
    SDL_Window* get_window();

    void close();
};

#endif  // APP_WINDOW_H