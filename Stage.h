#pragma once
#include"Player.h"
#include"Block.h"
#include"CollisionManager.h"
#include"LoadCSV.h"
#include"base.h"
#include"Vec2.h"
#include"Coordinate.h"

class Stage {

	//何ステージか
	static inline int stageNum_;

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


	//背景の動き
	Coordinate localCo_;
	Vec2 bkQuadPos_[50];
	Vec2 bkQuadSize_[50];
	Vec2 bkQuadVertex_[4][50];
	Vec2 bkQuadSpeed_[50];
	Vec2 bkQuadScaleValue_[50];
	Vec2 bkQuadMinScale_[50];
	Vec2 bkQuadMaxScale_[50];
	int bkQuadColor_;
	int subtractiveColor_;
	int bkGH_;

public:
	
	Stage(int stageNum,const std::string& csvFilePath) :csvFilePath_(csvFilePath) {
		
		stageNum_ = stageNum;
		
		//csvデータ読み込み
		stageCsv_ = LoadCsv(csvFilePath);

		//csvデータのサイズを入力
		row_ = static_cast<int>(stageCsv_.size());
		col_ = static_cast<int>(stageCsv_[0].size());

		//それぞれ動的配列の確保
		block_ = new Block* [row_] ;
		for (int i = 0; i < row_; i++) {
			block_[i] = new Block[col_]{};
		}
		
	}

	~Stage(){
		for (int i = 0; i < row_; i++) {
			
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

	int getStageNum() { return stageNum_; }

};

