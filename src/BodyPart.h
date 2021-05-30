#pragma once
#include "Vector3D.h"
#include "GL/glut.h"
template <class ...T>
class BodyPart {
private:
	Vector3D position;
public:
	virtual void Draw(T... t) = 0;
	virtual void Animation() = 0;
	virtual void SetPosition(float x, float y, float z) = 0;
};