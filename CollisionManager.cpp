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

	///当たり判定
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		//頂点の番地の計算
		rowAddress_ = player_.CalcuRowAddress(vertexNum);
		colAddress_ = player_.CalcuColAddress(vertexNum);

		if (block_[colAddress_][rowAddress_]->getType() != NONE) {
			if (vertexNum == 0) {
				player_.setIsHit(0); //左上が当たっている

			}else if (vertexNum == 1) {
				player_.setIsHit(1); //右上が当たっている

			} else if (vertexNum == 2) {
				player_.setIsHit(2); //右下が当たっている

			} else if (vertexNum == 3) {
				player_.setIsHit(3); //左下が当たっている
			}
		};
	}
};
