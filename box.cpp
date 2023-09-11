#include"box.h"
#include<Novice.h>

void Box::Draw() {
	Novice::DrawBox(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f,
		color_,
		kFillModeSolid
	);

}
