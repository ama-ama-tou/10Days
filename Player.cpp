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
			moveVH_ = Novice::PlayAudio(moveSH_, false, 0.1f);
		}
	}

	Quad::Draw();

	Novice::ScreenPrintf(10, 300, "player.pos.x:%f", getLtVertex().x);
	Novice::ScreenPrintf(10, 320, "player.pos.y:%f", getLtVertex().y);

	Novice::ScreenPrintf(10, 360, "vertex_[0].x:%f(leftTop)", getLtVertex().x);
	Novice::ScreenPrintf(10, 380, "vertex_[0].y:%f(leftTop)", getLtVertex().y);

	Novice::ScreenPrintf(10, 410, "vertex_[1].x:%f(rightTop)", getRtVertex().x);
	Novice::ScreenPrintf(10, 430, "vertex_[1].y:%f(rightTop)", getRtVertex().y);

	Novice::ScreenPrintf(10, 460, "vertex_[2].x:%f(leftBottom)", getLbVertex().x);
	Novice::ScreenPrintf(10, 480, "vertex_[2].y:%f(leftBottom)", getLbVertex().y);

	Novice::ScreenPrintf(10, 510, "vertex_[3].x:%f(rightBottom)", getRbVertex().x);
	Novice::ScreenPrintf(10, 530, "vertex_[3].y:%f(rightBottom)", getRbVertex().y);


	Novice::ScreenPrintf(1000, 300, "faicing_[0]:%d(top)", getIsFacingTop());
	Novice::ScreenPrintf(1000, 320, "faicing_[1]:%d(right)", getIsFacingRight());
	Novice::ScreenPrintf(1000, 340, "faicing_[2]:%d(bottom)", getIsFacingBottom());
	Novice::ScreenPrintf(1000, 360, "faicing_[3]:%d(left)", getIsFacingLeft());
}