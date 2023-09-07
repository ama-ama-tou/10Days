#include "InputManager.h"
#include <Novice.h>

// GetInstance インスタンスにアクセスするための関数
InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

// 更新処理
void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

}
