#include <iostream>

#include "app/include/app.h"

APP App;


VECTOR2D* p1 = new VECTOR2D{0, 0};
VECTOR2D* p2 = new VECTOR2D{100, 0};
VECTOR2D* p3 = new VECTOR2D{100, 60};
VECTOR2D* p4 = new VECTOR2D{0, 60};

VECTOR2D pos[4] = {
    VECTOR2D{0, 0},
    VECTOR2D{100, 0},
    VECTOR2D{100, 60},
    VECTOR2D{0, 60}
};

COLOR c[4] = {
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f}
};

SHAPE_SQUARE square(pos, c, {-50.0f, -50.0f});

SHAPE_IMAGE button;
SHAPE_IMAGE btnPlay;

TTF_Font* default_font;

void loop() {
    while (App.running) {
        SDL_Event e = App.poll_events();

        if (App.KeyManager.keys[APP_DOWN]) {
            button.square.position.y -= 1.0f;
        }

        App.Graphics.Draw.clear_color({0, 0, 0, 1.0f});
        App.Graphics.Draw.clear();

        //App.Graphics.Draw.square(square);
        App.Graphics.Draw.image(button, BLEND_ON);
        App.Graphics.Draw.image(btnPlay, BLEND_ON);
        //App.Graphics.Draw.text("aaaaaaaaaaaPlay", {0, 0}, {1.0f, 1.0f, 1.0f, 1.0f}, default_font);

        //SDL_GL_SwapWindow(App.get_window());
        App.Graphics.Draw.swap_buffers();
    }
}

int main(int argc, const char** argv) {
    if (!App.init(800, 600, "App")) {
        std::cerr << "Failed to initialize the application\n";
        return -1;
    }

    button.square = square;
    button.texture = App.Graphics.load_texture("assets/img/button.png");
    button.texCoord[0] = {0.0f, 1.0f};
    button.texCoord[1] = {1.0f, 1.0f};
    button.texCoord[2] = {1.0f, 0.0f};
    button.texCoord[3] = {0.0f, 0.0f};

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    btnPlay = button;
    btnPlay.texture = App.Graphics.load_texture("assets/img/texts/btn-play.png");

    default_font = App.Graphics.load_font("assets/font/PixelifySans-Bold.ttf", 24);
    if (default_font == nullptr) {
        std::cerr << "Failed to load font\n";
        return -1;
    }

    loop();
    //SDL_Delay(2000);
    
    App.Graphics.delete_font(default_font);
    App.quit();
    return 0;
}