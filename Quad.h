#pragma once
#include"Coordinate.h"


class Quad {
	//================
	//メンバ変数
	//================
	Coordinate localCo;
	Vec2 vertex_[4];

	int GH_;
	//画像の左上座標
	Vec2 imageLtPos_;
	//画像の描画範囲
	Vec2 imageSize_;

	//===============
	//メンバ関数
	//===============

	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin,int GH, Vec2 imageLtPos, Vec2 imageSize) {
		vertex_[0] = pos;
		vertex_[1] = Vec2(pos.x + size.x, pos.y);
		vertex_[2] = Vec2(pos.x, pos.y + size.y);
		vertex_[3] = Vec2(pos.x + size.x, pos.y + size.y);

		localCo.setOrigin(localCoOrigin);

		GH_ = GH;
		imageLtPos_ = imageLtPos;
		imageSize_ = imageSize;
	}

	void Draw();
	//===============
	//ゲッター/セッター
	//===============
	//ローカル座標系
	Vec2 getLtVertex() { return vertex_[0]; }
	Vec2 getRtVertex() { return vertex_[1]; }
	Vec2 getLbVertex() { return vertex_[2]; }
	Vec2 getRbVertex() { return vertex_[3]; }

	//スクリーン座標系
	Vec2 getScreenLtVertex() { return localCo.screenFromOrigin(vertex_[0]); }
	Vec2 getScreenRtVertex() { return localCo.screenFromOrigin(vertex_[1]); }
	Vec2 getScreenLbVertex() {return localCo.screenFromOrigin(vertex_[2]);}
	Vec2 getScreenRbVertex() { return localCo.screenFromOrigin(vertex_[3]); }


};
