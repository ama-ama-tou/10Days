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
			/*block_[r][c].setPrePos(block_[r][c].getLtVertex());*/
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
		if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() != NONE && //左上の1個上
			block_[rowAddress_[1] - 1][colAddress_[1]].getType() != NONE) { //右上の1個上

			//当たったブロックが壁以外の場合はくっつける
			if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() != WALL && //左上の1個上
				block_[rowAddress_[1] - 1][colAddress_[1]].getType() != WALL) { //右上の1個上
				if (block_[rowAddress_[0] - 1][colAddress_[0]].getIsHadBlock() != true) {
					//頂点の保存
					setBLtPreVertex(block_[rowAddress_[0] - 1][colAddress_[0]].getLtVertex(), rowAddress_[0] - 1, colAddress_[0]);
					///ローカル座標に追加するためのブロックの初期化
					Vec2 resetPos;
					resetPos.x = 0;
					resetPos.y = -53;
					block_[rowAddress_[0] - 1][colAddress_[0]].pointInit(resetPos);
					//ローカル座標に追加
					block_[rowAddress_[0] - 1][colAddress_[0]].setLocalCoOrigin(player_.getScreenLtVertex());
					//プレイヤーの上の面にはもうくっつかない
					player_.setIsFacingTop(true);
					//ブロックをプレイヤーに持たせる
					block_[rowAddress_[0] - 1][colAddress_[0]].setIsHadBlock(true);
				}
			}
		}
	}

	//右の面
	if (!player_.getIsFacingRight()) {
		if (block_[rowAddress_[1]][colAddress_[1] + 1].getType() != NONE && //右上の1個右
			block_[rowAddress_[2]][colAddress_[2] + 1].getType() != NONE) { //右下の1個右

			//当たったブロックが壁以外の場合はくっつける
			if (block_[rowAddress_[1]][colAddress_[1] + 1].getType() != WALL && //右上の1個右
				block_[rowAddress_[1]][colAddress_[1] + 1].getType() != WALL) { //右下の1個右
				if (block_[rowAddress_[1]][colAddress_[1] + 1].getIsHadBlock() != true) {
					///ローカル座標に追加するための初期化
					Vec2 resetPos;
					resetPos.x = 53;
					resetPos.y = 0;
					block_[rowAddress_[1]][colAddress_[1] + 1].pointInit(resetPos);
					//ローカル座標に追加
					block_[rowAddress_[1]][colAddress_[1] + 1].setLocalCoOrigin(player_.getScreenLtVertex());
					//プレイヤーの右にはもうつかない
					player_.setIsFacingRight(true);
					//ブロックをプレイヤーに持たせる
					block_[rowAddress_[1]][colAddress_[1] + 1].setIsHadBlock(true);
				}
			}
		}
	}

	//下の面
	if (!player_.getIsFacingBottom()) {
		if (block_[rowAddress_[2] + 1][colAddress_[2]].getType() != NONE && //右下の1個下
			block_[rowAddress_[3] + 1][colAddress_[3]].getType() != NONE) { //左下の1個下

			//当たったブロックが壁以外の場合はくっつける
			if (block_[rowAddress_[2] + 1][colAddress_[2]].getType() != WALL && //右下の1個右
				block_[rowAddress_[3] + 1][colAddress_[3]].getType() != WALL) { //左下の1個右
				if (block_[rowAddress_[2] + 1][colAddress_[2]].getIsHadBlock() != true) {
					///ローカル座標に追加するための初期化
					Vec2 resetPos;
					resetPos.x = 0;
					resetPos.y = 53;
					block_[rowAddress_[2] + 1][colAddress_[2]].pointInit(resetPos);
					//ローカル座標に追加
					block_[rowAddress_[2] + 1][colAddress_[2]].setLocalCoOrigin(player_.getScreenLtVertex());
					//プレイヤーの下にはもうつかない
					player_.setIsFacingBottom(true);
					//ブロックをプレイヤーに持たせる
					block_[rowAddress_[2] + 1][colAddress_[2]].setIsHadBlock(true);
				}
			}
		}
	}

	//左の面
	if (!player_.getIsFacingLeft()) {
		if (block_[rowAddress_[3]][colAddress_[3] - 1].getType() != NONE && //左下の1個左
			block_[rowAddress_[0]][colAddress_[0] - 1].getType() != NONE) { //左上の1個左

			//当たったブロックが壁以外の場合はくっつける
			if (block_[rowAddress_[3]][colAddress_[3] - 1].getType() != WALL && //左下の1個右
				block_[rowAddress_[0]][colAddress_[0] - 1].getType() != WALL) { //左上の1個右
				if (block_[rowAddress_[3]][colAddress_[3] - 1].getIsHadBlock() != true) {
					///ローカル座標に追加するための初期化
					Vec2 resetPos;
					resetPos.x = -53;
					resetPos.y = 0;
					block_[rowAddress_[3]][colAddress_[3] - 1].pointInit(resetPos);
					//ローカル座標に追加
					block_[rowAddress_[3]][colAddress_[3] - 1].setLocalCoOrigin(player_.getScreenLtVertex());
					//プレイヤーの左にはもうつかない
					player_.setIsFacingLeft(true);
					//ブロックをプレイヤーに持たせる
					block_[rowAddress_[3]][colAddress_[3] - 1].setIsHadBlock(true);
				}
			}
		}
	}

	//左上の番地がNONEじゃないとき元の座標に戻す
	if (block_[rowAddress_[0]][colAddress_[0]].getType() == WALL && //左上(今の座標)
		block_[rowAddress_[1]][colAddress_[1]].getType() == WALL) { //右上(今の座標)
		//戻す

		player_.setPos(player_.getPrePos());
		player_.pointInit(player_.getPos());
	}


};

