#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>
#include <rendering_engine/application.h>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    Application *app = new Application(SCR_WIDTH, SCR_HEIGHT, "LearningOpenGL");
    app->run();
    return 0;
}
