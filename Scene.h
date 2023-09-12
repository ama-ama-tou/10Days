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
	STAGE_12TH/*,
	STAGE_13TH,
	STAGE_14TH,
	STAGE_15TH,*/
};

enum SceneNum {
	SCENE_TITLE,
	SCENE_SELECT,
	SCENE_GAME,
	SCENE_CLEAR
};

class Scene{
private:

	bool isExitGame_;
	static int stageNum_;


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

	int getStageNum() { return stageNum_; }
	void setStageNum(int stageNum) { stageNum_ = stageNum; }

	bool getIsExitGame() { return isExitGame_; }
	void setIsExitGame(bool exit) { isExitGame_ = exit; }

};


