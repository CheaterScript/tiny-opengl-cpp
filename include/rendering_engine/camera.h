#pragma once

#include "rendering_engine/entity.h"

class Camera : public Entity
{
private:
    /* data */
public:
    Camera(/* args */);
    ~Camera();

    const glm::mat4 &GetViewMatrix() const;
    const glm::mat4 &GetProjectionMatrix() const;

    virtual void Render() override;
};