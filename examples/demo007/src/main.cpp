#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>
#include <rendering_engine/application.h>
#include <memory>
#include "mainScene.h"

using namespace std;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    Application *app = new Application(SCR_WIDTH, SCR_HEIGHT, "LearningOpenGL");

    shared_ptr<MainScene> mainScene = make_shared<MainScene>();

    app->getScene().AddChild(mainScene);
    app->Run();
    return 0;
}
