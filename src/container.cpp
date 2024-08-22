#include "rendering_engine/container.h"

Container::Container()
{
}

void Container::RemoveAllChildren()

{
    children.clear();
}

void Container::AddChild(std::shared_ptr<Container> child)
{
    children.push_back(child);
}

void Container::Render()
{
    for (auto child : children)
    {
        child->Render();
    }
}