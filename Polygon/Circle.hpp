#ifndef Circle_hpp
#define Circle_hpp

#include <iostream>
#include <GLFW/glfw3.h>
#include "Define.hpp"
#include "Shader.hpp"
#include "Sprite.hpp"

static constexpr int CIRCLE_DIVISION = 32;

class Circle : public Sprite<CIRCLE_DIVISION>
{
public:
    Circle();
    Circle(Vec2f aPos);
    
    ~Circle();
};

#endif /* Circle_hpp */
