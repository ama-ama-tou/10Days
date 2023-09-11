#include "Stage.h"
#include <stdlib.h>
#include <time.h>
#include "Vec2.h"

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


	//背景の動きの初期化

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 50; i++) {
		//座標をランダムで設定
		bkQuadPos_[i] = { static_cast<float>(rand() % 1280),static_cast<float>(rand() % 720) };
		//サイズをランダムで設定
		bkQuadSize_[i].x = static_cast<float>(rand() % 11 + 10);
		bkQuadSize_[i].y = bkQuadSize_[i].x;
		//最大・最小拡縮量
		bkQuadScaleValue_[i] = Vec2(0.1f, 0.1f);
		bkQuadMinScale_[i] = { bkQuadSize_[i].x - 5.0f,bkQuadSize_[i].y - 5.0f };
		bkQuadMaxScale_[i] = { bkQuadSize_[i].x + 5.0f,bkQuadSize_[i].y + 5.0f };
		//スピードをランダムで設定
		do {
			bkQuadSpeed_[i].x = static_cast<float>(rand() % 3 - 1);
			bkQuadSpeed_[i].y = static_cast<float>(rand() % 3 - 1);
		} while (bkQuadSpeed_[i] == 0);

		bkQuadColor_ = 0x000000aa;
		//引いて薄くさせる色
		subtractiveColor_ = 0x00000001;
	}
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

	//背景の動き
	for (int i = 0; i < 50; i++) {
		//quadの移動
		bkQuadPos_[i] += bkQuadSpeed_[i];

		//座標の更新
		bkQuadVertex_[0][i] = { bkQuadPos_[i].x - bkQuadSize_[i].x,bkQuadPos_[i].y - bkQuadSize_[i].y };
		bkQuadVertex_[1][i] = { bkQuadPos_[i].x + bkQuadSize_[i].x,bkQuadPos_[i].y - bkQuadSize_[i].y };
		bkQuadVertex_[2][i] = { bkQuadPos_[i].x - bkQuadSize_[i].x,bkQuadPos_[i].y + bkQuadSize_[i].y };
		bkQuadVertex_[3][i] = { bkQuadPos_[i].x + bkQuadSize_[i].x,bkQuadPos_[i].y + bkQuadSize_[i].y };
		
		//拡縮
		bkQuadSize_[i] += bkQuadScaleValue_[i];
		if (bkQuadSize_[i] += bkQuadScaleValue_[i]) {
			bkQuadScaleValue_[i] *= Vec2(-1, -1);
		} else if (bkQuadSize_[i] <= bkQuadMinScale_[i]) {
			bkQuadScaleValue_[i] *= Vec2(-1, -1);
		}

		//色の制御
		bkQuadColor_ += subtractiveColor_;
		if (bkQuadColor_ == 0x000000dd) {
			subtractiveColor_ *= -1;
		} else if (bkQuadColor_ == 0x000000aa) {
			subtractiveColor_ *= -1;
		}

		//画面外に出たら再スポーン
		if (bkQuadPos_[i].x >= 1280.0f || bkQuadPos_[i].x <= 0.0f ||
			bkQuadPos_[i] >= 720.0f || bkQuadPos_[i].y <= 0.0f) {
			bkQuadPos_[i].x = static_cast<float>(rand() % 1280);
			bkQuadPos_[i].y = static_cast<float>(rand() % 720);
		}

	}


}

void Stage::Draw() {

	for (int i = 0; i < 50; i++) {
		Novice::DrawQuad(
			static_cast<int>(localCo_.screenFromOrigin(bkQuadVertex_[0][i]).x),
			static_cast<int>(localCo_.screenFromOrigin(bkQuadVertex_[0][i]).y),
			static_cast<int>(localCo_.screenFromOrigin(bkQuadVertex_[1][i]).x),
			static_cast<int>(localCo_.screenFromOrigin(bkQuadVertex_[1][i]).y),
			static_cast<int>(localCo_.screenFromOrigin(bkQuadVertex_[2][i]).x),
			static_cast<int>(localCo_.screenFromOrigin(bkQuadVertex_[2][i]).y),
			static_cast<int>(localCo_.screenFromOrigin(bkQuadVertex_[3][i]).x),
			static_cast<int>(localCo_.screenFromOrigin(bkQuadVertex_[3][i]).y),
			0, 0, 32, 32, bkGH_,
			bkQuadColor_
		);
	}
	

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