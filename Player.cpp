#include "Player.h"

void Player::Move(char* keys,char* preKeys) {
	//左右の移動
	
	if (keys[DIK_A] && !preKeys[DIK_A]) {
		pos_.x += speed_;
	} else if (keys[DIK_D] && !preKeys[DIK_D]) {
		pos_.x -= speed_;
	}

	//上下の移動
	
	if (keys[DIK_W] && !preKeys[DIK_W]) {
		pos_.y -= speed_;
	} else if (keys[DIK_S] && !preKeys[DIK_S]) {
		pos_.y += speed_;
	}
}

void Player::Update() {
	getLtVertex() = pos_;
	getRtVertex() = Vec2(pos_.x + size_.x, pos_.y);
	getLbVertex() = Vec2(pos_.x, pos_.y + size_.y);
	getRbVertex() = Vec2(pos_.x + size_.x, pos_.y + size_.y);	
}

void Player::isHit() {
	 Player::Update();


}