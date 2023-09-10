#pragma once
#include"Player.h"
#include"Block.h"
#include"CollisionManager.h"
#include"LoadCSV.h"
#include"base.h"

class Stage {

	//何ステージか
	static int stageNum;

	Coordinate stageCo_{ kFieldLtPos };

	//プレイヤー
	Player player_;

	//ロードするファイル
	const std::string& csvFilePath_;
	//ファイルを読み込んだもの
	std::vector<std::vector<int>> stageCsv_;

	Block** block_;
	//block_の要素数
	int row_;
	int col_;

	//N極,S極の数の和()
	int NSBlockNum_;
	
	int playerHasBlockNum{0};


	CollisionManager* collision;

	bool isClear_;
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
		block_ = new Block* [col_] ;
		for (int i = 0; i < col_; i++) {
			block_[i] = new Block[row_]{};
		}
		
	}

	~Stage(){
		for (int i = 0; i < col_; i++) {
			
			delete block_[i];
			}
			
		delete[] block_;

		
		delete collision;
	}

	void Init();

	void Update(char* keys,char*preKeys);

	void Draw();

	void Unload() {};

	bool getIsClear() { return isClear_; }



};

