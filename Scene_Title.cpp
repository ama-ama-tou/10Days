#include "Scene_Title.h"
#include <Novice.h>

void Scene_Title::Load() {
	//title画面のBGM
	backgroundSH_ = Novice::LoadAudio("./Resources/sound/BGM/title.mp3");
	backgroundVH_ = -1;

	//titleBar初期化
	Vec2 titlePos;
	titlePos = Vec2{ 327.0f, 200.0f };
	Vec2 titleSize{ 625.0f,125.0f };
	int titleGH = Novice::LoadTexture("./Resources/image/obj/titleBar.png");
	Vec2 titleImageSize{ 625.0f,125.0f };
	titleBar.Init(titlePos, titleSize, Vec2(0.0f, 0.0f),
		titleGH, Vec2(0.0f, 0.0f), titleImageSize,WHITE
	);

	//=================
	//ボタン初期化
	//=================

	//ボタンサイズは統一する
	Vec2 buttonSize{ 245.0f,45.0f };

	Vec2 goSelectPos = Vec2((kWindowSize.x / 8.0f)*3.0f,
		titleBar.getScreenLbVertex().y + buttonSize.y);

	

	const char* goSelectGH = "./Resources/image/obj/button/goSelectButton.png";
	Button_goSelect.Init(goSelectPos, buttonSize, Vec2(0.0f, 0.0f),
		goSelectGH, 0x53558bff, 0xe28f8fff,
		Vec2(0.0f, 0.0f), buttonSize);

	Vec2 exitButtonPos{ goSelectPos.x,goSelectPos.y + (buttonSize.y * 0.4f) };

	const char* exitGH = "./Resources/image/obj/button/exit.png";
	
	Button_exit.Init(exitButtonPos, buttonSize, Vec2(0.0f, 0.0f),
		exitGH, 0x53558bff, 0xe28f8fff, Vec2(0.0f, 0.0f), buttonSize);

}


void Scene_Title::Update() {
	
	if (Button_goSelect.getIsClicked()) {
		Scene::sceneNum = SCENE_SELECT;
	}
	if (Button_exit.getIsClicked()) {
	//ゲームを終了させる処理
	}
}

void Scene_Title::Draw() {

		//bgmを鳴らす
	if (Novice::IsPlayingAudio(backgroundSH_) == false) {
		Novice::PlayAudio(backgroundSH_, true, 0.5f);
	}

	//ボタンの描画
	Button_exit.Draw();
	
	Button_goSelect.Draw();
}


void Scene_Title::Unload() {
	Novice::StopAudio(backgroundVH_);
}