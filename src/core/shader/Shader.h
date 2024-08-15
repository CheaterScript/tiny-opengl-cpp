#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Shader
{
private:
    /* data */
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    unsigned int ID;
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};