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
		bkRedQuadPos_[i].x = static_cast<float>(rand() % 1280);
		bkRedQuadPos_[i].y = static_cast<float>(rand() % 720);
		//サイズをランダムで設定
		bkRedQuadSize_[i].x = static_cast<float>(rand() % 11 + 10);
		bkRedQuadSize_[i].y = bkRedQuadSize_[i].x;
		//最大・最小拡縮量
		bkRedQuadScaleValue_[i] = { 0.1f,0.1f };
		bkRedQuadMinScale_[i] = { bkRedQuadSize_[i].x - 5.0f,bkRedQuadSize_[i].y - 5.0f };
		bkRedQuadMaxScale_[i] = { bkRedQuadSize_[i].x + 5.0f,bkRedQuadSize_[i].y + 5.0f };
		//スピードをランダムで設定
		do {
			bkRedQuadSpeed_[i].x = static_cast<float>(rand() % 3 - 1);
			bkRedQuadSpeed_[i].y = static_cast<float>(rand() % 3 - 1);
		} while (bkRedQuadSpeed_[i] == 0);

		bkRedQuadColor_[i] = 0xffb8b8aa;
		//引いて薄くさせる色
		subtractiveColorRed_[i] = 0x00000001;

		//===================
		//青色の四角
		//==================

		//座標をランダムで設定
		bkBlueQuadPos_[i].x = static_cast<float>(rand() % 1280);
		bkBlueQuadPos_[i].y = static_cast<float>(rand() % 720);
		//サイズをランダムで設定
		bkBlueQuadSize_[i].x = static_cast<float>(rand() % 11 + 10);
		bkBlueQuadSize_[i].y = bkBlueQuadSize_[i].x;
		//最大・最小拡縮量
		bkBlueQuadScaleValue_[i] = { 0.1f,0.1f };
		bkBlueQuadMinScale_[i] = { bkBlueQuadSize_[i].x - 5.0f,bkBlueQuadSize_[i].y - 5.0f };
		bkBlueQuadMaxScale_[i] = { bkBlueQuadSize_[i].x + 5.0f,bkBlueQuadSize_[i].y + 5.0f };
		//スピードをランダムで設定
		do {
			bkBlueQuadSpeed_[i].x = static_cast<float>(rand() % 3 - 1);
			bkBlueQuadSpeed_[i].y = static_cast<float>(rand() % 3 - 1);
		} while (bkBlueQuadSpeed_[i] == 0);

		bkBlueQuadColor_[i] = 0xb8cfffaa;
		subtractiveColorBlue_[i] = 0x00000001;

	}

	backgroundSH_ = Novice::LoadAudio("./Resources/sound/BGM/play.mp3");
	backgroundVH_ = -1;
}

