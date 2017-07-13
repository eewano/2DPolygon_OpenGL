#include <iostream>
#include <glad/glad.h>
#include <glad/glad.c>
#include <GLFW/glfw3.h>
#include <linmath.h>
#include "Define.hpp"
#include "Triangle.hpp"
#include "Cube.hpp"
#include "Shader.hpp"
#include "Circle.hpp"

Shader shader;

void ErrorCallback(int error, const char* description);

int main(int argc, const char * argv[]) {
    
    GLuint vertex_buffer[V_BUFFER_SIZE];
    
    if(!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    GLFWwindow* window = glfwCreateWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Sample", NULL, NULL);
    
    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    auto triangle01 = std::make_unique<Triangle>(Vec2f{ -0.8f, 0.0f });
    auto triangle02 = std::make_unique<Triangle>(Vec2f{ +0.8f, 0.0f });
    auto cube01 = std::make_unique<Cube>(Vec2f{ 0.0f, -0.3f });
    auto circle01 = std::make_unique<Circle>(Vec2f{ 0.0f, 0.3f });
    
    glfwSetErrorCallback(ErrorCallback);
    
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);
    
    shader.SetUp();
    
    glGenBuffers(V_BUFFER_SIZE, vertex_buffer);
    
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        triangle01->Draw(GL_TRIANGLES, vertex_buffer[0], 2);
        triangle02->Draw(GL_TRIANGLES, vertex_buffer[1], -1);
        cube01->Draw(GL_QUADS, vertex_buffer[2], -5);
        circle01->Draw(GL_TRIANGLE_FAN, vertex_buffer[3], 0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}

void ErrorCallback(int error, const char* description)
{
    std::cerr << "error: " << description << "\n";
}
