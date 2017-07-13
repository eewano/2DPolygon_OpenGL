#include "Circle.hpp"

Circle::Circle()
{
}

Circle::Circle(Vec2f aPos)
{
    const float radius = 0.2;
    
    for(int i = 0; i < CIRCLE_DIVISION; i++)
    {
        float angle = static_cast<float>(PI * 2.0 * i) / CIRCLE_DIVISION;
        polygon[i].x = radius * cos(angle);
        polygon[i].y = radius * sin(angle);
        polygon[i].r = 1.0f;
        polygon[i].g = 0.0f;
        polygon[i].b = 1.0f;
    }
    
    pos = aPos;
}

Circle::~Circle()
{
}
