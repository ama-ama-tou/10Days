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

	const char* filePass[2];
	int GH_;

public:

	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, const char* GH, const char* clicedGH,Vec2 imageLtPos, Vec2 imageSize) {
		Quad::Init(pos, size,localCoOrigin, 0, imageLtPos, imageSize);
	}

	void checkInsideMouse(Vec2 mousepos);

	void Update(Vec2 mousePos, int clickState);

	void Draw();

	bool getISInsideMouse() { return isInsideMouse_;}
	bool getIsClicked() { return isClicked_; }

};