///ブロックとブロック
void  CollisionManager::blockCollision(Player& player_, Block**& block_) {
	for (int r = 0; r < maxRow_; r++) {
		for (int c = 0; c < maxCol_; c++) {
			block_[r][c].getType();

			if (block_[r][c].getIsHadBlock() == true) {

				/*block_[r][c].setPrePos(block_[r][c].getLtVertex());
				block_[r][c].pointInit((block_[r][c].getLocalCo().OriginFromScreen(block_[r][c].getLocalCo().getOrigin())));*/
				Novice::ScreenPrintf(1000, 650, "block_[%d][%d].vertex.x:%f", r, c, block_[r][c].getRbVertex().x);
			}
		}
	}

	for (int r = 0; r < maxRow_; r++) {
		for (int c = 0; c < maxCol_; c++) {
			if (block_[r][c].getIsHadBlock() == true) {
				block_[r][c].Update(player_.getScreenLtVertex());
			}

			//頂点の番地の計算
			if (block_[r][c].getType() == N_POLE || block_[r][c].getType() == S_POLE) {
				for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
					if (vertexNum == 0) {
						bLtColAddress_ = static_cast<int>(block_[r][c].getScreenLtVertex().x / block_[r][c].getSize().x) - 6;
						bLtRowAddress_ = static_cast<int>(block_[r][c].getScreenLtVertex().y / block_[r][c].getSize().y);
					} else if (vertexNum == 1) {
						bRtColAddress_ = static_cast<int>((block_[r][c].getScreenRtVertex().x - 5) / block_[r][c].getSize().x) - 6;
						bRtRowAddress_ = static_cast<int>(block_[r][c].getScreenRtVertex().y / block_[r][c].getSize().y);
					} else if (vertexNum == 2) {
						bLbColAddress_ = static_cast<int>(block_[r][c].getScreenLbVertex().x / block_[r][c].getSize().x) - 6;
						bLbRowAddress_ = static_cast<int>((block_[r][c].getScreenLbVertex().y - 1) / block_[r][c].getSize().y);
					} else if (vertexNum == 3) {
						bRbColAddress_ = static_cast<int>((block_[r][c].getScreenRbVertex().x - 3) / block_[r][c].getSize().x) - 6;
						bRbRowAddress_ = static_cast<int>((block_[r][c].getScreenRbVertex().y - 3) / block_[r][c].getSize().y) - 1;
					}
				}
			}


			if (block_[r][c].getType() != WALL && block_[r][c].getType() != NONE) {
				///----------各頂点の番地からどの面が接しているかの判定----------///
				///上の面

				if (block_[bLtRowAddress_][bLtColAddress_].getIsFacingTop() != true) {

					if (block_[bLtRowAddress_ - 1][bLtColAddress_].getType() != NONE && //左上の1個上
						block_[bRtRowAddress_ - 1][bRtColAddress_].getType() != NONE) { //右上の1個上
						//面しているブロックの種類を判断
						if (block_[bLtRowAddress_ - 1][bLtColAddress_].getType() == block_[bLtRowAddress_][bLtColAddress_].getType() && //左上の1個上と今のブロック
							block_[bRtRowAddress_ - 1][bRtColAddress_].getType() == block_[bRtRowAddress_][bRtColAddress_].getType()) { //右上の1個上と今のブロック
							//持たれているブロックか判定する
							if (!block_[bLtRowAddress_ - 1][bLtColAddress_].getIsHadBlock()) {
								//反発させる
								block_[bLtRowAddress_ - 1][bLtColAddress_].pointInit(block_[bLtRowAddress_ - 2][bLtColAddress_].getPos());
							}

						} else {
							if (block_[bLtRowAddress_ - 1][bLtColAddress_].getType() == S_POLE || block_[bLtRowAddress_ - 1][bLtColAddress_].getType() == N_POLE) {
								//持たれているブロックか判定する
								if (block_[bLtRowAddress_ - 1][bLtColAddress_].getIsHadBlock() != true) {
									if (block_[bLtRowAddress_ - 1][bLtColAddress_].getIsHadBlock() != true) {
										///ローカル座標に追加するための初期化
										int aa = (bRtColAddress_) - colAddress_[0];
										int bb = (bRtRowAddress_ - 1)-rowAddress_[0];

										Vec2 resetPos = block_[bRtRowAddress_ -1][bRtColAddress_].getLtVertex();
										resetPos.x = 0 + aa * 53.0f;
										resetPos.y = bb * 53.0f;
										block_[bLtRowAddress_ - 1][bLtColAddress_].pointInit(resetPos);
										//ローカル座標に追加
										block_[bLtRowAddress_ - 1][bLtColAddress_].setLocalCoOrigin(player_.getScreenLtVertex());
										//ブロックを持たせる
										block_[bLtRowAddress_ - 1][bLtColAddress_].setIsHadBlock(true);
										//面している
										block_[bLtRowAddress_ - 1][bLtColAddress_].setIsFacingTop(true);
									}

								}
							} else if (block_[bLtRowAddress_ - 1][bLtColAddress_].getType() == WALL) {
								//WALLの時はFacingをtrueにするだけでいい
								block_[bLtRowAddress_][bLtColAddress_].setIsFacingTop(true);

							}
						}
					}
				}


				///右の面

				if (block_[bRtRowAddress_][bRtColAddress_].getIsFacingRight() != true) {

					if (block_[bRtRowAddress_][bRtColAddress_ + 1].getType() != NONE && //右上の1個右
						block_[bRbRowAddress_][bRbColAddress_ + 1].getType() != NONE) { //右下の1個右
						///面しているブロックの種類を判断
						if (block_[bRtRowAddress_][bRtColAddress_ + 1].getType() == block_[bRtRowAddress_][bRtColAddress_ + 1].getType() && //右上の1個上と今のブロック
							block_[bRbRowAddress_][bRbColAddress_ + 1].getType() == block_[bRbRowAddress_][bRbColAddress_ + 1].getType()) { //右下の1個上と今のブロック
							//持たれているブロックか判定する
							if (!block_[bRtRowAddress_][bRtColAddress_ + 1].getIsHadBlock()) {
								//1個先のブロックの左上座標を2個先にする
								block_[bRtRowAddress_][bRtColAddress_ + 1].pointInit(block_[bRtRowAddress_][bRtColAddress_ + 2].getPos());
							} else {
								if (block_[bRtRowAddress_][bRtColAddress_ + 1].getType() == S_POLE || block_[bRtRowAddress_][bRtColAddress_ + 1].getType() == N_POLE) {
									///持たれているブロックか判定する
									if (block_[bRtRowAddress_][bRtColAddress_ + 1].getIsHadBlock() != true) {

										///ローカル座標に追加するための初期化
										int aa = (bRtColAddress_ + 1) - colAddress_[0];
										int bb = (bRtRowAddress_)-rowAddress_[0];

										Vec2 resetPos = block_[bRtRowAddress_][bRtColAddress_ + 1].getLtVertex();
										resetPos.x = 0 + aa * 53.0f;
										resetPos.y = bb * 53.0f;
										block_[bRtRowAddress_][bRtColAddress_ + 1].pointInit(resetPos);
										///ローカル座標に追加
										block_[bRtRowAddress_][bRtColAddress_ + 1].setLocalCoOrigin(player_.getScreenLtVertex());
										//ブロックを持たせる
										block_[bRtRowAddress_][bRtColAddress_ + 1].setIsHadBlock(true);
										//面している
										block_[bRtRowAddress_][bRtColAddress_ + 1].setIsFacingRight(true);

									}

								} else if (block_[bRtRowAddress_][bRtColAddress_ + 1].getType() == WALL) {
									//WALLの時はFacingをtrueにするだけでいい
									block_[bRtRowAddress_][bRtColAddress_].setIsFacingRight(true);
								}

							}
						}

					}
				}



				///下の面
				//if (block_[bLtRowAddress_][bLtColAddress_].getType() != WALL) {

				//	if (block_[bLtRowAddress_][bLtColAddress_[r][c]].getIsHadBlock() == false) {
				//		if (block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].getIsFacingBottom() != true) {

				//			if (block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].getType() != NONE && //右下の1個下
				//				block_[bLbRowAddress_[r][c] + 1][bLbColAddress_[r][c]].getType() != NONE) { //左下の1個下
				//				//面しているブロックの種類を判断
				//				if (block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].getType() == block_[bRbColAddress_[r][c]][bRbRowAddress_[r][c]].getType() && //右下の1個上と今のブロック
				//					block_[bLbRowAddress_[r][c] + 1][bLbColAddress_[r][c]].getType() == block_[bLbColAddress_[r][c]][bLbRowAddress_[r][c]].getType()) { //左下の1個上と今のブロック
				//					//持たれているブロックか判定する
				//					if (!block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].getIsHadBlock()) {
				//						//1個先のブロックのposを奥に移動させる
				//						block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].pointInit(block_[bRbRowAddress_[r][c] + 2][bRbColAddress_[r][c]].getPos());
				//					}

				//				} else {
				//					if (block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].getType() == S_POLE || block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].getType() == N_POLE) {
				//						//持たれているブロックか判定する
				//						if (block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].getIsHadBlock() != block_[bRbRowAddress_[r][c]][bRbColAddress_[r][c]].getIsHadBlock()) {

				//							///ローカル座標に追加するための初期化
				//							Vec2 resetPos;
				//							resetPos.x = 0;
				//							resetPos.y = 53;
				//							block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].pointInit(resetPos);
				//							//ローカル座標に追加
				//						//	block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].setLocalCoOrigin(player_.getScreenLtVertex());
				//							//ブロックを持たせる
				//							block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].setIsHadBlock(true);
				//							//面している
				//							block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].setIsFacingBottom(true);

				//						}

				//					} else if (block_[bRbRowAddress_[r][c] + 1][bRbColAddress_[r][c]].getType() == WALL) {
				//						//WALLの時はFacingをtrueにするだけでいい
				//						block_[bRbRowAddress_[r][c]][bRbColAddress_[r][c]].setIsFacingBottom(true);

				//					}
				//				}
				//			}
				//		}
				//	}
				//}

				/////左の面
				//if (block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].getType() != WALL) {

				//	if (block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].getIsHadBlock() == false) {
				//		if (block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].getIsFacingBottom() != true) {

				//			if (block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].getType() != NONE && //左下の1個左
				//				block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c] - 1].getType() != NONE) { //左上の1個左
				//				//面しているブロックの種類を判断
				//				if (block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].getType() == block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c]].getType() && //左下の1個上と今のブロック
				//					block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c] - 1].getType() == block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].getType()) { //左上の1個上と今のブロック
				//					//持たれているブロックか判定する
				//					if (block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].getIsHadBlock() != true) {
				//						//1個先のブロックのposを奥に移動させる
				//						block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].pointInit(block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 2].getPos());
				//					}

				//				} else {
				//					if (block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].getType() == S_POLE || block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].getType() == N_POLE) {
				//						//持たれているブロックか判定する
				//						if (block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].getIsHadBlock() != block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c]].getIsHadBlock()) {

				//							///ローカル座標に追加するための初期化
				//							Vec2 resetPos;
				//							resetPos.x = -53;
				//							resetPos.y = 0;
				//							block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].pointInit(resetPos);
				//							//ローカル座標に追加
				//							//block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].setLocalCoOrigin(player_.getScreenLtVertex());
				//							//ブロックを持たせる
				//							block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].setIsHadBlock(true);
				//							//面している
				//							block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].setIsFacingLeft(true);

				//						}
				//					} else if (block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c] - 1].getType() == WALL) {
				//						//WALLの時はFacingをtrueにするだけでいい
				//						block_[bLbRowAddress_[r][c]][bLbColAddress_[r][c]].setIsFacingLeft(true);
				//					}
				//				}
				//			}
				//		}
				//	}
				//}


				//今の頂点が壁に侵入したら1f前に戻す
				//if (block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].getType() != NONE && //左上(今の座標)
				//	block_[bRtRowAddress_[r][c]][bRtColAddress_[r][c]].getType() != NONE) { //右上(今の座標)
				//	if (block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].getType() == WALL && //左上(今の座標)
				//		block_[bRtRowAddress_[r][c]][bRtColAddress_[r][c]].getType() == WALL) { //右上(今の座標)
				//		//左頂点を元の位置に戻す
				//		block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].pointInit(block_[bLtRowAddress_[r][c]][bLtColAddress_[r][c]].getPrePos());
				//	}
				//}

				//ブロックが壁に当たったときの処理
				for (int i = 0; i < maxRow_; i++) {
					for (int j = 0; j < maxCol_; j++) {
						if (block_[i][j].getType() == N_POLE || block_[i][j].getType() == S_POLE) {


							rbro_ = static_cast<int>(block_[i][j].getScreenLtVertex().y / 53.0f);
							cbro_ = static_cast<int>(block_[i][j].getScreenLtVertex().x / 53.0f) - 6;


							if (block_[rbro_][cbro_].getType() == WALL) {

								player_.setPos(player_.getPrePos());
								player_.pointInit(player_.getPos());
							}
						}
					}
				}
			}
		}
	}
};


