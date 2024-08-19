#pragma once

#include <string>

using namespace std;

class Shader
{
private:
    void Load();
    void CompileShader();
    unsigned id_;
    const char *vertexPath_, *fragmentPath_;
    const char *vShaderCode_, *fShaderCode_;

public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();

    void Use() const;
    void SetBool(const string &name, bool value) const;
    void SetInt(const string &name, int value) const;
    void SetFloat(const string &name, float value) const;
};
