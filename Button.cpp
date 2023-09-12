#include "Button.h"
#include <Novice.h>
#include"easing.h"

//マウスがスクリーン上にあるか調べる関数
void Button::checkInsideMouse(Vec2 mousePos) {
	bool inSide = mousePos.x >= getScreenLtVertex().x && mousePos.x <= getScreenRtVertex().x ;
	bool above = mousePos.y >= getScreenLtVertex().y && mousePos.y <= getScreenLbVertex().y;

	isInsideMouse_ = (inSide && above);
}

void Button::colorChange() {
	
	t = currentTime_ / 1.0f;
	color_ = colorBeforeClick_ + (colorAfterClick_ - colorBeforeClick_) * easeInOutQuart(t);
	Quad::setColor(color_);
}



void Button::Update(Vec2 mousePos, int clickState) {
	Button::checkInsideMouse(mousePos);

	colorChange();

	if (isInsideMouse_) {
		if (currentTime_<1.0f) {
			//colorAfterClickへ移動
			currentTime_ += 1.0 / 60.0f;//1秒間
		}
		

		if (clickState==1) {
			//右クリックされたとき
			isClicked_ = true;
		}
	} else {
		if (currentTime_<0.0f) {
			//colorBeforeClickへ移動
			currentTime_ -= 1.0 / 60.0f;//1秒間
		}


	}
}

void Button::Draw() {
	
	Quad::Draw();
}


