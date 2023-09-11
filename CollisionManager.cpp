#include "CollisionManager.h"
#include "player.h"
#include "Vec2.h"
#include "Block.h"
#include <Novice.h>


/*4頂点は実際に当たっているのではなく、
　4辺から見た各方向の1個先ブロックの値を見て判定*/


 ///プレイヤーの当たり判定
void CollisionManager::playerCollision(Player& player_, Block**& block_) {

	for (int r = 0; r < maxCol_; r++) {
		for (int c = 0; c < maxRow_; c++)
		{
			block_[r][c].getType();
		}
	}

	//頂点の番地の計算
	for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
		if (vertexNum == 0) {

			Vec2 vertexTest = player_.getLtVertex();

			Novice::ScreenPrintf(800, 10, "vertex[0].x:%f", player_.getLtVertex().y);
			colAddress_[vertexNum] = static_cast<int>(player_.getLtVertex().x / player_.getSize().x);
			rowAddress_[vertexNum] = static_cast<int>(player_.getLtVertex().y / player_.getSize().y);
			
		} else if (vertexNum == 1) {
			colAddress_[vertexNum] = static_cast<int>((player_.getRtVertex().x - 1) / player_.getSize().x);
			rowAddress_[vertexNum] = static_cast<int>(player_.getRtVertex().y / player_.getSize().y);
			
		} else if (vertexNum == 2) {
			colAddress_[vertexNum] = static_cast<int>(player_.getLbVertex().x / player_.getSize().x);
			rowAddress_[vertexNum] = static_cast<int>((player_.getLbVertex().y - 1) / player_.getSize().y);
			
		} else if (vertexNum == 3) {
			colAddress_[vertexNum] = static_cast<int>((player_.getRbVertex().x - 1) / player_.getSize().x);
			rowAddress_[vertexNum] = static_cast<int>((player_.getRbVertex().y - 1) / player_.getSize().y);
			
		}
	}

	//----------各頂点の番地からどの面が接しているかの判定----------//
	//上の面
	if (!player_.getIsFacingTop()) {
		if (block_[rowAddress_[0]][colAddress_[0] - 1].getType() != NONE && //左上の1個上
			block_[rowAddress_[1]][colAddress_[1] - 1].getType() != NONE) { //右上の1個上

			//当たったブロックが壁以外の場合はくっつける
			if (block_[rowAddress_[0]][colAddress_[0] - 1].getType() != WALL && //左上の1個上
				block_[rowAddress_[1]][colAddress_[1] - 1].getType() != WALL) { //右上の1個上
				//ローカル座標に追加
				block_[rowAddress_[0]][colAddress_[0] - 1].setLocalCoOrigin(player_.getScreenLtVertex());

				player_.setIsFacingTop(true);
			}
		}
	}

	//左上がの番地の値がNONEじゃないとき元の座標に戻す
	if (block_[rowAddress_[0]][colAddress_[0]].getType() != NONE && //左上(今の座標)
		block_[rowAddress_[1]][colAddress_[1]].getType() != NONE) { //右上(今の座標)
		//戻す
		player_.pointInit(player_.getPrePos());
		player_.setPos(player_.getPrePos());
	}


	//右の面
	if (!player_.getIsFacingRight()) {
		if (block_[rowAddress_[1] + 1][colAddress_[1]].getType() != NONE && //右上の1個右
			block_[rowAddress_[2] + 1][colAddress_[2]].getType() != NONE) { //右下の1個右

			//当たったブロックが壁以外の場合はくっつける
			if (block_[rowAddress_[1] + 1][colAddress_[1]].getType() != WALL && //右上の1個右
				block_[rowAddress_[1] + 1][colAddress_[1]].getType() != WALL) { //右下の1個右

				block_[rowAddress_[1] + 1][colAddress_[1]].setLocalCoOrigin(player_.getScreenLtVertex());

				player_.setIsFacingRight(true);
			}
		}
	}

	//左上がの番地の値がNONEじゃないとき元の座標に戻す
	if (block_[rowAddress_[1]][colAddress_[1]].getType() != NONE && //左上(今の座標)
		block_[rowAddress_[2]][colAddress_[2]].getType() != NONE) { //右上(今の座標)
		//戻す
		player_.pointInit(player_.getPrePos());
	}

	//下の面
	if (!player_.getIsFacingBottom()) {
		if (block_[rowAddress_[2]][colAddress_[2] + 1].getType() != NONE && //右下の1個下
			block_[rowAddress_[3]][colAddress_[3] + 1].getType() != NONE) { //左下の1個下

			//当たったブロックが壁以外の場合はくっつける
			if (block_[rowAddress_[2]][colAddress_[2] + 1].getType() != WALL && //右下の1個右
				block_[rowAddress_[3]][colAddress_[3] + 1].getType() != WALL) { //左下の1個右

				block_[rowAddress_[2]][colAddress_[2] + 1].setLocalCoOrigin(player_.getScreenLtVertex());

				player_.setIsFacingBottom(true);
			}
		}
	}

	//左上がの番地の値がNONEじゃないとき元の座標に戻す
	if (block_[rowAddress_[2]][colAddress_[2]].getType() != NONE && //左上(今の座標)
		block_[rowAddress_[3]][colAddress_[3]].getType() != NONE) { //右上(今の座標)
		//戻す
		player_.pointInit(player_.getPrePos());
	}

	//左の面
	if (!player_.getIsFacingBottom()) {
		if (block_[rowAddress_[3] - 1][colAddress_[3]].getType() != NONE && //左下の1個左
			block_[rowAddress_[0] - 1][colAddress_[0]].getType() != NONE) { //左上の1個左

			//当たったブロックが壁以外の場合はくっつける
			if (block_[rowAddress_[3] - 1][colAddress_[3]].getType() != WALL && //左下の1個右
				block_[rowAddress_[0] - 1][colAddress_[0]].getType() != WALL) { //左上の1個右

				block_[rowAddress_[3] - 1][colAddress_[3]].setLocalCoOrigin(player_.getScreenLtVertex());

				player_.setIsFacingLeft(true);
			}
		}
	}

	//左上がの番地の値がNONEじゃないとき元の座標に戻す
	if (block_[rowAddress_[3]][colAddress_[3]].getType() != NONE && //左上(今の座標)bLtColAddress[i][j] - 1
		block_[rowAddress_[0]][colAddress_[0]].getType() != NONE) { //右上(今の座標)
		//戻す
		player_.pointInit(player_.getPrePos());
	}
};

