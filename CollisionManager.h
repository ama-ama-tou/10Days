#pragma once
#include"Player.h"
#include"Block.h"
#include<vector>

class CollisionManager {
	Player player_;
	Block*** block_;

	//Še’¸“_‚Ì”Ô’n
	int rowAddress_;
	int colAddress_;

public:
	CollisionManager(Player& player,Block***& block) :player_(player),block_(block) {};

	//“–‚½‚è”»’è
	void playerCollision();

	void blockCollision();
};

