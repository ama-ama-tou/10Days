#pragma once
#include"Vec2.h"
/// <summary>/// 画像を使わない四角形 /// </summary>
struct Box {
	Vec2 pos_;
	Vec2 size_;

	unsigned int color_;

	///
	///	メンバ関数
	/// 

	void Init(Vec2 pos, Vec2 size, unsigned int color) {
		pos_ = pos;
		size_ = size;
		color_ = color;
	}

	void Draw();

};