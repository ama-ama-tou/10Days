﻿#pragma once
#include"Player.h"
#include"Block.h"
#include<vector>

class CollisionManager {
	/*Player player_;

	Block** block_;*/

	Quad quad_;

	//各頂点の番地
	int rowAddress_[4] = { 0 };
	int colAddress_[4] = { 0 };

	int preLtRowAddress_ = 0;
	int preLrColAddress_ = 0;

	int maxRow_;
	int maxCol_;

	///
	int rbro_;
	int cbro_;

	//保存用の変数
	Vec2 bLtPreVertex_[12][12] = {};

	bool initKeep_;

	int isGet_ = { 0 };

public:
	CollisionManager(const int& maxRow, const int& maxCol) {

		maxRow_ = maxRow;
		maxCol_ = maxCol;
	};

	//当たり判定
	void playerCollision(Player& player, Block**& block);

	void blockCollision(Player& player, Block**& block);

	
	//===============
	//ゲッター/セッター
	//===============
	int getRowAddress(int num) { return rowAddress_[num]; }

	const int getMaxRow() { return maxRow_; }
	const int getMaxCol() { return maxCol_; }

	Vec2 getBLtPreVertex() { return quad_.getLtVertex(); }
	void setBLtPreVertex(Vec2 vertex, int r, int c) { bLtPreVertex_[r][c] = vertex; }

	

};

