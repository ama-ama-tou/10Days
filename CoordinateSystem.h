#pragma once
#include"Vec2.h"

//==============================
//　　座標系クラス
//==============================
class Coordinate{
	
	Vec2 origin_;

public:

	Vec2 screenFromOrigin(Vec2 target) {
		return target += origin_;

	}



	//=========================
	//ゲッター/セッター
	//=========================
	Vec2 getOrigin() { return origin_; }
	void setOrigin(Vec2& origin) { origin_ = origin; }



};

