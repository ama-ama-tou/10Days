#include "SceneManager.h"

SceneManager::SceneManager() {
	//各シーンの配列
	sceneArr_[SCENE_TITLE] = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_SELECT] = std::make_unique<Scene_Select>();
	sceneArr_[SCENE_GAME] = std::make_unique<Scene_Game>();
	sceneArr_[SCENE_CLEAR] = std::make_unique<Scene_Clear>();
	//初期シーン
	sceneNo_ = SCENE_TITLE;
	sceneArr_[sceneNo_]->Load();
	
	bg.Init(Vec2(0.0f, 0.0f),kWindowSize, 0xf0f8ffff);
}

void SceneManager::Update() {
	///=======================
	///更新処理
	
	//前フレームのシーンナンバーを保存
	preSceneNo_ = sceneNo_;
	
	sceneNo_ = sceneArr_[sceneNo_]->getSceneNum();
	
	if (sceneNo_ != preSceneNo_) {
		if (sceneNo_!=SCENE_SELECT&&preSceneNo_!=SCENE_TITLE) {
			if (preSceneNo_==SCENE_SELECT) {
				sceneArr_[SCENE_TITLE]->Unload();
			}
			sceneArr_[preSceneNo_]->Unload();
		}
		
		//シーンが変わったら初期化
		sceneArr_[sceneNo_]->Load();
	}
	
	

		sceneArr_[sceneNo_]->Update();
	
		exit_ = sceneArr_[sceneNo_]->getIsExitGame();

	///=======================

	///=======================
	///描画処理
		bg.Draw();
		sceneArr_[sceneNo_]->Draw();
		
	///=======================
	
}

