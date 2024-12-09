#ifndef APP_TYPES_H
#define APP_TYPES_H

#include <GL/gl.h>

#define APP_TRUE 1
#define APP_FALSE 0

#define BLEND_ON 1
#define BLEND_OFF 0

typedef unsigned int uint;
typedef const char c_char;

class VECTOR2D {
public:
    float x, y;
};

class COLOR {
public:
    float r, g, b, a;
};





class SHAPE_SQUARE {
public:
    VECTOR2D vertices[4] = {
        { 0.0f,  0.0f  },
        { 10.0f, 0.0f  },
        { 10.0f, 10.0f },
        { 0.0f,  10.0f }
    };
    COLOR    color[4];
    VECTOR2D position;

    VECTOR2D scale = {1.0f, 1.0f};

    VECTOR2D get_position(int id);
    void update_scale(VECTOR2D scale);

    SHAPE_SQUARE(COLOR _color[4], VECTOR2D _position);
    SHAPE_SQUARE();
};

class SHAPE_IMAGE {
public:
    SHAPE_SQUARE square;
    GLuint texture;
    VECTOR2D texCoord[4] = {
        {0.0f, 1.0f},
        {1.0f, 1.0f},
        {1.0f, 0.0f},
        {0.0f, 0.0f}
    };
};

class COLORS {
public:
    COLOR WHITE       = {1.0f, 1.0f, 1.0f, 1.0f};
    COLOR BLACK       = {0.0f, 0.0f, 0.0f, 1.0f};
    COLOR RED         = {1.0f, 0.0f, 0.0f, 1.0f};
    COLOR GREEN       = {0.0f, 1.0f, 0.0f, 1.0f};
    COLOR BLUE        = {0.0f, 0.0f, 1.0f, 1.0f};
    COLOR YELLOW      = {1.0f, 1.0f, 0.0f, 1.0f};
    COLOR CYAN        = {0.0f, 1.0f, 1.0f, 1.0f};
    COLOR MAGENTA     = {1.0f, 0.0f, 1.0f, 1.0f};
    COLOR ORANGE      = {1.0f, 0.5f, 0.0f, 1.0f};
    COLOR PURPLE      = {0.5f, 0.0f, 0.5f, 1.0f};
    COLOR BROWN       = {0.5f, 0.25f, 0.0f, 1.0f};
    COLOR GRAY        = {0.5f, 0.5f, 0.5f, 1.0f};
    COLOR TRANSPARENT = {0.0f, 0.0f, 0.0f, 0.0f};
};

#endif  // APP_TYPES_H