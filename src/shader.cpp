#include "rendering_engine/shader.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>

void Shader::Load()
{
    ifstream vShaderFile;
    ifstream fShaderFile;
    vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    try
    {
        vShaderFile.open(vertexPath_);
        fShaderFile.open(fragmentPath_);
        stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (ifstream::failure e)
    {
        cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    vShaderCode_ = vertexCode.c_str();
    fShaderCode_ = fragmentCode.c_str();
}

void Shader::CompileShader()
{
    unsigned int vertex, fragment;
    int bIsSuccess;
    char errorInfo[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode_, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &bIsSuccess);
    if (!bIsSuccess)
    {
        glGetShaderInfoLog(vertex, 512, NULL, &errorInfo[0]);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << errorInfo << std::endl;
        throw std::runtime_error("Shader has errors!");
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode_, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &bIsSuccess);
    if (!bIsSuccess)
    {
        glGetShaderInfoLog(fragment, 512, NULL, errorInfo);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << errorInfo << std::endl;
        throw std::runtime_error("Shader has errors!");
    }

    id_ = glCreateProgram();
    glAttachShader(id_, vertex);
    glAttachShader(id_, fragment);
    glLinkProgram(id_);

    glGetProgramiv(id_, GL_LINK_STATUS, &bIsSuccess);
    if (!bIsSuccess)
    {
        glGetProgramInfoLog(id_, 512, NULL, errorInfo);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << errorInfo << std::endl;
        throw std::runtime_error("Shader has errors!");
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::Shader(const char *vertexPath, const char *fragmentPath) : vertexPath_(vertexPath), fragmentPath_(fragmentPath)
{
    Load();
    CompileShader();
}

Shader::~Shader()
{
    glDeleteProgram(id_);
}

void Shader::Use() const
{
    glUseProgram(id_);
}

void Shader::SetBool(const string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(id_, name.c_str()), (int)value);
}
void Shader::SetInt(const string &name, int value) const
{
    glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}
void Shader::SetFloat(const string &name, float value) const
{
    glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}
void Shader::SetMat4(const string &name, glm::mat4 value) const
{
    glUniformMatrix4fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}