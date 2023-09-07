#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "LC1B_08_オリハライッセイ_磁気・単・極子";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// GameManagerのインスタンスを作成
	GameManager* gameManager = new GameManager();

	// ゲームループ
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
