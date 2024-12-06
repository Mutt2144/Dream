#include <iostream>

#include "app/include/app.h"

APP App;

VECTOR2D pos[4] = {
    {-50,  50},
    { 50,  50},
    { 50,  -50},
    {-50,  -50}
};

COLOR c[4] = {
    {1.0f, 0.0f, 0.0f, 1.0f},
    {0.0f, 1.0f, 0.0f, 1.0f},
    {0.0f, 0.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f}
};

SHAPE_SQUARE square(pos, c, {100.0f, 0.0f});

SHAPE_IMAGE image;

void loop() {
    while (App.running) {
        SDL_Event e = App.poll_events();

        if (App.KeyManager.keys[APP_DOWN]) {
            image.square.position.y -= 1.0f;
        }

        App.Graphics.Draw.clear_color({0.2f, 0.3f, 0.3f, 1.0f});
        App.Graphics.Draw.clear();

        //App.Graphics.Draw.square(square);
        App.Graphics.Draw.image(image, BLEND_ON);

        //SDL_GL_SwapWindow(App.get_window());
        App.Graphics.Draw.swap_buffers();
    }
}

int main(int argc, const char** argv) {
    if (!App.init(800, 600, "App")) {
        std::cerr << "Failed to initialize the application\n";
        return -1;
    }

    image.square = square;
    image.texture = App.Graphics.load_texture("assets/img/test.png");
    image.texCoord[0] = {0.0f, 0.0f};
    image.texCoord[1] = {1.0f, 0.0f};
    image.texCoord[2] = {1.0f, 1.0f};
    image.texCoord[3] = {0.0f, 1.0f};

    loop();
    //SDL_Delay(2000);
    
    App.quit();
    return 0;
}