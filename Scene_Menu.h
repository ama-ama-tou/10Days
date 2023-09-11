#pragma once
#include "Scene.h"
#include"Button.h"


class Scene_Menu :
	public Scene {
private:
	Button game;
	Button setting;
	Button reStart;
	Button backSelect;

public:
	Scene_Menu() { sceneNum = SCENE_MENU; };

	void Load()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

	void setPlayStage(StageNum selectedStage)override { selectedStage; }
	StageNum getSelectedStage()override { return STAGE_1ST; }


};

