#pragma once

#include <vector>
#include <glad/glad.h>

using namespace std;

class Mesh
{
private:
    void SetupMesh();

    unsigned int vao_, vbo_, veo_;
    const vector<float>& vertices_;
    const vector<unsigned int>& indices_;
public:
    Mesh(const vector<float>& vertices, const vector<unsigned int>& indices);
    ~Mesh();

    void Bind() const;
    void Unbind() const;
    void Draw() const;
};