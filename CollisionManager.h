﻿#pragma once
#include"Player.h"
#include"Block.h"
#include<vector>

class CollisionManager {
	Player player_;
	
	Block** block_;

	//各頂点の番地
	int rowAddress_[4] = { 0 };
	int colAddress_[4] = { 0 };

	const int maxRow_ = 12;
	const int maxCol_ = 12;

	//ブロックの各頂点の番地
	int bLtRowAddress_[12][12] = { 0 };
	int bRtRowAddress_[12][12] = { 0 };

public:
	CollisionManager(Player& player,Block**& block, const int& maxRow, const int& maxCol) {
		player_ = player;
		block_ = block;
		maxRow_	= maxRow;
		maxCol_ = maxCol;
	};

	//当たり判定
	void playerCollision();

	void blockCollision();

	void Draw();

	//===============
	//ゲッター/セッター
	//===============
	int getRowAddress(int num) { return rowAddress_[num]; }

	const int getMaxRow() { return maxRow_; }
	const int getMaxCol() { return maxCol_; }

};

