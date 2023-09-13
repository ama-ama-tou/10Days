#include "Scene_Select.h"
#include "Button.h"
#include "Scene_Title.h"



void Scene_Select::Load() {

	//=================
	//ボタン初期化
	//=================

	//タイトル画面に戻るボタン
	Vec2 goTitlePos = Vec2(20.0f, 10.0f);
	Vec2 goTitleButtonSize{ 256,96.0f };
	const char* goTitleGH = "./Resources/image/obj/button/goTitleButton.png";
	go2Title.Init(goTitlePos, goTitleButtonSize, Vec2(0.0f, 0.0f),
		goTitleGH, WHITE, WHITE,
		Vec2(0.0f, 0.0f), goTitleButtonSize);

	//ステージセレクトボタン

	const char* stageGH[12] = { "./Resources/image/obj/button/stage1.png",
								"./Resources/image/obj/button/stage2.png",
								"./Resources/image/obj/button/stage3.png",
								"./Resources/image/obj/button/stage4.png",
								"./Resources/image/obj/button/stage5.png",
								"./Resources/image/obj/button/stage6.png",
								"./Resources/image/obj/button/stage7.png",
								"./Resources/image/obj/button/stage8.png",
								"./Resources/image/obj/button/stage9.png",
								"./Resources/image/obj/button/stage10.png",
								"./Resources/image/obj/button/stage11.png",
								"./Resources/image/obj/button/stage12.png",
	};

	Vec2 selectButtonSize = { 150.0f,150.0f };
	Vec2 selectButtonSpace = { 150.0f,50.0f };
	const int numCols = 4;
	const int numRows = 3;
	Vec2 selectButtonPos[numCols * numRows];
	for (int i = 0; i < numCols * numRows; i++) {
		int selectButtonRow = i / numCols;//行番号(0,1,2)
		int selectButtonCol = i % numCols;//列番号(0,1,2,3)
		selectButtonPos[i] = Vec2(115.0f + selectButtonCol * (selectButtonSize.x + selectButtonSpace.x),
			175.0f + selectButtonRow * (selectButtonSize.y + selectButtonSpace.y));



		stage_[i].Init(selectButtonPos[i], selectButtonSize, Vec2(0.0f, 0.0f),
			stageGH[i], WHITE, WHITE,
			Vec2(0.0f, 0.0f), selectButtonSize);
	}

	//ステージセレクトの効果音
	stageSelectSH_ = Novice::LoadAudio("./Resources/sound/SE/select.mp3");
	stageSelectVH_ = -1;
	isRang_ = false;
}

void Scene_Select::Update() {


	if (go2Title.getIsClicked()) {
		Scene::sceneNum = SCENE_TITLE;
	}

	for (int i = 0; i < 12; i++) {
		stage_[i].Update(inputManager->getMousePos(), inputManager->getClickState());
	}
#pragma region selctUpdate

	if (stage_[STAGE_1ST].getIsClicked()) {
		Scene::stageNum_ = STAGE_1ST;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_2ND].getIsClicked()) {
		Scene::stageNum_ = STAGE_2ND;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_3RD].getIsClicked()) {
		Scene::stageNum_ = STAGE_3RD;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_4TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_4TH;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_5TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_5TH;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_6TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_6TH;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_7TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_7TH;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_8TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_8TH;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_9TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_9TH;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_10TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_10TH;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_11TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_11TH;
		Scene::sceneNum = SCENE_GAME;
	}
	if (stage_[STAGE_12TH].getIsClicked()) {
		Scene::stageNum_ = STAGE_12TH;
		Scene::sceneNum = SCENE_GAME;
	}
#pragma endregion

}

void Scene_Select::Draw() {
	//効果音を鳴らす
	if (isRang_) {
		if (Novice::IsPlayingAudio(stageSelectVH_) == 0 || stageSelectSH_ == -1) {
			stageSelectVH_ = Novice::PlayAudio(stageSelectSH_, false, 0.5f);
		}
		isRang_ = false;
	}

	for (int i = 0; i < 12; i++) {
		stage_[i].Draw();
	}

	go2Title.Draw();

}

void Scene_Select::Unload() {

}