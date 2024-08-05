#include "mesh/Mesh.h"

class Triangle : public Mesh
{
private:
    /* data */
public:
    Triangle();
    void init() override;
    void draw() const override;
};