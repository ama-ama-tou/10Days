#include "Stage.h"

void Stage::Init() {

	Vec2 playerStartPos{ 0.0f,0.0f };

	//--------------------------------
	//ブロックの初期
	//--------------------------------
	Vec2 blockImageSize{ 64.0f,64.0f };


	for (int c = 0; c < col_; c++) {
		for (int r = 0; r < row_; r++) {
			block_[c][r]->Init(
				col_, row_, c, r,
				stageCo_.getOrigin(),
				Vec2(0.0f, 0.0f),//imageLtPos
				blockImageSize,
				static_cast<BlockType>(stageCsv_[c][r])
			);
			if (stageCsv_[c][r] == 9) {
				//playerStartPosを設定(r*size.x,c*size.y)
			}
			if (stageCsv_[c][r] == 1 || stageCsv_[c][r] == 2) {
				NSBlockNum_++;
			}
		}
	}
	//--------------------------------
	//プレイヤーの初期
	//--------------------------------
	player_->Init(
		playerStartPos,
		block_[0][0]->getSize(),//Quad型にサイズの追加
		stageCo_.getOrigin(),
		Vec2(0.0f, 0.0f),//imageLtPos
		blockImageSize
	);
}

void Stage::Update(char* keys, char* preKeys) {

	player_->Update(keys, preKeys);
	
	collision->playerCollision();
	collision->blockCollision();

	for (int c = 0; c < col_; c++) {
		for (int r = 0; r < row_; r++) {
			if (block_[c][r]->getIsHadBlock()) {
				playerHasBlockNum++;
			}
		}
	}

	if (playerHasBlockNum== NSBlockNum_) {

	}

}

void Stage::Draw() {

	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[c][r]->getType() !=NONE) {
				//blockが設置してあればDraw
				block_[c][r]->Draw();
			}
		}
	}

	player_->Draw();
}