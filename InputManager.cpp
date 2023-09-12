#include "InputManager.h"
#include <Novice.h>

// GetInstance インスタンスにアクセスするための関数
InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

// 更新処理
void InputManager::Update() {
	if (Novice::IsPressMouse(0)) {
		clickState_= LEFT_CLICK;
	} else {
		clickState_ = 0;
	}
	if (Novice::IsPressMouse(1)) {
		clickState_=RIGIHT_CLICK;
	} 

	//マウスの位置を受け取る
	Novice::GetMousePosition(&x_, &y_);
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

}
