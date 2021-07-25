#pragma once
#include "BodyPart.h"
#include "Material.h"
class PlayerArm : public BodyPart<const float&, const float&, const float&>
{
private:
	Material material;
	Material material2;
	MaterialParam param = {
		{0.99,0.86,0.74,1.0},
		{0.99,0.86,0.74,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};

public:
	PlayerArm();
	~PlayerArm();
	void Draw(const float& x, const float& y, const float& z);
	void Animation();
	void SetPosition(float x, float y, float z);
};