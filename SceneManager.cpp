#include "SceneManager.h"

SceneManager::SceneManager() {
	//各シーンの配列
	sceneArr_[SCENE_TITLE] = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_MENU] = std::make_unique<Scene_Menu>();
	sceneArr_[SCENE_SELLECT] = std::make_unique<Scene_Select>();
	sceneArr_[SCENE_GAME] = std::make_unique<Scene_Game>();

	//初期シーン
	sceneNo_ = SCENE_TITLE;
}

void SceneManager::Update() {
	preSceneNo_ = sceneNo_;

	sceneNo_ = sceneArr_[sceneNo_]->getSceneNum();

	if (sceneNo_!=preSceneNo_) {
		//シーンが変わったら初期化
		sceneArr_[sceneNo_]->Load();
		if (preSceneNo_==SCENE_SELLECT&&sceneNo_==SCENE_GAME) {
			//セレクト画面で選ばれたステージを受け取る
			sceneArr_[SCENE_GAME]->setPlayStage(sceneArr_[SCENE_SELLECT]->getSelectedStage());
		}
	}

	//現在のシーンの更新処理
	sceneArr_[sceneNo_]->Update();

	//現在のシーンの描画処理
	sceneArr_[sceneNo_]->Draw();
}

