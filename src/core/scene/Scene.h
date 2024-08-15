#pragma once
#include <vector>
#include "../mesh/Mesh.h"

using namespace std;

class Scene
{
private:
    vector<const Mesh *> meshes;

public:
    const Mesh *addChild(const Mesh &mesh);
    const Mesh *removeChild(const Mesh &mesh);
    vector<const Mesh *> getChildren();
    void draw();
};