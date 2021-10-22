#include "PlayerHead.h"

PlayerHead::PlayerHead()
{
	material.SetMaterial(param);
}

PlayerHead::~PlayerHead()
{
}

void PlayerHead::Draw(const float& x, const float& y, const float& z)
{
	glPushMatrix();
	{
		glTranslated(x * size, y * size, z * size);
		material.EnableMaterial(AMBIENT | DIFFUSE);
		glutSolidSphere(0.5 * size, 10 * size, 10 * size);
	}
	glPopMatrix();
}

void PlayerHead::Animation()
{
}

void PlayerHead::SetPosition(float x, float y, float z)
{
}
