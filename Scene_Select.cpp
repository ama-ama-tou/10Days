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
	Vec2
}

void Scene_Select::Draw() {
	for (int i = 0; i < 9; i++) {
		stage_[i].Draw();
	}
}