#include "Player.h"
#include <Novice.h>
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

	vertex_[0] = pos_;
	vertex_[1] = Vec2(pos_.x + size_.x, pos_.y);
	vertex_[2] = Vec2(pos_.x, pos_.y + size_.y);
	vertex_[3] = Vec2(pos_.x + size_.x, pos_.y + size_.y);
}


void Player::Update(char* keys, char* preKeys) {
	 Player::Move( keys, preKeys);
}

//衝突判定
void Player::isHit() {
	 Player::Update();
	 for (int i = 0; i < 4; i++) {
		 pos_.x = vertex_[i].x / size_;
		 pos_.y = vertex_[i].y / size_;
	 }


}

//描画関数
void Player::Draw() {
	Novice::DrawQuad(
		static_cast<int>(localCo_.screenFromOrigin(vertex_[0]).x),
		static_cast<int>(localCo_.screenFromOrigin(vertex_[0]).y),
		static_cast<int>(localCo_.screenFromOrigin(vertex_[1]).x),
		static_cast<int>(localCo_.screenFromOrigin(vertex_[1]).y),
		static_cast<int>(localCo_.screenFromOrigin(vertex_[2]).x),
		static_cast<int>(localCo_.screenFromOrigin(vertex_[2]).y),
		static_cast<int>(localCo_.screenFromOrigin(vertex_[3]).x),
		static_cast<int>(localCo_.screenFromOrigin(vertex_[3]).y),
		static_cast<int>(imageLtPos_.x),
		static_cast<int>(imageLtPos_.y),
		static_cast<int>(imageSize_.x),
		static_cast<int>(imageSize_.y),
		GH_,
		WHITE
	);
}