#include "SceneManager.h"

SceneManager::SceneManager() {
	//各シーンの配列
	sceneArr_[SCENE_TITLE] = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_MENU] = std::make_unique<Scene_Menu>();
	sceneArr_[SCENE_SELECT] = std::make_unique<Scene_Select>();
	sceneArr_[SCENE_GAME] = std::make_unique<Scene_Game>();

	//初期シーン
	sceneNo_ = SCENE_TITLE;
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
	switch (sceneNo_) {
	case SCENE_TITLE:
		sceneArr_[sceneNo_]->Update();
		break;
	case SCENE_MENU:
		sceneArr_[sceneNo_]->Update();
		break;
	case SCENE_SELECT:
		sceneArr_[sceneNo_]->Update();
		break;
	case SCENE_GAME:
		sceneArr_[sceneNo_]->Update();
		break;
	default:
		break;
	}
	///=======================

	///=======================
	///描画処理
	switch (sceneNo_) {
	case SCENE_TITLE:
		sceneArr_[sceneNo_]->Draw();
		break;
	case SCENE_SELECT:
		sceneArr_[sceneNo_]->Draw();
		if (sceneNo_ != SCENE_MENU) {
			break;
		}
	case SCENE_GAME:
		sceneArr_[sceneNo_]->Draw();
		if (sceneNo_!=SCENE_MENU) {
			break;
		}
	case SCENE_MENU:
		sceneArr_[sceneNo_]->Draw();
		break;
	default:
		break;
	}
	//現在のシーンの描画処理
	
}

