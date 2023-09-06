#include "Bottun.h"

//マウスがスクリーン上にあるか調べる関数
void Bottun::checkInsideMouse(Vec2 mousePos) {
	bool inSide = mousePos.x >= getScreenLtVertex().x && mousePos.x <= getScreenRtVertex().x ;
	bool above = mousePos.y >= getScreenLtVertex().y && mousePos.y <= getScreenLbVertex().y;

	isInsideMouse_ = (inSide && above);
}

void Bottun::Update(Vec2 mousePos, int clickState) {
	Bottun::checkInsideMouse(mousePos);
	if (isInsideMouse_) {
		isClicked_ = clickState;
	}
}

void Bottun::Draw() {
	if (isInsideMouse_) {
		Quad::Draw(clicedGH_);
	}
}


