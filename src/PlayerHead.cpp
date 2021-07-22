#include "PlayerHead.h"

PlayerHead::PlayerHead()
{

}

PlayerHead::~PlayerHead()
{
}

void PlayerHead::Draw(const float& x, const float& y, const float& z)
{
	glPushMatrix();
	{
		glTranslated(x * size, y * size, z * size);
		glutWireSphere(0.5 * size, 10 * size, 10 * size);
	}
	glPopMatrix();
}

void PlayerHead::Animation()
{
}

void PlayerHead::SetPosition(float x, float y, float z)
{
}
