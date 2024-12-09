#ifndef APP_GRAPHICS_H
#define APP_GRAPHICS_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/types.h"

class DRAW {
private:
    SDL_Texture* create_text_texture(TTF_Font* font, c_char* text, COLOR c);
    void bind_texture(GLuint id);
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

    void text(c_char* text, VECTOR2D position, COLOR color, TTF_Font* font);
};

class GRAPHICS {
private:
    SDL_GLContext glContext;

public:
    DRAW Draw;
    static TTF_Font* font;

    bool create_context(SDL_Window* window, int w, int h);
    void delete_context();

    GLuint load_texture(c_char* fileName);
    TTF_Font* load_font(c_char* fileName, int size);

    void delete_font(TTF_Font* font);
};

#endif  // APP_GRAPHICS_H