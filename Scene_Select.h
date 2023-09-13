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

	//選んでるステージを示す三角
	Quad triangle_;
	Vec2 trianglePos_;
	Vec2 triangleSize_;
	Vec2 triangleVertex_[4];
	int triangleGH_;
	int selectNum_;

	

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

