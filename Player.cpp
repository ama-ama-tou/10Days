#include "Player.h"

void Player::Move(char* keys,char* preKeys) {
	//左右の移動
	
	if (keys[DIK_A] && !preKeys[DIK_A]) {
		pos.x += speed;
	} else if (keys[DIK_D] && !preKeys[DIK_D]) {
		pos.x -= speed;
	}

	//上下の移動
	
	if (keys[DIK_W] && !preKeys[DIK_W]) {
		pos.y -= speed;
	} else if (keys[DIK_S] && !preKeys[DIK_S]) {
		pos.y += speed;
	}
}