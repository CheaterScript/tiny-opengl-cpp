#pragma once

#include <rendering_engine/container.h>
#include "rendering_engine/mesh.h"
#include "rendering_engine/entity.h"

using namespace std;

class MainScene: public Container
{
private:
    /* data */
     shared_ptr<Entity> box;
public:
    MainScene(/* args */);
    ~MainScene();

    void Init();
    void Update() override;
};