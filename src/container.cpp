#include "rendering_engine/container.h"

#include <iostream>

Container::Container()
{
}

void Container::RemoveAllChildren()

{
    children.clear();
}

void Container::AddChild(const std::shared_ptr<Container> &child)
{
    children.push_back(child);
    child->parent = shared_from_this();
}

void Container::Render(RenderingContext &renderingContext)
{
    Update(renderingContext.deltaTime);

    for (auto child : children)
    {
        child->Render(renderingContext);
    }
}

void Container::setTransform(const glm::mat4 &transform)
{
    worldTransform_ = transform;
}

const glm::mat4 &Container::getWorldTransform()
{
    UpdateTransform();
    return worldTransform_;
}

void Container::UpdateTransform()
{
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, location);
    glm::quat quaternion = glm::quat(glm::radians(rotation));
    glm::mat4 rotationMatrix = glm::mat4_cast(quaternion);
    trans = trans * rotationMatrix;
    trans = glm::scale(trans, scale);

    setTransform(trans);
}