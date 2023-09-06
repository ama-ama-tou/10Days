#include "Block.h"
#include <Novice.h>
#include"base.h"

void Block::Init(int MaxCol, int MaxRow,int colNum,int rowNum,
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

	Vec2 size;
	size.x = kFieldSize.x / static_cast<float>(MaxRow);
	size.y = kFieldSize.y / static_cast<float>(MaxCol);

	Vec2 pos;
	pos.x = rowNum * size.x;
	pos.y = colNum * size.y;


	Quad::Init(pos, size, 
		localCoOrigin,
		GH_, imageLtPos, imageSize);
}
