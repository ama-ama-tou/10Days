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