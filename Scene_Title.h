#pragma once
#include "Scene.h"
#include <Novice.h>

class Scene_Title {

	private Scene{
		//================
		//メンバ変数
		//================

		int GH_;

	};

	//================
	//メンバ関数
	//================
	public Scene{

	void Load()override;

	void Update()override;

	void Unload()override;

	};
};

