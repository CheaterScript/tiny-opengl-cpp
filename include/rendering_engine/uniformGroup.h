#include <memory>
#include <string>
#include <functional>
#include <variant>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>


class UniformGroup
{
private:
    /* data */
    using UniformVariant =  std::variant<float,glm::mat4, glm::vec3>;
    std::unordered_map<std::string, std::function<UniformVariant()>> uniforms_;

public:
    UniformGroup(/* args */) = default;
    ~UniformGroup() = default;
public:
    static std::shared_ptr<UniformGroup> GetDefaultUniformGroup()
    {
        auto group = std::make_shared<UniformGroup>();
        return group;
    }  

    void Register(std::string name, std::function<UniformVariant()> setter)
    {
        uniforms_[name] = setter;
    }
};