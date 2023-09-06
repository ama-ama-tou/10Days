#include "Block.h"
#include <Novice.h>

void Block::Init(Vec2 pos, Vec2 size,
	Vec2 localCoOrigin,
	Vec2 imageLtPos, Vec2 imageSize, BlockType whatType) {

	type_ = whatType;

	//typeに合わせてGHを変更
	if (type_ == NONE) {
		GH_ = 0;
	} else if (type_==N_POLE) {
		GH_ = Novice::LoadTexture("./Resource/image/character/nPole.png");
	} else if (type_==S_POLE) {
		GH_ = Novice::LoadTexture("./Resource/image/character/sPole.png");
	} else if (type_==WALL) {
		GH_ = Novice::LoadTexture("./Resource/image/obj/wall.png");
	}

	Quad::Init(pos, size, 
		localCoOrigin,
		GH_, imageLtPos, imageSize);
}
