#pragma once

#include "rendering_engine/renderingContext.h"
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Container : public std::enable_shared_from_this<Container>
{
protected:
    std::vector<std::shared_ptr<Container>> children;
    glm::mat4 worldTransform_;

    void UpdateTransform();

public:
    Container(/* args */);
    virtual ~Container() = default;

    glm::vec3 location;
    glm::vec3 rotation;
    glm::vec3 scale;

    std::shared_ptr<Container> parent;

    void RemoveAllChildren();
    void AddChild(const std::shared_ptr<Container> &child);
    virtual void Render(RenderingContext &renderingContext);
    virtual void Update(float deltaTime) {};

    void setTransform(const glm::mat4 &transform);
    const glm::mat4 &getWorldTransform();
};