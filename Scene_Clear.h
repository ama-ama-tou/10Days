#pragma once
#include "Scene.h"
class Scene_Clear :
    public Scene {

private:
    
    //==================
    //�����o�ϐ�
    //==================

    //�N���A�摜
    Vec2 clearImagePos_[3];
    Vec2 clearImageSize;
    Vec2 clearImageVertex_[3][4];

    int GH_;
    int roagedGH_;
    
};

