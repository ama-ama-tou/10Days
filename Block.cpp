#include "Block.h"
#include <Novice.h>
#include"base.h"

void Block::Init(int MaxCol, int MaxRow,int colNum,int rowNum,
	Vec2 localCoOrigin,
	Vec2 imageLtPos, Vec2 imageSize) {

	int x= static_cast<int>(kFieldSize.x / MaxRow);
	int y = static_cast<int>(kFieldSize.y / MaxCol);

	Vec2 size(static_cast<float>(x), static_cast<float>(y));
	
	Vec2 pos;
	pos.x = rowNum * size.x;
	pos.y = colNum * size.y;


	//typeに合わせてGHを変更
	/*if (type_ ==NONE) {
		GH_ = 0;
	} else if (type_==N_POLE) {
		GH_ = Novice::LoadTexture("./Resources/image/character/nPole.png");
	} else if (type_==S_POLE) {
		GH_ = Novice::LoadTexture("./Resources/image/character/sPole.png");
	} else if (type_==WALL) {
		GH_ = Novice::LoadTexture("./Resources/image/obj/wall.png");
	}*/


	Quad::Init(pos, size, 
		localCoOrigin,
		GH_, imageLtPos, imageSize);
}


void Block::Update(Vec2 pos) {

	isPreHadBlock_ = isHadBlock_;

	setLocalCoOrigin(pos);
}


void Block::Draw() {
	if (!isPreHadBlock_ && isHadBlock_) {
		if (Novice::IsPlayingAudio(VH_)==0||VH_==-1) {
			VH_ = Novice::PlayAudio(SH_, false, 0.3f);
		}
	}
}


int Block::CalcuRowAddress(int vertexNum) {
	int row = { 0 };
	if (vertexNum == 0) {
		row = static_cast<int>(getLtVertex().x / getSize().x); //左上の場合
	} else if(vertexNum == 1) {
		row = static_cast<int>((getRtVertex().x - 1) / getSize().x); //右上の場合
	} else if (vertexNum == 2) {
		row = static_cast<int>((getRbVertex().x - 1) / getSize().x); //右下の場合
	} else if (vertexNum == 3) {
		row = static_cast<int>((getLbVertex().x - 1) / getSize().x); //左下の場合
	}
	return row;
}

int Block::CalcuColAddress(int vertexNum) {
	int col = { 0 };
	if (vertexNum == 0) {
		col = static_cast<int>(getLtVertex().y / getSize().y); //左上の場合
	} else if (vertexNum == 1) {
		col = static_cast<int>((getRtVertex().y - 1) / getSize().y); //右上の場合
	} else if (vertexNum == 2) {
		col = static_cast<int>((getRbVertex().y - 1) / getSize().y); //右下の場合
	} else if (vertexNum == 3) {
		col = static_cast<int>((getLbVertex().y - 1) / getSize().y); //左下の場合
	}
	return col;
}

void Block::setType(int type) {
	
	if (type == 0) {
		GH_ = 0;
		testType_ = NONE;
	} else if (type == 1) {
		testType_ = N_POLE;
		GH_ = Novice::LoadTexture("./Resources/image/character/nPole.png");
	} else if (type == 2) {
		testType_ = S_POLE;
		GH_ = Novice::LoadTexture("./Resources/image/character/sPole.png");
	} else if (type == 3) {
		testType_ = WALL;
		GH_ = Novice::LoadTexture("./Resources/image/obj/wall.png");
	} else{
		GH_ = 0;
		testType_ = NONE;
	}
}

