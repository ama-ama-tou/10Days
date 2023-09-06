#pragma once

enum SceneNum {
	SCENE_TITLE,
	SCENE_MENU,
	SCENE_STAGESELLECT,
	SCENE_GAME,
};

class Scene{

public :

	virtual void Load() = 0;

	virtual void Update() = 0;

	virtual void Unload() = 0;

};