//描画
void CollisionManager::Draw(Block**& block_) {
	Novice::ScreenPrintf(10, 10, "rawAddress[0]:%d", rowAddress_[0]);
	Novice::ScreenPrintf(10, 30, "rawAddress[1]:%d", rowAddress_[1]);
	Novice::ScreenPrintf(10, 50, "rawAddress[2]:%d", rowAddress_[2]);
	Novice::ScreenPrintf(10, 70, "rawAddress[3]:%d", rowAddress_[3]);

	Novice::ScreenPrintf(180, 10, "colAddress[0]:%d(leftTop)", colAddress_[0]);
	Novice::ScreenPrintf(180, 30, "colAddress[1]:%d(rightTop)", colAddress_[1]);
	Novice::ScreenPrintf(180, 50, "colAddress[2]:%d(leftBottom)", colAddress_[2]);
	Novice::ScreenPrintf(180, 70, "colAddress[3]:%d(rightBottom)", colAddress_[3]);

	for (int r = 0; r < maxRow_; r++) {
		for (int c = 0; c < maxCol_; c++) {
			if (block_[r][c].getIsHadBlock() == true) {
				Novice::ScreenPrintf(10, 200 + (r * 20), "isHitBlock[%d][%d]", r, c);
				Novice::ScreenPrintf(10, 200 + (r * 20), "isHitBlock[%d][%d]", r, c);
				Novice::ScreenPrintf(10, 270 + (r * 20), "origin.x:%f", block_[r][c].getLtVertex().x);
				Novice::ScreenPrintf(200, 270, "origin.y:%f", block_[r][c].getLocalCo().getOrigin().y);

				Novice::ScreenPrintf(200, 270, "origin.y:%f", block_[r][c].getLocalCo().getOrigin().y);

				Novice::ScreenPrintf(10, 600, "vertex[0].x:%f", block_[r][c].getScreenLtVertex().x);

				Novice::ScreenPrintf(10, 620, "bRtRowAddress_:%d", bRtRowAddress_);
				Novice::ScreenPrintf(10, 640, "bRtColAddress_:%d", bRtColAddress_);

				Novice::ScreenPrintf(10, 660, "bRbRowAddress_:%d", bRbRowAddress_);
				Novice::ScreenPrintf(10, 680, "bRbColAddress_:%d", bRbColAddress_);
			}
		}
	}

}
