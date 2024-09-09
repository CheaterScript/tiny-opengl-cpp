#pragma once

#include "rendering_engine/entity.h"
#include "rendering_engine/renderingContext.h"

class Camera : public Entity
{
private:
    /* data */
public:
    Camera(/* args */);
    ~Camera();

    const glm::mat4 GetViewMatrix() const;
    const glm::mat4 GetProjectionMatrix() const;

    float fov = 45.0f;
    float aspectRatio = 8.0f/6.0f;
    float near = 0.1f;
    float far = 1000.0f;

    virtual void Render(RenderingContext renderingContext) override;
};