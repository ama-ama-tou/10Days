#include "Triangle.h"
#include<Novice.h>

void Triangle::EasingUpdate() {



}

void Triangle::Draw() {
	Novice::DrawTriangle(
		static_cast<int>(vertex_[0].x),
		static_cast<int>(vertex_[0].y),
		static_cast<int>(vertex_[1].x),
		static_cast<int>(vertex_[1].y),
		static_cast<int>(vertex_[2].x),
		static_cast<int>(vertex_[2].y),
		color_,
		kFillModeSolid
	);
}
