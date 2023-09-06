#pragma once
#include "Quad.h"
#include <Novice.h>
class Player {

	//================
	//メンバ変数
	//================
	Coordinate localCo_;
	Vec2 pos_;
	float speed_;
	Vec2 size_;

	Vec2 vertex_[4];

	int GH_;
	//画像の左上座標
	Vec2 imageLtPos_;
	//画像サイズ(表示する)
	Vec2 imageSize_;

	//面しているかどうか
	bool isFacing_;

public:
	//===============
	//メンバ関数
	//===============
	
	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, int GH, Vec2 imageLtPos, Vec2 imageSize) {
		
		vertex_[0] = pos;
		vertex_[1] = Vec2(pos.x + size.x, pos.y);
		vertex_[2] = Vec2(pos.x, pos.y + size.y);
		vertex_[3] = Vec2(pos.x + size.x, pos.y + size.y);

		localCo_.setOrigin(localCoOrigin);

		GH_ = GH;
		imageLtPos_ = imageLtPos;
		imageSize_ = imageSize; speed_ = imageSize;
	}

	void Update(char* keys, char* preKeys);
	void Draw();
	void Move(char* keys,char* preKeys);

	//===============
	//ゲッター/セッター
	//===============
	bool getIsFacing() { return isFacing_; }
	
	bool setIsFacing(bool isFacing) { isFacing_ = isFacing; }
	
};

