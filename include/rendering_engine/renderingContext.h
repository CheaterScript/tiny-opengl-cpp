#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct RenderingContext
{
public:
    glm::mat4 viewMatrial = glm::mat4(1.0f);
    glm::mat4 projectionMatrial = glm::mat4(1.0f);
};
