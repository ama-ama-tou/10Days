﻿#pragma once
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

	Button stage_[9];
	
public:
	//======================
	//メンバ関数
	//======================
	void Load()override;
	void Update()override;
	void Draw()override;
	void Unload()override;




	//=======================
	//ゲッター
	//=======================
	StageNum getSelectedStage(Vec2 mousePos, int clickState);




};

