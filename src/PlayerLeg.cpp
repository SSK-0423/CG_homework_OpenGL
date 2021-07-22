#include "PlayerLeg.h"

PlayerLeg::PlayerLeg()
{
}

PlayerLeg::~PlayerLeg()
{
}

void PlayerLeg::Draw(const float& x, const float& y, const float& z)
{
	glPushMatrix();
	{
		glTranslated(x * size, y * size, z * size);
		glPushMatrix();
		{
			glTranslated(0, (0.5 + 0.25 / 2) * size, 0);
			glPushMatrix();
			{
				glTranslated(0, 1 * size, 0);
				glScaled(0.5 * size, 1 * size, 0.5 * size);
				glutWireCube(1);	// ëæÇ‡Ç‡
			}
			glPopMatrix();
			glScaled(0.5 * size, 1 * size, 0.5 * size);
			glutWireCube(1);	// Ç∑ÇÀ
		}
		glPopMatrix();
		glTranslated(0, 0, (0.75 - 0.5) / 2);
		glScaled(0.4 * size, 0.25 * size, 0.75 * size);
		glutWireCube(1);	// ë´êÊ
	}
	glPopMatrix();
}

void PlayerLeg::Animation()
{
}

void PlayerLeg::SetPosition(float x, float y, float z)
{
}