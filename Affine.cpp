#include "Affine.h"

Vec2 Translation(Vec2& target, Vec2 trans) {
	Matrix3x3 translation{
		1.0f,0.0f,trans.x,
		0.0f,1.0f,trans.y,
		0.0f,0.0f,1.0f
	};
	float target3x1[3]{ target.x,target.y,1.0f };
	float result[3]{ 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result[i] += translation.m[i][j] * target3x1[j];
		}
	}

	return Vec2(result[0], result[1]);
}

Vec2 Scaling(Vec2& target, Vec2 scale) {
	Matrix3x3 scaling{
		scale.x,0.0f,0.0f,
		0.0f,scale.y,0.0f,
		0.0f,0.0f,1.0f
	};
	float target3x1[3]{ target.x,target.y,1.0f };
	float result[3]{ 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result[i] += scaling.m[i][j] * target3x1[j];
		}
	}
	return Vec2(result[0], result[1]);
}

Vec2 Rotating(Vec2& target, float theta) {
	Matrix3x3 rotating{
		cosf(theta),-sinf(theta),0,
		sinf(theta),cosf(theta),0,
		0	,	0	,	1
	};
	float target3x1[3]{ target.x,target.y,1.0f };
	float result[3]{ 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result[i] += rotating.m[i][j] * target3x1[j];
		}
	}
	return Vec2(result[0], result[1]);
}

Vec2 Affine(Vec2& target, Vec2 target2origine, Vec2 scale, float theta) {
	Vec2 result;
	result = Translation(target, target2origine * Vec2(-1.0f, -1.0f));
	result = Scaling(result, scale);
	result = Rotating(result, theta);
	result = Translation(result, target2origine);
	return result;
}

