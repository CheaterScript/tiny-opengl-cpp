#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
private:
    /* data */
public:
    Shader(char *vertexShader, char *fragmentShader);
    unsigned int shaderProgram;
};