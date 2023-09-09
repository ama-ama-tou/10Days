#pragma once
#include "SceneManager.h"
#include "InputManager.h"

class GameManager {
private:
	InputManager* inputManager_ = InputManager::GetInstance();
	SceneManager* sceneManager_{};

public:
	GameManager() {};
	void Run();
};

