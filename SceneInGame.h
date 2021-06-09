#pragma once
#include "Scene.h"
#include "tigl.h"
#include "FpsCam.h"
#include "Texture.h"

class SceneInGame :
    public Scene
{
private:
    
    /*tigl::VBO* kubusVbo;
    float time;
    int menuIndex;*/

    Texture* textureSkybox[6];

public:
    SceneInGame();
    ~SceneInGame();
    void initSkyboxTextures();
    virtual void draw() override;
    virtual void update() override;
    virtual void onKey(int key, int scancode, int action, int mods) override;
};

