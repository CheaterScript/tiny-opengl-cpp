#include "rendering_engine/entity.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

Entity::Entity(const Mesh &mesh, const Shader &shader, const Texture &texture) : Container(), mesh_(make_shared<Mesh>(mesh)), shader_(make_shared<Shader>(shader)), texture_(make_shared<Texture>(texture))
{
}

void Entity::Render()
{
    glActiveTexture(GL_TEXTURE0);
    texture_->Bind();
    shader_->Use();
    mesh_->Bind();
    mesh_->Draw();
    mesh_->Unbind();

    Container::Render();
}