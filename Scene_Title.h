﻿#pragma once
#include "Scene.h"
#include"Button.h"
#include"Quad.h"

class Scene_Title:
	public Scene{

private:
	Quad titleBar;
	Button Button_goSelect;
	
	Button Button_exit;


public:
	Scene_Title() {}

	void Load()override;

	void Update()override;

	void Draw()override;

	void Unload()override;
	

	
};

