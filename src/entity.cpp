#include "rendering_engine/entity.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

Entity::Entity(const shared_ptr<Mesh> mesh, const shared_ptr<Shader> shader) : Entity(mesh, shader, std::vector<std::shared_ptr<Texture>>{})
{
}

Entity::Entity(const shared_ptr<Mesh> mesh, const shared_ptr<Shader> shader, const vector<shared_ptr<Texture>> &textures) : Container(), mesh_(mesh), shader_(shader), textures_(textures)
{
    transform_ = glm::mat4(1.0f);
}

Entity::~Entity()
{
}
void Entity::Render()
{
    shader_->Use();
    shader_->SetMat4("transform", transform_);
    unsigned int index = GL_TEXTURE0;
    for (auto texture : textures_)
    {
        glActiveTexture(index);
        texture->Bind();
        if (texture->getUniformName() != "")
        {
            shader_->SetInt(texture->getUniformName(), index - GL_TEXTURE0);
        }
        index++;
    }
    mesh_->Bind();
    mesh_->Draw();

    for (auto child : children)
    {
        child->Render();
    }
}

void Entity::setTransform(const glm::mat4 &transform)
{
    transform_ = transform;
}