#pragma once
#include "BodyPart.h"
class SpyderBody : public BodyPart {
public:
	void Draw(float x, float y, float z);
	void Animation();
	void SetPosition(float x, float y, float z);
};