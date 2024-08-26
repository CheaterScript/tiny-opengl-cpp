#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "rendering_engine/texture.h"
#include <glad/glad.h>

Texture::Texture(const string &path) : Texture(path, NULL)
{
}

Texture::Texture(const string &path, const string &uniformName) : path_(path), uniformName_(uniformName)
{
        Load();
}
Texture::~Texture()
{
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, id_);
}

const std::string &Texture::getUniformName() const
{
    return uniformName_;
}

void Texture::Load()
{
    glGenTextures(1, &id_);
    glBindTexture(GL_TEXTURE_2D, id_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(path_.c_str(), &width, &height, &nrChannels, 0);

    if (!data)
    {
        std::cout << "Failed to load texture" << std::endl;
        stbi_image_free(data);
    }

    unsigned int format;
    switch (nrChannels)
    {
    case 1:
        format = GL_RED;
        break;
    case 3:
        format = GL_RGB;
        break;
    case 4:
        format = GL_RGBA;
        break;

    default:
        format = GL_RGB;
        break;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}