#include "Player.h"
#include "InputManager.h"
#include <Novice.h>

void Player::Move(char* keys, char* preKeys) {
	
	//移動前の座標を保存しておく
	prePos_ = pos_;

	if (!isSoundStart_) {

	//左右の移動

		if (keys[DIK_A] && !preKeys[DIK_A]) {
			pos_.x -= speed_;
			isSoundStart_ = true;
		} else if (keys[DIK_D] && !preKeys[DIK_D]) {
			pos_.x += speed_;
			isSoundStart_ = true;
		}

		//上下の移動

		if (keys[DIK_W] && !preKeys[DIK_W]) {
			pos_.y -= speed_;
			isSoundStart_ = true;
		} else if (keys[DIK_S] && !preKeys[DIK_S]) {
			pos_.y += speed_;
			isSoundStart_ = true;
		}
	} else {
		frameCount_++;
		if (frameCount_>=14) {
			isSoundStart_ = false;
			frameCount_ = 0;
		}
	}


	pointInit(pos_);
}


void Player::Update(char* keys, char* preKeys) {
	Move(keys, preKeys);
}


//描画関数
void Player::Draw() {
	//プレイヤーが移動したときのse
	if (isSoundStart_) {
		if (Novice::IsPlayingAudio(moveVH_)==0||moveVH_==-1 ){
			moveVH_ = Novice::PlayAudio(moveSH_, false, 0.3f);
		}
	}

	Quad::Draw();


	Novice::ScreenPrintf(1000, 300, "faicing_[0]:%d(top)", getIsFacingTop());
	Novice::ScreenPrintf(1000, 320, "faicing_[1]:%d(right)", getIsFacingRight());
	Novice::ScreenPrintf(1000, 340, "faicing_[2]:%d(bottom)", getIsFacingBottom());
	Novice::ScreenPrintf(1000, 360, "faicing_[3]:%d(left)", getIsFacingLeft());
}