#pragma once
#include"Coordinate.h"

class Quad {
private:
	//================
	//メンバ変数
	//================
	Coordinate localCo_{Vec2(0.0f,0.0f)};
	Vec2 vertex_[4];
	Vec2 size_;

	int GH_;
	//画像の左上座標
	Vec2 imageLtPos_;
	//画像サイズ(表示する)
	Vec2 imageSize_;

public:
	//===============
	//メンバ関数
	//===============
	Quad() {};


	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin,int GH, Vec2 imageLtPos, Vec2 imageSize) {
		vertex_[0] = pos;
		vertex_[1] = Vec2(pos.x + size.x, pos.y);
		vertex_[2] = Vec2(pos.x, pos.y + size.y);
		vertex_[3] = Vec2(pos.x + size.x, pos.y + size.y);

		localCo_.setOrigin(localCoOrigin);

		size_ = size;

		GH_ = GH;
		imageLtPos_ = imageLtPos;
		imageSize_ = imageSize;
	}

	void Draw();
	//===============
	//ゲッター/セッター
	//===============
	// 4点を一度に更新
	void setPos(Vec2 ltPos) {
		vertex_[0] = ltPos;
		vertex_[1] = Vec2(ltPos.x + size_.x, ltPos.y);
		vertex_[2] = Vec2(ltPos.x, ltPos.y + size_.y);
		vertex_[3] = ltPos + size_;
	}

	//ローカル座標上
	Vec2 getLtVertex() { return vertex_[0]; }
	Vec2 getRtVertex() { return vertex_[1]; }
	Vec2 getLbVertex() { return vertex_[2]; }
	Vec2 getRbVertex() { return vertex_[3]; }

	void setLtVertex(Vec2 pos) {vertex_[0]=pos; }
	void setRtVertex(Vec2 pos) {vertex_[1]=pos; }
	void setLbVertex(Vec2 pos) {vertex_[2]=pos; }
	void setRbVertex(Vec2 pos) {vertex_[3]=pos; }

	//スクリーン座標上
	Vec2 getScreenLtVertex() { return localCo_.screenFromOrigin(vertex_[0]); }
	Vec2 getScreenRtVertex() { return localCo_.screenFromOrigin(vertex_[1]); }
	Vec2 getScreenLbVertex() { return localCo_.screenFromOrigin(vertex_[2]); }
	Vec2 getScreenRbVertex() { return localCo_.screenFromOrigin(vertex_[3]); }

	Coordinate getLocalCo() { return localCo_; }
	void setLocalCoOrigin(Vec2 pos) { localCo_.setOrigin(pos); }

	Vec2 getImageLtPos() { return imageLtPos_; }
	void setImageLtPos(Vec2 imageLtPos) { imageLtPos_ = imageLtPos; }

	///サイズ
	Vec2 getSize() { return size_; }
	void setSize(Vec2 size) { size_ = size; }

};
