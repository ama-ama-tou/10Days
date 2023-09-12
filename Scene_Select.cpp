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

	const char* stageGH[12] = { "./Resources/image/obj/button/stage1.png",
									"./Resources/image/obj/button/stage2.png"
									"./Resources/image/obj/button/stage3.png"
									"./Resources/image/obj/button/stage4.png"
									"./Resources/image/obj/button/stage5.png"
									"./Resources/image/obj/button/stage6.png"
									"./Resources/image/obj/button/stage7.png"
									"./Resources/image/obj/button/stage8.png"
									"./Resources/image/obj/button/stage9.png"
									"./Resources/image/obj/button/stage10.png"
									"./Resources/image/obj/button/stage11.png"
									"./Resources/image/obj/button/stage12.png"
	};

	Vec2 selectButtonSize = { 150.0f,150.0f };
	Vec2 selectButtonSpace = { 150.0f,50.0f };
	const int numCols = 4;
	const int numRows = 3;
	Vec2 selectButtonPos[numCols*numRows];
	for (int i = 0; i < numCols * numRows; i++) {
		int selectButtonRow = i / numCols;//行番号(0,1,2)
		int selectButtonCol = i % numCols;//列番号(0,1,2,3)
		selectButtonPos[i] = Vec2(115.0f + selectButtonCol * (selectButtonSize.x + selectButtonSpace.x),
			85.0f + selectButtonRow * (selectButtonSize.y + selectButtonSpace.y));

		
		
		stage_[i].Init(selectButtonPos[i], selectButtonSize, Vec2(0.0f, 0.0f),
			stageGH[i], WHITE,WHITE,
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

	for (int i = 0; i < 12; i++) {
		stage_[i].Draw();
	}
	go2Title.Draw();

}

void Scene_Select::Unload() {

}