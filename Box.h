#pragma once
#include"Vec2.h"
/// <summary>/// �摜���g��Ȃ��l�p�` /// </summary>
struct Box {
	Vec2 pos_;
	Vec2 size_;

	unsigned int color_;

	///
	///	�����o�֐�
	/// 

	void Init(Vec2 pos, Vec2 size, unsigned int color) {
		pos_ = pos;
		size_ = size;
		color_ = color;
	}

	void Draw();

};