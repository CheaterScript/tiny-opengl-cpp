#pragma once

class Texture
{
private:
    /* data */
public:
    Texture(const char *imagePath);

    unsigned int ID;

    void use();
    void use(int index);
};
