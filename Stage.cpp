#include "Stage.h"

void Stage::Init() {

	Vec2 playerStartPos{ 0.0f,0.0f };

	//--------------------------------
	//ブロックの初期
	//--------------------------------
	Vec2 blockImageSize{ 64.0f,64.0f };

	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			block_[r][c]->Init(
				col_, row_, c, r,
				stageCo_.getOrigin(),
				Vec2(0.0f, 0.0f),//imageLtPos
				blockImageSize,
				static_cast<BlockType>(stageCsv_[r][c])
			);
			if (stageCsv_[r][c]==9) {
				//playerStartPosを設定(r*size.x,c*size.y)
			}
			if (stageCsv_[r][c]==1||stageCsv_[r][c]==2) {
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
	//コリジョンマネージャーの追加
	//blockのlocalCoordinateの更新の処理(必要なら)
	if (/*clear条件*/) {
		isClear_ == true;
	}



	if (/*reset条件*/) {
		isReset_ == true;
	}

}

void Stage::Draw() {
	
	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[r][c]->getType()!=NONE) {
				//blockが設置してあればDraw
				block_[r][c]->Draw();
			}
		}
	}

	player_->Draw();
}