#pragma once
#include "Quad.h"
class Player :
    public Quad {

	//================
	//メンバ変数
	//================
	Vec2 pos;
	float speed;

	

	//===============
	//メンバ関数
	//===============
	
	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, int GH, Vec2 imageLtPos, Vec2 imageSize) {
		Quad::Init(pos, size, localCoOrigin, GH, imageLtPos, imageSize);
		speed = 8.0f;
	}

	void Move(char* keys,char* preKeys);
};

