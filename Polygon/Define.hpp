#ifndef Define_h
#define Define_h

#include "Vec2.hpp"

#define V_BUFFER_SIZE 4
#define PI 3.1415926
#define DEG2RAD 0.0174532925
#define ANGLE 180

struct Vertex
{
    float x, y;
    float r, g, b;
};

static Vec2i WINDOW_SIZE = { 800, 600 };
static float ASPECT_RATIO = static_cast<float>(WINDOW_SIZE.x) / WINDOW_SIZE.y;

#endif /* Define_h */
