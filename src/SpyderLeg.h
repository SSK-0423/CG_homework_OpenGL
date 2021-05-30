#pragma once
#include "BodyPart.h"
class SpyderLeg : public BodyPart {
public:
	void Draw();
	void Animation();
	void SetPosition(float x, float y, float z);
};