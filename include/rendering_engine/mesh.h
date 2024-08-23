#pragma once

#include <vector>
#include <memory>

using namespace std;

class Mesh
{
private:
    void SetupMesh();

    unsigned int vao_, vbo_, ebo_;
    const shared_ptr<vector<float>> vertices_;
    const shared_ptr<vector<unsigned int>> indices_;
public:
    Mesh(const vector<float>& vertices, const vector<unsigned int>& indices);
    ~Mesh();

    void Bind() const;
    void Unbind() const;
    void Draw() const;
};