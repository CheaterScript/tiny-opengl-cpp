#pragma once

#include <rendering_engine/mesh.h>
#include <rendering_engine/shader.h>
#include <rendering_engine/texture.h>
#include <rendering_engine/Container.h>
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Entity : public Container
{
private:
    /* data */
    shared_ptr<Mesh> mesh_;
    shared_ptr<Shader> shader_;
    vector<shared_ptr<Texture>> textures_;
public:
    Entity(const shared_ptr<Mesh> mesh, const shared_ptr<Shader> shader);
    Entity(const shared_ptr<Mesh> mesh, const shared_ptr<Shader> shader, const vector<shared_ptr<Texture>> &textures_);
    ~Entity();

    virtual void Render() override;
};