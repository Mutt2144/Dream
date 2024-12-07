#include "../include/app.h"

bool APP::init(int w, int h, c_char* title) {
    printf("Starting dependencies...\n");

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "Failed do Load Dependencies: " << SDL_GetError() << "\n";
        std::cerr << "[ABORTED]\n";
        return APP_FALSE;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        std::cerr << "Failed do Load IMG Dependencies: " << IMG_GetError() << "\n";
        std::cerr << "[ABORTED]\n";
        return APP_FALSE;
    }

    if (TTF_Init() < 0) {
        std::cerr << "Failed do Load TTF Dependencies: " << TTF_GetError() << "\n";
        std::cerr << "[ABORTED]\n";
        return APP_FALSE;
    }

    printf("Process: [WINDOW->create_window] started.\n");
    if (!Window.create_window(w, h, title)) {
        std::cerr << "[ABORTED]\n";
        return APP_FALSE;
    }

    printf("Process: [Graphics->create_context] started.\n");
    if (!Graphics.create_context(Window.get_window(), w, h)) {
        std::cerr << "[ABORTED]\n";
        return APP_FALSE;
    }

    return APP_TRUE;
}

void APP::quit() {
    printf("Quitting...\n");
    Window.close();
    Graphics.delete_context();
    SDL_Quit();
}


SDL_Event APP::poll_events() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) running = APP_FALSE;
        else if (e.type == SDL_KEYDOWN) KeyManager.check_key_down(e);
        else if (e.type == SDL_KEYUP) KeyManager.check_key_up(e);
    }

    return e;
}

SDL_Window* APP::get_window() {
    return Window.get_window();
}