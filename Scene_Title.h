#pragma once
#include "Scene.h"
#include"Quad.h"
#include"Button.h"

class Scene_Title:
	public Scene{
private:
	Quad titleBar;

	Button Button_goSelect;
	Button Button_goManu;
	Button Button_exit;

public:
	void Load()override;
	void Update()override;
	void Unload()override;


};

