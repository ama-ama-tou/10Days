﻿#pragma once
#include "Quad.h"
enum BlockType {
    NONE,
    N_POLE,//N極
    S_POLE,//S極
    WALL//壁
};

class Block :
    public Quad {

    int GH_;

    bool isPlayerFaced_;
    bool isLocated_;
    BlockType type_;

    

public:
    void Init(Vec2 pos, Vec2 size,
        Vec2 localCoOrigin,
        Vec2 imageLtPos, Vec2 imageSize,BlockType whatType);

    

};

