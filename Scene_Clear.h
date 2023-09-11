#pragma once
#include "Scene.h"
#include "Vec2.h"
class Scene_Clear :
	public Scene {

	//===============
	//メンバ変数
	//==============

	//クリアの文字
	Vec2 clearPos_;
	Vec2 clearSize_;
	Vec2 clearVertex_[4];

	int clearGH_;
	int roatedClearGH_;
	bool isRoated_;

	//周りの円
	Vec2 elementPos_[50];
	float inisialElementRadius_[50];
	float currentElementRadius_[50];
	bool isDisaappear_;

	//クリア画像の後ろのライン
	Vec2 LINEpOS_;
	Vec2 lineSize_;
	Vec2 lineVertex_[4];
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
	//===================
	//メンバ関数
	//==================
	void Load();
	void Update();
	void Draw();
	void Unload();

};

