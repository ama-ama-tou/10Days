#pragma once
#include "Scene.h"
#include <Novice.h>

class Scene_Title {

	private Scene{
		//================
		//�����o�ϐ�
		//================

		int GH_;

	};

	//================
	//�����o�֐�
	//================
	public Scene{

	void Load()override;

	void Update()override;

	void Unload()override;

	};
};

