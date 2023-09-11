#pragma once
#include"Player.h"
#include"Block.h"
#include<vector>

class CollisionManager {
	/*Player player_;
	
	Block** block_;*/

	//各頂点の番地
	int rowAddress_[4] = { 0 };
	int colAddress_[4] = { 0 };

	int maxRow_;
	int maxCol_;

	//ブロックの各頂点の番地
	int bLtRowAddress_[12][12] = { 0 };
	int bRtRowAddress_[12][12] = { 0 };

public:
	CollisionManager(const int& maxRow, const int& maxCol) {
	
		maxRow_	= maxRow;
		maxCol_ = maxCol;
	};

	//当たり判定
	void playerCollision(Player& player , Block**& block);

	void blockCollision(Player& player, Block**& block);

	void Draw();

	//===============
	//ゲッター/セッター
	//===============
	int getRowAddress(int num) { return rowAddress_[num]; }

	const int getMaxRow() { return maxRow_; }
	const int getMaxCol() { return maxCol_; }

};

