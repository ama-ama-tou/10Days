#include "GameManager.h"
#include<Novice.h>


void GameManager::Run() {

	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();

		inputManager_->Update();


		//�I�΂ꂽ�V�[���̏���
		sceneManager_->Update();	

		// �t���[���̏I��
		Novice::EndFrame();

		// ESC�L�[�������ꂽ�烋�[�v�𔲂���
		if (inputManager_->GetPreKeys()[DIK_ESCAPE] == 0 && inputManager_->GetKeys()[DIK_ESCAPE] != 0) {
			break;
		}
	}
}
