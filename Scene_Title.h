#pragma once
#include "Scene.h"

class Scene_Title:
	public Scene{
private:
	Quad titleBar;

	Button Button_goSelect;
	Button Button_goManu;
	Button Button_exit;

	void Update()override;

	void Unload()override;

	};
};

