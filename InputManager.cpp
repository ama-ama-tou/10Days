#include "InputManager.h"
#include <Novice.h>

// GetInstance �C���X�^���X�ɃA�N�Z�X���邽�߂̊֐�
InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

// �X�V����
void InputManager::Update() {
	// �L�[���͂��󂯎��
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

}
