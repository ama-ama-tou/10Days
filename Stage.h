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
	STAGE_4TH,
	STAGE_5TH,
	STAGE_6TH,
	STAGE_7TH,
	STAGE_8TH,
	STAGE_9TH,
	STAGE_10TH,
	STAGE_11TH,
	STAGE_12TH,
	STAGE_13TH,
	STAGE_14TH,
	STAGE_15TH,

};

class Stage {

	//何ステージか
	static int stageNum;

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

	
	//N極,S極の数の和()
	int NSBlockNum_;

	//リセットするか
	bool isReset_;


public:

	Stage(const std::string& csvFilePath) :csvFilePath_(csvFilePath) {
		stageCsv_ = LoadCsv(csvFilePath);

		row_ = stageCsv_.size();
		col_ = stageCsv_[0].size();

		block_ = new Block** [col_];
		for (int i = 0; i < col_; i++) {
			block_[i] = new Block*[row_];
		}

	}

	void Init();

	void Update(char* keys,char*preKeys);

	void Draw();

	void Unload() {};

};

