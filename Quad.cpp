#include "Quad.h"
#include<Novice.h>

void Quad::Draw() {
	Novice::DrawQuad(
		static_cast<int>(vertex_[0].x),
		static_cast<int>(vertex_[0].y),
		static_cast<int>(vertex_[1].x),
		static_cast<int>(vertex_[1].y),
		static_cast<int>(vertex_[2].x),
		static_cast<int>(vertex_[2].y),
		static_cast<int>(vertex_[3].x),
		static_cast<int>(vertex_[3].y),
		static_cast<int>(imageLtPos_.x),
		static_cast<int>(imageLtPos_.y),
		static_cast<int>(imageSize_.x),
		static_cast<int>(imageSize_.y),
		GH_,
		WHITE
	);
}