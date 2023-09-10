#pragma once
#include "Scene.h"
class Scene_Clear :
	public Scene {

private:

	//==================
	//メンバ変数
	//==================

	//クリア画像
	Vec2 clearImagePos_[3];
	Vec2 clearImageSize_;
	Vec2 clearImageVertex_[3][4];

	int clearGH_;
	int roagedClearGH_;

	//周りの丸
	Vec2 elementPos_[50];
	float inisialElementRadius_[50];
	float currentElementRadius_[50];
	Vec2 elementSpeed_[50];
	unsigned int elementColor_;
	bool isDisappear_;

	//クリア画像の後ろのline
	Vec2 linePos_;
	Vec2 lineSize_;
	Vec2 lineVertex[4];
	int lineGH_;
	unsigned int lineColor_;

	//フラッシュ
	Vec2 flashPos_;
	Vec2 flashSize_;
	Vec2 flashVertex_[4];
	unsigned int flashColor_;
	int flashGH_;
	bool isFlash_;

public:
	//==============
	//メンバ関数
	//=============

	void Init() {

	//クリア画像
		clearImageSize_ = { 64.0f,64.0f };
		for (int i = 0; i < 3; i++) {
			clearImagePos_[3] = { (1280.0f / 2.0f - clearImageSize_.x * 2.0f) + (clearImageSize_.x * 2.0f * i), 720.0f / 2.0f };
			clearImageVertex_[i][0] = Vec2(clearImagePos_[i].x - clearImageSize_.x, clearImagePos_[i].y - clearImageSize_.y);
			clearImageVertex_[i][1] = Vec2(clearImagePos_[i].x + clearImageSize_.x, clearImagePos_[i].y - clearImageSize_.y);
			clearImageVertex_[i][2] = Vec2(clearImagePos_[i].x - clearImageSize_.x, clearImagePos_[i].y + clearImageSize_.y);
			clearImageVertex_[i][3] = Vec2(clearImagePos_[i].x + clearImageSize_.x, clearImagePos_[i].y + clearImageSize_.y);
		}
		clearGH_ = Novice::LoadTexture("./Resources/image/3.png")

	}
};

