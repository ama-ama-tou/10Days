#include "Scene_Menu.h"

void Scene_Menu::Load() {
	float widthPart(kFieldSize.x / 3.0f);
	float heightPart = (kFieldSize.y / 15.0f);

	//-------back2GameButton-------

	Vec2 gameButtonPos(widthPart, heightPart * 2.0f);
	Vec2 buttonSize(widthPart, heightPart * 2.0f);

	back2Game.Init(
		gameButtonPos, buttonSize, Vec2(kFieldLtPos),
		"./Resources/image/obj/button/back2GameButton.png",
		"./Resources/image/obj/button/back2GameClickedButton.png",
		Vec2(0.0f, 0.0f),//imageLtPos
		buttonSize
	);
	//----------------------------

	//-----------settingButton-----------
	Vec2 settingButtonPos(widthPart, heightPart * 5.0f);

	setting.Init(settingButtonPos, buttonSize, kFieldLtPos,
		"./Resources/image/obj/button/settingButton.png",
		"./Resources/image/obj/button/settingClickedButton.png",
		Vec2(0.0f, 0.0f),
		buttonSize
	);
	//-----------------------------------

	//-----------reSetButton-----------
	Vec2 reSetButtonPos(widthPart, heightPart * 8.0f);
	reSet.Init(reSetButtonPos, buttonSize, kFieldLtPos,
		"Resources/image/obj/button/reSetButton.png",
		"Resources/image/obj/button/reSetClickedButton.png",
		Vec2(0.0f, 0.0f),
		buttonSize
	);
	//--------------------------------

	//---------------back2Select-----------------
	Vec2 back2SelectPos(widthPart, heightPart * 11.0f);
	back2Select.Init(back2SelectPos, buttonSize, kFieldLtPos,
		"Resources/image/obj/button/back2SelectButton.png",
		"Resources/image/obj/button/back2SelectSelectButton.png",
		Vec2(0.0f, 0.0f),
		buttonSize
	);


}

void Scene_Menu::Update() {
}

void Scene_Menu::Draw() {
}

void Scene_Menu::Unload() {
}
