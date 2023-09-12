#pragma once
#include"Vec2.h"
#include"Coordinate.h"

struct Triangle {

	Coordinate localCo{ Vec2(0.0f,0.0f) };
	Vec2 vertex_[3];
	
	float currentTime_;
	float t_;

	unsigned int color_;

	void EasingUpdate();

	void Draw();



};

