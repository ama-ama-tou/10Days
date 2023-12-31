﻿#include "CollisionManager.h"
#include "Vec2.h"
#include "base.h"
#include <Novice.h>


/*4頂点は実際に当たっているのではなく、
　4辺から見た各方向の1個先ブロックの値を見て判定*/


 ///プレイヤーの当たり判定
void CollisionManager::playerCollision(Player& player_, Block**& block_) {


	for (int r = 0; r < maxCol_; r++) {
		for (int c = 0; c < maxRow_; c++) {
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

			preLrColAddress_ = static_cast<int>(player_.getPrePos().x / player_.getSize().x);
			preLtRowAddress_ = static_cast<int>(player_.getPrePos().y / player_.getSize().y);

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

	if (block_[rowAddress_[0]][colAddress_[0]].getType() != block_[preLtRowAddress_][preLrColAddress_].getType()) {
		int keep = block_[rowAddress_[0]][colAddress_[0]].getType();
		block_[rowAddress_[0]][colAddress_[0]].setType(block_[preLtRowAddress_][preLrColAddress_].getType());
		block_[preLtRowAddress_][preLrColAddress_].setType(keep);

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

					block_[rowAddress_[0] - 1][colAddress_[0]].setIsHadCount(block_[rowAddress_[0] - 1][colAddress_[0]].getIsHadCount() + 1);

					if (block_[rowAddress_[0] - 1][colAddress_[0]].getGetting() == false) {
						block_[rowAddress_[0] - 1][colAddress_[0]].setIsGetting(true);
					}

					if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == N_POLE) {
						player_.setIsFacingTopType(1);

						player_.setRkeepTop(rowAddress_[0] - 1);
						player_.setCkeepTop(colAddress_[0]);


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

				if (block_[rowAddress_[1]][colAddress_[1] + 1].getType() != 9 && //右上の1個右
					block_[rowAddress_[1]][colAddress_[1] + 1].getType() != 9) { //右下の1個右
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

						block_[rowAddress_[1]][colAddress_[1] + 1].setIsHadCount(block_[rowAddress_[1]][colAddress_[1] + 1].getIsHadBlock() + 1);

						if (block_[rowAddress_[1]][colAddress_[1] + 1].getGetting() == false) {
							block_[rowAddress_[1]][colAddress_[1] + 1].setIsGetting(true);
						}

						if (block_[rowAddress_[0]][colAddress_[0] + 1].getType() == N_POLE) {
							player_.setIsFacingRightType(1);
						} else if (block_[rowAddress_[0]][colAddress_[0] + 1].getType() == S_POLE) {
							player_.setIsFacingRightType(2);
						}
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

				if (block_[rowAddress_[2] + 1][colAddress_[2]].getType() != 9 && //右下の1個右
					block_[rowAddress_[3] + 1][colAddress_[3]].getType() != 9) { //左下の1個右
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

						block_[rowAddress_[3] + 1][colAddress_[3]].setIsHadCount(block_[rowAddress_[3] + 1][colAddress_[3]].getIsHadBlock() + 1);

						if (block_[rowAddress_[3] + 1][colAddress_[3]].getGetting() == false) {
							block_[rowAddress_[3] + 1][colAddress_[3]].setIsGetting(true);
						}

						if (block_[rowAddress_[0] + 1][colAddress_[0]].getType() == N_POLE) {
							player_.setIsFacingBottomType(1);
						} else if (block_[rowAddress_[0] + 1][colAddress_[0]].getType() == S_POLE) {
							player_.setIsFacingBottomType(2);
						}
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

				if (block_[rowAddress_[3]][colAddress_[3] - 1].getType() != 9 && //左下の1個右
					block_[rowAddress_[0]][colAddress_[0] - 1].getType() != 9) { //左上の1個右
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

						block_[rowAddress_[0]][colAddress_[0] - 1].setIsHadCount(block_[rowAddress_[0]][colAddress_[0] - 1].getIsHadBlock() + 1);

						if (block_[rowAddress_[0]][colAddress_[0] - 1].getGetting() == false) {
							block_[rowAddress_[0]][colAddress_[0] - 1].setIsGetting(true);
						}

						if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == N_POLE) {
							player_.setIsFacingLeftType(1);

						} else if (block_[rowAddress_[0] - 1][colAddress_[0]].getType() == S_POLE) {
							player_.setIsFacingLeftType(2);

						}
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

	for (int r = 0; r < maxRow_; r++) {
		for (int c = 0; c < maxCol_; c++) {
			if (block_[r][c].getGetting() == true) {
				isGet_++;
				block_[r][c].setIsGetting(false);

				if (isGet_ > block_[r][c].getIsHadCount()) {
					block_[r][c].setIsHadCount(isGet_);
				}
			}
		}
	}
};

///ブロックとブロック
void  CollisionManager::blockCollision(Player& player_, Block**& block_) {
	

	for (int r = 0; r < maxRow_; r++) {
		for (int c = 0; c < maxCol_; c++) {

			//block_[r][c].Update(player_.getScreenLtVertex(), block_[r][c].getType());
			for (int i = 0; i < maxRow_; i++) {
				for (int j = 0; j < maxCol_; j++) {
					block_[i][j].getType();
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
							block_[r][c].setBLbRowAddress(static_cast<int>((block_[r][c].getScreenLbVertex().y - kFieldLtPos.y - 1) / block_[r][c].getSize().y));
						} else if (vertexNum == 3) {
							block_[r][c].setBRbColAddress(static_cast<int>((block_[r][c].getScreenRbVertex().x - kFieldLtPos.x - 1) / block_[r][c].getSize().x));
							block_[r][c].setBRbRowAddress(static_cast<int>((block_[r][c].getScreenRbVertex().y - kFieldLtPos.y - 1) / block_[r][c].getSize().y));
						}
					}
				}

				for (int i = 0; i < maxRow_; i++) {
					for (int j = 0; j < maxCol_; j++) {
						block_[i][j].Keep();
					}
				}

				if (block_[r][c].getType() == N_POLE || block_[r][c].getType() == S_POLE) {
					if (block_[r][c].getType() != WALL && block_[r][c].getType() != NONE) {
						///----------各頂点の番地からどの面が接しているかの判定----------///
						///上の面
						if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getIsFacingTop() != true) {
							if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType() != WALL) {
								if (block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getType() != 9) {

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
													block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getType()) {
													///ローカル座標に追加するための初期化
													int aa = (block_[r][c].getBLtColAddress()) - colAddress_[0];
													int bb = (block_[r][c].getBLtRowAddress() - 1) - rowAddress_[0];
													Vec2 resetPos = block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getLtVertex();
													resetPos.x = 0 + aa * 53.0f;
													resetPos.y = bb * 53.0f;
													block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].pointInit(resetPos);
													//ローカル座標に追加
													block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].setLocalCoOrigin(player_.getScreenLtVertex());
													//ブロックを持たせる
													block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].setIsHadBlock(true);

													if (block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].getGetting() == false) {
														block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].setIsGetting(true);
													}
													//面している
													block_[block_[r][c].getBLtRowAddress() - 1][block_[r][c].getBLtColAddress()].setIsFacingTop(true);
												}
											}
										}
									}
								}
							}
						}


						///右の面
						if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getIsFacingTop() != true) {
							if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType() != WALL) {
								if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress() + 1].getType() != 9) {
									///面しているブロックの種類を判断

									if (block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].getType() == block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress()].getType() && //右上の1個右と今のブロック
										block_[block_[r][c].getBRbRowAddress()][block_[r][c].getBRbColAddress() + 1].getType() == block_[block_[r][c].getBRbRowAddress()][block_[r][c].getBRbColAddress()].getType()) { //右下の1個右と今のブロック
										if (block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress()].getType() != NONE) {

											//1個先のブロックの左上座標を2個先にする
											block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].pointInit(block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 2].getPos());
										}
									} else {
										if (block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].getType() == S_POLE ||
											block_[block_[r][c].getBRbRowAddress()][block_[r][c].getBRbColAddress() + 1].getType() == N_POLE) {

											if (block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress()].getType() !=
												block_[block_[r][c].getBRbRowAddress()][block_[r][c].getBRbColAddress() + 1].getType()) {
												///持たれているブロックか判定する
												if (block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].getIsHadBlock() != true) {

													///ローカル座標に追加するための初期化
													int aa = (block_[r][c].getBLtColAddress() + 1) - colAddress_[0];
													int bb = (block_[r][c].getBLtRowAddress()) - rowAddress_[0];
													Vec2 resetPos = block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress() + 1].getLtVertex();
													resetPos.x = 0 + aa * 53.0f;
													resetPos.y = bb * 53.0f;
													block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].pointInit(resetPos);
													///ローカル座標に追加
													block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].setLocalCoOrigin(player_.getScreenLtVertex());
													//ブロックを持たせる
													block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].setIsHadBlock(true);

													if (block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].getGetting() == false) {
														block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].setIsHadBlock(true);
													}
													//面している
													block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].setIsFacingRight(true);

												}
											}
										}
									}
								}
							}
						} else if (block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].getType() == NONE) {
							block_[block_[r][c].getBRtRowAddress()][block_[r][c].getBRtColAddress() + 1].setIsFacingRight(false);
						}



						///下の面
						if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getIsFacingBottom() != true) {
							if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType() != WALL) {
								if (block_[block_[r][c].getBLtRowAddress() + 1][block_[r][c].getBLtColAddress()].getType() != 9) {
									//面しているブロックの種類を判断
									if (block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].getType() != 9) {
										if (block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].getType() == block_[block_[r][c].getBRbRowAddress()][block_[r][c].getBRbColAddress()].getType() && //右下の1個上と今のブロック
											block_[block_[r][c].getBLbRowAddress() + 1][block_[r][c].getBLbColAddress()].getType() == block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress()].getType()) { //左下の1個上と今のブロック
											//1個先のブロックのposを奥に移動させる
											block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].pointInit(block_[block_[r][c].getBRbRowAddress() + 2][block_[r][c].getBRbColAddress()].getPos());
										} else {
											if (block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].getType() == S_POLE ||
												block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].getType() == N_POLE) {
												//持たれているブロックか判定する
												if (block_[block_[r][c].getBRbRowAddress()][block_[r][c].getBRbColAddress()].getType() !=
													block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].getType()) {
													if (block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].getIsHadBlock() != true) {
														///ローカル座標に追加するための初期化
														int aa = (block_[r][c].getBLtColAddress()) - colAddress_[0];
														int bb = (block_[r][c].getBLtRowAddress() + 1) - rowAddress_[0];
														Vec2 resetPos = block_[block_[r][c].getBLtRowAddress() + 1][block_[r][c].getBLtColAddress()].getLtVertex();
														resetPos.x = 0 + aa * 53.0f;
														resetPos.y = bb * 53.0f;
														block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].pointInit(resetPos);
														//ローカル座標に追加
														block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].setLocalCoOrigin(player_.getScreenLtVertex());
														//ブロックを持たせる
														block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].setIsHadBlock(true);

														if (block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].getGetting() == false) {
															block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].setIsGetting(true);
														}
														//面している
														block_[block_[r][c].getBRbRowAddress() + 1][block_[r][c].getBRbColAddress()].setIsFacingBottom(true);
													}
												}
											
											}
										}
									}
								}
							}
						}


						/////左の面
						if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getIsFacingLeft() != true) {
							if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType() != WALL) {
								if (block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress() - 1].getType() != 9) {
									//面しているブロックの種類を判断
									if (block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].getType() == block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress()].getType() && //左下の1個上と今のブロック
										block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress() - 1].getType() == block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType()) { //左上の1個上と今のブロック
										//1個先のブロックのposを奥に移動させる
										block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].pointInit(block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 2].getPos());
									} else {
										if (block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].getType() == S_POLE ||
											block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].getType() == N_POLE) {

											if (block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress()].getType() !=
												block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].getType()) {
												//持たれているブロックか判定する
												if (block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].getIsHadBlock() != true) {
													///ローカル座標に追加するための初期化
													int aa = (block_[r][c].getBLtColAddress() - 1) - colAddress_[0];
													int bb = (block_[r][c].getBLtRowAddress()) - rowAddress_[0];
													Vec2 resetPos = block_[block_[r][c].getBLtRowAddress() + 1][block_[r][c].getBLtColAddress()].getLtVertex();
													resetPos.x = 0 + aa * 53.0f;
													resetPos.y = bb * 53.0f;
													block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].pointInit(resetPos);
													//ローカル座標に追加
													block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].setLocalCoOrigin(player_.getScreenLtVertex());

													//ブロックを持たせる
													block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].setIsHadBlock(true);

													if (block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].getGetting() == false) {
														block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].setIsGetting(true);
													}
													//面している
													block_[block_[r][c].getBLbRowAddress()][block_[r][c].getBLbColAddress() - 1].setIsFacingLeft(true);
												}
											}
										}
									}
								}
							}
						}

						//ブロックが壁に当たったときの処理
						for (int i = 0; i < maxRow_; i++) {
							for (int j = 0; j < maxCol_; j++) {
								if (block_[i][j].getType() == N_POLE || block_[i][j].getType() == S_POLE) {
									rbro_ = static_cast<int>((block_[r][c].getScreenLtVertex().y - kFieldLtPos.y) / block_[r][c].getSize().y);
									cbro_ = static_cast<int>((block_[r][c].getScreenLtVertex().x - kFieldLtPos.x) / block_[r][c].getSize().x);


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


			if (block_[r][c].getPreType() != block_[block_[r][c].getBLtRowAddress()][block_[r][c].getBLtColAddress()].getType()) {
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
			}


			if (block_[r][c].getGetting() == true) {
				isGet_++;
				block_[r][c].setIsGetting(false);

				if (isGet_ > block_[r][c].getIsHadCount()) {
					block_[r][c].setIsHadCount(isGet_);
				}
			}

		}
	}




	
};

