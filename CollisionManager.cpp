#include "CollisionManager.h"
#include "player.h"
#include "Vec2.h"
#include "Block.h"


/*4頂点は実際に当たっているのではなく、
　4辺から見た各方向の1個先ブロックの値を見て判定*/

///プレイヤーの当たり判定
void CollisionManager::playerCollision() {

	for (int i = 0; i < maxCol_; i++) {
		for (int j = 0; j < maxRow_; j++)
		{
			block_[i][j].getType();
		}
	}

	//頂点の番地の計算
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		rowAddress_[vertexNum] = player_.CalcuRowAddress(vertexNum);
		colAddress_[vertexNum] = player_.CalcuColAddress(vertexNum);
	}
	
	//----------各頂点の番地からどの面が接しているかの判定----------//
	//上の面
	if (!player_.getIsFacingTop()) {
		if (block_[colAddress_[0] - 1][rowAddress_[0]].getType() !=NONE && //左上の1個上
			block_[colAddress_[1] - 1][rowAddress_[1]].getType() !=NONE) { //右上の1個上
			
			player_.setIsFacingTop(true);

			//当たったブロックが壁以外の場合はくっつける
			if (block_[colAddress_[0] - 1][rowAddress_[0]].getType() != WALL && //左上の1個上
				block_[colAddress_[1] - 1][rowAddress_[1]].getType() != WALL) { //右上の1個上
				//ローカル座標に追加
				block_[colAddress_[0] - 1][rowAddress_[0]].setLocalCoOrigin(player_.getScreenLtVertex());
			} 
		}
	} else {
		if (block_[colAddress_[0]][rowAddress_[0]].getType() !=NONE && //左上(今の座標)
			block_[colAddress_[1]][rowAddress_[1]].getType() !=NONE) { //右上(今の座標)
			//戻す
			player_.setPos(player_.getPrePos());
		}
	}

	//右の面
	if (!player_.getIsFacingRight()) {
		if (block_[colAddress_[1]][rowAddress_[1] + 1].getType() !=NONE && //右上の1個右
			block_[colAddress_[2]][rowAddress_[2] + 1].getType() !=NONE) { //右下の1個右
			
			player_.setIsFacingRight(true);

			//当たったブロックが壁以外の場合はくっつける
			if (block_[colAddress_[1]][rowAddress_[1] + 1].getType() != WALL && //右上の1個右
				block_[colAddress_[2]][rowAddress_[2] + 1].getType() != WALL) { //右下の1個右

				block_[colAddress_[1]][rowAddress_[1] + 1].setLocalCoOrigin(player_.getScreenLtVertex());
			}
		}
	} else {
		if (block_[colAddress_[1]][rowAddress_[1]].getType() !=NONE && //右上(今の座標)
			block_[colAddress_[2]][rowAddress_[2]].getType() !=NONE) { //右下(今の座標)
			//戻す
			player_.setPos(player_.getPrePos());
		}
	}

	//下の面
	if (!player_.getIsFacingBottom()) {
		if (block_[colAddress_[2] + 1][rowAddress_[2]].getType() !=NONE && //右下の1個下
			block_[colAddress_[3] + 1][rowAddress_[3]].getType() !=NONE) { //左下の1個下
			
			player_.setIsFacingBottom(true);

			//当たったブロックが壁以外の場合はくっつける
			if (block_[colAddress_[2] + 1][rowAddress_[2]].getType() != WALL && //右下の1個右
				block_[colAddress_[3] + 1][rowAddress_[3]].getType() != WALL) { //左下の1個右

				block_[colAddress_[2] + 1][rowAddress_[2]].setLocalCoOrigin(player_.getScreenLtVertex());
			} 
		}
	} else {
		if (block_[colAddress_[2]][rowAddress_[2]].getType() !=NONE && //右下(今の座標)
			block_[colAddress_[3]][rowAddress_[3]].getType() !=NONE) { //左下(今の座標)
			//戻す
			player_.setPos(player_.getPrePos());
		}
	}

	//左の面
	if (!player_.getIsFacingBottom()) {
		if (block_[colAddress_[3]][rowAddress_[3] - 1].getType() !=NONE && //左下の1個左
			block_[colAddress_[0]][rowAddress_[0] - 1].getType() !=NONE) { //左上の1個左
			
			player_.setIsFacingLeft(true);

			//当たったブロックが壁以外の場合はくっつける
			if (block_[colAddress_[3]][rowAddress_[3] - 1].getType() != WALL && //左下の1個右
				block_[colAddress_[0]][rowAddress_[0] - 1].getType() != WALL) { //左上の1個右

				block_[colAddress_[3]][rowAddress_[3] - 1].setLocalCoOrigin(player_.getScreenLtVertex());
			}
		}
	} else {
		if (block_[colAddress_[3]][rowAddress_[3]].getType() !=NONE && //左下(今の座標)
			block_[colAddress_[0]][rowAddress_[0]].getType() !=NONE) { //左上(今の座標)
			//戻す
			player_.setPos(player_.getPrePos());
		}
	}
};