///ブロックとブロック
void  CollisionManager::blockCollision(Player& player_, Block**& block_) {
	for (int r = 0; r < maxRow_; r++) {
		for (int c = 0; c < maxCol_; c++) {
			block_[r][c].getType();
		}
	}

	for (int r = 0; r < maxRow_; r++) {
		for (int c = 0; c < maxCol_; c++) {

			//頂点の番地の計算
			for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
				if (vertexNum == 0) {
					bLtColAddress_[r][c] = static_cast<int>(block_[r][c].getLtVertex().x / block_[r][c].getSize().x);
					bLtRowAddress_[r][c] = static_cast<int>(block_[r][c].getLtVertex().y / block_[r][c].getSize().y);
				} else if (vertexNum == 1) {
					bRtColAddress_[r][c] = static_cast<int>((block_[r][c].getRtVertex().x - 1) / block_[r][c].getSize().x);
					bRtRowAddress_[r][c] = static_cast<int>(block_[r][c].getRtVertex().y / block_[r][c].getSize().y);
				} else if (vertexNum == 2) {
					bLbColAddress_[r][c] = static_cast<int>(block_[r][c].getLbVertex().x / block_[r][c].getSize().x);
					bLbRowAddress_[r][c] = static_cast<int>((block_[r][c].getLbVertex().y - 1) / block_[r][c].getSize().y);
				} else if (vertexNum == 3) {
					bRbColAddress_[r][c] = static_cast<int>((block_[r][c].getRbVertex().x - 1) / block_[r][c].getSize().x);
					bRbRowAddress_[r][c] = static_cast<int>((block_[r][c].getRbVertex().y - 1) / block_[r][c].getSize().y);
				}
			}

			///----------各頂点の番地からどの面が接しているかの判定----------///
			///上の面
			if (!block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getIsFacingTop()) {
				if (block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].getType() != NONE && //左上の1個上
					block_[bRtColAddress_[r][c] - 1][bRtRowAddress_[r][c]].getType() != NONE) { //右上の1個上
					//面しているブロックの種類を判断
					if (block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].getType() == block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getType() && //左上の1個上と今のブロック
						block_[bRtColAddress_[r][c] - 1][bRtRowAddress_[r][c]].getType() == block_[bRtColAddress_[r][c]][bRtRowAddress_[r][c]].getType()) { //右上の1個上と今のブロック
						//持たれているブロックか判定する
						if (!block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].getIsHadBlock()) {
							//反発させる
							block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].pointInit(block_[bLtColAddress_[r][c] - 2][bLtRowAddress_[r][c]].getPos());
						}

					} else {
						if (block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].getType() == S_POLE || block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].getType() == N_POLE) {
							//持たれているブロックか判定する
							if (block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].getIsHadBlock() != block_[colAddress_[0]][bLtRowAddress_[r][c]].getIsHadBlock()) {
								//ローカル座標に追加
								block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].setLocalCoOrigin(player_.getScreenLtVertex());
								//ブロックを持たせる
								block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].setIsHadBlock(true);
								//面している
								block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].setIsFacingTop(true);
							}
						} else if (block_[bLtColAddress_[r][c] - 1][bLtRowAddress_[r][c]].getType() == WALL) {
							//WALLの時はFacingをtrueにするだけでいい
							block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].setIsFacingTop(true);

						}
					}
				}
			}

			//今の頂点が壁に侵入したら1f前に戻す
			if (block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getType() != NONE && //左上(今の座標)
				block_[bRtColAddress_[r][c]][bRtRowAddress_[r][c]].getType() != NONE) { //右上(今の座標)
				if (block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getType() != WALL && //左上(今の座標)
					block_[bRtColAddress_[r][c]][bRtRowAddress_[r][c]].getType() != WALL) { //右上(今の座標)
					//左頂点を元の位置に戻す
					block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].pointInit(block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getPrePos());
				}
			}


			///右の面
			if (!block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getIsFacingRight()) {
				if (block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].getType() != NONE && //右上の1個右
					block_[bRbColAddress_[r][c]][bRbColAddress_[r][c] + 1].getType() != NONE) { //右下の1個右
					///面しているブロックの種類を判断
					if (block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].getType() == block_[bRtColAddress_[r][c]][bRtColAddress_[r][c]].getType() && //右上の1個上と今のブロック
						block_[bRbColAddress_[r][c]][bRbColAddress_[r][c] + 1].getType() == block_[bRbColAddress_[r][c]][bRbColAddress_[r][c]].getType()) { //右下の1個上と今のブロック
						//持たれているブロックか判定する
						if (!block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].getIsHadBlock()) {
							//1個先のブロックの左上座標を2個先にする
							block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].pointInit(block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 2].getPos());
						}

					} else {
						if (block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].getType() == S_POLE || block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].getType() == N_POLE) {
							///持たれているブロックか判定する
							if (block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].getIsHadBlock() != block_[colAddress_[1]][rowAddress_[1]].getIsHadBlock()) {
								//ローカル座標に追加
								block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].setLocalCoOrigin(player_.getScreenLtVertex());
								//ブロックを持たせる
								block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].setIsHadBlock(true);
								//面している
								block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].setIsFacingRight(true);
							}

						} else if (block_[bRtColAddress_[r][c]][bRtColAddress_[r][c] + 1].getType() == WALL) {
							//WALLの時はFacingをtrueにするだけでいい
							block_[colAddress_[0]][rowAddress_[0]].setIsFacingRight(true);
						}
					}
				}
			}
			////今の頂点が壁に侵入したら1f前に戻す
			//if (block_[bRtColAddress_[r][c]][bRtColAddress_[r][c]].getType() != NONE && //右上
			//	block_[bRbColAddress_[r][c]][bRbColAddress_[r][c]].getType() != NONE) { //右下
			//	if (block_[bRtColAddress_[r][c]][bRtColAddress_[r][c]].getType() != WALL && //右上
			//		block_[bRbColAddress_[r][c]][bRbColAddress_[r][c]].getType() != WALL) { //右下
			//		//左頂点を元の位置に戻す
			//		block_[bRtColAddress_[r][c]][bRtColAddress_[r][c]].pointInit(block_[bRtColAddress_[r][c]][bRtColAddress_[r][c]].getPrePos());
			//	}
			//}


			///下の面
			if (!block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getIsFacingBottom()) {
				if (block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].getType() != NONE && //右下の1個下
					block_[bLbColAddress_[r][c] + 1][bLbRowAddress_[r][c]].getType() != NONE) { //左下の1個下
					//面しているブロックの種類を判断
					if (block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].getType() == block_[bRbColAddress_[r][c]][bRbRowAddress_[r][c]].getType() && //右下の1個上と今のブロック
						block_[bLbColAddress_[r][c] + 1][bLbRowAddress_[r][c]].getType() == block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].getType()) { //左下の1個上と今のブロック
						//持たれているブロックか判定する
						if (!block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].getIsHadBlock()) {
							//1個先のブロックのposを奥に移動させる
							block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].pointInit(block_[bRbColAddress_[r][c] + 2][bRbRowAddress_[r][c]].getPos());
						}

					} else {
						if (block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].getType() == S_POLE || block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].getType() == N_POLE) {
							//持たれているブロックか判定する
							if (block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].getIsHadBlock() != block_[bRbColAddress_[r][c]][bRbRowAddress_[r][c]].getIsHadBlock()) {
								//ローカル座標に追加
								block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].setLocalCoOrigin(player_.getScreenLtVertex());
								//ブロックを持たせる
								block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].setIsHadBlock(true);
								//面している
								block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].setIsFacingBottom(true);
							}

						} else if (block_[bRbColAddress_[r][c] + 1][bRbRowAddress_[r][c]].getType() == WALL) {
							//WALLの時はFacingをtrueにするだけでいい
							block_[bRbColAddress_[r][c]][bRbRowAddress_[r][c]].setIsFacingBottom(true);

						}
					}
				}
			}

			////今の頂点が壁に侵入したら1f前に戻す
			//if (block_[bRbColAddress_[r][c]][bRbRowAddress_[r][c]].getType() != NONE && //右下
			//	block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].getType() != NONE) { //左下
			//	if (block_[bRbColAddress_[r][c]][bRbRowAddress_[r][c]].getType() != WALL && //右下
			//		block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].getType() != WALL) { //左下
			//		//左頂点を元の位置に戻す
			//		block_[bRbColAddress_[r][c]][bRbRowAddress_[r][c]].pointInit(block_[bRbColAddress_[r][c]][bRbRowAddress_[r][c]].getPrePos());
			//	}
			//}


			///左の面
			if (!block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getIsFacingBottom()) {
				if (block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].getType() != NONE && //左下の1個左
					block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c] - 1].getType() != NONE) { //左上の1個左
					//面しているブロックの種類を判断
					if (block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].getType() == block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].getType() && //左下の1個上と今のブロック
						block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c] - 1].getType() == block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getType()) { //左上の1個上と今のブロック
						//持たれているブロックか判定する
						if (!block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].getIsHadBlock()) {
							//1個先のブロックのposを奥に移動させる
							block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].pointInit(block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 2].getPos());
						}

					} else {
						if (block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].getType() == S_POLE || block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].getType() == N_POLE) {
							//持たれているブロックか判定する
							if (block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].getIsHadBlock() != block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].getIsHadBlock())
								//ローカル座標に追加
								block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].setLocalCoOrigin(player_.getScreenLtVertex());
							//ブロックを持たせる
							block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].setIsHadBlock(true);
							//面している
							block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].setIsFacingLeft(true);

						} else if (block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c] - 1].getType() == WALL) {
							//WALLの時はFacingをtrueにするだけでいい
							block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].setIsFacingLeft(true);
						}
					}
				}
			}
			////今の頂点が壁に侵入したら1f前に戻す
			//if (block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].getType() != NONE && //左下
			//	block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getType() != NONE) { //左上
			//	if (block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].getType() != WALL && //左下
			//		block_[bLtColAddress_[r][c]][bLtRowAddress_[r][c]].getType() != WALL) { //左上
			//		//左頂点を元の位置に戻す
			//		block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].pointInit(block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].getPrePos());
			//	}
			//}

		}
	}
};


//描画
void CollisionManager::Draw() {
	Novice::ScreenPrintf(10, 10, "rawAddress[0]:%d", rowAddress_[0]);
	Novice::ScreenPrintf(10, 30, "rawAddress[1]:%d", rowAddress_[1]);
	Novice::ScreenPrintf(10, 50, "rawAddress[2]:%d", rowAddress_[2]);
	Novice::ScreenPrintf(10, 70, "rawAddress[3]:%d", rowAddress_[3]);

	Novice::ScreenPrintf(180, 10, "colAddress[0]:%d(leftTop)", colAddress_[0]);
	Novice::ScreenPrintf(180, 30, "colAddress[1]:%d(rightTop)", colAddress_[1]);
	Novice::ScreenPrintf(180, 50, "colAddress[2]:%d(leftBottom)", colAddress_[2]);
	Novice::ScreenPrintf(180, 70, "colAddress[3]:%d(rightBottom)", colAddress_[3]);

}
