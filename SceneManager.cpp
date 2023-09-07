#include "SceneManager.h"

SceneManager::SceneManager() {
	//�e�V�[���̔z��
	sceneArr_[SCENE_TITLE] = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_SELLECT] = std::make_unique<Scene_Select>();
	sceneArr_[SCENE_GAME] = std::make_unique<Scene_Game>();

	//�����V�[��
	sceneNum_ = SCENE_TITLE;
}

void SceneManager::Update() {
	preSceneNum_ = sceneNum_;

	if (sceneNum_!=preSceneNum_) {
		//�V�[�����ς�����珉����
		sceneArr_[sceneNum_]->Load();
	}

	//���݂̃V�[���̍X�V����
	sceneArr_[sceneNum_]->Update();

	//���݂̃V�[���̕`�揈��
	sceneArr_[sceneNum_]->Draw();


}

