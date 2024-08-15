#include "Scene.h"
#include <algorithm>

const Mesh *Scene::addChild(const Mesh &mesh)
{
    if (std::find(meshes.begin(), meshes.end(), &mesh) != meshes.end())
    {
        return nullptr;
    }

    meshes.push_back(&mesh);
    return &mesh;
}

const Mesh *Scene::removeChild(const Mesh &mesh)
{
    meshes.erase(std::remove(meshes.begin(), meshes.end(), &mesh), meshes.end());

    return &mesh;
}

std::vector<const Mesh *> Scene::getChildren()
{
    return meshes;
}

void Scene::draw()
{
    for (auto iter = meshes.begin(); iter != meshes.end();iter++)
    {
        (*iter)->draw();
    }
}
