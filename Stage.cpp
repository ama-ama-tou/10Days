﻿#include "Stage.h"

void Stage::Init() {
	//--------------------------------
	//ブロックの初期
	//--------------------------------
	Vec2 blockImageSize{ 64.0f,64.0f };

	Vec2 playerStartPos = { 0.0f, 0.0f };

	for (int c = 0; c < col_; c++) {
		for (int r = 0; r < row_; r++) {
			block_[c][r].setType(stageCsv_[c][r]);

			block_[c][r].Init(
				col_, row_, c, r,
				stageCo_.getOrigin(),
				Vec2(0.0f, 0.0f),//imageLtPos
				blockImageSize
			);
			if (stageCsv_[c][r] == 1 || stageCsv_[c][r] == 2) {
				NSBlockNum_++;
			}
			if (stageCsv_[c][r] == 9) {
				playerStartPos.x = block_[0][0].getSize().x * r;
				playerStartPos.y = block_[0][0].getSize().y * c;
			}
		}
	}
	//--------------------------------
	//プレイヤーの初期
	//--------------------------------
	player_.Init(
		playerStartPos,
		block_[0][0].getSize(),//Quad型にサイズの追加
		stageCo_.getOrigin(),
		Vec2(0.0f, 0.0f),//imageLtPos
		blockImageSize
	);

	isClear_ = false;
	isReset_ = false;

	collision = new CollisionManager(player_, block_, row_, col_);
}

void Stage::Update(char* keys, char* preKeys) {

	player_.Update(keys, preKeys);

	collision->playerCollision();
	collision->blockCollision();

	for (int c = 0; c < col_; c++) {
		for (int r = 0; r < row_; r++) {
			if (block_[c][r].getIsHadBlock()) {
				playerHasBlockNum++;
			}
		}
	}

	if (playerHasBlockNum == NSBlockNum_) {
		isClear_ = true;
	}

}

void Stage::Draw() {

	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[r][c].getType() != 0) {
				//blockが設置してあればDraw
				block_[r][c].Draw();
			}
		}
	}

	player_.Draw();
}