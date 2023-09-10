﻿#pragma once
#include "Scene.h"
#include"Button.h"
#include"Quad.h"

class Scene_Title:
	public Scene{

private:
	Quad titleBar;
	Button Button_goSelect;
	Button Button_goManu;
	Button Button_exit;

	int SH_ = 0;
	int VH_ = 0;

public:
	Scene_Title() { sceneNum = SCENE_TITLE; }

	void Load()override;

	void Update()override;

	void Draw()override;

	void Unload()override;
	
	//使わない
	StageNum getSelectedStage()override { return STAGE_1ST; }
	void setPlayStage(StageNum selectedStage)override { selectedStage; }

};

