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
   // int isHitBlockType_[4];

    ///ブロックの各面がブロックと接しているか
    bool isFacing_;

    //ブロックの各面がどのブロックと面しているか
    int isFacingType_[4];

    //ブロックを持っているかいないか

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
    /*int getHitBlockTopType() { return isHitBlockType_[type_]; }
    int getHitBlockRightType() { return isHitBlockType_[type_]; }
    int getHitBlockbottomType() { return isHitBlockType_[type_]; }
    int getHitBlockLeftType() { return isHitBlockType_[type_]; }

    void setHitBlockTopType(int isHitBlockType) { isHitBlockType_[type_] = isHitBlockType; }
    void setHitBlockRightType(int isHitBlockType) { isHitBlockType_[type_] = isHitBlockType; }
    void setHitBlockBottomType(int isHitBlockType) { isHitBlockType_[type_] = isHitBlockType; }
    void setHitBlockLeftType(int isHitBlockType) { isHitBlockType_[type_] = isHitBlockType; }*/

    ///ブロックの各面が接しているか
    bool getIsFacingTop() { return isFacing_; }
    bool getIsFacingRight() { return isFacing_; }
    bool getIsFacingBottom() { return isFacing_; }
    bool getIsFacingLeft() { return isFacing_; }

    void setIsFacingTop(bool isFacing) { isFacing_ = isFacing; }
    void setIsFacingRight(bool isFacing) { isFacing_ = isFacing; }
    void setIsFacingBottom(bool isFacing) { isFacing_ = isFacing; }
    void setIsFacingLeft(bool isFacing) { isFacing_ = isFacing; }


    ///どの面がどの種類と接しているか(上→右→下→左)
    int getIsFacingTopType() { return isFacingType_[0]; }
    int getIsFacingRightType() { return isFacingType_[1]; }
    int getIsFacingBottomType() { return isFacingType_[2]; }
    int getIsFacingLeftType() { return isFacingType_[3]; }

    void setIsFacingTopType(int isFacing) { isFacingType_[0] = isFacing; }
    void setIsFacingRightType(int isFacing) { isFacingType_[1] = isFacing; }
    void setIsFacingBottomType(int isFacing) { isFacingType_[2] = isFacing; }
    void setIsFacingLeftType(int isFacing) { isFacingType_[3] = isFacing; }
};

