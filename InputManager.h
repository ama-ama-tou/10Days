#pragma once
#include "Vec2.h"

enum ClickState {
	STATE_NONE,
	LEFT_CLICK,
	RIGIHT_CLICK
};

class InputManager final {
private:
	// コンストラクタ・デストラクタをprivateとして外部からインスタンスを作れないようにする。
	InputManager() {};
	~InputManager() {};

	// コピーコンストラクタの禁止
	InputManager(const InputManager&) = delete;

	// 代入演算子のオーバーロードを禁止
	const InputManager& operator=(const InputManager&) = delete;

	// メンバ変数 メンバ変数は後ろに_をつけて区別する
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

	int x_;
	int y_;

	int clickState_;

	int num_;

public:
	// 一つしか生成されないインスタンスにはGetInstance()関数経由でアクセスする
	static InputManager* GetInstance();

	void Update();

	Vec2 getMousePos() { return Vec2(static_cast<float>(x_), static_cast<float>(y_)); }
	int getClickState() { return clickState_; }
	void setClickState(int clickState) { clickState_ = clickState; }

	// Getter経由でキーの入力状況を取得する
	char* GetKeys() { return keys_; }
	char* GetPreKeys() { return preKeys_; }
};