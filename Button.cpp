#include "Buttun.h"
#include <Novice.h>

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
		GH_ = Novice::LoadTexture(filePass[1]);
	} else {
		GH_ = Novice::LoadTexture(filePass[0]);
	}
	Quad::Draw();
}


