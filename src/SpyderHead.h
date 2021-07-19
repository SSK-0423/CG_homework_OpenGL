#pragma once
#include "BodyPart.h"
#include "Texture.h"
class SpyderHead : public BodyPart<float,float,float> {
private:
	Texture* eyeTexture;
	float mtr[2][4] = {
		{0.5,0.0,0.0,0.0},
		{1.0,0.0,0.0,0.0},
	};
	// ñ⁄
	void DrawEye(float x, float y, float z, double r, int slices, int stacks);
	// êGäo
	void DrawTactile(float x, float y, float z);
public:
	SpyderHead();
	void Draw(float x, float y, float z);
	void Animation();
	void SetPosition(float x, float y, float z);
};