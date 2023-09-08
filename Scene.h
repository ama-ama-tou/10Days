#pragma once
#include"InputManager.h"
#include"Vec2.h"
#include"Stage.h"

enum StageNum {
	STAGE_1ST,
	STAGE_2ND,
	STAGE_3RD,
	STAGE_4TH,
	STAGE_5TH,
	STAGE_6TH,
	STAGE_7TH,
	STAGE_8TH,
	STAGE_9TH,
	STAGE_10TH,
	STAGE_11TH,
	STAGE_12TH,
	STAGE_13TH,
	STAGE_14TH,
	STAGE_15TH,
};

enum SceneNum {
	SCENE_TITLE,
	SCENE_SELLECT,
	SCENE_GAME,
	SCENE_MENU
};

class Scene{
protected:
	InputManager* inputManager = InputManager::GetInstance();
	static int sceneNum;

public :

	virtual ~Scene(){};

	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;

	int getSceneNum() { return sceneNum; }

	virtual void setPlayStage(StageNum selectedStage)=0;
	virtual StageNum getSelectedStage() = 0;
};

int Scene::sceneNum = SCENE_TITLE;
