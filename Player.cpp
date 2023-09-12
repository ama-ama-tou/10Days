#include "Player.h"
#include "InputManager.h"
#include <Novice.h>

void Player::Move(char* keys, char* preKeys) {
	
	//移動前の座標を保存しておく
	prePos_ = pos_;

	//左右の移動

	if (keys[DIK_A] && !preKeys[DIK_A]) {
		pos_.x -= speed_;
	} else if (keys[DIK_D] && !preKeys[DIK_D]) {
		pos_.x += speed_;
	}

	//上下の移動

	if (keys[DIK_W] && !preKeys[DIK_W]) {
		pos_.y -= speed_;
	} else if (keys[DIK_S] && !preKeys[DIK_S]) {
		pos_.y += speed_;
	}

	pointInit(pos_);
}


void Player::Update(char* keys, char* preKeys) {
	Move(keys, preKeys);
}


//描画関数
void Player::Draw() {

	Quad::Draw();

	


	Novice::ScreenPrintf(1000, 300, "faicing_[0]:%d(top)", getIsFacingTop());
	Novice::ScreenPrintf(1000, 320, "faicing_[1]:%d(right)", getIsFacingRight());
	Novice::ScreenPrintf(1000, 340, "faicing_[2]:%d(bottom)", getIsFacingBottom());
	Novice::ScreenPrintf(1000, 360, "faicing_[3]:%d(left)", getIsFacingLeft());
}