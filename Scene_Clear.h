#pragma once
#include "Scene.h"
#include "Vec2.h"
#include "Coordinate.h"
class Scene_Clear :
	public Scene {

	//===============
	//メンバ変数
	//==============

	Coordinate localCo_{ Vec2(0.0f,0.0f) };

	//クリアの文字
	Vec2 clearPos_[3];
	Vec2 clearSize_;
	Vec2 clearVertex_[3][4];

	int clearGH_[3];
	int roatedClearGH_[3];
	bool isRoated_;
	int roatedCount_;

	//周りの円
	Vec2 elementPos_[30];
	float inisialElementRadius_[30];
	float currentElementRadius_[30];
	Vec2 elementSpeed_[30];
	bool isDisappear_;
	unsigned int elementColor_;

	//クリア画像の後ろのライン
	Vec2 linePos_;
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

	//効果音
	int clearSH_;
	int clearVH_;
	int soundCount_;
	bool isRang_;

	Button goSelect_;

public:
	//===================
	//メンバ関数
	//==================
	void Load()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

	
};

