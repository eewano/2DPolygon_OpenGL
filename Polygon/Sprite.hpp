#ifndef Sprite_h
#define Sprite_h

#include <iostream>
#include <GLFW/glfw3.h>
#include <linmath.h>
#include "Define.hpp"
#include "Shader.hpp"

extern Shader shader;

template<int VERTS_COUNT>
class Sprite
{
public:
    Sprite(){}
    ~Sprite(){}
    
public:
    void Draw(GLint gl, GLuint vertex_buffer, GLint rotateDir)
    {
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(polygon), polygon, GL_STATIC_DRAW);
        
        mat4x4_identity(m);
        mat4x4_translate_in_place(m, pos.x, pos.y, 0);
        mat4x4_rotate_Z(m, m, (float)glfwGetTime() * rotateDir);
        mat4x4_ortho(p, -ASPECT_RATIO, ASPECT_RATIO, -1.0f, 1.0f, 1.0f, -1.0f);
        mat4x4_mul(mvp, p, m);
        
        glVertexAttribPointer(shader.vpos_location, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
        glVertexAttribPointer(shader.vcol_location, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 2));
        
        glUniformMatrix4fv(shader.mvp_location, 1, GL_FALSE, (const GLfloat*)mvp);
        glDrawArrays(gl, 0, VERTS_COUNT);
    }
    
public:
    Vec2f pos{};
    Vertex polygon[VERTS_COUNT]{};
    
private:
    mat4x4 m, p, mvp;
};

#endif /* Sprite_h */
