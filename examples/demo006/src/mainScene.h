#pragma once

#include <rendering_engine/container.h>

using namespace std;

class MainScene: public Container
{
private:
    /* data */
public:
    MainScene(/* args */);
    ~MainScene();

    void Init();
};