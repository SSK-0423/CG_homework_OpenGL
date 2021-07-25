#pragma once
#include "BodyPart.h"
#include "Material.h"
class PlayerHead : public BodyPart<const float&, const float&, const float&>
{
private:
	Material material;
	MaterialParam param = {
	{0.99,0.86,0.74,1.0},
	{0.99,0.86,0.74,1.0},
	{0.0,0.0,0.0,1.0},
	{0.0,0.0,0.0,1.0},
	0
	};
public:
	PlayerHead();
	~PlayerHead();
	void Draw(const float& x, const float& y, const float& z);
	void Animation();
	void SetPosition(float x, float y, float z);
};