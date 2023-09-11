#pragma once
#include "Quad.h"
#include "Vec2.h"
#include <Novice.h>

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

    int testType_;

    ///ブロックの各面がブロックと接しているか
    bool isFacing_;

    //ブロックの各面がどのブロックと面しているか
    int isFacingType_[4];

    //ブロックを持っているかいないか
    bool isHadBlock_;

public:
    Block() {
        GH_ = 0;
        for (int i = 0; i < 4; i++) {
            isFacingType_[i] = false;
        }

    }
   //=======================
   //メンバ関数
   //=======================
    void Init(int MaxCol, int MaxRow, 
        int colNum, int rowNum,
        Vec2 localCoOrigin,
        Vec2 imageLtPos, Vec2 imageSize);

    void Update();

    int CalcuRowAddress(int vertexNum);
    int CalcuColAddress(int vertexNum);

    //=======================
    //ゲッター/セッター
    //=======================
    Vec2 getPos() { return pos_; }
    void serPos(Vec2 pos) { pos_ = pos; }

    Vec2 getPrePos() { return prePos_; }
    void setPrePos(Vec2 prePos) { prePos_ = prePos; }

    int getType() { return testType_; }
    void setType(int testType_);
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

