#pragma once
#include "Scene.h"
#include "tigl.h"
#include "FpsCam.h"

class SceneIngame :
    public Scene
{
private:
    tigl::VBO* kubusVbo;

    float time;
    int menuIndex;

public:
    SceneIngame();
    virtual void draw() override;
    virtual void update() override;
    virtual void onKey(int key, int scancode, int action, int mods) override;
};

