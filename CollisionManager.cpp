#include "CollisionManager.h"
#include "player.h"
#include "Vec2.h"
#include "Block.h"


/*4頂点は実際に当たっているのではなく、
　4辺から見た各方向の1個先ブロックの値を見て判定*/

///プレイヤーの当たり判定
void CollisionManager::playerCollision() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++)
		{
			block_[i][j]->getType();
		}
	}

	//頂点の番地の計算
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		rowAddress_[vertexNum] = player_.CalcuRowAddress(vertexNum);
		colAddress_[vertexNum] = player_.CalcuColAddress(vertexNum);
	}
	
	//----------各頂点の番地からどの面が接しているかの判定----------//
	///上の面
	if (!player_.getIsFacingTop()) {
		if (block_[colAddress_[0]][rowAddress_[0] - 1]->getType() != NONE && //左上の1個上
			block_[colAddress_[1]][rowAddress_[1] - 1]->getType() != NONE) { //右上の1個上
			
			player_.setIsFacingTop(true);

			///
		}
	}

	///右の面
	if (!player_.getIsFacingRight()) {
		if (block_[colAddress_[1] + 1][rowAddress_[1]]->getType() != NONE && //右上の1個右
			block_[colAddress_[2] + 1][rowAddress_[2]]->getType() != NONE) { //右下の1個右
			
			player_.setIsFacingRight(true);
		}
	}

	///下の面
	if (!player_.getIsFacingBottom()) {
		if (block_[colAddress_[2]][rowAddress_[2] + 1]->getType() != NONE && //右下の1個下
			block_[colAddress_[3]][rowAddress_[3] + 1]->getType() != NONE) { //左下の1個下
			
			player_.setIsFacingBottom(true);
		}
	}

	///左の面
	if (!player_.getIsFacingBottom()) {
		if (block_[colAddress_[3] - 1][rowAddress_[3]]->getType() != NONE && //左下の1個左
			block_[colAddress_[0] - 1][rowAddress_[0]]->getType() != NONE) { //左上の1個左
			
			player_.setIsFacingLeft(true);
		}
	}
};

