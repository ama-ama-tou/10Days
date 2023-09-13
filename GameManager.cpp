#include "GameManager.h"
#include<Novice.h>


void GameManager::Run() {

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		inputManager_->Update();

		//選ばれたシーンの処理
		sceneManager_->Update();
		// フレームの終了
		Novice::EndFrame();

		// ループを抜ける
		if (sceneManager_->getExit()) {
			break;
		}
	}
}
