#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh
{
public:
    Mesh();
    unsigned int VAO, VBO, EBO;
    unsigned int shaderProgram;

    void load();
    virtual void init();
    virtual void draw() const;
};