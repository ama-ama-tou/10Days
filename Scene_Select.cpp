#include "Scene_Select.h"
#include "Button.h"

StageNum Scene_Select::getSelectedStage(Vec2 mousePos, int clickState) {
	for (int i = 0; i < 9; i++) {
		stage_[i].Update(mousePos, clickState);

		if (stage_[i].getIsClicked()) {
			//�I�΂ꂽ�X�e�[�W�̔ԍ���Ԃ�
			return static_cast<StageNum>(i);
		}
	}
}

void Scene_Select::Load() {
	//=================
	//�{�^��������
	//=================

	//�^�C�g����ʂɖ߂�{�^��
	Vec2 goTitlePos = Vec2(50.0f,670.0f);
	Vec2 goTitleButtonSize{ 100,50.0f };
	const char* goTitleGH = "./Resource/image/obj/button/goTitleButton.png";
	const char* goTitleClickedGH = "./Resource/image/obj/button/goTitleClickedButton.png";
	go2Title.Init(goTitlePos, goTitleButtonSize, Vec2(0.0f, 0.0f),
		goTitleGH, goTitleClickedGH,
		Vec2(0.0f, 0.0f), goTitleButtonSize);

	//�X�e�[�W�Z���N�g�{�^��
	Vec2 selectButtonSize = { 150.0f,150.0f };
	Vec2 selectButtonSpace = { 100.0f,50.0f };
	Vec2 selectButtonPos[9];
	for (int i = 0; i < 9; i++) {
		int selectButtonRow = i / 3;//�s�ԍ�(0,1,2)
		int selectButtonCol = i % 3;//��ԍ�(0,1,2)
		selectButtonPos[i] = Vec2(340.0f + selectButtonCol * (selectButtonSize.x + selectButtonSpace.x),
								60.0f + selectButtonRow * (selectButtonSize.y + selectButtonSpace.y));

		const char* selectGH = "./Resource/image/obj/button/select.png";
		const char* selectClickedGH = "./Resource/image/obj/button/selectClickedGH.png";

		stage_[9].Init(selectButtonPos[i], selectButtonSize, Vec2(0.0f, 0.0f),
			selectGH, selectClickedGH,
			Vec2(0.0f, 0.0f), selectButtonSize);
	}

}

void Scene_Select::Update() {
	if (go2Title.getIsClicked()) {
		sceneNum = SCENE_TITLE;
	}
}

void Scene_Select::Draw() {
	for (int i = 0; i < 9; i++) {
		stage_[i].Draw();
		go2Title.Draw();
	}
}

void Scene_Select::Unload() {

}