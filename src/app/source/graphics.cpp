#include "../include/graphics.h"

void DRAW::clear_color(COLOR c) {
    glClearColor(c.r, c.g, c.b, c.a);
}

void DRAW::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void DRAW::swap_buffers() {
    SDL_GL_SwapWindow(graphic_window);
}

void DRAW::set_color(COLOR c) {
    glColor3f(c.r, c.g, c.b);
}

void DRAW::set_vertice(VECTOR2D v) {
    glVertex2f(v.x, v.y);
}

void DRAW::set_tex_cord(VECTOR2D v) {
    glTexCoord2f(v.x, v.y);
}

void DRAW::square(SHAPE_SQUARE square) {
    glBegin(GL_QUADS);
        set_color(square.color[0]);
        set_vertice(square.get_position(0));

        set_color(square.color[1]);
        set_vertice(square.get_position(1));

        set_color(square.color[2]);
        set_vertice(square.get_position(2));

        set_color(square.color[3]);
        set_vertice(square.get_position(3));
    glEnd();
}

void DRAW::image(SHAPE_IMAGE image, int blend_mode) {
    glEnable(GL_TEXTURE_2D);
    if (blend_mode == BLEND_ON) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    glBindTexture(GL_TEXTURE_2D, image.texture);

    glBegin(GL_QUADS);
        set_color(image.square.color[0]);
        set_tex_cord(image.texCoord[0]);        set_vertice(image.square.get_position(0));

        set_color(image.square.color[1]);
        set_tex_cord(image.texCoord[1]);       set_vertice(image.square.get_position(1));
        
        set_color(image.square.color[2]);
        set_tex_cord(image.texCoord[2]);       set_vertice(image.square.get_position(2));
        
        set_color(image.square.color[3]);
        set_tex_cord(image.texCoord[3]);       set_vertice(image.square.get_position(3));
    glEnd();

    glDisable(GL_TEXTURE_2D);
    if (blend_mode == BLEND_ON) glDisable(GL_BLEND);
}

bool GRAPHICS::create_context(SDL_Window* _window, int w, int h) {
    glContext = SDL_GL_CreateContext(_window);
    if (!glContext) {
        std::cerr << "Failed to load graphic API: " << SDL_GetError() << "\n";
        return APP_FALSE;
    }

    glLoadIdentity();
    glOrtho(-w/2, w/2, -h/2, h/2, -1, 1);

    Draw.graphic_window = _window;

    return APP_TRUE;
}

void GRAPHICS::delete_context() {
    printf("[Context Deleted]\n");
    SDL_GL_DeleteContext(glContext);
}

GLuint GRAPHICS::load_texture(c_char* fileName) {
    GLuint texture;
    SDL_Surface* surface = IMG_Load(fileName);
    if (!surface) {
        std::cerr << "Failed to load texture: " << SDL_GetError() << "\n";
        return 0;
    }
    SDL_Surface* surface_format = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA32, 0);
    SDL_FreeSurface(surface);
    if (!surface_format) {
        std::cerr << "Failed to load texture: " << SDL_GetError() << "\n";
        return 0;
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface_format->w, surface_format->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface_format->pixels);
    SDL_FreeSurface(surface_format);
    return texture;
}

/*GLuint GRAPHICS::load_texture(c_char* fileName) {
    GLuint texture;
    SDL_Surface* surface = IMG_lo(fileName);
    if (!surface) {
        std::cerr << "Failed to load texture: " << SDL_GetError() << "\n";
        return 0;
    }
    SDL_Surface* surface_format = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA32, 0);
    SDL_FreeSurface(surface);
    if (!surface_format) {
        std::cerr << "Failed to load texture: " << SDL_GetError() << "\n";
        return 0;
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface_format->w, surface_format->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface_format->pixels);
    SDL_FreeSurface(surface_format);
    return texture;
}*/