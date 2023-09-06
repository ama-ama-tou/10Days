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
    int isHitBlockType_[4];

public:

   //=======================
   //メンバ関数
   //=======================
    void Init(int MaxCol, int MaxRow, 
        int colNum, int rowNum,
        Vec2 localCoOrigin,
        Vec2 imageLtPos, Vec2 imageSize,BlockType whatType);


    int CalcuRowAddress(int vertexNum);
    int CalcuColAddress(int vertexNum);

    //=======================
    //ゲッター/セッター
    //=======================
    BlockType getType() { return type_; }
    void setType(BlockType type) { type_ = type; }

    int getHitting() { return isHit_; }
    void setHitting(int isHit) { isHit_ = isHit; }

    //各頂点がどのブロックと接しているかのフラグ
    int getHitBlockLtType() { return isHitBlockType_[0]; }
    int getHitBlockRtType() { return isHitBlockType_[1]; }
    int getHitBlockRbType() { return isHitBlockType_[2]; }
    int getHitBlockLbType() { return isHitBlockType_[3]; }

    void setHitBlockLtType(int isHitBlockType) { isHitBlockType_[0] = isHitBlockType; }
    void setHitBlockRtType(int isHitBlockType) { isHitBlockType_[1] = isHitBlockType; }
    void setHitBlockRbType(int isHitBlockType) { isHitBlockType_[2] = isHitBlockType; }
    void setHitBlockLbType(int isHitBlockType) { isHitBlockType_[3] = isHitBlockType; }
};

