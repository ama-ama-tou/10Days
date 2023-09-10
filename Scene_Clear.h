#pragma once
#include "Scene.h"
class Scene_Clear :
    public Scene {

private:
    
    //==================
    //メンバ変数
    //==================

    //クリア画像
    Vec2 clearImagePos_[3];
    Vec2 clearImageSize;
    Vec2 clearImageVertex_[3][4];

    int GH_;
    int roagedGH_;
    
};

