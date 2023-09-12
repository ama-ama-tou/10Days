#include "Scene_Clear.h"
#include <stdlib.h>
#include <time.h>

void Scene_Clear::Load() {

	//クリア画像
	clearSize_ = { 64.0f,64.0f };
	for (int i = 0; i < 3; i++) {
		clearPos_[i] = { (1280.0f / 2.0f - clearSize_.x * 2.0f) + (clearSize_.x * 2.0f * i), 720.0f / 2.0f };
		clearVertex_[i][0] = Vec2(clearPos_[i].x - clearSize_.x, clearPos_[i].y - clearSize_.y);
		clearVertex_[i][1] = Vec2(clearPos_[i].x + clearSize_.x, clearPos_[i].y - clearSize_.y);
		clearVertex_[i][2] = Vec2(clearPos_[i].x - clearSize_.x, clearPos_[i].y + clearSize_.y);
		clearVertex_[i][3] = Vec2(clearPos_[i].x + clearSize_.x, clearPos_[i].y + clearSize_.y);
	}
	clearGH_[0] = Novice::LoadTexture("./Resources/image/font/clear1.png");
	clearGH_[1] = Novice::LoadTexture("./Resources/image/font/clear2.png");
	clearGH_[2] = Novice::LoadTexture("./Resources/image/font/clear3.png");

	roatedClearGH_[0] = Novice::LoadTexture("./Resources/image/font/roatedClear1.png");
	roatedClearGH_[1] = Novice::LoadTexture("./Resources/image/font/roatedClear2.png");
	roatedClearGH_[2] = Novice::LoadTexture("./Resources/image/font/roatedClear3.png");

	isRoated_ = false;
	roatedCount_ = 0;

	//周りの丸
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 50; i++) {
		//エレメントの座標をランダムで設定
		elementPos_[i].x = static_cast<float>(rand() % 1280);
		elementPos_[i].y = static_cast<float>(rand() % 720);
		//エレメントの半径をランダムで設定
		inisialElementRadius_[i] = static_cast<float>(rand() % 11 + 30);
		currentElementRadius_[i] = inisialElementRadius_[i];
		//スピードをランダムで設定
		elementSpeed_[i].x = static_cast<float>(rand() % 3 - 1);
		elementSpeed_[i].y = static_cast<float>(rand() % 3 - 1);
	}
	elementColor_ = 0xffffffaa;
	isDisappear_ = false;

	//クリア画像の後ろのline
	linePos_ = { 0.0f ,720.0f / 2.0f };
	lineSize_ = { 1280.0f,3.0f };
	lineGH_ = Novice::LoadTexture("white1x1.png");
	lineVertex_[0] = Vec2(linePos_.x - lineSize_.x, linePos_.y - lineSize_.y);
	lineVertex_[1] = Vec2(linePos_.x + lineSize_.x, linePos_.y - lineSize_.y);
	lineVertex_[2] = Vec2(linePos_.x - lineSize_.x, linePos_.y + lineSize_.y);
	lineVertex_[3] = Vec2(linePos_.x + lineSize_.x, linePos_.y + lineSize_.y);
	lineColor_ = 0xfef263ff;

	//フラッシュ
	flashPos_ = { 0.0f,0.0f };
	flashSize_ = { 1280.0f,720.0f };
	flashVertex_[0] = Vec2(flashPos_.x - flashSize_.x, flashPos_.y - flashSize_.y);
	flashVertex_[1] = Vec2(flashPos_.x + flashSize_.x, flashPos_.y - flashSize_.y);
	flashVertex_[2] = Vec2(flashPos_.x - flashSize_.x, flashPos_.y + flashSize_.y);
	flashVertex_[3] = Vec2(flashPos_.x + flashSize_.x, flashPos_.y + flashSize_.y);
	flashColor_ = 0xffffffff;
	flashGH_ = Novice::LoadTexture("white1x1.png");
	isFlash_ = false;



	//===============
	//クリア演出の効果音
	//===============
	clearSH_ = Novice::LoadAudio("./Resources/sound/SE/clear.mp3");
	clearVH_ = -1;
	soundCount_ = 0;
}

