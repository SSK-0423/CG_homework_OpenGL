#pragma once
#include "Vector3D.h"
class BodyPart {
private:
	Vector3D position;
public:
	virtual void Draw() = 0;
	virtual void Animation() = 0;
	virtual void SetPosition(float x, float y, float z) = 0;
};