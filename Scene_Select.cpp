#include "Scene_Select.h"
#include "Button.h"
#include "Scene_Title.h"
#include "InputManager.h"


void Scene_Select::Load() {


	//ステージセレクトバーの初期化
	Vec2 titleBarPos = Vec2(1000.0f, 10.0f);
	Vec2 titleBarImageSize{ 512.0f,256.0f };
	Vec2 titleBarSize{ 256.0f,128.0f };
	int titleBarGH = Novice::LoadTexture("./Resources/image/obj/selectBar.png");

	selectBar_.Init(titleBarPos, titleBarSize, Vec2(0.0f, 0.0f),
		titleBarGH, Vec2(0.0f, 0.0f), titleBarImageSize, WHITE);



	//タイトル画面に戻るボタン
	Vec2 goTitlePos = Vec2(20.0f, 10.0f);
	Vec2 goTitleButtonImageSize{512.0f,256.0f};
	Vec2 goTitleButtonSize{256.0f,128.0f};
	
	const char* goTitleGH = "./Resources/image/obj/button/goTitleButton.png";
	go2Title.Init(goTitlePos, goTitleButtonSize, Vec2(0.0f, 0.0f),
		goTitleGH, 0x53558bff, WHITE,
		Vec2(0.0f, 0.0f), goTitleButtonImageSize);

	
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
		selectButtonPos[i] = Vec2(150.0f + selectButtonCol * (selectButtonSize.x + selectButtonSpace.x),
			175.0f + selectButtonRow * (selectButtonSize.y + selectButtonSpace.y));



		stage_[i].Init(selectButtonPos[i], selectButtonSize, Vec2(0.0f, 0.0f),
			stageGH[i], WHITE, WHITE,
			Vec2(0.0f, 0.0f), selectButtonSize);
	}

	
}

void Scene_Select::Update() {

	go2Title.Update(inputManager->getMousePos(), inputManager->getClickState());

	if (inputManager->getClickState()==1) {
		
	}

	if (go2Title.getISInsideMouse() == true) {
		if (go2Title.getIsClicked() == true) {
			Scene::sceneNum = SCENE_TITLE;
		}
	}
	if (inputManager->GetKeys()[DIK_ESCAPE] && inputManager->GetPreKeys()[DIK_ESCAPE] == false) {
		Scene::sceneNum = SCENE_TITLE;

	}

	for (int i = 0; i < 12; i++) {
		stage_[i].Update(inputManager->getMousePos(), inputManager->getClickState());
		if (stage_[i].getIsClicked()) {
			
			Scene::stageNum_ = i;
			Scene::sceneNum = SCENE_GAME;
		}
	}
	
}

void Scene_Select::Draw() {
	

	for (int i = 0; i < 12; i++) {
		stage_[i].Draw();
	}

	go2Title.Draw();
	selectBar_.Draw();
}

void Scene_Select::Unload() {

}
