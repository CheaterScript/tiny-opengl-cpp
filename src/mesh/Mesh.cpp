#include "Mesh.h"
#include "stdio.h"

Mesh::Mesh(Shader *shader)
{
    this->shader = shader;
}

Mesh::Mesh(Shader *shader, Texture *texture) : Mesh(shader)
{
    this->addTexture(texture);
}

void Mesh::load()
{
}

void Mesh::init()
{
}

void Mesh::draw() const
{
}

void Mesh::addTexture(Texture *texture)
{
    this->textures.push_back(texture);
}
