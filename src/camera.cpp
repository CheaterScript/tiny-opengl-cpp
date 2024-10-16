#include "rendering_engine/camera.h"

Camera::Camera() : Entity()
{
}

Camera::~Camera()
{
}

const glm::mat4 Camera::GetViewMatrix() const
{
    glm::quat quaternion = glm::quat(glm::radians(rotation));
    glm::mat4 rotationMatrix = glm::mat4_cast(quaternion);
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), -location);

    auto viewMatrix = rotationMatrix * translationMatrix;

    return viewMatrix;
}

const glm::mat4 Camera::GetProjectionMatrix() const
{
    return glm::perspective(glm::radians(fov), aspectRatio, near, far);
}

void Camera::Render(RenderingContext &renderingContext)
{
}
