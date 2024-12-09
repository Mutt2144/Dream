#include <iostream>

#include "app/include/app.h"

APP App;
COLORS Colors;

COLOR c[4] = {
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f}
};

SHAPE_SQUARE square(c, {-50.0f, -50.0f});

SHAPE_IMAGE button;
SHAPE_IMAGE btnPlay;

VECTOR2D test_vertices[4] = {
    VECTOR2D{0,   0},
    VECTOR2D{100, 0},
    VECTOR2D{100, 62.5},
    VECTOR2D{0,   62.5f}
};

COLOR test_color[4] = { Colors.CYAN, Colors.WHITE, Colors.BLUE, Colors.PURPLE };

VECTOR2D test_pos = { -350, -250 };

SHAPE_IMAGE test_image;

TTF_Font* default_font;

void loop() {
    while (App.running) {
        SDL_Event e = App.poll_events();

        if (App.KeyManager.keys[APP_DOWN]) {
            button.square.position.y -= 1.0f;
        }

        App.Graphics.Draw.clear_color(Colors.BLACK);
        App.Graphics.Draw.clear();

        //App.Graphics.Draw.square(square);
        App.Graphics.Draw.image(button, BLEND_ON);
        App.Graphics.Draw.image(btnPlay, BLEND_ON);
        App.Graphics.Draw.image(test_image, BLEND_ON);
        //App.Graphics.Draw.text("aaaaaaaaaaaPlay", {0, 0}, {1.0f, 1.0f, 1.0f, 1.0f}, default_font);

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

    btnPlay = button;
    btnPlay.texture = App.Graphics.load_texture("./assets/img/texts/btn-play.png");

    test_image.square = SHAPE_SQUARE(test_color, test_pos);
    test_image.texture = App.Graphics.load_texture("./assets/img/something.jpg");
    test_image.square.update_scale(VECTOR2D{ 50.0f, 31.25f });

    default_font = App.Graphics.load_font("./assets/font/PixelifySans-Bold.ttf", 24);
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