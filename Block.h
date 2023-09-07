#pragma once
#include "Quad.h"
#include "Vec2.h"

enum BlockType {
    NONE,
    N_POLE,//N極
    S_POLE,//S極
    WALL//壁
};

class Block :
    public Quad {

    Vec2 pos_;
    Vec2 prePos_;

    int GH_;

    int isHit_;
    BlockType type_;

    ///ブロックの各面がブロックと接しているか
    bool isFacing_;

    //ブロックの各面がどのブロックと面しているか
    int isFacingType_[4];

    //ブロックを持っているかいないか
    bool isHadBlock_;

public:

   //=======================
   //メンバ関数
   //=======================
    void Init(int MaxCol, int MaxRow, 
        int colNum, int rowNum,
        Vec2 localCoOrigin,
        Vec2 imageLtPos, Vec2 imageSize,BlockType whatType);

    void Update();

    int CalcuRowAddress(int vertexNum);
    int CalcuColAddress(int vertexNum);

    //=======================
    //ゲッター/セッター
    //=======================

    BlockType getType() { return type_; }
    void setType(BlockType type) { type_ = type; }

    int getHitting() { return isHit_; }
    void setHitting(int isHit) { isHit_ = isHit; }

    bool getIsHadBlock() { return isHadBlock_; }
    void setIsHadBlock(bool isHadBlock) { isHadBlock_ = isHadBlock; }

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

