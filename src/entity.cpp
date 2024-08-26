#include "rendering_engine/entity.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

Entity::Entity(const shared_ptr<Mesh> mesh, const shared_ptr<Shader> shader) : Entity(mesh, shader, std::vector<std::shared_ptr<Texture>>{})
{
}

Entity::Entity(const shared_ptr<Mesh> mesh, const shared_ptr<Shader> shader, const vector<shared_ptr<Texture>> &textures) : Container(), mesh_(mesh), shader_(shader), textures_(textures)
{
}

Entity::~Entity()
{
}
void Entity::Render()
{
    unsigned int index = GL_TEXTURE0;
    for (auto texture : textures_)
    {
        glActiveTexture(index);
        texture->Bind();
        index++;
    }

    shader_->Use();
    mesh_->Bind();
    mesh_->Draw();

    for (auto child : children)
    {
        child->Render(); 
    }
}