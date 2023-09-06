﻿#pragma once
#include "Quad.h"
#include <Novice.h>
class Player {

	//================
	//メンバ変数
	//================
	Coordinate localCo_;
	Vec2 pos_;
	float speed_;
	Vec2 size_;

	Vec2 vertex_[4];

	int GH_;
	//画像の左上座標
	Vec2 imageLtPos_;
	//画像サイズ(表示する)
	Vec2 imageSize_;

	//接っしているかどうか
	bool isHit_;

	//面しているかどうか
	int isFacing_;

public:
	//===============
	//メンバ関数
	//===============
	
	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, Vec2 imageLtPos, Vec2 imageSize) {
		
		vertex_[0] = pos;
		vertex_[1] = Vec2(pos.x + size.x, pos.y);
		vertex_[2] = Vec2(pos.x, pos.y + size.y);
		vertex_[3] = Vec2(pos.x + size.x, pos.y + size.y);

		localCo_.setOrigin(localCoOrigin);

		GH_ =Novice::LoadTexture("./Resource/image/character/player.png");
		imageLtPos_ = imageLtPos;
		imageSize_ = imageSize; speed_ = imageSize;
	}

	void Update(char* keys, char* preKeys);
	void Draw();
	void Move(char* keys,char* preKeys);

	int CalcuRowAddress(int vertexNum);
	int CalcuColAddress(int vertexNum);

	//===============
	//ゲッター/セッター
	//===============
	///各頂点の当たっていかフラグ
	int getIsHitLt() { return isHit_; }
	int getIsHitRt() { return isHit_; }
	int getIsHitRb() { return isHit_; }
	int getIsHitLb() { return isHit_; }

	int setIsHitLt(bool isHit) { isHit_ = isHit; }
	int setIsHitRt(bool isHit) { isHit_ = isHit; }
	int setIsHitRb(bool isHit) { isHit_ = isHit; }
	int setIsHitLb(bool isHit) { isHit_ = isHit; }

	///
	int getIsFacing() { return isFacing_; }
	int setIsFacing(int isFacing) { isFacing_ = isFacing; }
	
	//ローカル座標上
	Vec2 getLtVertex() { return vertex_[0]; }
	Vec2 getRtVertex() { return vertex_[1]; }
	Vec2 getLbVertex() { return vertex_[2]; }
	Vec2 getRbVertex() { return vertex_[3]; }

	void setLtVertex(Vec2 pos) { vertex_[0] = pos; }
	void setRtVertex(Vec2 pos) { vertex_[1] = pos; }
	void setLbVertex(Vec2 pos) { vertex_[2] = pos; }
	void setRbVertex(Vec2 pos) { vertex_[3] = pos; }

	//スクリーン座標上
	Vec2 getScreenLtVertex() { return localCo_.screenFromOrigin(vertex_[0]); }
	Vec2 getScreenRtVertex() { return localCo_.screenFromOrigin(vertex_[1]); }
	Vec2 getScreenLbVertex() { return localCo_.screenFromOrigin(vertex_[2]); }
	Vec2 getScreenRbVertex() { return localCo_.screenFromOrigin(vertex_[3]); }

	Coordinate getLocalCo() { return localCo_; }
	void setLocalCoOrigin(Vec2 pos) { localCo_.setOrigin(pos); }

	Vec2 getImageLtPos() { return imageLtPos_; }
	void setImageLtPos(Vec2 imageLtPos) { imageLtPos_ = imageLtPos; }


};

