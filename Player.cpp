#include "Player.h"

void Player::Move(char* keys,char* preKeys) {
	//¶‰E‚ÌˆÚ“®
	if (keys[DIK_A]) {
		pos.x += speed;
	} else if (keys[DIK_D]) {
		pos.x -= speed;
	}

	//ã‰º‚ÌˆÚ“®
	if (keys[DIK_W]) {
		pos.y -= speed;
	} else if (DIK_D) {
		pos.y += speed;
	}
}