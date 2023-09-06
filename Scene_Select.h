#pragma once
#include "Scene.h"
#include "Button.h"

class Scene_Select:
	public Scene {

	
private:

	//======================
	//メンバ変数
	//======================

	Button stage_[9];
	
public:
	//=======================
	//ゲッター
	//=======================
	int getSelectedStage(Vec2 mousePos, int clickState);




};

