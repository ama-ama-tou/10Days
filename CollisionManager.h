#pragma once
#include"Player.h"
#include"Block.h"
#include<vector>

class CollisionManager {
	Player player_;
	Block*** block_;

	//�e���_�̔Ԓn
	int rowAddress_;
	int colAddress_;

public:
	CollisionManager(Player& player,Block***& block) :player_(player),block_(block) {};

	//�����蔻��
	void playerCollision();

	void blockCollision();
};

