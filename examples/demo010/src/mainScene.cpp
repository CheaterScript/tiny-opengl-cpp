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
        //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 右上
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // 右下
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // 左下
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // 左上
    };

    vector<unsigned int> indices = {
        // 注意索引从0开始!
        // 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
        // 这样可以由下标代表顶点组合成矩形

        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };

    shared_ptr<Mesh> mesh = make_shared<Mesh>(vertices, indices);
    shared_ptr<Shader> shader = make_shared<Shader>("assets/shaders/transformVShader.glsl", "assets/shaders/transformFShader.glsl");
    shared_ptr<Texture> texture1 = make_shared<Texture>("assets/images/container.jpg", "texture1");
    shared_ptr<Texture> texture2 = make_shared<Texture>("assets/images/awesomeface.png", "texture2");

    vector<shared_ptr<Texture>> *const textures = new vector<shared_ptr<Texture>>();

    textures->push_back(texture1);
    textures->push_back(texture2);

    box = make_shared<Entity>(mesh, shader, *textures);
    AddChild(box);
}

void MainScene::Update()
{
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

    box->setTransform(trans);
}


