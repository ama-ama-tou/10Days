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
	STAGE_15TH
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
	
	int playerHasBlockNum{0};


	CollisionManager* collision;

	bool isClear;
	//リセットするか
	bool isReset_;


public:

	Stage(const std::string& csvFilePath) :csvFilePath_(csvFilePath) {
		//csvデータ読み込み
		stageCsv_ = LoadCsv(csvFilePath);

		//csvデータのサイズを入力
		row_ = static_cast<int>(stageCsv_[0].size());
		col_ = static_cast<int>(stageCsv_.size());

		//それぞれ動的配列の確保
		block_ = new Block** [col_];
		for (int i = 0; i < col_; i++) {
			block_[i] = new Block*[row_];
		}
		
		collision = new CollisionManager{*player_,block_,row_,col_};
	}

	void Init();

	void Update(char* keys,char*preKeys);

	void Draw();

	void Unload() {};

	bool getIsClear() { return isClear; }



};

