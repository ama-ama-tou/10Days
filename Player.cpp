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
}