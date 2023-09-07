#include "Player.h"
#include <Novice.h>
void Player::Move(char* keys,char* preKeys) {
	//移動前の座標を保存しておく
	prePos_ = pos_;

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

int Player::CalcuRowAddress(int vertexNum){
	int row;
	if (vertexNum == 0) {
		row = static_cast<int>(vertex_[vertexNum].x / size_.x); //左上の場合

	} else {
		row = static_cast<int>((vertex_[vertexNum].x - 1) / size_.x); //それ以外の場合-1する必要がある
	}
	return row;
}

int Player::CalcuColAddress(int vertexNum){
	int col;
	if (vertexNum == 0) {
		col = static_cast<int>(vertex_[vertexNum].y / size_.y); //左上の場合

	} else {
		col = static_cast<int>((vertex_[vertexNum].y - 1) / size_.y); //それ以外の場合-1する必要がある
	}
	return col;
}


void Player::Update(char* keys, char* preKeys) {
	Player::Move(keys, preKeys);
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