void Scene_Clear::Update() {

	//クリア画像の更新処理
	float vertexMoveSpeed = 2.0f;

	//幅の増加量
	float heightIncrease = 0.5f;

	// 拡大・縮小ステップ数と速度
	int steps = 100;  // ステップ数
	float scaleFactor = 0.5f;  // 拡大・縮小速度

	//=========================
	//	フラッシュの更新処理
	//========================


	flashColor_ -= 0x00000003;

	for (int i = 0; i < 3; i++) {
		//2回回転するまで
		if (roatedCount_ <= 2) {
			if (!isRoated_) {
				if (clearVertex_[i][0].x > clearPos_[i].x + clearSize_.x / 2) {
					isRoated_ = true;
					clearVertex_[i][0].x = clearPos_[i].x - clearSize_.x / 2.0f;
					clearVertex_[i][1].x = clearPos_[i].x + clearSize_.x / 2.0f;
					clearVertex_[i][2].x = clearPos_[i].x - clearSize_.x / 2.0f;
					clearVertex_[i][3].x = clearPos_[i].x + clearSize_.x / 2.0f;
				}
			} else if (clearVertex_[i][0].x > clearPos_[i].x + clearSize_.x / 2) {
				isRoated_ = false;
				//回転した回数をカウント
				roatedCount_++;
			}

			// 座標の更新
			clearVertex_[i][0].x += vertexMoveSpeed;
			clearVertex_[i][1].x -= vertexMoveSpeed;
			clearVertex_[i][2].x += vertexMoveSpeed;
			clearVertex_[i][3].x -= vertexMoveSpeed;

			clearVertex_[i][0].y = clearPos_[i].y - clearSize_.y / 2.0f;
			clearVertex_[i][1].y = clearPos_[i].y - clearSize_.y / 2.0f;
			clearVertex_[i][2].y = clearPos_[i].y + clearSize_.y / 2.0f;
			clearVertex_[i][3].y = clearPos_[i].y + clearSize_.y / 2.0f;


		} else {
			//画面中央まで来たら画像の回転を止める
			isRoated_ = false;
			clearVertex_[i][0] = Vec2(clearPos_[i].x - clearSize_.x / 2.0f, clearPos_[i].y - clearSize_.y / 2.0f);
			clearVertex_[i][1] = Vec2(clearPos_[i].x + clearSize_.x / 2.0f, clearPos_[i].y - clearSize_.y / 2.0f);
			clearVertex_[i][2] = Vec2(clearPos_[i].x - clearSize_.x / 2.0f, clearPos_[i].y + clearSize_.y / 2.0f);
			clearVertex_[i][3] = Vec2(clearPos_[i].x + clearSize_.x / 2.0f, clearPos_[i].y + clearSize_.y / 2.0f);

			//円を消す
			elementColor_ = 0x00000000;

			flashColor_ = 0x00000000;

		}
	}

	//=========================
	//	クリア画像の下のline
	//========================
	if (roatedCount_ <= 2) {
		lineSize_.y += heightIncrease;
	}
	//座標の更新
	lineVertex_[0] = Vec2(linePos_.x - lineSize_.x, linePos_.y - lineSize_.y);
	lineVertex_[1] = Vec2(linePos_.x + lineSize_.x, linePos_.y - lineSize_.y);
	lineVertex_[2] = Vec2(linePos_.x - lineSize_.x, linePos_.y + lineSize_.y);
	lineVertex_[3] = Vec2(linePos_.x + lineSize_.x, linePos_.y + lineSize_.y);



	//=========================
	//	周りの円の更新処理
	//========================

	// elementColor_ が 0x00000000 のとき、処理を終了
	if (elementColor_ >= 0x00000001) {


		for (int k = 0; k < 50; k++) {

		// 半径を拡大または縮小
			if (steps > 0) {
				currentElementRadius_[k] += scaleFactor;
				steps--;

				// 半径が一定値以上になったら反転して縮小
				if (currentElementRadius_[k] >= inisialElementRadius_[k] + 10) {
					scaleFactor = -scaleFactor;
				}
			}
			// 座標の更新
			elementPos_[k].x += elementSpeed_[k].x;
			elementPos_[k].y += elementSpeed_[k].y;
		}
		// elementColor_ の更新
		elementColor_ -= 0x00000002;
	}
}