void Stage::Update(char* keys, char* preKeys) {
	player_.Update(keys, preKeys);

	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[r][c].getType() != WALL) {
				if (block_[r][c].getIsHadBlock() == true) {
					block_[r][c].setType(block_[r][c].getType());
					block_[r][c].Update(player_.getScreenLtVertex());
					block_[r][c].HitUpdate();
				}
			}
		}
	}

	collision->playerCollision(player_, block_);
	collision->blockCollision(player_, block_);

	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[r][c].getType() != WALL) {
				if (block_[r][c].getIsHadBlock() == true) {
					block_[r][c].Update(player_.getScreenLtVertex());
					block_[r][c].HitUpdate();
				}
			}

			
		}
	}

	//デバック用
	collision->Draw(block_);



	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[r][c].getIsHadBlock() == true && block_[r][c].getIsPreHadBlock() == false) {
				//クリア条件
				playerHasBlockNum++;
			}
		}
	}
	Novice::ScreenPrintf(10, 500, "hasBlock=%d, goalBlocks=%d", playerHasBlockNum, NSBlockNum_);


	if (playerHasBlockNum == NSBlockNum_) {
		isClear_ = true;
	}




	//背景の動き
	for (int i = 0; i < 20; i++) {

		//===================
		//赤色の四角
		//==================

			//quadの移動
		bkRedQuadPos_[i] += bkRedQuadSpeed_[i];

		//座標の更新
		bkRedQuadVertex_[i][0] = { bkRedQuadPos_[i].x - bkRedQuadSize_[i].x,bkRedQuadPos_[i].y - bkRedQuadSize_[i].y };
		bkRedQuadVertex_[i][1] = { bkRedQuadPos_[i].x + bkRedQuadSize_[i].x,bkRedQuadPos_[i].y - bkRedQuadSize_[i].y };
		bkRedQuadVertex_[i][2] = { bkRedQuadPos_[i].x - bkRedQuadSize_[i].x,bkRedQuadPos_[i].y + bkRedQuadSize_[i].y };
		bkRedQuadVertex_[i][3] = { bkRedQuadPos_[i].x + bkRedQuadSize_[i].x,bkRedQuadPos_[i].y + bkRedQuadSize_[i].y };

		//拡縮
		bkRedQuadSize_[i] += bkRedQuadScaleValue_[i];
		if (bkRedQuadSize_[i] >= bkRedQuadMaxScale_[i]) {
			bkRedQuadScaleValue_[i] *= Vec2(-1, -1);
		} else if (bkRedQuadSize_[i] <= bkRedQuadMinScale_[i]) {
			bkRedQuadScaleValue_[i] *= Vec2(-1, -1);
		}

		//色の制御
		bkRedQuadColor_[i] += subtractiveColorRed_[i];
		if (bkRedQuadColor_[i] == 0xffb8b8cc) {
			subtractiveColorRed_[i] *= -1;
		} else if (bkRedQuadColor_[i] == 0xffb8b811) {
			subtractiveColorRed_[i] *= -1;
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
		bkBlueQuadVertex_[i][0] = { bkBlueQuadPos_[i].x - bkBlueQuadSize_[i].x,bkBlueQuadPos_[i].y - bkBlueQuadSize_[i].y };
		bkBlueQuadVertex_[i][1] = { bkBlueQuadPos_[i].x + bkBlueQuadSize_[i].x,bkBlueQuadPos_[i].y - bkBlueQuadSize_[i].y };
		bkBlueQuadVertex_[i][2] = { bkBlueQuadPos_[i].x - bkBlueQuadSize_[i].x,bkBlueQuadPos_[i].y + bkBlueQuadSize_[i].y };
		bkBlueQuadVertex_[i][3] = { bkBlueQuadPos_[i].x + bkBlueQuadSize_[i].x,bkBlueQuadPos_[i].y + bkBlueQuadSize_[i].y };

		//拡縮
		bkBlueQuadSize_[i] += bkBlueQuadScaleValue_[i];
		if (bkBlueQuadSize_[i] >= bkBlueQuadMaxScale_[i]) {
			bkBlueQuadScaleValue_[i] *= Vec2(-1, -1);
		} else if (bkBlueQuadSize_[i] <= bkBlueQuadMinScale_[i]) {
			bkBlueQuadScaleValue_[i] *= Vec2(-1, -1);
		}



		//色の制御
		bkBlueQuadColor_[i] += subtractiveColorBlue_[i];
		if (bkBlueQuadColor_[i] == 0xb8cfffcc) {
			subtractiveColorBlue_[i] *= -1;
		} else if (bkBlueQuadColor_[i] == 0xb8cfff11) {
			subtractiveColorBlue_[i] *= -1;
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

	//bgmを鳴らす
	if (Novice::IsPlayingAudio(backgroundVH_) == 0 || backgroundVH_ == -1) {
		backgroundVH_=Novice::PlayAudio(backgroundSH_, true, 0.5f);
	}

	//===================
	//背景の四角
	//==================
	for (int i = 0; i < 20; i++) {
		Novice::DrawQuad(
			static_cast<int>(bkRedQuadVertex_[i][0].x),
			static_cast<int>(bkRedQuadVertex_[i][0].y),
			static_cast<int>(bkRedQuadVertex_[i][1].x),
			static_cast<int>(bkRedQuadVertex_[i][1].y),
			static_cast<int>(bkRedQuadVertex_[i][2].x),
			static_cast<int>(bkRedQuadVertex_[i][2].y),
			static_cast<int>(bkRedQuadVertex_[i][3].x),
			static_cast<int>(bkRedQuadVertex_[i][3].y),
			0, 0, 32, 32, bkGH_,
			bkRedQuadColor_[i]
		);

		Novice::DrawQuad(
			static_cast<int>(bkBlueQuadVertex_[i][0].x),
			static_cast<int>(bkBlueQuadVertex_[i][0].y),
			static_cast<int>(bkBlueQuadVertex_[i][1].x),
			static_cast<int>(bkBlueQuadVertex_[i][1].y),
			static_cast<int>(bkBlueQuadVertex_[i][2].x),
			static_cast<int>(bkBlueQuadVertex_[i][2].y),
			static_cast<int>(bkBlueQuadVertex_[i][3].x),
			static_cast<int>(bkBlueQuadVertex_[i][3].y),
			0, 0, 32, 32, bkGH_,
			bkBlueQuadColor_[i]
		);
	}


	for (int r = 0; r < row_; r++) {
		for (int c = 0; c < col_; c++) {
			if (block_[r][c].getType() != NONE) {
				//blockが設置してあればDraw
				block_[r][c].Draw();

				Novice::ScreenPrintf(10, 200, "NSBlockNum:%d", NSBlockNum_);
				Novice::ScreenPrintf(10, 220, "playerHasBlockNum:%d", playerHasBlockNum);

			}
		}
	}
	player_.Draw();

}

