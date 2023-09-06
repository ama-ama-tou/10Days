#include <Novice.h>
#include <Vec2.h>
#include "Player.h"

const char kWindowTitle[] = "LC1B_08_オリハライッセイ_タイトル";

struct Box {
	Vec2 vertex[4];
	Vec2 pos;
	float width;
	float height;
	bool isHitting;
	void isHit(Box& another);
};

// 当たり判定関数
void Box::isHit(Box& another) {
	bool hitLeft = vertex[1].x < another.vertex[0].x && vertex[2].x > another.vertex[0].x;
	bool hitRight = vertex[0].x > another.vertex[1].x && vertex[3].x < another.vertex[1].x;
	bool hitTop = vertex[1].y < another.vertex[0].y && vertex[0].y > another.vertex[2].y;
	bool hitBottom = vertex[0].y > another.vertex[3].y && vertex[2].y < another.vertex[3].y;

	isHitting = (hitLeft || hitRight) && (hitTop || hitBottom);
}


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		

		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		/// 

		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
