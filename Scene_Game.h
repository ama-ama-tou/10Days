#pragma once
#include "Scene.h"
#include"Stage.h"


class Scene_Game:
	public Scene {

	int preStageNum;

	Button goSelect_;

	int backgroundSH_;
	int backgroundVH_;
	bool isRang_;

	std::unique_ptr<Stage> stageArr_[12];

public:
	Scene_Game();
	~Scene_Game();
	void Load()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

	int getBackgroundVH() { return backgroundVH_; }

};

