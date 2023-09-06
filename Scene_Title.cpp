#include "Scene_Title.h"
#include <Novice.h>

void Scene_Title::Load() {
	//titleBar初期化
	Vec2 titlePos;
	titlePos=Vec2{ 327.0f, 200.0f };
	Vec2 titleSize{ 625.0f,125.0f };
	int titleGH = Novice::LoadTexture("./Resource/image/obj/title.png");
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
	const char* goSelectGH = "./Resource/image/obj/button/goSelectButton.png";
	const char* goSelectClickedGH = "./Resource/image/obj/button/goSelectCickedButton.png";
	Button_goSelect.Init(goSelectPos, buttonSize, Vec2(0.0f, 0.0f),
		goSelectGH, goSelectClickedGH, 
		Vec2(0.0f, 0.0f), buttonSize);

	//menuボタン
	Vec2 menuButtonPos{ Button_goSelect.getScreenLbVertex().x,
		Button_goSelect.getScreenLbVertex().y + 50.0f };

	const char* goMenuGH = "./Resource/image/obj/button/menu.png";
	const char* goMenuClickedGH = "./Resource/image/obj/button/menuClicked.png";

	Button_goManu.Init(menuButtonPos, buttonSize, Vec2(0.0f, 0.0f),
		goMenuGH, goMenuClickedGH,
		Vec2(0.0f, 0.0f), buttonSize);

	Vec2 exitButtonPos{ menuButtonPos.x,menuButtonPos.y + 50.0f };
	
	const char* exitGH = "./Resource/image/obj/button/exit.png";
	const char* exitClickedGH = "./Resource/image/obj/button/exitClicked.png";
	
	Button_exit.Init(exitButtonPos, buttonSize, Vec2(0.0f, 0.0f),
		exitGH, exitClickedGH, Vec2(0.0f, 0.0f), buttonSize);
}


void Scene_Title::Update() {

}


void Scene_Title::Unload() {

}