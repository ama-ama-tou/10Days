#include "Scene_Game.h"

Scene_Game::Scene_Game() {
	stageArr_[STAGE_1ST] = std::make_unique<Stage>("./Resources/csv/stage1.csv");
	stageArr_[STAGE_2ND] = std::make_unique<Stage>("./Resources/csv/stage2.csv");
	stageArr_[STAGE_3RD] = std::make_unique<Stage>("./Resources/csv/stage3.csv");
	stageArr_[STAGE_4TH] = std::make_unique<Stage>("./Resources/csv/stage4.csv");
	stageArr_[STAGE_5TH] = std::make_unique<Stage>("./Resources/csv/stage5.csv");
	stageArr_[STAGE_6TH] = std::make_unique<Stage>("./Resources/csv/stage6.csv");
	stageArr_[STAGE_7TH] = std::make_unique<Stage>("./Resources/csv/stage7.csv");
	stageArr_[STAGE_8TH] = std::make_unique<Stage>("./Resources/csv/stage8.csv");
	stageArr_[STAGE_9TH] = std::make_unique<Stage>("./Resources/csv/stage9.csv");
	stageArr_[STAGE_10TH] = std::make_unique<Stage>("./Resources/csv/stage10.csv");
	stageArr_[STAGE_11TH] = std::make_unique<Stage>("./Resources/csv/stage11.csv");
	stageArr_[STAGE_12TH] = std::make_unique<Stage>("./Resources/csv/stage12.csv");

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

	Novice::StopAudio(backgroundVH_);
	backgroundSH_ = Novice::LoadAudio("./Resources/sound/BGM/play.mp3");
	backgroundVH_ = -1;
	isRang_ = false;

	stageArr_[stageNum_]->Init();
}

void Scene_Game::Update() {
	goSelect_.Update(inputManager->getMousePos(),inputManager->getClickState());

	if (goSelect_.getISInsideMouse() == true) {
		if (goSelect_.getIsClicked() == true) {
			Scene::sceneNum = SCENE_SELECT;
			Novice::StopAudio(backgroundVH_);
			isRang_ = true;

		}
	}


	if (stageNum_ == STAGE_1ST) {
		stageArr_[STAGE_1ST]->Tutorial(inputManager->GetKeys(), inputManager->GetPreKeys(), inputManager->getClickState());
	} else {
		stageArr_[stageNum_]->Update(inputManager->GetKeys(), inputManager->GetPreKeys());
	}

	if (stageArr_[stageNum_]->getIsClear()) {
		Scene::sceneNum = SCENE_CLEAR;
	}
	Novice::ScreenPrintf(100, 100, "stageNum=%d", stageNum_);

}

void Scene_Game::Draw() {
	if (!isRang_) {
		//bgmを鳴らす
		if (Novice::IsPlayingAudio(backgroundVH_) == 0 || backgroundVH_ == -1) {
			backgroundVH_ = Novice::PlayAudio(backgroundSH_, true, 0.3f);
		}
	}
	

	goSelect_.Draw();
	
	if (stageNum_ == STAGE_1ST) {
		stageArr_[STAGE_1ST]->TutorialDraw();
	} else {
		stageArr_[stageNum_]->Draw();
	}
}

void Scene_Game::Unload() {
	Novice::StopAudio(backgroundVH_);
	stageArr_[stageNum_]->Unload();
};