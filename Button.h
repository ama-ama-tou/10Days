#pragma once
#include "Quad.h"
#include <Vec2.h>

class Button :
	public Quad {
private:

	Vec2 pos_;
	Vec2 size_;

	bool isInsideMouse_;
	bool isClicked_;

	const char* filePass_;

	unsigned int color_;
	unsigned int colorAfterClicked_;
	
	
public:

	Button() {};

	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, const char* GH,unsigned int color,unsigned int colorAfterClicked,Vec2 imageLtPos, Vec2 imageSize) {
		
		color_ = color;
		colorAfterClicked_ = colorAfterClicked;

		filePass_ = GH;
		int GH_ = Novice::LoadTexture(filePass_);
		Quad::Init(pos, size, localCoOrigin, GH_, imageLtPos, imageSize,color);
	}

	void checkInsideMouse(Vec2 mousepos);

	void Update(Vec2 mousePos, int clickState);

	void Draw();

	bool getISInsideMouse() { return isInsideMouse_;}
	bool getIsClicked() { return isClicked_; }

};

