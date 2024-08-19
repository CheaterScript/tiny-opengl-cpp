#pragma once

using namespace std;

class Shader
{
private:
    void Load();

    unsigned id_;
    const char *vertexPath_, fragmentPath_;

public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();

    void use() const;
};