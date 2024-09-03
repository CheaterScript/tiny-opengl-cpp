#include "rendering_engine/camera.h"

Camera::Camera() : Entity()
{
}

Camera::~Camera()
{
}

const glm::mat4 Camera::GetViewMatrix() const
{
    glm::vec3 position;
    if (location == glm::vec3(0.0f, 0.0f, 0.0f))
    {
        position = glm::vec3(0.0f, 0.0f, 1.0f);
    }
    else
    {
        position = location;
    }
    auto origin = glm::vec3(0.0f, 0.0f, 0.0f);
    auto front = glm::normalize(origin - position);
    auto worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    auto right = glm::normalize(glm::cross(front, worldUp));
    auto up = glm::normalize(glm::cross(front, right));

    auto result = glm::mat4(1.0f);

    result[0][0] = right.x;
    result[1][0] = right.y;
    result[2][0] = right.z;
    result[0][1] = up.x;
    result[1][1] = up.y;
    result[2][1] = up.z;
    result[0][2] = -front.x;
    result[1][2] = -front.y;
    result[2][2] = -front.z;
    result[3][0] = -glm::dot(right, location);
    result[3][1] = -glm::dot(up, location);
    result[3][2] = glm::dot(front, location);

    return result;
}

const glm::mat4 Camera::GetProjectionMatrix() const
{
    return glm::mat4(1.0f);
}

void Camera::Render()
{
}
