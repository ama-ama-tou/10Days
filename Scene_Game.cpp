#include "Scene_Game.h"

Scene_Game::Scene_Game() {
	stageArr_[STAGE_1ST] = std::make_unique<Stage>(STAGE_1ST, "./Resources/csv/stage1.csv");
	stageArr_[STAGE_2ND] = std::make_unique<Stage>(STAGE_2ND, "./Resources/csv/stage2.csv");
	stageArr_[STAGE_3RD] = std::make_unique<Stage>(STAGE_3RD, "./Resources/csv/stage3.csv");
	stageArr_[STAGE_4TH] = std::make_unique<Stage>(STAGE_4TH, "./Resources/csv/stage4.csv");
	stageArr_[STAGE_5TH] = std::make_unique<Stage>(STAGE_5TH, "./Resources/csv/stage5.csv");
	stageArr_[STAGE_6TH] = std::make_unique<Stage>(STAGE_6TH, "./Resources/csv/stage6.csv");
	stageArr_[STAGE_7TH] = std::make_unique<Stage>(STAGE_7TH, "./Resources/csv/stage7.csv");
	stageArr_[STAGE_8TH] = std::make_unique<Stage>(STAGE_8TH, "./Resources/csv/stage8.csv");
	stageArr_[STAGE_9TH] = std::make_unique<Stage>(STAGE_9TH, "./Resources/csv/stage9.csv");
	stageArr_[STAGE_10TH] = std::make_unique<Stage>(STAGE_10TH, "./Resources/csv/stage10.csv");
	stageArr_[STAGE_11TH] = std::make_unique<Stage>(STAGE_11TH, "./Resources/csv/stage11.csv");
	stageArr_[STAGE_12TH] = std::make_unique<Stage>(STAGE_12TH, "./Resources/csv/stage12.csv");

	stageNum_ = STAGE_1ST;
}

Scene_Game::~Scene_Game() {

}

void Scene_Game::Load() {

	//--------------------------------
	//ボタンの初期化	
	//--------------------------------

	//セレクト画面に戻るボタン
	Vec2 goSelectPos = Vec2(20.0f, 10.0f);
	Vec2 goSelectButtonImageSize{ 760.0f,220.0f };
	Vec2 goSelectButtonSize{ 190.0f,55.0f };

	const char* goSelectGH = "./Resources/image/obj/button/goSelectSceneButton.png";
	goSelect_.Init(goSelectPos, goSelectButtonSize, Vec2(0.0f, 0.0f),
		goSelectGH, 0x53558bff, WHITE,
		Vec2(0.0f, 0.0f), goSelectButtonImageSize);


	stageArr_[stageNum_]->Init();
}

void Scene_Game::Update() {
	stageArr_[stageNum_]->Update(inputManager->GetKeys(), inputManager->GetPreKeys());
	
	//ボタンの更新
	goSelect_.Update(inputManager->getMousePos(), inputManager->getClickState());

	if (goSelect_.getISInsideMouse() == true) {
		if (goSelect_.getIsClicked() == true) {
			Scene::sceneNum = SCENE_SELECT;
		}
	}



	if (stageArr_[stageNum_]->getIsClear()) {
		Scene::sceneNum = SCENE_CLEAR;
	}
	Novice::ScreenPrintf(100, 100, "stageNum=%d", stageNum_);

}

void Scene_Game::Draw() {

	goSelect_.Draw();

	stageArr_[stageNum_]->Draw();
}

void Scene_Game::Unload() {
	
};