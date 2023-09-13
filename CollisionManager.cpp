#include "CollisionManager.h"
#include "Vec2.h"
#include "base.h"
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

					if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == N_POLE) {
						player_.setIsFacingTopType(1);

						player_.setRkeepTop(rowAddress_[0] - 1);
						player_.setCkeepTop(colAddress_[0]);
						player_.setSwitch(true);
						player_.setIsSwitch(true);

						/*block_[rowAddress_[0] - 1][colAddress_[0]].setTypeReset(N_POLE, rowAddress_[0] - 1, colAddress_[0]);*/
					} else if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == S_POLE) {
						player_.setIsFacingTopType(2);
						/*block_[rowAddress_[0] - 1][colAddress_[0]].setTypeReset(S_POLE, rowAddress_[0] - 1, colAddress_[0]);*/
					}
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

					if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == N_POLE) {
						player_.setIsFacingRightType(1);
					} else if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == S_POLE) {
						player_.setIsFacingRightType(2);
					}
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

					if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == N_POLE) {
						player_.setIsFacingBottomType(1);
					} else if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == S_POLE) {
						player_.setIsFacingBottomType(2);
					}
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

					if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == N_POLE) {
						player_.setIsFacingLeftType(1);

					} else if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == S_POLE) {
						player_.setIsFacingLeftType(2);

					}
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

			//block_[r][c].Update(player_.getScreenLtVertex(), block_[r][c].getType());
			for (int i = 0; i < maxRow_; i++) {
				for (int j = 0; j < maxCol_; j++) {
					block_[i][j].getPreType();
				}
			}



			if (block_[r][c].getIsHadBlock() == true) {

				//頂点の番地の計算
				if (block_[r][c].getType() == N_POLE || block_[r][c].getType() == S_POLE) {
					for (int vertexNum = 0; vertexNum < 4; vertexNum++) {
						if (vertexNum == 0) {
							block_[r][c].setBLtColAddress(static_cast<int>((block_[r][c].getScreenLtVertex().x - kFieldLtPos.x) / block_[r][c].getSize().x));
							block_[r][c].setBLtRowAddress(static_cast<int>((block_[r][c].getScreenLtVertex().y - kFieldLtPos.y) / block_[r][c].getSize().y));
						} else if (vertexNum == 1) {
							block_[r][c].setBRtColAddress(static_cast<int>((block_[r][c].getScreenRtVertex().x - kFieldLtPos.x - 1) / block_[r][c].getSize().x));
							block_[r][c].setBRtRowAddress(static_cast<int>((block_[r][c].getScreenRtVertex().y - kFieldLtPos.y) / block_[r][c].getSize().y));
						} else if (vertexNum == 2) {
							block_[r][c].setBLbColAddress(static_cast<int>((block_[r][c].getScreenLbVertex().x - kFieldLtPos.x) / block_[r][c].getSize().x));
							block_[r][c].setBLbRowAddress(static_cast<int>((block_[r][c].getScreenLbVertex().y - kFieldLtPos.y - 1) / block_[r][c].getSize().y)) ;
						} else if (vertexNum == 3) {
							block_[r][c].setBRbColAddress(static_cast<int>((block_[r][c].getScreenRbVertex().x - kFieldLtPos.x - 1) / block_[r][c].getSize().x));
							block_[r][c].setBRbRowAddress(static_cast<int>((block_[r][c].getScreenRbVertex().y - kFieldLtPos.y - 1) / block_[r][c].getSize().y));
						}
					}
				}



				
					///前フレームの位置
					int keep = block_[block_[r][c].getRowKeepTop()][block_[r][c].getColKeepTop()].getType();

					///前フレームのアドレスを更新
					block_[block_[r][c].getRowKeepTop()][block_[r][c].getColKeepTop()].setType(block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType());

					///今のアドレスを更新
					block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].setType(keep);

					
				

				
					Vec2 keepCo;
					///入手したときの座標
					keepCo.x = block_[block_[r][c].getRowKeepTop()][block_[r][c].getColKeepTop()].getLtVertex().x;
					keepCo.y = block_[block_[r][c].getRowKeepTop()][block_[r][c].getColKeepTop()].getLtVertex().y;

					///入手したときの座標に動いていない座標ができる
					block_[block_[r][c].getRowKeepTop()][block_[r][c].getColKeepTop()].setLtVertex(block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getLtVertex());

					///今の座標に入手した時の座標を入れる
					block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].setLtVertex(keepCo);

					player_.setSwitch(false);
				

				if (block_[r][c].getType() == N_POLE || block_[r][c].getType() == S_POLE) {
					if (block_[r][c].getType() != WALL && block_[r][c].getType() != NONE) {
						///----------各頂点の番地からどの面が接しているかの判定----------///
						///上の面
						if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getIsFacingTop() != true) {
							if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType() != WALL) {

								/*------------------------------反発------------------------------*/
								//面しているブロックの種類を判断
								if (block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getType() == block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType() && //左上の1個上と今のブロック
									block_[block_[r][c].getBRtRowAddress() - 1][block_[r][c].getBRtColAddress()].getType() == block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress()].getType()) { //右上の1個上と今のブロック
									//反発させる
									block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].pointInit(block_[block_[r][c].getBLtRowAddress() - 2][block_[r][c].getBLtColAddress()].getPos());



								} else {

									/*------------------------------くっつける------------------------------*/
									if (block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getType() == S_POLE || 
										block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getType() == N_POLE) {
										//持たれているブロックか判定する
										if (block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getIsHadBlock() != true) {
											if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType() != 
												block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType()) {
												///ローカル座標に追加するための初期化
												int aa = (block_[r][c].getBLtRowAddress())-colAddress_[0];
												int bb = (block_[r][c].getBLtRowAddress() - 1) - rowAddress_[0];
												Vec2 resetPos = block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getLtVertex();
												resetPos.x = 0 + aa * 53.0f;
												resetPos.y = bb * 53.0f;
												block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].pointInit(resetPos);
												//ローカル座標に追加
												block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].setLocalCoOrigin(player_.getScreenLtVertex());
												//ブロックを持たせる
												block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].setIsHadBlock(true);
												//面している
												block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].setIsFacingTop(true);
											}
										}
									}
								}
							}
						}


						/////右の面
						//if (block_[bRtRowAddress_][bRtColAddress_].getIsFacingRight() != true) {
						//	if (block_[bLtRowAddress_][bLtColAddress_].getType() != WALL) {
						//			///面しているブロックの種類を判断
						//		if (block_[bRtRowAddress_][bRtColAddress_ + 1].getType() == block_[bRtRowAddress_][bRtColAddress_].getType() && //右上の1個右と今のブロック
						//			block_[bRbRowAddress_][bRbColAddress_ + 1].getType() == block_[bRbRowAddress_][bRbColAddress_].getType()) { //右下の1個右と今のブロック
						//			if (block_[bLtRowAddress_][bLtColAddress_].getType() != NONE) {
						//				//1個先のブロックの左上座標を2個先にする
						//				block_[bRtRowAddress_][bRtColAddress_ + 1].pointInit(block_[bRtRowAddress_][bRtColAddress_ + 2].getPos());
						//			}
						//		} else {
						//			if (block_[bRtRowAddress_][bRtColAddress_ + 1].getType() == S_POLE ||
						//				block_[bRtRowAddress_][bRtColAddress_ + 1].getType() == N_POLE) {
						//						///持たれているブロックか判定する
						//				if (block_[bRtRowAddress_][bRtColAddress_ + 1].getIsHadBlock() != true) {
						//					if (block_[bRtRowAddress_][bRtColAddress_ + 1].getType() != block_[bRtRowAddress_][bRtColAddress_].getType() && //右上の1個右と今のブロック
						//						block_[bRbRowAddress_][bRbColAddress_ + 1].getType() != block_[bRbRowAddress_][bRbColAddress_].getType()) {
						//						///ローカル座標に追加するための初期化
						//						int aa = (bRtColAddress_ + 1) - colAddress_[0];
						//						int bb = (bRtRowAddress_)-rowAddress_[0];
						//						Vec2 resetPos = block_[bRtRowAddress_][bRtColAddress_ + 1].getLtVertex();
						//						resetPos.x = 0 + aa * 53.0f;
						//						resetPos.y = bb * 53.0f;
						//						block_[bRtRowAddress_][bRtColAddress_ + 1].pointInit(resetPos);
						//						///ローカル座標に追加
						//						block_[bRtRowAddress_][bRtColAddress_ + 1].setLocalCoOrigin(player_.getScreenLtVertex());
						//						//ブロックを持たせる
						//						block_[bRtRowAddress_][bRtColAddress_ + 1].setIsHadBlock(true);
						//						//面している
						//						block_[bRtRowAddress_][bRtColAddress_ + 1].setIsFacingRight(true);
						//					}
						//				}

						//			}
						//		}
						//	}
						//} else if (block_[bRtRowAddress_][bRtColAddress_ + 1].getType() == NONE) {
						//	block_[bRtRowAddress_][bRtColAddress_].setIsFacingRight(false);
						//}



						/////下の面
						//if (block_[bLtRowAddress_][bLtColAddress_].getIsFacingBottom() != true) {
						//	if (block_[bLtRowAddress_][bLtColAddress_].getType() != WALL) {
						//			//面しているブロックの種類を判断
						//		if (block_[bRbRowAddress_ + 1][bRbColAddress_].getType() == block_[bRbColAddress_][bRbRowAddress_].getType() && //右下の1個上と今のブロック
						//			block_[bLbRowAddress_ + 1][bLbColAddress_].getType() == block_[bLbColAddress_][bLbRowAddress_].getType()) { //左下の1個上と今のブロック
						//			//1個先のブロックのposを奥に移動させる
						//			block_[bRbRowAddress_ + 1][bRbColAddress_].pointInit(block_[bRbRowAddress_ + 2][bRbColAddress_].getPos());
						//		} else {
						//			if (block_[bRbRowAddress_ + 1][bRbColAddress_].getType() == S_POLE ||
						//				block_[bRbRowAddress_ + 1][bRbColAddress_].getType() == N_POLE) {
						//				//持たれているブロックか判定する
						//				if (block_[bRbRowAddress_][bRbColAddress_].getType() == NONE) {
						//					if (block_[bRbRowAddress_ + 1][bRbColAddress_].getIsHadBlock() != true) {
						//						///ローカル座標に追加するための初期化
						//						int aa = (bRtColAddress_)-colAddress_[0];
						//						int bb = (bRtRowAddress_ + 1) - rowAddress_[0];
						//						Vec2 resetPos = block_[bRbRowAddress_ + 1][bRbColAddress_].getLtVertex();
						//						resetPos.x = 0 + aa * 53.0f;
						//						resetPos.y = bb * 53.0f;
						//						block_[bRbRowAddress_ + 1][bRbColAddress_].pointInit(resetPos);
						//						//ローカル座標に追加
						//						block_[bRbRowAddress_ + 1][bRbColAddress_].setLocalCoOrigin(player_.getScreenLtVertex());
						//						//ブロックを持たせる
						//						block_[bRbRowAddress_ + 1][bRbColAddress_].setIsHadBlock(true);
						//						//面している
						//						block_[bRbRowAddress_ + 1][bRbColAddress_].setIsFacingBottom(true);
						//					}
						//				}
						//			}
						//		}
						//	}
						//}



						/////左の面
						//if (block_[bLtRowAddress_][bLtColAddress_].getIsFacingLeft() != true) {
						//	if (block_[bLtRowAddress_][bLtColAddress_].getType() != WALL) {
						//			//面しているブロックの種類を判断
						//		if (block_[bLbRowAddress_][bLbColAddress_ - 1].getType() == block_[bLbRowAddress_][bLbColAddress_].getType() && //左下の1個上と今のブロック
						//			block_[bLtRowAddress_][bLtColAddress_ - 1].getType() == block_[bLtRowAddress_][bLtColAddress_].getType()) { //左上の1個上と今のブロック
						//			//1個先のブロックのposを奥に移動させる
						//			block_[bLbRowAddress_][bLbColAddress_ - 1].pointInit(block_[bLbRowAddress_][bLbColAddress_ - 2].getPos());
						//		} else {
						//			if (block_[bLbRowAddress_][bLbColAddress_ - 1].getType() == S_POLE ||
						//				block_[bLbRowAddress_][bLbColAddress_ - 1].getType() == N_POLE) {
						//					//持たれているブロックか判定する
						//				if (block_[bLbRowAddress_][bLbColAddress_ - 1].getIsHadBlock() != true) {
						//					///ローカル座標に追加するための初期化
						//					int aa = (bRtColAddress_ - 1) - colAddress_[0];
						//					int bb = (bRtRowAddress_)-rowAddress_[0];

						//					Vec2 resetPos = block_[bRbRowAddress_][bRbColAddress_ - 1].getLtVertex();
						//					resetPos.x = 0 + aa * 53.0f;
						//					resetPos.y = bb * 53.0f;
						//					block_[bLbRowAddress_][bLbColAddress_ - 1].pointInit(resetPos);
						//					//ローカル座標に追加
						//					block_[bLbRowAddress_][bLbColAddress_ - 1].setLocalCoOrigin(player_.getScreenLtVertex());

						//					//ブロックを持たせる
						//					block_[bLbRowAddress_][bLbColAddress_ - 1].setIsHadBlock(true);

						//					//面している
						//					block_[bLbRowAddress_][bLbColAddress_ - 1].setIsFacingLeft(true);
						//				}
						//			}
						//		}
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

			///保存
			block_[r][c].Keep();


			/*block_[r][c].setRowKeepTop(bLtRowAddress_);
			block_[r][c].setRowKeepRight(bRtRowAddress_);
			block_[r][c].setRowKeepBottom(bLbRowAddress_);
			block_[r][c].setRowKeepLeft(bRbRowAddress_);

			block_[r][c].setColKeepTop(bLtColAddress_);
			block_[r][c].setColKeepRight(bRtColAddress_);
			block_[r][c].setColKeepBottom(bLbColAddress_);
			block_[r][c].setColKeepLeft(bRbColAddress_);

			block_[r][c].setKeepLtVer(block_[r][c].getLtVertex());
			block_[r][c].setKeepRtVer(block_[r][c].getRtVertex());
			block_[r][c].setKeepLbVer(block_[r][c].getLbVertex());
			block_[r][c].setKeepRbVer(block_[r][c].getRbVertex());

			block_[r][c].setKeepIsHadBlock(block_[r][c].getIsHadBlock());*/

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


			}
		}
	}

	Novice::ScreenPrintf(10, 620, "colAddress_[0]:%d", colAddress_[0]);
	Novice::ScreenPrintf(170, 620, "rowAddress_[0]:%d", rowAddress_[0] - 1);
	Novice::ScreenPrintf(10, 640, "colAddress_[1]:%d", colAddress_[1]);
	Novice::ScreenPrintf(170, 640, "rowAddress_[1]:%d", rowAddress_[1] - 1);
	Novice::ScreenPrintf(10, 660, "colAddress_[2]:%d", colAddress_[2]);
	Novice::ScreenPrintf(170, 660, "rowAddress_[2]:%d", rowAddress_[2] - 1);
	Novice::ScreenPrintf(10, 680, "colAddress_[3]:%d", colAddress_[3]);
	Novice::ScreenPrintf(170, 680, "rowAddress_[3]:%d", rowAddress_[3] - 1);

}
