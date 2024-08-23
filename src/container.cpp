#include "rendering_engine/container.h"

#include <iostream>

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
    Update();

    for (auto child : children)
    {
        child->Render();
    }
}