#include "Stage.h"

void Stage::Init() {
	//--------------------------------
	//ブロックの初期
	//--------------------------------
	Vec2 blockImageSize{ 64.0f,64.0f };

	Vec2 playerStartPos = { 0.0f, 0.0f };

	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			block_[r][c].setType(stageCsv_[r][c]);

			block_[r][c].Init(
				col_, row_,
				r, c,
				stageCo_.getOrigin(),
				Vec2(0.0f, 0.0f),//imageLtPos
				blockImageSize
			);
				if (stageCsv_[r][c] == 1 || stageCsv_[r][c] == 2) {
				NSBlockNum_++;
			}
			if (stageCsv_[r][c] == 9) {
				playerStartPos.x = block_[0][0].getSize().x * c;
				playerStartPos.y = block_[0][0].getSize().y * r;
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

	collision = new CollisionManager(row_, col_);
}

void Stage::Update(char* keys, char* preKeys) {
	player_.Update(keys, preKeys);

	collision->playerCollision(player_, block_);
	collision->blockCollision(player_, block_);

	//デバック用
	collision->Draw();

	


	for (int c = 0; c < col_; c++) {
		for (int r = 0; r < row_; r++) {
			if (block_[r][c].getIsHadBlock()) {
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