#include "CollisionManager.h"
#include "player.h"
#include "Vec2.h"
#include "Block.h"

void CollisionManager::Collision() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++)
		{
			block_[i][j]->getType();
		}
	}

	///“–‚½‚è”»’è
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		rowAddress_ = player_.CalcuRowAddress(vertexNum);
		colAddress_ = player_.CalcuColAddress(vertexNum);

		if(block_[colAddress_][rowAddress_] )



	}
};
