#pragma once
class Mesh
{
public:
    char *shader;
    void load();
    virtual void draw() const;
};