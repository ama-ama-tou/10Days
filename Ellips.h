#pragma once
#include "Vec2.h"
#include "Coordinate.h"

class Ellips {

	//================
	//メンバ変数
	//===============
	Coordinate localCo_;
	Vec2 pos_;
	float radius_;
	float angle_;

public:
	//===============
	//メンバ関数
	//===============
	void Init(Vec2 pos,Vec2 radius,float angle) {
		pos_ = pos;
		radius_ = radius;
		angle_ = angle;
	}
	void Draw();


	//===============
	//ゲッター/セッター
	//===============

	//ローカル座標上
	Vec2 getPos() { return pos_; }
	void setPos(Vec2 pos) { pos_ = pos; }

	//スクリーン座標上
	Vec2 getScreenPos() { return localCo_.screenFromOrigin(pos_); }


	float getRadius() { return radius_; }
	void setRadius(float radius) { radius_ = radius; }

	float getAngle() { return angle_; }
	void setAngle(float angle) { angle_ = angle; }

};

