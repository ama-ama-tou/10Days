#pragma once
#include"Vec2.h"

//==============================
//�@�@���W�n�N���X
//==============================
class Coordinate{
	
	Vec2 origin_;

public:

	Vec2 screenFromOrigin(Vec2 target) {
		return target += origin_;

	}



	//=========================
	//�Q�b�^�[/�Z�b�^�[
	//=========================
	Vec2 getOrigin() { return origin_; }
	void setOrigin(Vec2& origin) { origin_ = origin; }



};

