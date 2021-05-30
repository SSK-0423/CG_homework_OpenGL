#pragma once
#include "BodyPart.h"
class SpyderTale : public BodyPart<float,float,float> {
private:
	void DrawThread(float x, float y, float z, int angle);
public:
	void Draw(float x, float y, float z);
	void Animation();
	void SetPosition(float x, float y, float z);
};