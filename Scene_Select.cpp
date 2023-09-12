#include "Scene_Select.h"
#include "Button.h"
#include "Scene_Title.h"

StageNum Scene_Select::getSelectedStage() {
	for (int i = 0; i < 9; i++) {
		stage_[i].Update(inputManager->getMousePos(), inputManager->getClickState());

		if (stage_[i].getIsClicked()) {
			//選ばれたステージの番号を返す
			return static_cast<StageNum>(i);
		}
	}
	return static_cast<StageNum>(0);
}

void Scene_Select::Load() {

	//=================
	//ボタン初期化
	//=================

	//タイトル画面に戻るボタン
	Vec2 goTitlePos = Vec2(50.0f, 670.0f);
	Vec2 goTitleButtonSize{ 100,50.0f };
	const char* goTitleGH = "./Resources/image/obj/button/goTitleButton.png";
	go2Title.Init(goTitlePos, goTitleButtonSize, Vec2(0.0f, 0.0f),
		goTitleGH,WHITE,WHITE,
		Vec2(0.0f, 0.0f), goTitleButtonSize);

	//ステージセレクトボタン
	Vec2 selectButtonSize = { 150.0f,150.0f };
	Vec2 selectButtonSpace = { 200.0f,50.0f };
	Vec2 selectButtonPos[9];
	for (int i = 0; i < 9; i++) {
		int selectButtonRow = i / 3;//行番号(0,1,2)
		int selectButtonCol = i % 3;//列番号(0,1,2)
		selectButtonPos[i] = Vec2(240.0f + selectButtonCol * (selectButtonSize.x + selectButtonSpace.x),
			60.0f + selectButtonRow * (selectButtonSize.y + selectButtonSpace.y));

		const char* selectGH = "./Resources/image/obj/button/select.png";
		
		stage_[i].Init(selectButtonPos[i], selectButtonSize, Vec2(0.0f, 0.0f),
			selectGH, WHITE,WHITE,
			Vec2(0.0f, 0.0f), selectButtonSize);
	}

	//ステージセレクトの効果音
	stageSelectSH_ = Novice::LoadAudio("./Resources/sound/SE/stageSelect.png");
	stageSelectVH_ = -1;
	isRang_ = false;
}

void Scene_Select::Update() {

	inputManager->Update();

	if (go2Title.getIsClicked()) {
		Scene::sceneNum = SCENE_TITLE;
	}

	for (int i = 0; i < 9; i++) {
		if (stage_[i].getIsClicked()) {
			Scene::sceneNum = SCENE_GAME;
		}
	}


}

void Scene_Select::Draw() {
	//効果音を鳴らす
	if (isRang_) {
		if (Novice::IsPlayingAudio(stageSelectVH_) == 0 || stageSelectSH_ == -1) {
			stageSelectVH_ = Novice::PlayAudio(stageSelectSH_, false, 0.5f);
		}
		isRang_ = false;
	}

	for (int i = 0; i < 9; i++) {
		if (stage_[i].getIsClicked()) {

		}
	}

	for (int i = 0; i < 9; i++) {
		stage_[i].Draw();
		go2Title.Draw();
	}
}

void Scene_Select::Unload() {

}