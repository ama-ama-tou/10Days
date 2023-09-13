#pragma once
#include "Quad.h"
#include <Novice.h>

class Player
	: public Quad {

	//================
	//メンバ変数
	//================

	Vec2 pos_;

	float speed_;

	Vec2 prePos_;

	//接っしているかどうか
	bool isHit_;

	//面しているかどうか
	bool isFacing_[4];

	//移動してる時の音
	int moveSH_;
	int moveVH_;
	int frameCount_;
	bool isSoundStart_;

	///プレイヤーの上辺が持っていいるブロックの種類
	int isFacingTopType_;
	int isFacingRightType_;
	int isFacingBottomType_;
	int isFacingLeftType_;


	int rKeepTop_;
	int cKeepTop_;

	bool switch_;

	bool isSwitch_;
	
public:
	//===============
	//メンバ関数
	//===============

	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, Vec2 imageLtPos, Vec2 imageSize) {

		int x = static_cast<int>(size.x);
		int y = static_cast<int>(size.y);

		size.x = static_cast<float>(x);
		size.y = static_cast<float>(y);

		pos_ = pos;

		prePos_ = pos;

		//1マスずつ進める
		speed_ = static_cast<float>(size);

		int GH = Novice::LoadTexture("./Resources/image/character/player.png");

		moveSH_ = Novice::LoadAudio("./Resources/sound/SE/playerMove.mp3");
		moveVH_ = -1;
		frameCount_ = 0;
		isSoundStart_ = false;

		Quad::Init(pos, size, localCoOrigin, GH, imageLtPos, imageSize,WHITE);
	}

	void Update(char* keys, char* preKeys);
	void Draw();
	void Move(char* keys, char* preKeys);

	int CalacRowAddress(int vertexNum);
	int CalacColAddress(int vertexNum);

	//===============
	//ゲッター/セッター
	//===============
	//各頂点の当たっていかフラグ
	bool getIsHitLt() { return isHit_; }
	bool getIsHitRt() { return isHit_; }
	bool getIsHitRb() { return isHit_; }
	bool getIsHitLb() { return isHit_; }

	void setIsHitLt(bool isHit) { isHit_ = isHit; }
	void setIsHitRt(bool isHit) { isHit_ = isHit; }
	void setIsHitRb(bool isHit) { isHit_ = isHit; }
	void setIsHitLb(bool isHit) { isHit_ = isHit; }

	int getRkeepTop() { return rKeepTop_; }
	void setRkeepTop(int ad) { rKeepTop_ = ad; }

	int getCkeepTop() { return cKeepTop_; }
	void setCkeepTop(int ad) { cKeepTop_ = ad; }

	bool getSwitch() { return switch_; }
	void setSwitch(bool switchA) { switch_ = switchA; }

	bool getIsSwitch() { return isSwitch_; }
	void setIsSwitch(bool switchA) { isSwitch_ = switchA; }

	//どの面が接しているか(上→右→下→左)
	bool getIsFacingTop() { return isFacing_[0]; }
	bool getIsFacingRight() { return isFacing_[1]; }
	bool getIsFacingBottom() { return isFacing_[2]; }
	bool getIsFacingLeft() { return isFacing_[3]; }

	void setIsFacingTop(bool isFacing) { isFacing_[0] = isFacing; }
	void setIsFacingRight(bool isFacing) { isFacing_[1] = isFacing; }
	void setIsFacingBottom(bool isFacing) { isFacing_[2] = isFacing; }
	void setIsFacingLeft(bool isFacing) { isFacing_[3] = isFacing; }

	///どの面がどの種類と接しているか(上→右→下→左)
	int getIsFacingTopType() { return isFacingTopType_; }
	int getIsFacingRightType() { return isFacingRightType_; }
	int getIsFacingBottomType() { return isFacingBottomType_; }
	int getIsFacingLeftType() { return isFacingLeftType_; }

	void setIsFacingTopType(int isFacing) { isFacingTopType_ = isFacing; }
	void setIsFacingRightType(int isFacing) { isFacingRightType_ = isFacing; }
	void setIsFacingBottomType(int isFacing) { isFacingBottomType_ = isFacing; }
	void setIsFacingLeftType(int isFacing) { isFacingLeftType_ = isFacing; }

	Vec2 getPos() { return pos_; }
	void setPos(Vec2 pos) { pos_ = pos; }

	//保存用pos(左上座標)
	Vec2 getPrePos() { return prePos_; }
	void setPrePos(Vec2 prePos) { prePos_ = prePos; }

};

