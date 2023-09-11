#pragma once
#include"Scene.h"
#include"Scene_Title.h"
#include"Scene_Select.h"
#include"Scene_Game.h"
#include"InputManager.h"
#include"box.h"


class SceneManager {
private:

	std::unique_ptr<Scene> sceneArr_[3];

	int sceneNo_;
	int preSceneNo_;

	//バックグラウンド
	Box bg;


public:
	SceneManager();

	void Update();

};

