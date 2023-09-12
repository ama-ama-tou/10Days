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


	//背景画像
	bkGH_ = Novice::LoadTexture("white1x1.png");

	//背景の動きの初期化

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 20; i++) {

		//===================
		//赤色の四角
		//==================

		//座標をランダムで設定
		bkRedQuadPos_[i] = { static_cast<float>(rand() % 1280),static_cast<float>(rand() % 720) };
		//サイズをランダムで設定
		bkRedQuadSize_[i].x = static_cast<float>(rand() % 11 + 10);
		bkRedQuadSize_[i].y = bkRedQuadSize_[i].x;
		//最大・最小拡縮量
		bkRedQuadScaleValue_[i] = Vec2(0.1f, 0.1f);
		bkRedQuadMinScale_[i] = { bkRedQuadSize_[i].x - 5.0f,bkRedQuadSize_[i].y - 5.0f };
		bkRedQuadMaxScale_[i] = { bkRedQuadSize_[i].x + 5.0f,bkRedQuadSize_[i].y + 5.0f };
		//スピードをランダムで設定
		do {
			bkRedQuadSpeed_[i].x = static_cast<float>(rand() % 3 - 1);
			bkRedQuadSpeed_[i].y = static_cast<float>(rand() % 3 - 1);
		} while (bkRedQuadSpeed_[i] == 0);

		bkRedQuadColor_ = 0x000000aa;
		//引いて薄くさせる色
		subtractiveColor_ = 0x00000001;

		//===================
		//青色の四角
		//==================

		//座標をランダムで設定
		bkRedQuadPos_[i] = { static_cast<float>(rand() % 1280),static_cast<float>(rand() % 720) };
		//サイズをランダムで設定
		bkBlueQuadSize_[i].x = static_cast<float>(rand() % 11 + 10);
		bkBlueQuadSize_[i].y = bkBlueQuadSize_[i].x;
		//最大・最小拡縮量
		bkBlueQuadScaleValue_[i] = Vec2(0.1f, 0.1f);
		bkBlueQuadMinScale_[i] = { bkBlueQuadSize_[i].x - 5.0f,bkBlueQuadSize_[i].y - 5.0f };
		bkBlueQuadMaxScale_[i] = { bkBlueQuadSize_[i].x + 5.0f,bkBlueQuadSize_[i].y + 5.0f };
		//スピードをランダムで設定
		do {
			bkBlueQuadSpeed_[i].x = static_cast<float>(rand() % 3 - 1);
			bkBlueQuadSpeed_[i].y = static_cast<float>(rand() % 3 - 1);
		} while (bkBlueQuadSpeed_[i] == 0);

		bkBlueQuadColor_ = 0x000000aa;
	}
}

