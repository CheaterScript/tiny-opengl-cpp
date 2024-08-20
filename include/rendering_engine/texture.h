#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
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