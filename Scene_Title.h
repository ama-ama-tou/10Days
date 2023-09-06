#pragma once
#include "Scene.h"

class Scene_Title:
	public Scene{
private:
	Quad titleBar;


	void Update()override;

	void Unload()override;

	};
};

