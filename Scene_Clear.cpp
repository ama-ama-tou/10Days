#include "Scene_Clear.h"
#include <stdlib.h>
#include <time.h>

void Scene_Clear::Load() {

	//クリア画像
	clearSize_ = { 64.0f,64.0f };
	for (int i = 0; i < 3; i++) {
		clearPos_[i] = { (1280.0f / 2.0f - clearSize_.x * 2.0f) + (clearSize_ * 2.0f * i),720.0f / 2.0f };
		clearVertex_[i][0] = Vec2(clearPos_[i].x - clearSize_.x, clearPos_[i].y - clearSize_.y);
		clearVertex_[i][1] = Vec2(clearPos_[i].x + clearSize_.x, clearPos_[i].y - clearSize_.y);
		clearVertex_[i][2] = Vec2(clearPos_[i].x - clearSize_.x, clearPos_[i].y + clearSize_.y);
		clearVertex_[i][3] = Vec2(clearPos_[i].x + clearSize_.x, clearPos_[i].y + clearSize_.y);
	}
	clearGH_[1] = Novice::LoadTexture("./Resources/image/font/clear1");
	clearGH_[2] = Novice::LoadTexture("./Resources/image/font/clear2");
	clearGH_[3] = Novice::LoadTexture("./Resources/image/font/clear3");

	roatedClearGH_[1] = Novice::LoadTexture("./Resources/image/font/roatedClear1");
	roatedClearGH_[2] = Novice::LoadTexture("./Resources/image/font/roatedClear2");
	roatedClearGH_[3] = Novice::LoadTexture("./Resources/image/font/roatedClear3");

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
	isDisaappear_ = false;

	//クリアの後ろのライン
	linePos_ = { 0.0f,720.0f / 2.0f };
	lineSize_ = { 1280.9f,3.0f };
	lineVertex_[0] = { linePos_.x - lineSize_.x / 2.0f,linePos_.y - lineSize_.y / 2.0f };
	lineVertex_[1] = { linePos_.x + lineSize_.x / 2.0f,linePos_.y - lineSize_.y / 2.0f };
	lineVertex_[2] = { linePos_.x - lineSize_.x / 2.0f,linePos_.y + lineSize_.y / 2.0f };
	lineVertex_[3] = { linePos_.x + lineSize_.x / 2.0f,linePos_.y + lineSize_.y / 2.0f };
	
	lineGH_ = Novice::LoadTexture("white1x1.png");
	lineColor_ = 0xfef263ff;

	//フラッシュ
	flashPos_ = { 0.0f,0.0f };
	flashSize_ = { 1280.0f,720.0f };
	flashVertex_[0] = flashPos_;
	flashVertex_[1] = { flashPos_.x + flashSize_.x,flashPos_.y };
	flashVertex_[2] = { flashPos_.x,flashPos_.y + flashSize_.y };
	flashVertex_[3] = { flashPos_.x + flashSize_.x,flashPos_.y + flashSize_ };

	flashGH_ = Novice::LoadTexture("white1x1.png");
	flashColor_ = 0xffffffff;
	isFlash_ = false;
}