#include "../include/types.h"

VECTOR2D SHAPE_SQUARE::get_position(int id) {
    return {  vertices[id].x + position.x,
                vertices[id].y + position.y };
}

void SHAPE_SQUARE::update_scale(VECTOR2D scale) {
    this->scale = scale;

    vertices[0] = { vertices[0].x * -scale.x, vertices[0].y * -scale.y };
    vertices[1] = { vertices[1].x *  scale.x, vertices[1].y * -scale.y };
    vertices[2] = { vertices[2].x *  scale.x, vertices[2].y *  scale.y };
    vertices[3] = { vertices[3].x * -scale.x, vertices[3].y *  scale.y };
}

SHAPE_SQUARE::SHAPE_SQUARE(COLOR _color[4], VECTOR2D _position) {
    for (int i = 0; i < 4; i++) {
        color[i] = _color[i];
    }
    position = _position;
}

SHAPE_SQUARE::SHAPE_SQUARE() {
    for (int i = 0; i < 4; i++) {
        color[i] = {0.0f, 0.0f, 0.0f, 0.0f};
    }
    position = {0.0f, 0.0f};
}

