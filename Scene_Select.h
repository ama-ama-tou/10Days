#pragma once
#include "Scene.h"
#include "Button.h"
#include"Stage.h"

class Scene_Select:
	public Scene {
private:
	//======================
	//メンバ変数
	//======================
	Button go2Title;
	
	Button stage_[12];

	int stageSelectSH_;
	int stageSelectVH_;
	int frameCount_;
	bool isRang_;

	Quad selectBar_;

public:
	//======================
	//メンバ関数
	//======================
	Scene_Select() { };

	void Load()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

	//=======================
	//ゲッター
	//=======================
	


};

