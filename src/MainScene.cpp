#include "MainScene.h"
#include "Triangle.h"
#include "shader/Shader.h"
#include <iostream>
#include "texture/Texture.h"

MainScene::MainScene() : Scene()
{

    Texture *texture1 = new Texture("assets/images/container.jpg");
    Texture *texture2 = new Texture("assets/images/awesomeface.png");

    Shader *shader = new Shader("assets/shaders/vertex.vs", "assets/shaders/fragment.fs");

    Mesh *mesh = new Triangle(shader, texture1);
    mesh->addTexture(texture2);
    this->addChild(*mesh);

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
}