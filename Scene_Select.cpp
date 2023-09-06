#include "Scene_Select.h"
#include "Button.h"

int Scene_Select::getSelectedStage(Vec2 mousePos, int clickState) {
	for (int i = 0; i < 9; i++) {
		stage_[i].Update(mousePos, clickState);

		if (stage_[i].getIsClicked()) {
			return i+1;
		}
	}
}