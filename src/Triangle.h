#include "mesh/Mesh.h"
#include "shader/Shader.h"

class Triangle : public Mesh
{
private:
    /* data */
public:
    Triangle(Shader *shader);
    void init() override;
    void draw() const override;
};