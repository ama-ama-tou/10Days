#include "Scene_Game.h"

Scene_Game::Scene_Game() {
	stageArr_[STAGE_1ST] = std::make_unique<Stage>("./Resources/csv/stage1.CSV");
	stageArr_[STAGE_2ND] = std::make_unique<Stage>("./Resources/csv/stage2.CSV");
	stageArr_[STAGE_3RD] = std::make_unique<Stage>("./Resources/csv/stage3.CSV");
	stageArr_[STAGE_4TH] = std::make_unique<Stage>("./Resources/csv/stage4.CSV");
	stageArr_[STAGE_5TH] = std::make_unique<Stage>("./Resources/csv/stage5.CSV");
	stageArr_[STAGE_6TH] = std::make_unique<Stage>("./Resources/csv/stage6.CSV");
	stageArr_[STAGE_7TH] = std::make_unique<Stage>("./Resources/csv/stage7.CSV");
	stageArr_[STAGE_8TH] = std::make_unique<Stage>("./Resources/csv/stage8.CSV");
	stageArr_[STAGE_9TH] = std::make_unique<Stage>("./Resources/csv/stage9.CSV");
	stageArr_[STAGE_10TH] = std::make_unique<Stage>("./Resources/csv/stage10.CSV");
	stageArr_[STAGE_11TH] = std::make_unique<Stage>("./Resources/csv/stage11.CSV");
	stageArr_[STAGE_12TH] = std::make_unique<Stage>("./Resources/csv/stage12.CSV");

	stageNum = STAGE_1ST;

}

Scene_Game::~Scene_Game() {
}

void Scene_Game::Load() {
		stageArr_[stageNum]->Init();
}

void Scene_Game::Update() {
	inputManager->Update();
	stageArr_[stageNum]->Update(inputManager->GetKeys(), inputManager->GetPreKeys());
	if (stageArr_[stageNum]->getIsClear()) {
		sceneNum=SCENE_SELLECT;
	}

}

void Scene_Game::Draw() {
	stageArr_[stageNum]->Draw();
}

void Scene_Game::Unload() {};