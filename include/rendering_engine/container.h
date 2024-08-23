#pragma once

#include <vector>
#include <memory>

class Container
{
protected:
    std::vector<std::shared_ptr<Container>> children;

public:
    Container(/* args */);

    void RemoveAllChildren();
    void AddChild(std::shared_ptr<Container> child);
    virtual void Render();
    virtual void Update(){};
};