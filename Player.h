#pragma once
#include "Quad.h"
#include <Novice.h>
class Player :
    public Quad {

	//================
	//メンバ変数
	//================
	Vec2 pos_;
	float speed_;

	

	//===============
	//メンバ関数
	//===============
	
	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, int GH, Vec2 imageLtPos, Vec2 imageSize) {
		Quad::Init(pos, size, localCoOrigin, GH, imageLtPos, imageSize);
		speed_ = imageSize;
	}
	void Update();
	void Move(char* keys,char* preKeys);
	void isHit();
};

