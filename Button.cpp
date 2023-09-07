#include "Button.h"
#include <Novice.h>

//マウスがスクリーン上にあるか調べる関数
void Button::checkInsideMouse(Vec2 mousePos) {
	bool inSide = mousePos.x >= getScreenLtVertex().x && mousePos.x <= getScreenRtVertex().x ;
	bool above = mousePos.y >= getScreenLtVertex().y && mousePos.y <= getScreenLbVertex().y;

	isInsideMouse_ = (inSide && above);
}

void Button::Update(Vec2 mousePos, int clickState) {
	Button::checkInsideMouse(mousePos);
	if (isInsideMouse_) {
		if (clickState==1) {
			//右クリックされたとき
			isClicked_ = true;
		}
	}
}

void Button::Draw() {
	if (isInsideMouse_) {
		GH_ = Novice::LoadTexture(filePass_[1]);
	} else {
		GH_ = Novice::LoadTexture(filePass_[0]);
	}
	Quad::Draw();
}


