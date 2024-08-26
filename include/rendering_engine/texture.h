#pragma once

#include <string>
#include <iostream>

using namespace std;

class Texture
{
private:
    unsigned int id_;
    const string path_;
    const string uniformName_;
    void Load();

public:
    Texture(const string &path);
    Texture(const string &path, const string &uniformName);
    ~Texture();

    void Bind() const;
    const std::string &getUniformName() const;
};