#pragma once
#include "Vec2.h"
#include "Coordinate.h"

class Ellips {

	//================
	//�����o�ϐ�
	//===============
	Coordinate localCo_;
	Vec2 pos_;
	float radius_;
	float angle_;

public:
	//===============
	//�����o�֐�
	//===============
	void Init(Vec2 pos,Vec2 radius,float angle) {
		pos_ = pos;
		radius_ = radius;
		angle_ = angle;
	}
	void Draw();


	//===============
	//�Q�b�^�[/�Z�b�^�[
	//===============

	//���[�J�����W��
	Vec2 getPos() { return pos_; }
	void setPos(Vec2 pos) { pos_ = pos; }

	//�X�N���[�����W��
	Vec2 getScreenPos() { return localCo_.screenFromOrigin(pos_); }


	float getRadius() { return radius_; }
	void setRadius(float radius) { radius_ = radius; }

	float getAngle() { return angle_; }
	void setAngle(float angle) { angle_ = angle; }

};

