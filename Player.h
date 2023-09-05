#pragma once
#include "Quad.h"
class Player :
    public Quad {

	//================
	//ÉÅÉìÉoïœêî
	//================
	Vec2 pos;
	float speed;

	

	//===============
	//ÉÅÉìÉoä÷êî
	//===============
	
	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, int GH, Vec2 imageLtPos, Vec2 imageSize) {
		vertex_[0] = pos;
		vertex_[1] = Vec2(pos.x + size.x, pos.y);
		vertex_[2] = Vec2(pos.x, pos.y + size.y);
		vertex_[3] = Vec2(pos.x + size.x, pos.y + size.y);

		speed = 8.0f;

		localCo.setOrigin(localCoOrigin);

		GH_ = GH;
		imageLtPos_ = imageLtPos;
		imageSize_ = imageSize;
	}

	void Move(char* keys,char* preKeys);
};

