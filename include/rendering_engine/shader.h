#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>
#include <rendering_engine/uniformGroup.h>
#include <memory>
#include <functional>

using namespace std;

class Shader
{
private:
    void Load();
    void CompileShader();
    unsigned id_;
    const char *vertexPath_, *fragmentPath_;
    const char *vShaderCode_, *fShaderCode_;
    string vertexCode;
    string fragmentCode;
    std::unordered_map<std::string, unsigned int> uniforms_;
    shared_ptr<UniformGroup> uniformGroup_;

public:
    Shader(const char *vertexPath, const char *fragmentPath);
    Shader(const char *vertexPath, const char *fragmentPath, shared_ptr<UniformGroup> &uniformGroup);
    ~Shader();

    void Use() const;
    void SetBool(const string &name, bool value) const;
    void SetInt(const string &name, int value) const;
    void SetFloat(const string &name, float value) const;
    void SetMat4(const string &name, glm::mat4 value) const;
    void ExtractUniforms();
     std::unordered_map<std::string, unsigned int> &GetUniforms();
     std::unordered_map<std::string, UniformSetter> &GetUniformGroup();
};
