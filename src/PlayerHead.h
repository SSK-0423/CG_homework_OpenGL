#pragma once
#include "BodyPart.h"

class PlayerHead : public BodyPart<const float&, const float&, const float&>
{
private:
public:
	PlayerHead();
	~PlayerHead();
	void Draw(const float& x, const float& y, const float& z);
	void Animation();
	void SetPosition(float x, float y, float z);
};