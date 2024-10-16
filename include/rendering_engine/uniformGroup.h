#pragma once

#include <memory>
#include <string>
#include <functional>
#include <variant>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>
#include <rendering_engine/renderingContext.h>

class Entity;

using UniformVariant = std::variant<float, glm::mat4, glm::vec3>;
using UniformSetter = std::function<UniformVariant(RenderingContext &, Entity *)>;

class UniformGroup
{
private:
    /* data */
    std::unordered_map<std::string, UniformSetter> uniforms_;

public:
    UniformGroup(/* args */) = default;
    ~UniformGroup() = default;

public:
    static std::shared_ptr<UniformGroup> GetDefaultUniformGroup()
    {
        auto group = std::make_shared<UniformGroup>();
        return group;
    }

    void Register(std::string name, UniformSetter setter)
    {
        uniforms_[name] = setter;
    }

    std::unordered_map<std::string, UniformSetter> &GetUniforms()
    {
        return uniforms_;
    }
};