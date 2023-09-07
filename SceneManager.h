#pragma once
#include"Scene.h"
#include"Scene_Title.h"
#include"Scene_Select.h"
#include"Scene_Game.h"
#include"InputManager.h"

class SceneManager {
private:

	InputManager* inputManager = InputManager::GetInstance();
	std::unique_ptr<Scene> sceneArr_[3];

	int sceneNum_;
	int preSceneNum_;

public:

	SceneManager();

	void Update();

};

