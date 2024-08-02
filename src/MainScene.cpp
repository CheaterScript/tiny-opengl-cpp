#include "MainScene.h"
#include "Triangle.h"

MainScene::MainScene() : Scene()
{
    const Mesh *mesh = new Triangle();

    this->addChild(*mesh);
}