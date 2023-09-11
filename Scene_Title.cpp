#include "Scene_Title.h"
#include <Novice.h>

void Scene_Title::Load() {
	//title画面のBGM
	SH_ = Novice::LoadAudio("./Resources/sount/BGM/title.mp3");
	VH_ = -1;

	//titleBar初期化
	Vec2 titlePos;
	titlePos = Vec2{ 327.0f, 200.0f };
	Vec2 titleSize{ 625.0f,125.0f };
	int titleGH = Novice::LoadTexture("./Resources/image/obj/title.png");
	Vec2 titleImageSize{ 625.0f,125.0f };
	titleBar.Init(titlePos, titleSize, Vec2(0.0f, 0.0f),
		titleGH, Vec2(0.0f, 0.0f), titleImageSize
	);

	//=================
	//ボタン初期化
	//=================

	Vec2 goSelectPos = Vec2(titleBar.getScreenLbVertex().x,
		titleBar.getScreenLbVertex().y + 100.0f);

	//ボタンサイズは統一する
	Vec2 buttonSize{ 500.0f,100.0f };
	const char* goSelectGH = "./Resources/image/obj/button/goSelectButton.png";
	const char* goSelectClickedGH = "./Resources/image/obj/button/goSelectCickedButton.png";
	Button_goSelect.Init(goSelectPos, buttonSize, Vec2(0.0f, 0.0f),
		goSelectGH, goSelectClickedGH,
		Vec2(0.0f, 0.0f), buttonSize);

	//menuボタン
	Vec2 menuButtonPos{ Button_goSelect.getScreenLbVertex().x,
		Button_goSelect.getScreenLbVertex().y + 50.0f };

	const char* goMenuGH = "./Resources/image/obj/button/menu.png";
	const char* goMenuClickedGH = "./Resources/image/obj/button/menuClicked.png";

	Button_goManu.Init(menuButtonPos, buttonSize, Vec2(0.0f, 0.0f),
		goMenuGH, goMenuClickedGH,
		Vec2(0.0f, 0.0f), buttonSize);

	Vec2 exitButtonPos{ menuButtonPos.x,menuButtonPos.y + 50.0f };

	const char* exitGH = "./Resources/image/obj/button/exit.png";
	const char* exitClickedGH = "./Resources/image/obj/button/exitClicked.png";

	Button_exit.Init(exitButtonPos, buttonSize, Vec2(0.0f, 0.0f),
		exitGH, exitClickedGH, Vec2(0.0f, 0.0f), buttonSize);

}


void Scene_Title::Update() {
	if (Button_goManu.getIsClicked()) {
		Scene::sceneNum = SCENE_MENU;
	}
	if (Button_goSelect.getIsClicked()) {
		Scene::sceneNum = SCENE_SELECT;
	}
	if (Button_exit.getIsClicked()) {
	//ゲームを終了させる処理
	}
}

void Scene_Title::Draw() {

		//bgmを鳴らす
		if (Novice::IsPlayingAudio(SH_) == false) {
			Novice::PlayAudio(SH_, true, 0.5f);
	}

	//ボタンの描画
	Button_exit.Draw();
	Button_goManu.Draw();
	Button_goSelect.Draw();
}


void Scene_Title::Unload() {
	Novice::StopAudio(VH_);
}