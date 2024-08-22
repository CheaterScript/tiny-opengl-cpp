#pragma once

#include <rendering_engine/mesh.h>
#include <rendering_engine/shader.h>
#include <rendering_engine/texture.h>
#include <rendering_engine/Container.h>
#include <memory>

using namespace std;

class Entity: public Container
{
private:
    /* data */
    shared_ptr<Mesh> mesh_;
    shared_ptr<Shader> shader_;
    shared_ptr<Texture> texture_;

public:
    Entity(const Mesh& mesh, const Shader& shader, const Texture& texture);
    ~Entity();

    virtual void Render() override;
}; 