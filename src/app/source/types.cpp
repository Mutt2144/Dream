#include "../include/types.h"

VECTOR2D SHAPE_SQUARE::get_position(int id) {
    return {  vertices[id].x + position.x,
                vertices[id].y + position.y };
}

SHAPE_SQUARE::SHAPE_SQUARE(VECTOR2D _vertices[4], COLOR _color[4], VECTOR2D _position) {
    for (int i = 0; i < 4; i++) {
        vertices[i] = _vertices[i];
        color[i] = _color[i];
    }
    position = _position;
}

SHAPE_SQUARE::SHAPE_SQUARE() {
    for (int i = 0; i < 4; i++) {
        vertices[i] = {0.0f, 0.0f};
        color[i] = {0.0f, 0.0f, 0.0f, 0.0f};
    }
    position = {0.0f, 0.0f};
}

/*SHAPE_IMAGE::SHAPE_IMAGE(SHAPE_SQUARE _square, GLuint _texture, VECTOR2D _texCoord[4]) {
    square = _square;
    texture = _texture;
    for (int i = 0; i < 4; i++) {
        texCoord[i] = _texCoord[i];
    }
}*/