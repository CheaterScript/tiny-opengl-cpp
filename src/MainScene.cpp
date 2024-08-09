#include "MainScene.h"
#include "Triangle.h"
#include "shader/Shader.h"
#include <iostream>

MainScene::MainScene() : Scene()
{

    char *vertexShader = R"(#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
})";
    char *fragmentShader = R"(#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.8f, 0.2f, 1.0f);
} )";
    Shader *shader = new Shader(vertexShader, fragmentShader);

    char *vertexShader2 = R"(#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
})";
    char *fragmentShader2 = R"(#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0f, 0f, 1.0f);
} )";
    Shader *shader2 = new Shader(vertexShader2, fragmentShader2);

    Mesh *mesh = new Triangle(shader2);

    this->addChild(*mesh);

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
}