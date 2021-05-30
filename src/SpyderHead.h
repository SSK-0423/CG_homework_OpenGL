#pragma once
#include "BodyPart.h"
class SpyderHead : public BodyPart<float,float,float> {
private:
	// ��
	void DrawEye(float x, float y, float z, double r, int slices, int stacks);
	// �G�o
	void DrawTactile(float x, float y, float z);
public:
	void Draw(float x, float y, float z);
	void Animation();
	void SetPosition(float x, float y, float z);
};