void Scene_Clear::Draw() {

	if (soundCount_ <= 0) {
		//効果音を鳴らす
		if (Novice::IsPlayingAudio(clearVH_) == 0 || clearVH_ == -1) {
			clearVH_ = Novice::PlayAudio(clearSH_, false, 0.3f);
			soundCount_++;
		}
	}


	//lineの描画
	Novice::DrawQuad(
		static_cast<int>(localCo_.screenFromOrigin(lineVertex_[0]).x),
		static_cast<int>(localCo_.screenFromOrigin(lineVertex_[0]).y),
		static_cast<int>(localCo_.screenFromOrigin(lineVertex_[1]).x),
		static_cast<int>(localCo_.screenFromOrigin(lineVertex_[1]).y),
		static_cast<int>(localCo_.screenFromOrigin(lineVertex_[2]).x),
		static_cast<int>(localCo_.screenFromOrigin(lineVertex_[2]).y),
		static_cast<int>(localCo_.screenFromOrigin(lineVertex_[3]).x),
		static_cast<int>(localCo_.screenFromOrigin(lineVertex_[3]).y),
		0, 0, 32, 32,
		lineGH_, lineColor_
	);


	//エレメントの描画
	for (int i = 0; i < 30; i++) {
		Novice::DrawEllipse(
			static_cast<int>(localCo_.screenFromOrigin(elementPos_[i]).x),
			static_cast<int>(localCo_.screenFromOrigin(elementPos_[i]).y),
			static_cast<int>(currentElementRadius_[i]),
			static_cast<int>(currentElementRadius_[i]),
			0.0f, elementColor_, kFillModeSolid
		);
	}

	//クリア画像の描画

	for (int i = 0; i < 3; i++) {
		if (!isRoated_) {
			Novice::DrawQuad(
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][0]).x),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][0]).y),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][1]).x),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][1]).y),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][2]).x),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][2]).y),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][3]).x),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][3]).y),
				0, 0, 64, 64,
				clearGH_[i], WHITE
			);
		} else {
			Novice::DrawQuad(
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][0]).x),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][0]).y),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][1]).x),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][1]).y),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][2]).x),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][2]).y),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][3]).x),
				static_cast<int>(localCo_.screenFromOrigin(clearVertex_[i][3]).y),
				0, 0, 64, 64,
				roatedClearGH_[i], WHITE
			);
		}
	}

	Novice::DrawQuad(
		static_cast<int>(localCo_.screenFromOrigin(flashVertex_[0]).x),
		static_cast<int>(localCo_.screenFromOrigin(flashVertex_[0]).y),
		static_cast<int>(localCo_.screenFromOrigin(flashVertex_[1]).x),
		static_cast<int>(localCo_.screenFromOrigin(flashVertex_[1]).y),
		static_cast<int>(localCo_.screenFromOrigin(flashVertex_[2]).x),
		static_cast<int>(localCo_.screenFromOrigin(flashVertex_[2]).y),
		static_cast<int>(localCo_.screenFromOrigin(flashVertex_[3]).x),
		static_cast<int>(localCo_.screenFromOrigin(flashVertex_[3]).y),
		0, 0, 32, 32,
		flashGH_, flashColor_
	);

}

void Scene_Clear::Unload() {};