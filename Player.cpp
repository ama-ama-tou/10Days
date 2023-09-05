#include "Player.h"

void Player::Move(char* keys,char* preKeys) {
	//左右の移動
	if (keys[DIK_A]) {
		pos.x += speed;
	} else if (keys[DIK_D]) {
		pos.x -= speed;
	}

	//上下の移動
	if (keys[DIK_W]) {
		pos.y -= speed;
	} else if (keys[DIK_S]) {
		pos.y += speed;
	}
}