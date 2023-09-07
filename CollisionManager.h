﻿#pragma once
#include"Player.h"
#include"Block.h"
#include<vector>

class CollisionManager {
	Player player_;
	Player* playerPos_;
	Block*** block_;
	Block blockType_;

	//各頂点の番地
	int rowAddress_[4] = { 0 };
	int colAddress_[4] = { 0 };

public:
	CollisionManager(Player& player,Block***& block , Block*& blockType) :player_(player),block_(block),blockType_(blockType) {};

	//当たり判定
	void playerCollision();

	void blockCollision();
};

