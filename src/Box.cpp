#include "Box.h"

Box::Box(Shader *shader) : Mesh(shader)
{
    init();
}

Box::Box(Shader *shader, Texture *texture) : Mesh(shader, texture)
{
    init();
}

void Box::init()
{
}

void Box::draw() const
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    
}
