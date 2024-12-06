#include "../include/window.h"

bool WINDOW::create_window(int w, int h, const char* title) {
    std::cout << "Window: " << w << "x" << h << "\n";

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "Failed to create the window: " << SDL_GetError() << "\n";
        return APP_FALSE;
    }

    printf("Window created.\n");
    return APP_TRUE;
}

SDL_Window* WINDOW::get_window() {
    return window;
}

void WINDOW::close() {
    std::cout << "[Window Closed]\n";
    SDL_DestroyWindow(window);
}