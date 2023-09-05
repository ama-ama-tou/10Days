﻿#pragma once
#include"Vec2.h"

struct Quad {
	//================
	//メンバ変数
	//================
	Vec2 vertex_[4];
	

	int GH_;
	//画像の左上座標
	Vec2 imageLtPos_;
	//画像の描画範囲
	Vec2 imageSize_;

	//===============
	//メンバ関数
	//===============

	void Init(Vec2 pos, Vec2 size, int GH, Vec2 imageLtPos, Vec2 imageSize) {
		vertex_[0] = pos;
		vertex_[1] = Vec2(pos.x + size.x, pos.y);
		vertex_[2] = Vec2(pos.x, pos.y + size.y);
		vertex_[3] = Vec2(pos.x + size.x, pos.y + size.y);

		GH_ = GH;
		imageLtPos_ = imageLtPos;
		imageSize_ = imageSize;
	}

	void Draw();




};
