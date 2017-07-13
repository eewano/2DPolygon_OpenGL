#include "Triangle.hpp"

Triangle::Triangle()
{
}

Triangle::Triangle(Vec2f aPos)
{
    polygon[0] = { -0.3f, -0.2f, 1.0f, 0.0f, 0.0f };
    polygon[1] = { 0.3f, -0.2f, 0.0f, 1.0f, 0.0f };
    polygon[2] = { 0.f, 0.3f, 0.0f, 0.0f, 1.0f };
    
    pos = aPos;
}

Triangle::~Triangle()
{
}
