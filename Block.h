﻿#pragma once
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
	int preType_;

	///ブロックの各面がブロックと接しているか
	bool isFacing_;

	//ブロックの各面がどのブロックと面しているか
	int isFacingType_[4];

	//ブロックを持っているかいないか
	bool isHadBlock_;
	bool isPreHadBlock_;

	int isHadCount_;

	bool isGetting_;

	//ブロックがくっついたときの効果音
	int SH_;
	int VH_;

	//ブロックの各頂点の番地
	int bLtRowAddress_;
	int bRtRowAddress_;
	int bLbRowAddress_;
	int bRbRowAddress_;

	int bLtColAddress_;
	int bRtColAddress_;
	int bLbColAddress_;
	int bRbColAddress_;

	///保存用変数
	int rowKeepTop_;
	int rowKeepRight_;
	int rowKeepBottom_;
	int rowKeepLeft_;

	int colKeepTop_;
	int colKeepRight_;
	int colKeepBottom_;
	int colKeepLeft_;

	Vec2 keepLtVer_;
	Vec2 keepRtVer_;
	Vec2 keepLbVer_;
	Vec2 keepRbVer_;

	int keepIsHadBlock_;

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

	void Update(Vec2 pos);
	void HitUpdate() {
		isPreHadBlock_ = isHadBlock_;
	};

	void Draw();

	void Keep();
	
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

	int getPreType() { return preType_; }
	void setPreType(int preType_);

	int getHitting() { return isHit_; }
	void setHitting(int isHit) { isHit_ = isHit; }

	bool getGetting() { return isGetting_; }
	void setIsGetting(bool isGetting) { isGetting_ = isGetting; }

	/* int getResetAddressR_(int i, int j) { return resetAddressR_[i][j]; }
	 void setResetAddressR_(int i, int j) { resetAddressC_[i][j] = type; }*/


	bool getIsHadBlock() { return isHadBlock_; }
	void setIsHadBlock(bool isHadBlock) { isHadBlock_ = isHadBlock; }
	bool getIsPreHadBlock() { return isPreHadBlock_; }
	//void setIsPreHadBlock(bool ){} セットしてはいけない

	///ブロックの各面が接しているか
	bool getIsFacingTop() { return isFacing_; }
	bool getIsFacingRight() { return isFacing_; }
	bool getIsFacingBottom() { return isFacing_; }
	bool getIsFacingLeft() { return isFacing_; }

	void setIsFacingTop(bool isFacing) { isFacing_ = isFacing; }
	void setIsFacingRight(bool isFacing) { isFacing_ = isFacing; }
	void setIsFacingBottom(bool isFacing) { isFacing_ = isFacing; }
	void setIsFacingLeft(bool isFacing) { isFacing_ = isFacing; }


	//各頂点のアドレスを保存
	int getRowKeepTop() { return rowKeepTop_; }
	int getRowKeepRight() { return rowKeepRight_; }
	int getRowKeepBottom() { return rowKeepBottom_; }
	int getRowKeepLeft() { return rowKeepLeft_; }

	void setRowKeepTop(int rowKeepTop) { rowKeepTop_ = rowKeepTop; }
	void setRowKeepRight(int rowKeepRight) { rowKeepRight_ = rowKeepRight; }
	void setRowKeepBottom(int rowKeepBottom) { rowKeepBottom_ = rowKeepBottom; }
	void setRowKeepLeft(int rowKeepLeft) { rowKeepLeft_ = rowKeepLeft; }

	int getColKeepTop() { return colKeepTop_; }
	int getColKeepRight() { return colKeepRight_; }
	int getColKeepBottom() { return colKeepBottom_; }
	int getColKeepLeft() { return colKeepLeft_; }

	void setColKeepTop(int colKeepTop) { colKeepTop_ = colKeepTop; }
	void setColKeepRight(int colKeepRight) { colKeepRight_ = colKeepRight; }
	void setColKeepBottom(int colKeepBottom) { colKeepBottom_ = colKeepBottom; }
	void setColKeepLeft(int colKeepLeft) { colKeepLeft_ = colKeepLeft; }

	//各頂点の座標の保存
	Vec2 getKeepLtVer() { return keepLtVer_; }
	Vec2 getKeepRtVer() { return keepRtVer_; }
	Vec2 getKeepLbVer() { return keepLbVer_; }
	Vec2 getKeepRbVer() { return keepRbVer_; }

	void setKeepLtVer(Vec2 pos) { keepLtVer_ = pos; }
	void setKeepRtVer(Vec2 pos) { keepRtVer_ = pos; }
	void setKeepLbVer(Vec2 pos) { keepLbVer_ = pos; }
	void setKeepRbVer(Vec2 pos) { keepRbVer_ = pos; }

	int getKeepIsHadBlock() { return keepIsHadBlock_; }
	void setKeepIsHadBlock(int isHadBlock) { keepIsHadBlock_ = isHadBlock; }


	///どの面がどの種類と接しているか(上→右→下→左)
	int getIsFacingTopType() { return isFacingType_[0]; }
	int getIsFacingRightType() { return isFacingType_[1]; }
	int getIsFacingBottomType() { return isFacingType_[2]; }
	int getIsFacingLeftType() { return isFacingType_[3]; }

	void setIsFacingTopType(int isFacing) { isFacingType_[0] = isFacing; }
	void setIsFacingRightType(int isFacing) { isFacingType_[1] = isFacing; }
	void setIsFacingBottomType(int isFacing) { isFacingType_[2] = isFacing; }
	void setIsFacingLeftType(int isFacing) { isFacingType_[3] = isFacing; }


	//各頂点のアドレス
	int getBLtRowAddress() { return bLtRowAddress_; }
	int getBRtRowAddress() { return bRtRowAddress_; }
	int getBLbRowAddress() { return bLbRowAddress_; }
	int getBRbRowAddress() { return bRbRowAddress_; }

	void setBLtRowAddress(int ad) { bLtRowAddress_ = ad; }
	void setBRtRowAddress(int ad) { bRtRowAddress_ = ad; }
	void setBLbRowAddress(int ad) { bLbRowAddress_ = ad; }
	void setBRbRowAddress(int ad) { bRbRowAddress_ = ad; }

	int getBLtColAddress() { return bLtColAddress_; }
	int getBRtColAddress() { return bRtColAddress_; }
	int getBLbColAddress() { return bLbColAddress_; }
	int getBRbColAddress() { return bRbColAddress_; }

	void setBLtColAddress(int ad) { bLtColAddress_ = ad; }
	void setBRtColAddress(int ad) { bRtColAddress_ = ad; }
	void setBLbColAddress(int ad) { bLbColAddress_ = ad; }
	void setBRbColAddress(int ad) { bRbColAddress_ = ad; }

	int getIsHadCount() { return isHadCount_; }
	void setIsHadCount(int num) { isHadCount_ = num; }
};

