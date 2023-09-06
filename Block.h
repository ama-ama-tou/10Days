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

    bool isFacing_;
    BlockType type_;

public:
    void Init(int MaxCol, int MaxRow, 
        int colNum, int rowNum,
        Vec2 localCoOrigin,
        Vec2 imageLtPos, Vec2 imageSize,BlockType whatType);
    //=======================
    //ゲッター/セッター
    //=======================
    BlockType getType() { return type_; }
    void setType(BlockType type) { type_ = type; }

    bool getFacing() { return isFacing_; }
    void setFacing(bool isFacing) { isFacing_ = isFacing; }


};
