#pragma once
#include "Scene.h"
class Scene_Menu :
	public Scene {
private:




public:
	Scene_Menu() {};

	void Load()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

	void setPlayStage(StageNum selectedStage) { selectedStage; }
	StageNum getSelectedStage() { return STAGE_1ST; }


};

