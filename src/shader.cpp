#include "rendering_engine/shader.h"

#include <string>


void Shader::Load()
{
}

Shader::Shader(const char *vertexPath, const char *fragmentPath): vertexPath_(vertexPath), fragmentPath_(fragmentPath_)
{
    Load();
}

Shader::~Shader()
{
}

void Shader::use() const
{
}
