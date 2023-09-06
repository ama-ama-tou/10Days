#pragma once
class Scene
{



public :
	virtual void Load() = 0;

	virtual void Update() = 0;

	virtual void Unload() = 0;

};

