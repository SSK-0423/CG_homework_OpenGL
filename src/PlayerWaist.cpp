#include "PlayerWaist.h"

PlayerWaist::PlayerWaist()
{
}

PlayerWaist::~PlayerWaist()
{
}

void PlayerWaist::Draw(const float& x, const float& y, const float& z)
{
	glPushMatrix();
	{
		glTranslated(x * size, y * size, z * size);
		glScaled(1.5 * size, 0.5 * size, 0.5 * size);
		glutSolidCube(1);
	}
	glPopMatrix();
}

void PlayerWaist::Animation()
{
}

void PlayerWaist::SetPosition(float x, float y, float z)
{
}