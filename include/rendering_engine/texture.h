#pragma once

#include <string>
#include <iostream>

using namespace std;

class Texture
{
private:
    unsigned int id_;
    const string path_;

    void Load();
public:
    Texture(const string &path);
    ~Texture();

    void Bind() const;
};