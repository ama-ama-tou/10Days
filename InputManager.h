#pragma once

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

	int num_;

public:
	// 一つしか生成されないインスタンスにはGetInstance()関数経由でアクセスする
	static InputManager* GetInstance();


	void Update();

	// Getter経由でキーの入力状況を取得する
	char* GetKeys() { return keys_; }
	char* GetPreKeys() { return preKeys_; }
};