void Stage::Update(char* keys, char* preKeys) {
	player_.Update(keys, preKeys);


	collision->playerCollision(player_, block_);
	collision->blockCollision(player_, block_);

	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[r][c].getType() != WALL) {
				if (block_[r][c].getIsHadBlock() == true) {
					block_[r][c].Update(player_.getScreenLtVertex());
				}
			}
		}
	}

	//デバック用
	collision->Draw(block_);


	/*for (int r = 0; r < col_; r++) {
		for (int c = 0; c < row_; c++) {
			if (block_[r][c].getIsHadBlock() == true) {
				playerHasBlockNum++;
			}
		}
	}*/

	if (playerHasBlockNum == NSBlockNum_) {
		isClear_ = true;
	}




	//背景の動き
	for (int i = 0; i < 50; i++) {

		//===================
		//赤色の四角
		//==================

			//quadの移動
		bkRedQuadPos_[i] += bkRedQuadSpeed_[i];

		//座標の更新
		bkRedQuadVertex_[0][i] = { bkRedQuadPos_[i].x - bkRedQuadSize_[i].x,bkRedQuadPos_[i].y - bkRedQuadSize_[i].y };
		bkRedQuadVertex_[1][i] = { bkRedQuadPos_[i].x + bkRedQuadSize_[i].x,bkRedQuadPos_[i].y - bkRedQuadSize_[i].y };
		bkRedQuadVertex_[2][i] = { bkRedQuadPos_[i].x - bkRedQuadSize_[i].x,bkRedQuadPos_[i].y + bkRedQuadSize_[i].y };
		bkRedQuadVertex_[3][i] = { bkRedQuadPos_[i].x + bkRedQuadSize_[i].x,bkRedQuadPos_[i].y + bkRedQuadSize_[i].y };

		//拡縮
		bkRedQuadSize_[i] += bkRedQuadScaleValue_[i];
		if (bkRedQuadSize_[i] += bkRedQuadScaleValue_[i]) {
			bkRedQuadScaleValue_[i] *= Vec2(-1, -1);
		} else if (bkRedQuadSize_[i] <= bkRedQuadMinScale_[i]) {
			bkRedQuadScaleValue_[i] *= Vec2(-1, -1);
		}

		//色の制御
		bkRedQuadColor_ += subtractiveColor_;
		if (bkRedQuadColor_ == 0x000000dd) {
			subtractiveColor_ *= -1;
		} else if (bkRedQuadColor_ == 0x000000aa) {
			subtractiveColor_ *= -1;
		}

		//画面外に出たら再スポーン
		if (bkRedQuadPos_[i].x >= 1280.0f || bkRedQuadPos_[i].x <= 0.0f ||
			bkRedQuadPos_[i] >= 720.0f || bkRedQuadPos_[i].y <= 0.0f) {
			bkRedQuadPos_[i].x = static_cast<float>(rand() % 1280);
			bkRedQuadPos_[i].y = static_cast<float>(rand() % 720);
		}


		//===================
		//青色の四角
		//==================

			//quadの移動
		bkBlueQuadPos_[i] += bkBlueQuadSpeed_[i];

		//座標の更新
		bkBlueQuadVertex_[0][i] = { bkBlueQuadPos_[i].x - bkBlueQuadSize_[i].x,bkBlueQuadPos_[i].y - bkBlueQuadSize_[i].y };
		bkBlueQuadVertex_[1][i] = { bkBlueQuadPos_[i].x + bkBlueQuadSize_[i].x,bkBlueQuadPos_[i].y - bkBlueQuadSize_[i].y };
		bkBlueQuadVertex_[2][i] = { bkBlueQuadPos_[i].x - bkBlueQuadSize_[i].x,bkBlueQuadPos_[i].y + bkBlueQuadSize_[i].y };
		bkBlueQuadVertex_[3][i] = { bkBlueQuadPos_[i].x + bkBlueQuadSize_[i].x,bkBlueQuadPos_[i].y + bkBlueQuadSize_[i].y };

		//拡縮
		bkBlueQuadSize_[i] += bkBlueQuadScaleValue_[i];
		if (bkBlueQuadSize_[i] += bkBlueQuadScaleValue_[i]) {
			bkBlueQuadScaleValue_[i] *= Vec2(-1, -1);
		} else if (bkBlueQuadSize_[i] <= bkBlueQuadMinScale_[i]) {
			bkBlueQuadScaleValue_[i] *= Vec2(-1, -1);
		}

		//色の制御
		bkBlueQuadColor_ += subtractiveColor_;
		if (bkBlueQuadColor_ == 0x000000dd) {
			subtractiveColor_ *= -1;
		} else if (bkBlueQuadColor_ == 0x000000aa) {
			subtractiveColor_ *= -1;
		}

		//画面外に出たら再スポーン
		if (bkBlueQuadPos_[i].x >= 1280.0f || bkBlueQuadPos_[i].x <= 0.0f ||
			bkBlueQuadPos_[i] >= 720.0f || bkBlueQuadPos_[i].y <= 0.0f) {
			bkBlueQuadPos_[i].x = static_cast<float>(rand() % 1280);
			bkBlueQuadPos_[i].y = static_cast<float>(rand() % 720);
		}

	}


}

void Stage::Draw() {

	//===================
	//背景の四角
	//==================
	for (int i = 0; i < 30; i++) {
		Novice::DrawQuad(
			static_cast<int>(bkRedQuadVertex_[0][i].x),
			static_cast<int>(bkRedQuadVertex_[0][i].y),
			static_cast<int>(bkRedQuadVertex_[1][i].x),
			static_cast<int>(bkRedQuadVertex_[1][i].y),
			static_cast<int>(bkRedQuadVertex_[2][i].x),
			static_cast<int>(bkRedQuadVertex_[2][i].y),
			static_cast<int>(bkRedQuadVertex_[3][i].x),
			static_cast<int>(bkRedQuadVertex_[3][i].y),
			0, 0, 32, 32, bkGH_,
			bkRedQuadColor_
		);

		Novice::DrawQuad(
			static_cast<int>(bkBlueQuadVertex_[0][i].x),
			static_cast<int>(bkBlueQuadVertex_[0][i].y),
			static_cast<int>(bkBlueQuadVertex_[1][i].x),
			static_cast<int>(bkBlueQuadVertex_[1][i].y),
			static_cast<int>(bkBlueQuadVertex_[2][i].x),
			static_cast<int>(bkBlueQuadVertex_[2][i].y),
			static_cast<int>(bkBlueQuadVertex_[3][i].x),
			static_cast<int>(bkBlueQuadVertex_[3][i].y),
			0, 0, 32, 32, bkGH_,
			bkBlueQuadColor_
		);
	}


	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[r][c].getType() != 0) {
				//blockが設置してあればDraw
				block_[r][c].Draw();

				Novice::ScreenPrintf(10, 200, "NSBlockNum:%d", NSBlockNum_);
				Novice::ScreenPrintf(10, 220, "playerHasBlockNum:%d", playerHasBlockNum);

			}
		}
	}

	player_.Draw();
}