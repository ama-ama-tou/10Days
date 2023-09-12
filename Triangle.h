#pragma once
#include"Vec2.h"
#include"Coordinate.h"

struct Triangle {

	Coordinate localCo{ Vec2(0.0f,0.0f) };
	Vec2 vertex_[3];
	
	float currentTime;
	float t;

	unsigned int color;

	void EasingUpdate();

	void Draw();



};