///ブロックとブロック
void  CollisionManager::blockCollision() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++)
		{
			block_[i][j]->getType();
		}
	}

	//頂点の番地の計算
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		rowAddress_[vertexNum] = blockType_.CalcuRowAddress(vertexNum);
		colAddress_[vertexNum] = blockType_.CalcuColAddress(vertexNum);
	}

	///----------各頂点の番地からどの面が接しているかの判定----------///
	///上の面
	//面していないなら進める
	if (!block_[colAddress_[0]][rowAddress_[0]]->getIsFacingTop()) {
		if (block_[colAddress_[0]][rowAddress_[0] - 1]->getType() != NONE && //左上の1個上
			block_[colAddress_[1]][rowAddress_[1] - 1]->getType() != NONE) { //右上の1個上

			block_[colAddress_[0]][rowAddress_[0]]->setIsFacingTop(true);

			///面しているブロックの種類を判断
			if (block_[colAddress_[0]][rowAddress_[0] - 1]->getType() == block_[colAddress_[0]][rowAddress_[0]]->getType() && //左上の1個上と今のブロック
				block_[colAddress_[1]][rowAddress_[1] - 1]->getType() == block_[colAddress_[0]][rowAddress_[0]]->getType()) { //右上の1個上と今のブロック
				///反発させる


			} else if (block_[colAddress_[0]][rowAddress_[0] - 1]->getType() != block_[colAddress_[0]][rowAddress_[0]]->getType() && //左上の1個上と今のブロック
					   block_[colAddress_[1]][rowAddress_[1] - 1]->getType() != block_[colAddress_[0]][rowAddress_[0]]->getType()) { //右上の1個上と今のブロック
				if (block_[colAddress_[0]][rowAddress_[0] - 1]->getType() == S_POLE) {
					///くっつかせる(カウントする)


				} else if (block_[colAddress_[0]][rowAddress_[0] - 1]->getType() == WALL) {
					///止める

				}
			}
		}
	}

	///右の面
	if (!block_[colAddress_[0]][rowAddress_[0]]->getIsFacingRight()) {
		if (block_[colAddress_[1] + 1][rowAddress_[1]]->getType() != NONE && //右上の1個右
			block_[colAddress_[2] + 1][rowAddress_[2]]->getType() != NONE) { //右下の1個右
			
			block_[colAddress_[0]][rowAddress_[0]]->setIsFacingRight(true);

			///面しているブロックの種類を判断
			if (block_[colAddress_[1] + 1][rowAddress_[1]]->getType() == block_[colAddress_[0]][rowAddress_[0]]->getType() && //右上の1個上と今のブロック
				block_[colAddress_[2] + 1][rowAddress_[2]]->getType() == block_[colAddress_[0]][rowAddress_[0]]->getType()) { //右下の1個上と今のブロック
				///反発させる


			} else if (block_[colAddress_[1] + 1][rowAddress_[1]]->getType() != block_[colAddress_[0]][rowAddress_[0]]->getType() && //右上の1個上と今のブロック
					   block_[colAddress_[2] + 1][rowAddress_[2]]->getType() != block_[colAddress_[0]][rowAddress_[0]]->getType()) { //右下の1個上と今のブロック
				if (block_[colAddress_[1] + 1][rowAddress_[1]]->getType() == S_POLE) {
					///くっつかせる(カウントする)

				} else if (block_[colAddress_[1] + 1][rowAddress_[1]]->getType() == WALL) {
					///止める

				}
			}
		}
	}

	///下の面
	if (!block_[colAddress_[0]][rowAddress_[0]]->getIsFacingBottom()) {
		if (block_[colAddress_[2]][rowAddress_[2] + 1]->getType() != NONE && //右下の1個下
			block_[colAddress_[3]][rowAddress_[3] + 1]->getType() != NONE) { //左下の1個下
			
			block_[colAddress_[0]][rowAddress_[0]]->setIsFacingBottom(true);

			///面しているブロックの種類を判断
			if (block_[colAddress_[2]][rowAddress_[2] + 1]->getType() == block_[colAddress_[0]][rowAddress_[0]]->getType() && //右下の1個上と今のブロック
				block_[colAddress_[3]][rowAddress_[3] + 1]->getType() == block_[colAddress_[0]][rowAddress_[0]]->getType()) { //左下の1個上と今のブロック
				///反発させる

			} else if (block_[colAddress_[2]][rowAddress_[2] + 1]->getType() != block_[colAddress_[0]][rowAddress_[0]]->getType() && //右下の1個上と今のブロック
					   block_[colAddress_[3]][rowAddress_[3] + 1]->getType() != block_[colAddress_[0]][rowAddress_[0]]->getType()) { //左下の1個上と今のブロック
				if (block_[colAddress_[2]][rowAddress_[2] + 1]->getType() == S_POLE) {
					///くっつかせる(カウントする)

				} else if (block_[colAddress_[2]][rowAddress_[2] + 1]->getType() == WALL) {
					///止める

				}
			}
		}
	}

	///左の面
	if (!block_[colAddress_[0]][rowAddress_[0]]->getIsFacingBottom()) {
		if (block_[colAddress_[3] - 1][rowAddress_[3]]->getType() != NONE && //左下の1個左
			block_[colAddress_[0] - 1][rowAddress_[0]]->getType() != NONE) { //左上の1個左
			
			block_[colAddress_[0]][rowAddress_[0]]->setIsFacingLeft(true);

			///面しているブロックの種類を判断
			if (block_[colAddress_[3] - 1][rowAddress_[3]]->getType() == block_[colAddress_[0]][rowAddress_[0]]->getType() && //左下の1個上と今のブロック
				block_[colAddress_[0] - 1][rowAddress_[0]]->getType() == block_[colAddress_[0]][rowAddress_[0]]->getType()) { //左上の1個上と今のブロック
				///反発させる

			} else if (block_[colAddress_[3] - 1][rowAddress_[3]]->getType() != block_[colAddress_[0]][rowAddress_[0]]->getType() && //左下の1個上と今のブロック
					   block_[colAddress_[0] - 1][rowAddress_[0]]->getType() != block_[colAddress_[0]][rowAddress_[0]]->getType()) { //左上の1個上と今のブロック
				if (block_[colAddress_[3] - 1][rowAddress_[3]]->getType() == S_POLE) {
					///くっつかせる(カウントする)

				} else if (block_[colAddress_[3] - 1][rowAddress_[3]]->getType() == WALL) {
					///止める

				}
			}
		}
	}
};