///ブロックとブロック
void  CollisionManager::blockCollision() {
	for (int i = 0; i < maxCol_; i++) {
		for (int j = 0; j < maxRow_; j++)
		{
			block_[i][j].getType();
		}
	}

	//頂点の番地の計算
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		rowAddress_[vertexNum] = block_[0][0].CalcuRowAddress(vertexNum);
		colAddress_[vertexNum] = block_[0][0].CalcuColAddress(vertexNum);
	}

	///----------各頂点の番地からどの面が接しているかの判定----------///
	///上の面
	if (!block_[colAddress_[0]][rowAddress_[0]].getIsFacingTop()) {
		if (block_[colAddress_[0] - 1][rowAddress_[0]].getType() != NONE && //左上の1個上
			block_[colAddress_[1] - 1][rowAddress_[1]].getType() != NONE) { //右上の1個上
			//面しているブロックの種類を判断
			if (block_[colAddress_[0] - 1][rowAddress_[0]].getType() == block_[colAddress_[0]][rowAddress_[0]].getType() && //左上の1個上と今のブロック
				block_[colAddress_[1] - 1][rowAddress_[1]].getType() == block_[colAddress_[1]][rowAddress_[1]].getType()) { //右上の1個上と今のブロック
				//持たれているブロックか判定する
				if (!block_[colAddress_[0] - 1][rowAddress_[0]].getIsHadBlock()) {
					//反発させる
					block_[colAddress_[0] - 1][rowAddress_[0]].setPos(block_[colAddress_[0] - 2][rowAddress_[0]].getPos());
				}

			} else {
				if (block_[colAddress_[0] - 1][rowAddress_[0]].getType() == S_POLE || block_[colAddress_[0] - 1][rowAddress_[0]].getType() == N_POLE) {
					//持たれているブロックか判定する
					if (block_[colAddress_[0] - 1][rowAddress_[0]].getIsHadBlock() != block_[colAddress_[0]][rowAddress_[0]].getIsHadBlock()) {
						//ローカル座標に追加
						block_[colAddress_[0] - 1][rowAddress_[0]].setLocalCoOrigin(player_.getScreenLtVertex());
						//ブロックを持たせる
						block_[colAddress_[0] - 1][rowAddress_[0]].setIsHadBlock(true);
						//面している
						block_[colAddress_[0]][rowAddress_[0]].setIsFacingTop(true);
					}
				} else if (block_[colAddress_[0] - 1][rowAddress_[0]].getType() == WALL) {
					//WALLの時はFacingをtrueにするだけでいい
					block_[colAddress_[0]][rowAddress_[0]].setIsFacingTop(true);

				}
			}
		}
	} else {
		//今の頂点が壁に侵入したら1f前に戻す
		if (block_[colAddress_[0]][rowAddress_[0]].getType() != NONE && //左上(今の座標)
			block_[colAddress_[1]][rowAddress_[1]].getType() != NONE) { //右上(今の座標)
			//左頂点を元の位置に戻す
			block_[colAddress_[0]][rowAddress_[0]].setPos(block_[colAddress_[0]][rowAddress_[0]].getPrePos());
		}
	}

	///右の面
	if (!block_[colAddress_[0]][rowAddress_[0]].getIsFacingRight()) {
		if (block_[colAddress_[1]][rowAddress_[1] + 1].getType() != NONE && //右上の1個右
			block_[colAddress_[2]][rowAddress_[2] + 1].getType() != NONE) { //右下の1個右
			///面しているブロックの種類を判断
			if (block_[colAddress_[1]][rowAddress_[1] + 1].getType() == block_[colAddress_[1]][rowAddress_[1]].getType() && //右上の1個上と今のブロック
				block_[colAddress_[2]][rowAddress_[2] + 1].getType() == block_[colAddress_[2]][rowAddress_[2]].getType()) { //右下の1個上と今のブロック
				//持たれているブロックか判定する
				if (!block_[colAddress_[1]][rowAddress_[1] + 1].getIsHadBlock()) {
					//1個先のブロックの左上座標を2個先にする
					block_[colAddress_[0]][rowAddress_[0] + 1].setPos(block_[colAddress_[0]][rowAddress_[0] + 2].getPos());
				}

			} else {
				if (block_[colAddress_[1]][rowAddress_[1] + 1].getType() == S_POLE || block_[colAddress_[1]][rowAddress_[1] + 1].getType() == N_POLE) {
					///持たれているブロックか判定する
					if (block_[colAddress_[1]][rowAddress_[1] + 1].getIsHadBlock() != block_[colAddress_[1]][rowAddress_[1]].getIsHadBlock()) {
						//ローカル座標に追加
						block_[colAddress_[1]][rowAddress_[1] + 1].setLocalCoOrigin(player_.getScreenLtVertex());
						//ブロックを持たせる
						block_[colAddress_[1]][rowAddress_[1] + 1].setIsHadBlock(true);
						//面している
						block_[colAddress_[0]][rowAddress_[0]].setIsFacingRight(true);
					}

				} else if (block_[colAddress_[1]][rowAddress_[1] + 1].getType() == WALL) {
					//WALLの時はFacingをtrueにするだけでいい
					block_[colAddress_[0]][rowAddress_[0]].setIsFacingRight(true);
				}
			}
		}
	} else {
		//今の頂点が壁に侵入したら1f前に戻す
		if (block_[colAddress_[1]][rowAddress_[1]].getType() != NONE && //右上
			block_[colAddress_[2]][rowAddress_[2]].getType() != NONE) { //右下
			//左頂点を元の位置に戻す
			block_[colAddress_[0]][rowAddress_[0]].setPos(block_[colAddress_[0]][rowAddress_[0]].getPrePos());
		}
	}

	///下の面
	if (!block_[colAddress_[0]][rowAddress_[0]].getIsFacingBottom()) {
		if (block_[colAddress_[2] + 1][rowAddress_[2]].getType() != NONE && //右下の1個下
			block_[colAddress_[3] + 1][rowAddress_[3]].getType() != NONE) { //左下の1個下
			//面しているブロックの種類を判断
			if (block_[colAddress_[2] + 1][rowAddress_[2]].getType() == block_[colAddress_[2]][rowAddress_[2]].getType() && //右下の1個上と今のブロック
				block_[colAddress_[3] + 1][rowAddress_[3]].getType() == block_[colAddress_[3]][rowAddress_[3]].getType()) { //左下の1個上と今のブロック
				//持たれているブロックか判定する
				if (!block_[colAddress_[2] + 1][rowAddress_[2]].getIsHadBlock()) {
					//1個先のブロックのposを奥に移動させる
					block_[colAddress_[0] + 1][rowAddress_[0]].setPos(block_[colAddress_[0] + 2][rowAddress_[0]].getPos());
				}

			} else { 
				if (block_[colAddress_[2] + 1][rowAddress_[2]].getType() == S_POLE || block_[colAddress_[2] + 1][rowAddress_[2]].getType() == N_POLE) {
					//持たれているブロックか判定する
					if (block_[colAddress_[2] + 1][rowAddress_[2]].getIsHadBlock() != block_[colAddress_[2]][rowAddress_[2]].getIsHadBlock()) {
						//ローカル座標に追加
						block_[colAddress_[2] + 1][rowAddress_[2]].setLocalCoOrigin(player_.getScreenLtVertex());
						//ブロックを持たせる
						block_[colAddress_[2] + 1][rowAddress_[2]].setIsHadBlock(true);
						//面している
						block_[colAddress_[0]][rowAddress_[0]].setIsFacingBottom(true);
					}

				} else if (block_[colAddress_[2] + 1][rowAddress_[2]].getType() == WALL) {
					//WALLの時はFacingをtrueにするだけでいい
					block_[colAddress_[0]][rowAddress_[0]].setIsFacingBottom(true);

				}
			}
		}
	} else {
		//今の頂点が壁に侵入したら1f前に戻す
		if (block_[colAddress_[2]][rowAddress_[2]].getType() != NONE && //右下
			block_[colAddress_[3]][rowAddress_[3]].getType() != NONE) { //左下
			//左頂点を元の位置に戻す
			block_[colAddress_[0]][rowAddress_[0]].setPos(block_[colAddress_[0]][rowAddress_[0]].getPrePos());
		}
	}

	///左の面
	if (!block_[colAddress_[0]][rowAddress_[0]].getIsFacingBottom()) {
		if (block_[colAddress_[3]][rowAddress_[3] - 1].getType() != NONE && //左下の1個左
			block_[colAddress_[0]][rowAddress_[0] - 1].getType() != NONE) { //左上の1個左
			//面しているブロックの種類を判断
			if (block_[colAddress_[3]][rowAddress_[3] - 1].getType() == block_[colAddress_[3]][rowAddress_[3]].getType() && //左下の1個上と今のブロック
				block_[colAddress_[0]][rowAddress_[0] - 1].getType() == block_[colAddress_[0]][rowAddress_[0]].getType()) { //左上の1個上と今のブロック
				//持たれているブロックか判定する
				if (!block_[colAddress_[3]][rowAddress_[3] - 1].getIsHadBlock()) {
					//1個先のブロックのposを奥に移動させる
					block_[colAddress_[0]][rowAddress_[0] - 1].setPos(block_[colAddress_[0]][rowAddress_[0] - 2].getPos());
				}

			} else {
				if (block_[colAddress_[3]][rowAddress_[3] - 1].getType() == S_POLE || block_[colAddress_[3] - 1][rowAddress_[3]].getType() == N_POLE) {
					//持たれているブロックか判定する
					if(block_[colAddress_[3]][rowAddress_[3] - 1].getIsHadBlock() != block_[colAddress_[3]][rowAddress_[3]].getIsHadBlock())
					//ローカル座標に追加
					block_[colAddress_[3]][rowAddress_[3] - 1].setLocalCoOrigin(player_.getScreenLtVertex());
					//ブロックを持たせる
					block_[colAddress_[3]][rowAddress_[3] - 1].setIsHadBlock(true);
					//面している
					block_[colAddress_[0]][rowAddress_[0]].setIsFacingLeft(true);

				} else if (block_[colAddress_[3]][rowAddress_[3] - 1].getType() == WALL) {
					//WALLの時はFacingをtrueにするだけでいい
					block_[colAddress_[0]][rowAddress_[0]].setIsFacingLeft(true);
				}
			}
		}
	} else {
		//今の頂点が壁に侵入したら1f前に戻す
		if (block_[colAddress_[3]][rowAddress_[3]].getType() != NONE && //左下
			block_[colAddress_[0]][rowAddress_[0]].getType() != NONE) { //左上
			//左頂点を元の位置に戻す
			block_[colAddress_[0]][rowAddress_[0]].setPos(block_[colAddress_[0]][rowAddress_[0]].getPrePos());
		}
	}
};
