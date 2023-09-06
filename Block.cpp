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

int Block::CalcuRowAddress(int vertexNum) {
	int row;
	if (vertexNum == 0) {
		row = getLtVertex().x / getSize().x; //左上の場合
	} else if(vertexNum == 1) {
		row = (getRtVertex().x - 1) / getSize().x; //右上の場合
	} else if (vertexNum == 2) {
		row = (getRbVertex().x - 1) / getSize().x; //右下の場合
	} else if (vertexNum == 3) {
		row = (getLbVertex().x - 1) / getSize().x; //左下の場合
	}
	return row;
}

int Block::CalcuColAddress(int vertexNum) {
	int col;
	if (vertexNum == 0) {
		col = getLtVertex().y / getSize().y; //左上の場合
	} else if (vertexNum == 1) {
		col = (getRtVertex().y - 1) / getSize().y; //右上の場合
	} else if (vertexNum == 2) {
		col = (getRbVertex().y - 1) / getSize().y; //右下の場合
	} else if (vertexNum == 3) {
		col = (getLbVertex().y - 1) / getSize().y; //左下の場合
	}
	return col;
}
