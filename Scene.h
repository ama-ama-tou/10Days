#pragma once
#include"InputManager.h"


enum SceneNum {
	SCENE_TITLE,
	SCENE_MENU,
	SCENE_STAGESELLECT,
	SCENE_GAME,
};

class Scene{
protected:
	InputManager* inputManager = InputManager::GetInstance();
	static int sceneNum;

public :

	virtual void Load() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Unload() = 0;

};

