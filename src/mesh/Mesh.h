#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../shader/Shader.h"
#include "../texture/Texture.h"
#include <vector>

using namespace std;

class Mesh
{
public:
    Mesh(Shader *shader);
    Mesh(Shader *shader, Texture *texture);
    unsigned int VAO, VBO, EBO;
    Shader *shader;
    vector<Texture *> textures;

    void load();
    virtual void init();
    virtual void draw() const;
    void addTexture(Texture *texture);
};