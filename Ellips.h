#pragma once
#include "Vec2.h"
#include "Coordinate.h"

class Ellips {
private:
	//================
	//�����o�ϐ�
	//===============
	Coordinate localCo_{ Vec2(0.0f,0.0f) };
	Vec2 pos_;
	float radius_;
	float angle_;
	unsigned int color_;
public:
	//===============
	//�����o�֐�
	//===============
	void Init(Vec2 pos,float radius,float angle,unsigned int color) {
		pos_ = pos;
		radius_ = radius;
		angle_ = angle;
		color_ = color;
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

