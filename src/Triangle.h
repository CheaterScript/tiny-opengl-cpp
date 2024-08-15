#include "core/mesh/Mesh.h"
#include "core/shader/Shader.h"
#include "core/texture/Texture.h"

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