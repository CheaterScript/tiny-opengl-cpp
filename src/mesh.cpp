#include "rendering_engine/mesh.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>

void Mesh::SetupMesh()
{

    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);
    glGenBuffers(1, &ebo_);

    glBindVertexArray(vao_);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, vertices_->size() * sizeof(float), vertices_->data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_->size() * sizeof(unsigned int), indices_->data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
}

Mesh::Mesh(const vector<float> &vertices, const vector<unsigned int> &indices) : vertices_(make_shared<vector<float>>(vertices)), indices_(make_shared<vector<unsigned int>>(indices))
{
    SetupMesh();
}

Mesh::~Mesh()
{

    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &ebo_);
    glDeleteVertexArrays(1, &vao_);
}

void Mesh::Bind() const
{
    glBindVertexArray(vao_);
}

void Mesh::Unbind() const
{
    glBindVertexArray(0);
}

void Mesh::Draw() const
{
    glDrawElements(GL_TRIANGLES, indices_->size(), GL_UNSIGNED_INT, 0);
}
