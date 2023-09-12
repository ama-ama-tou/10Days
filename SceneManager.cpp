#include "SceneManager.h"

SceneManager::SceneManager() {
	//各シーンの配列
	sceneArr_[SCENE_TITLE] = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_SELECT] = std::make_unique<Scene_Select>();
	sceneArr_[SCENE_GAME] = std::make_unique<Scene_Game>();
	sceneArr_[SCENE_CLEAR] = std::make_unique<Scene_Clear>();
	//初期シーン
	sceneNo_ = SCENE_TITLE;

	bg.Init(Vec2(0.0f, 0.0f),kWindowSize, 0x7d7b83ff);
}

void SceneManager::Update() {
	///=======================
	///更新処理
	
	//前フレームのシーンナンバーを保存
	preSceneNo_ = sceneNo_;
	
	sceneNo_ = sceneArr_[sceneNo_]->getSceneNum();

	if (sceneNo_ != preSceneNo_) {
		//シーンが変わったら初期化
		sceneArr_[sceneNo_]->Load();

		if (preSceneNo_ == SCENE_SELECT && sceneNo_ == SCENE_GAME) {
			//セレクト画面で選ばれたステージを受け取る
			sceneArr_[SCENE_GAME]->setPlayStage(sceneArr_[SCENE_SELECT]->getSelectedStage());
		}
	}
	
		sceneArr_[sceneNo_]->Update();
	
	///=======================

	///=======================
	///描画処理
		//bg.Draw();
		sceneArr_[sceneNo_]->Draw();
	
	///=======================
	
}

