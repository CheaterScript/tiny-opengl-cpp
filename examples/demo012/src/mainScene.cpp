#include "mainScene.h"

#include <vector>
#include "rendering_engine/shader.h"
#include "rendering_engine/texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <glfw/glfw3.h>

MainScene::MainScene()
{
    Init();
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
    vector<float> vertices = {
        // 前面
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // 0
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,  // 1
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,   // 2
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,  // 3

        // 后面
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, // 4
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,  // 5
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,   // 6
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,  // 7

        // 左面
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 8
        -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 9
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 10
        -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,  // 11

        // 右面
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 12
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // 13
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 14
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,  // 15

        // 上面
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,  // 16
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,   // 17
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,  // 18
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // 19

        // 下面
        -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, // 20
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,  // 21
        0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f, // 22
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f // 23
    };
    vector<unsigned int> indices = {
        // 前面
        0, 1, 2,
        2, 3, 0,
        // 后面
        4, 5, 6,
        6, 7, 4,
        // 左面
        8, 9, 10,
        10, 11, 8,
        // 右面
        12, 13, 14,
        14, 15, 12,
        // 上面
        16, 17, 18,
        18, 19, 16,
        // 下面
        20, 21, 22,
        22, 23, 20};

    shared_ptr<Mesh> mesh = make_shared<Mesh>(vertices, indices);
    shared_ptr<Shader> shader = make_shared<Shader>("assets/shaders/transformVShader.glsl", "assets/shaders/transformFShader.glsl");
    shared_ptr<Texture> texture1 = make_shared<Texture>("assets/images/container.jpg", "texture1");
    shared_ptr<Texture> texture2 = make_shared<Texture>("assets/images/awesomeface.png", "texture2");

    vector<shared_ptr<Texture>> *const textures = new vector<shared_ptr<Texture>>();

    textures->push_back(texture1);
    textures->push_back(texture2);

    box = make_shared<Entity>(mesh, shader, *textures);
    box2 = make_shared<Entity>(mesh, shader, *textures);
    AddChild(box);
    AddChild(box2);
}

void MainScene::Update()
{
    glm::mat4 trans = glm::mat4(1.0f);
    box->rotation = glm::vec3((float)glfwGetTime() * 50, (float)glfwGetTime() * 50, (float)glfwGetTime() * 50);
    box->scale = glm::vec3(0.5f);

    box2->location = glm::vec3(0.2,0,-1);
    box2->scale = glm::vec3(0.2f);
    box2->rotation = glm::vec3((float)glfwGetTime() * -50, (float)glfwGetTime() * 50, (float)glfwGetTime() * 50);
}
