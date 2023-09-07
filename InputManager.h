#pragma once

class InputManager final {
private:
	// �R���X�g���N�^�E�f�X�g���N�^��private�Ƃ��ĊO������C���X�^���X�����Ȃ��悤�ɂ���B
	InputManager() {};
	~InputManager() {};

	// �R�s�[�R���X�g���N�^�̋֎~
	InputManager(const InputManager&) = delete;

	// ������Z�q�̃I�[�o�[���[�h���֎~
	const InputManager& operator=(const InputManager&) = delete;

	// �����o�ϐ� �����o�ϐ��͌���_�����ċ�ʂ���
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

	int num_;

public:
	// �������������Ȃ��C���X�^���X�ɂ�GetInstance()�֐��o�R�ŃA�N�Z�X����
	static InputManager* GetInstance();


	void Update();

	// Getter�o�R�ŃL�[�̓��͏󋵂��擾����
	char* GetKeys() { return keys_; }
	char* GetPreKeys() { return preKeys_; }
};