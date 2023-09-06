#pragma once
#include"Player.h"
#include"Block.h"
#include"CollisionManager.h"
#include"LoadCSV.h"
#include"base.h"

enum StageNum {
	STAGE_1ST,
	STAGE_2ND,
	STAGE_3RD,
	STAGE_4TH
	///後々追加


};

class Stage {

	Coordinate stageCo_{ kFieldLtPos };

	//プレイヤー
	Player* player_;

	//ロードするファイル
	const std::string& csvFilePath_;
	//ファイルを読み込んだもの
	std::vector<std::vector<int>> stageCsv_;


	Block*** block_;
	//block_の要素数
	int row_;
	int col_;

	//クリアしたか
	bool isClear;
	//リセットするか
	bool isReset;


public:

	Stage(const std::string& csvFilePath) :csvFilePath_(csvFilePath) {
		stageCsv_ = LoadCsv(csvFilePath);

		row_ = stageCsv_.size();
		col_ = stageCsv_[0].size();

		block_ = new Block** [row_];
		for (int i = 0; i < row_; i++) {
			block_[i] = new Block*[col_];
		}

	}

	void Init();

	void Update(char* keys,char*preKeys);

	void Draw();

	void Unload();

};

