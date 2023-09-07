#pragma once
#include "Quad.h"
#include <Novice.h>
class Player {

	//================
	//メンバ変数
	//================
	Coordinate localCo_;
	Vec2 pos_;
	Vec2 size_;

	float speed_;
	
	Vec2 vertex_[4];

	int GH_;
	//画像の左上座標
	Vec2 imageLtPos_;
	//画像サイズ(表示する)
	Vec2 imageSize_;

	//接っしているかどうか
	//bool isHit_;

	//面しているかどうか
	bool isFacing_[4];

public:
	//===============
	//メンバ関数
	//===============
	
	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, Vec2 imageLtPos, Vec2 imageSize) {
		size_ = size;

		vertex_[0] = pos;
		vertex_[1] = Vec2(pos.x + size_.x, pos.y);
		vertex_[2] = Vec2(pos.x, pos.y + size_.y);
		vertex_[3] = Vec2(pos.x + size_.x, pos.y + size_.y);

		//1マスずつ進める
		speed_ = size_;

		localCo_.setOrigin(localCoOrigin);

		GH_ =Novice::LoadTexture("./Resource/image/character/player.png");
		imageLtPos_ = imageLtPos;
		imageSize_ = imageSize; 
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
	/*bool getIsHitLt() { return isHit_; }
	bool getIsHitRt() { return isHit_; }
	bool getIsHitRb() { return isHit_; }
	bool getIsHitLb() { return isHit_; }

	void setIsHitLt(bool isHit) { isHit_ = isHit; }
	void setIsHitRt(bool isHit) { isHit_ = isHit; }
	void setIsHitRb(bool isHit) { isHit_ = isHit; }
	void setIsHitLb(bool isHit) { isHit_ = isHit; }*/

	///どの面が接しているか(上→右→下→左)
	bool getIsFacingTop() { return isFacing_[0]; }
	bool getIsFacingRight() { return isFacing_[1]; }
	bool getIsFacingBottom() { return isFacing_[2]; }
	bool getIsFacingLeft() { return isFacing_[3]; }

	void setIsFacingTop(bool isFacing) { isFacing_[0] = isFacing; }
	void setIsFacingRight(bool isFacing) { isFacing_[1] = isFacing; }
	void setIsFacingBottom(bool isFacing) { isFacing_[2] = isFacing; }
	void setIsFacingLeft(bool isFacing) { isFacing_[3] = isFacing; }
	 
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

