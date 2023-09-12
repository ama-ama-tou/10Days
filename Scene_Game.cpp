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

	stageNum = STAGE_1ST;

	
}

Scene_Game::~Scene_Game() {
}

void Scene_Game::Load() {

	backgroundSH_ = Novice::LoadAudio("./Resources/sound/BGM/play.mp3");
	backgroundVH_ = -1;


	stageArr_[stageNum]->Init();
}

void Scene_Game::Update() {
	


	stageArr_[stageNum]->Update(inputManager->GetKeys(), inputManager->GetPreKeys());
	
	if (stageArr_[stageNum]->getIsClear()) {
		Scene::sceneNum = SCENE_CLEAR;
	}

}

void Scene_Game::Draw() {

	//bgmを鳴らす
	if (Novice::IsPlayingAudio(backgroundSH_) == false) {
		Novice::PlayAudio(backgroundSH_, true, 0.5f);
	}

	stageArr_[stageNum]->Draw();
}

void Scene_Game::Unload() {
	Novice::StopAudio(backgroundVH_);
};