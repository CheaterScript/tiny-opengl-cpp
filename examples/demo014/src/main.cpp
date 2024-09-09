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
    auto *app = new Application(SCR_WIDTH, SCR_HEIGHT, "LearningOpenGL");
    // app->ShowMouseCursor(false);
    app->eventManager.AddListener(EventType::MouseEvent, [](Event *event)
                                  { MouseEvent *mouseEvent = static_cast<MouseEvent *>(event);
                                  cout << mouseEvent->x<<endl; });
    auto mainScene = make_shared<MainScene>();
    mainScene->Init(app);
    app->getScene().AddChild(mainScene);
    app->Run();
    return 0;
}
