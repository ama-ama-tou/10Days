#include "Player.h"

void Player::Move(char* keys,char* preKeys) {
	//���E�̈ړ�
	if (keys[DIK_A]) {
		pos.x += speed;
	} else if (keys[DIK_D]) {
		pos.x -= speed;
	}

	//�㉺�̈ړ�
	if (keys[DIK_W]) {
		pos.y -= speed;
	} else if (DIK_D) {
		pos.y += speed;
	}
}