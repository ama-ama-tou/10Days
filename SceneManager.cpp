#include "SceneManager.h"

SceneManager::SceneManager() {
	//各シーンの配列
	sceneArr_[SCENE_TITLE] = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_SELLECT] = std::make_unique<Scene_Select>();
	sceneArr_[SCENE_GAME] = std::make_unique<Scene_Game>();

	//初期シーン
	sceneNum_ = SCENE_TITLE;
}

void SceneManager::Update() {
	preSceneNum_ = sceneNum_;

	
	if (sceneNum_!=preSceneNum_) {
		//シーンが変わったら初期化
		sceneArr_[sceneNum_]->Load();
		if (preSceneNum_==SCENE_SELLECT&&sceneNum_==SCENE_GAME) {
			//セレクト画面で選ばれたステージを受け取る
			sceneArr_[SCENE_GAME]->setPlayStage(sceneArr_[SCENE_SELLECT]->getSelectedStage());
		}
	}

	//現在のシーンの更新処理
	sceneArr_[sceneNum_]->Update();

	//現在のシーンの描画処理
	sceneArr_[sceneNum_]->Draw();


}

