#ifndef Cube_hpp
#define Cube_hpp

#include <iostream>
#include <GLFW/glfw3.h>
#include "Vec2.hpp"
#include "Define.hpp"
#include "Shader.hpp"
#include "Sprite.hpp"

static constexpr int QUAD_VERTS_COUNT = 4;

class Cube : public Sprite<QUAD_VERTS_COUNT>
{
public:
    Cube();
    Cube(Vec2f aPos);
    
    ~Cube();
};

#endif /* Cube_hpp */
