#include "mainScene.h"

#include <vector>
#include "rendering_engine/shader.h"
#include "rendering_engine/texture.h"
#include "rendering_engine/uniformGroup.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <glfw/glfw3.h>

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::Init(Application *app)
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
    shared_ptr<UniformGroup> uniforms = UniformGroup::GetDefaultUniformGroup();
    uniforms->Register("u_lightPosition", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                       { return glm::vec3(5.0, 5.0, 0.0); });
    uniforms->Register("u_lightColor", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                       { return glm::vec3(0.11, 0.91, 0.41); });
    uniforms->Register("u_ambientStrength", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                       { return 0.3f; });
    uniforms->Register("u_normalMatrix", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                       { return glm::inverse(glm::transpose(entity->getWorldTransform())); });
    uniforms->Register("u_cameraPosition", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                       { return glm::vec3(0, 0, 15.0f); });
    uniforms->Register("u_specularStrength", [](RenderingContext &renderingContext, Entity *entity) -> UniformVariant
                       { return 0.5f; });
    shared_ptr<Shader>
        shader = make_shared<Shader>("assets/shaders/demo016/vShader.glsl", "assets/shaders/demo016/fShader.glsl", uniforms);

    vector<shared_ptr<Texture>> *const textures = new vector<shared_ptr<Texture>>();
    box_ = make_shared<Entity>(mesh, shader, *textures);
    box2_ = make_shared<Entity>(mesh, shader, *textures);
    AddChild(box_);
    AddChild(box2_);

    camera_ = make_shared<Camera>();
    camera_->location = glm::vec3(0, 0, 15.0f);
    AddChild(camera_);
    app->setMainCamera(camera_);

    app->eventManager.AddListener(EventType::KeyEvent, [](Event *event)
                                  { KeyEvent *keyEvent = static_cast<KeyEvent *>(event);
                                  cout << keyEvent->keyCode << "----" <<  keyEvent->action << endl; });

    delete textures;
}

void MainScene::Update(float deltaTime)
{

    glm::mat4 trans = glm::mat4(1.0f);
    box_->rotation = glm::vec3((float)glfwGetTime() * 50, (float)glfwGetTime() * 50, (float)glfwGetTime() * 50);
    box_->scale = glm::vec3(5.0f);

    box2_->location = glm::vec3(1, 0, -0.5);
    box2_->scale = glm::vec3(0.2f);
    box2_->rotation = glm::vec3((float)glfwGetTime() * -50, (float)glfwGetTime() * 50, (float)glfwGetTime() * 50);

    // cout << sin((float)glfwGetTime()) << endl;
    // camera_->location = glm::vec3(0, 0, 5);
    // camera_->rotation = glm::vec3(sin((float)glfwGetTime()) * 15, 0, 0);
}
