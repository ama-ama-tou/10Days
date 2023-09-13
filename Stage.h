#pragma once
#include"Player.h"
#include"Block.h"
#include"CollisionManager.h"
#include"LoadCSV.h"
#include"base.h"
#include"Vec2.h"

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
	
	//プレイヤーがもっているblockの数
	int playerHasBlockNum;

	CollisionManager* collision;

	bool isClear_;
	//リセットするか
	bool isReset_;


	//背景の四角（赤色）
	Vec2 bkRedQuadPos_[20];
	Vec2 bkRedQuadSize_[20];
	Vec2 bkRedQuadVertex_[20][4];
	Vec2 bkRedQuadSpeed_[20];
	Vec2 bkRedQuadScaleValue_[20];
	Vec2 bkRedQuadMinScale_[20];
	Vec2 bkRedQuadMaxScale_[20];
	int bkRedQuadColor_[20];
	int subtractiveColorRed_[20];
	int bkGH_;

	//背景の四角（青色）
	Vec2 bkBlueQuadPos_[20];
	Vec2 bkBlueQuadSize_[20];
	Vec2 bkBlueQuadVertex_[20][4];
	Vec2 bkBlueQuadSpeed_[20];
	Vec2 bkBlueQuadScaleValue_[20];
	Vec2 bkBlueQuadMinScale_[20];
	Vec2 bkBlueQuadMaxScale_[20];
	int bkBlueQuadColor_[20];
	int subtractiveColorBlue_[20];

	int stageSelectSH_;
	int stageSelectVH_;
	int frameCount_;
	bool isRang_;

	int backgroundSH_;
	int backgroundVH_;

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

	void Unload() { Novice::StopAudio(backgroundVH_); };

	bool getIsClear() { return isClear_; }

};

