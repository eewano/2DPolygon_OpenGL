#include "Cube.hpp"

Cube::Cube()
{
}

Cube::Cube(Vec2f aPos)
{
    polygon[0] = { -0.2f, 0.2f, 0.2f, 0.2f, 0.2f };
    polygon[1] = { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f };
    polygon[2] = { 0.2f, -0.2f, 0.8f, 0.8f, 0.8f };
    polygon[3] = { -0.2f, -0.2f, 0.8f, 0.8f, 0.8f };
    
    pos = aPos;
}

Cube::~Cube()
{
}
