#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "mesh/Mesh.h"
#include "shader/Shader.h"
#include "texture/Texture.h"

class Box : public Mesh
{
private:
    /* data */
public:
    Box(Shader *shader);
    Box(Shader *shader, Texture *texture);
    void init() override;
    void draw() const override;
};