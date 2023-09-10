#pragma once
#include "Scene.h"
class Scene_Clear :
    public Scene {

private:
    
    //==================
    //ƒƒ“ƒo•Ï”
    //==================

    //ƒNƒŠƒA‰æ‘œ
    Vec2 clearImagePos_[3];
    Vec2 clearImageSize;
    Vec2 clearImageVertex_[3][4];

    int GH_;
    int roagedGH_;
    
};

