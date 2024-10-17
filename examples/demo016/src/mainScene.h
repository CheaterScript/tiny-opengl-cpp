#pragma once

#include <rendering_engine/container.h>
#include "rendering_engine/mesh.h"
#include "rendering_engine/entity.h"
#include "rendering_engine/application.h"
#include "rendering_engine/camera.h"
#include "rendering_engine/uniformGroup.h"

using namespace std;

class MainScene : public Container
{
private:
    /* data */
    shared_ptr<Entity> box_;
    shared_ptr<Entity> box2_;
    shared_ptr<Camera> camera_;
    shared_ptr<UniformGroup> uniforms_;

public:
    MainScene(/* args */);
    ~MainScene();

    void Init(Application * app);
    void Update(float deltaTime) override;
};