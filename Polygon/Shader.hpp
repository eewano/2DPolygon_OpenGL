#ifndef Shader_hpp
#define Shader_hpp

#include <GLFW/glfw3.h>

class Shader
{
public:
    Shader();
    ~Shader();
    
public:
    GLuint program;
    GLint vpos_location;
    GLint mvp_location;
    GLint vcol_location;
    
    static const char* ID_position;
    static const char* ID_MVP;
    static const char* ID_color;
    
public:
    void SetUp();
};

#endif /* Shader_hpp */
