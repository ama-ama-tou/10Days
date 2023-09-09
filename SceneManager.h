#pragma once
#include"Scene.h"
#include"Scene_Title.h"
#include "Scene_Menu.h"
#include"Scene_Select.h"
#include"Scene_Game.h"
#include"InputManager.h"

class SceneManager {
private:

	std::unique_ptr<Scene> sceneArr_[4];

	int sceneNo_;
	int preSceneNo_;

public:
	SceneManager();

	void Update();

};

