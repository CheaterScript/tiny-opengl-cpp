#include <memory>
#include <string>

class UniformGroup
{
private:
    /* data */
public:
    UniformGroup(/* args */) = default;
    ~UniformGroup() = default;
public:
    static std::shared_ptr<UniformGroup> GetDefaultUniformGroup()
    {
        auto group = std::make_shared<UniformGroup>();
    }

    template<typename T>
    void Register(std::string name, )
};