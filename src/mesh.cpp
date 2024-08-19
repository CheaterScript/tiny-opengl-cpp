#include "rendering_engine/mesh.h"

#include <glfw/glfw3.h>

void Mesh::SetupMesh()
{
    glGenBuffers(1, &vbo_);
    glGenBuffers(1, &veo_);
    glGenVertexArrays(1, &vao_);

    glBindVertexArray(vao_);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(float), &vertices_[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, veo_);
    glBufferData(GL_ARRAY_BUFFER, indices_.size() * sizeof(unsigned int), &indices_[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

Mesh::Mesh(const vector<float> &vertices, const vector<unsigned int> &indices) : vertices_(vertices), indices_(indices)
{
    SetupMesh();
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &veo_);
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
    Bind();
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices_.size()), GL_UNSIGNED_INT, 0);
}
