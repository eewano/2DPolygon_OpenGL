#include "Shader.hpp"
#include <iostream>

const char* Shader::ID_MVP = "MVP";
const char* Shader::ID_position = "vPos";
const char* Shader::ID_color = "vCol";

Shader::Shader()
{
}

Shader::~Shader()
{
}

void Shader::SetUp()
{
    auto vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    static const char* vertex_shader_text = R"#(
    uniform mat4 MVP;
    attribute vec3 vCol;
    attribute vec2 vPos;
    varying vec3 color;
    void main(void){
        gl_Position = MVP * vec4(vPos, 0.0, 1.0);
        color = vCol;
    }
    )#";
    glShaderSource(vertex_shader, 1, &vertex_shader_text, nullptr);
    glCompileShader(vertex_shader);
    
    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    static const char* fragment_shader_text = R"#(
    varying vec3 color;
    void main(void){
        gl_FragColor = vec4(color, 1.0);
    }
    )#";
    glShaderSource(fragment_shader, 1, &fragment_shader_text, nullptr);
    glCompileShader(fragment_shader);
    
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    glUseProgram(program);
    
    mvp_location = glGetUniformLocation(program, ID_MVP);
    vpos_location = glGetAttribLocation(program, ID_position);
    vcol_location = glGetAttribLocation(program, ID_color);
    
    glEnableVertexAttribArray(vpos_location);
    glEnableVertexAttribArray(vcol_location);
}
