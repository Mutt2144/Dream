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
    VECTOR2D vertices[4];
    COLOR    color[4];
    VECTOR2D position;

    VECTOR2D get_position(int id);

    SHAPE_SQUARE(VECTOR2D _vertices[4], COLOR _color[4], VECTOR2D _position);
    SHAPE_SQUARE();
};

class SHAPE_IMAGE {
public:
    SHAPE_SQUARE square;
    GLuint texture;
    VECTOR2D texCoord[4];
};

#endif  // APP_TYPES_H