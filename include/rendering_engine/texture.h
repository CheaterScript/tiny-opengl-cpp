#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <string>
#include <iostream>
#include <glad/glad.h>

using namespace std;

class Texture
{
private:
    unsigned int id_;
    const string path_;
public:
    Texture(const string &path);
    ~Texture();
};