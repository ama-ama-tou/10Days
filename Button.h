#pragma once
#include "Quad.h"
#include <Vec2.h>
#include<Novice.h>

class Button :
	public Quad {
private:

	Vec2 pos_;
	Vec2 size_;

	bool isInsideMouse_;
	bool isClicked_;

	int GH_;

	unsigned int colorBeforeClick_;
	unsigned int color_;
	unsigned int colorAfterClick_;
	
	//easing計算
	float currentTime_;
	float t;
	
public:

	Button() {};

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="size"></param>
	/// <param name="localCoOrigin"></param>
	/// <param name="GH"></param>
	/// <param name="color">alpha値を含まない</param>
	/// <param name="colorAfterClicked">alpha値を含まない</param>
	/// <param name="imageLtPos"></param>
	/// <param name="imageSize"></param>
	void Init(Vec2 pos, Vec2 size, Vec2 localCoOrigin, const char* GH,unsigned int color,unsigned int colorAfterClicked,Vec2 imageLtPos, Vec2 imageSize) {
		
		currentTime_ = 0.0f;

		colorBeforeClick_ = color;
		color_ = colorBeforeClick_;
		colorAfterClick_ = colorAfterClicked;

		GH_ = Novice::LoadTexture(GH);
		
		Quad::Init(pos, size, localCoOrigin, GH_, imageLtPos, imageSize,color_+0xff);
	}

	void checkInsideMouse(Vec2 mousepos);

	
	void colorChange();
	
	void Update(Vec2 mousePos, int clickState);

	void Draw();

	bool getISInsideMouse() { return isInsideMouse_;}
	bool getIsClicked() { return isClicked_; }

};

