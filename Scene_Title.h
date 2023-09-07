#pragma once
#include "Scene.h"
#include"Button.h"
#include"Quad.h"

class Scene_Title:
	public Scene{

private:
	Quad titleBar;

	Button Button_goSelect;
	Button Button_goManu;
	Button Button_exit;

	void Load()override;

	void Update()override;

	void Draw()override;

	void Unload()override;
	
};

