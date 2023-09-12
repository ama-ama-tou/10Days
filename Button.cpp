#include "Button.h"
#include <Novice.h>
#include"easing.h"

//マウスがスクリーン上にあるか調べる関数
void Button::checkInsideMouse(Vec2 mousePos) {
	bool inSide = mousePos.x >= getScreenLtVertex().x && mousePos.x <= getScreenRtVertex().x ;
	bool above = mousePos.y >= getScreenLtVertex().y && mousePos.y <= getScreenLbVertex().y;

	isInsideMouse_ = (inSide && above);
}



void Button::Update(Vec2 mousePos, int clickState) {

	Button::checkInsideMouse(mousePos);
	if (isInsideMouse_) {
		Quad::setColor(colorAfterClick_);
		if (clickState==1) {
			//右クリックされたとき
			isClicked_ = true;
		} else {
			isClicked_ = false;
		}
	} else {
		Quad::setColor(colorBeforeClick_);
	}
}

void Button::Draw() {
	Quad::Draw();
}


