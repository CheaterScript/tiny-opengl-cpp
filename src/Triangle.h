#include "mesh/Mesh.h"
#include "shader/Shader.h"
#include "texture/Texture.h"

class Triangle : public Mesh
{
private:
    /* data */
public:
    Triangle(Shader *shader);
    Triangle(Shader *shader, Texture *texture);
    void init() override;
    void draw() const override;
};