#pragma once
#include "Scene.h"
#include "Button.h"

class Scene_Select:
	public Scene {

	
private:

	//======================
	//�����o�ϐ�
	//======================

	Button stage_[9];
	
public:
	//=======================
	//�Q�b�^�[
	//=======================
	int getSelectedStage(Vec2 mousePos, int clickState);




};

