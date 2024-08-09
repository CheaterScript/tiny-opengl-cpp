#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../shader/Shader.h"

class Mesh
{
public:
    Mesh(Shader* shader);
    unsigned int VAO, VBO, EBO;
    Shader* shader;

    void load();
    virtual void init();
    virtual void draw() const;
};