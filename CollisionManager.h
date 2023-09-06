#pragma once
#include"Player.h"
#include"Block.h"
#include<vector>

class CollisionManager {
	Player player_;
	std::vector<Block*> block_;
public:
	CollisionManager(Player& player) :player_(player) {};

	void AddBlock(Block* block) {
		block_.push_back(block);
	}
	void Collision();


};

