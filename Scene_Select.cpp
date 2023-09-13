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


	triangleGH_ = Novice::LoadTexture("white1x1.png");
	trianglePos_.x = stage_[0].getLtVertex().x + 30.0f;
	trianglePos_.y = stage_[0].getLtVertex().y - 30.0f;
	triangleSize_ = { 32.0f,32.0f };
	selectNum_ = 1;


}

void Scene_Select::Update() {

	go2Title.Update(inputManager->getMousePos(), inputManager->getClickState());


	if (go2Title.getISInsideMouse() == true) {
		if (go2Title.getIsClicked() == true) {
			Scene::sceneNum = SCENE_TITLE;
		}
	}
	if (inputManager->GetKeys()[DIK_ESCAPE] && inputManager->GetPreKeys()[DIK_ESCAPE] == false) {
		Scene::sceneNum = SCENE_TITLE;

	}



	//キーボードでの移動
	if (selectNum_ != 3 && selectNum_ != 7 && selectNum_ != 11) {
		if (inputManager->GetKeys()[DIK_RIGHT] && inputManager->GetPreKeys()[DIK_RIGHT] == false) {
			selectNum_++;
			trianglePos_.x = stage_[selectNum_].getLtVertex().x + 30.0f;
		}
	}

	if (selectNum_ != 0 && selectNum_ != 4 && selectNum_ != 8) {
		if (inputManager->GetKeys()[DIK_LEFT] && inputManager->GetPreKeys()[DIK_LEFT] == false) {
			selectNum_--;
			trianglePos_.x = stage_[selectNum_].getLtVertex().x + 30.0f;
		}
	}

	//キーボードでの移動
	if (selectNum_ != 0 && selectNum_ != 1 && selectNum_ != 2 && selectNum_ != 3 ) {
		if (inputManager->GetKeys()[DIK_UP] && inputManager->GetPreKeys()[DIK_UP] == false) {
			selectNum_ -= 3;
			trianglePos_.y = stage_[selectNum_].getLtVertex().y;
		}
	}
	if (selectNum_ != 8 && selectNum_ != 9 && selectNum_ != 10 && selectNum_ != 11) {
		if (inputManager->GetKeys()[DIK_DOWN] && inputManager->GetPreKeys()[DIK_DOWN] == false) {
			selectNum_ += 3;
			trianglePos_.y = stage_[selectNum_].getLtVertex().y;
		}
	}


	if (inputManager->GetKeys()[DIK_RETURN]&&inputManager->GetPreKeys()[DIK_RETURN]) {
		Scene::stageNum_ = selectNum_;
		Scene::sceneNum = SCENE_GAME;
	}


	for (int i = 0; i < 12; i++) {
		stage_[i].Update(inputManager->getMousePos(), inputManager->getClickState());
		selectNum_ = i;

		//三角のポジションの移動


		//マウスでの移動
		if (stage_[i].getISInsideMouse() == true) {
			trianglePos_.x = stage_[i].getLtVertex().x + 30.0f;
			trianglePos_.y = stage_[i].getLtVertex().y - 30.0f;
		}

		if (stage_[i].getIsClicked()) {

			Scene::stageNum_ = i;
			Scene::sceneNum = SCENE_GAME;
		}
	}

	//選んでるステージを示す三角

	//各頂点の更新
	triangleVertex_[0] = { trianglePos_.x - triangleSize_.x / 2.0f,trianglePos_.y - triangleSize_.y / 2.0f };
	triangleVertex_[1] = { trianglePos_.x + triangleSize_.x / 2.0f,trianglePos_.y - triangleSize_.y / 2.0f };
	triangleVertex_[2] = { trianglePos_.x,trianglePos_.y + triangleSize_.y / 2.0f };
	triangleVertex_[3] = { trianglePos_.x,trianglePos_.y + triangleSize_.y / 2.0f };


}

void Scene_Select::Draw() {

	Novice::ScreenPrintf(10, 10, "trianglePos.x= %.1f", trianglePos_.x);
	Novice::ScreenPrintf(10, 30, "trianglePos.y = %.1f", trianglePos_.y);

	Novice::ScreenPrintf(10, 50, "triangleVertex[0] = %.1f", triangleVertex_[0].x);
	Novice::ScreenPrintf(10, 70, "triangleVertex[0] = %.1f", triangleVertex_[0].y);

	Novice::ScreenPrintf(10, 90, "triangleVertex[1] = %.1f", triangleVertex_[1].x);
	Novice::ScreenPrintf(10, 110, "triangleVertex[1] = %.1f", triangleVertex_[1].y);

	Novice::ScreenPrintf(10, 130, "triangleVertex[2] = %.1f", triangleVertex_[2].x);
	Novice::ScreenPrintf(10, 150, "triangleVertex[2] = %.1f", triangleVertex_[2].y);

	Novice::ScreenPrintf(10, 170, "triangleVertex[3] = %.1f", triangleVertex_[3].x);
	Novice::ScreenPrintf(10, 190, "triangleVertex[3] = %.1f", triangleVertex_[3].y);

	Novice::ScreenPrintf(10, 210, "selectNum = %d", selectNum_);


	for (int i = 0; i < 12; i++) {
		stage_[i].Draw();
	}

	go2Title.Draw();
	selectBar_.Draw();
	Novice::DrawQuad(
		static_cast<int>(triangleVertex_[0].x),
		static_cast<int>(triangleVertex_[0].y),
		static_cast<int>(triangleVertex_[1].x),
		static_cast<int>(triangleVertex_[1].y),
		static_cast<int>(triangleVertex_[2].x),
		static_cast<int>(triangleVertex_[2].y),
		static_cast<int>(triangleVertex_[3].x),
		static_cast<int>(triangleVertex_[3].y),
		0, 0, 32, 32,
		triangleGH_, 0xF1E266ff
	);
}

void Scene_Select::Unload() {

}
