#ifndef APP_GRAPHICS_H
#define APP_GRAPHICS_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>

#include "../include/types.h"

class DRAW {
public:
    SDL_Window* graphic_window;

    void clear_color(COLOR c);
    void clear();
    void swap_buffers();

    void set_color(COLOR c);
    void set_vertice(VECTOR2D v);
    void set_tex_cord(VECTOR2D v);

    void square(SHAPE_SQUARE square);
    void image(SHAPE_IMAGE image, int blend_mode);
};

class GRAPHICS {
private:
    SDL_GLContext glContext;

public:
    DRAW Draw;

    bool create_context(SDL_Window* window, int w, int h);
    void delete_context();

    GLuint load_texture(c_char* fileName);
};

#endif  // APP_GRAPHICS_H