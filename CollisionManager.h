#pragma once
#include"Player.h"
#include"Block.h"
#include<vector>

class CollisionManager {
	Player player_;
	Block*** block_;
	Block* blockType_;

	//Še’¸“_‚Ì”Ô’n
	int rowAddress_;
	int colAddress_;

public:
	CollisionManager(Player& player,Block***& block , Block*& blockType) :player_(player),block_(block),blockType_(blockType) {};

	//“–‚½‚è”»’è
	void playerCollision();

	void blockCollision();
};

