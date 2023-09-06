#pragma once
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

    int isHit_;
    BlockType type_;

    //当たっているブロックの種類
    int isHitBlockType_;

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

    int getHitting() { return isHit_; }
    void setHitting(int isHit) { isHit_ = isHit; }

    int getHitBlockType() { return isHitBlockType_; }
    void setHitBlockType(int isHitBlockType) { isHitBlockType_ = isHitBlockType; }

};

