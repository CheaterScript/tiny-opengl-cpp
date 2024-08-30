#include "rendering_engine/camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

const glm::mat4 Camera::GetViewMatrix() const
{
    return glm::mat4(1.0f);
}

const glm::mat4 Camera::GetProjectionMatrix() const
{
    return glm::mat4(1.0f);
}

void Camera::Render()
{
}
