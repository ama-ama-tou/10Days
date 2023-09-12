#pragma once
#include "Scene.h"
#include"Stage.h"


class Scene_Game:
	public Scene {

	int preStageNum;

	int backgroundSH_;
	int backgroundVH_;

	std::unique_ptr<Stage> stageArr_[12];

public:
	Scene_Game();
	~Scene_Game();
	void Load()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

};

