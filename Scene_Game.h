#pragma once
#include "Scene.h"
#include"Stage.h"


class Scene_Game:
	public Scene {

	int stageNum;
	int preStageNum;

	std::unique_ptr<Stage> stageArr_[12];

public:
	Scene_Game();

	void Load()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

	//問題点セットできない(未解決)
	StageNum setPlayStage(StageNum selectedStage)override { stageNum = selectedStage; }
};

