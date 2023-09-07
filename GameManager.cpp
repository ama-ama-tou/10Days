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

		// ESCキーが押されたらループを抜ける
		if (inputManager_->GetPreKeys()[DIK_ESCAPE] == 0 && inputManager_->GetKeys()[DIK_ESCAPE] != 0) {
			break;
		}
	}
}
