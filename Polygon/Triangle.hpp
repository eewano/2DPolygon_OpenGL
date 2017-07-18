#ifndef Triangle_hpp
#define Triangle_hpp

#include <iostream>
#include <GLFW/glfw3.h>
#include "Vec2.hpp"
#include "Define.hpp"
#include "Shader.hpp"
#include "Sprite.hpp"

static constexpr int TRIANGLE_VERTS_COUNT = 3;

class Triangle : public Sprite<TRIANGLE_VERTS_COUNT>
{
public:
    Triangle();
    Triangle(Vec2f aPos);
    
    ~Triangle();
};

#endif /* Triangle_hpp */
