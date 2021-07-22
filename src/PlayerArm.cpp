#include "PlayerArm.h"

PlayerArm::PlayerArm()
{
}

PlayerArm::~PlayerArm()
{

}

void PlayerArm::Draw(const float& x, const float& y, const float& z)
{
	glPushMatrix();
	{
		glTranslated(x * size, y * size, z * size);
		glPushMatrix();
		{
			glTranslated(0, -(0.4 + 0.5) * size / 2, 0);
			glRotated(-90, 1, 0, 0);
			glTranslated(0, -(0.4 + 0.5) * size / 2, 0);
			glPushMatrix();
			{
				glTranslated(0, -(0.5 + 0.2) * size, 0);
				glScaled(0.4 * size, 0.4 * size, 0.5 * size);
				glutWireCube(1);
			}
			glPopMatrix();
			glScaled(0.4 * size, 1.0 * size, 0.5 * size);
			glutWireCube(1);
		}
		glPopMatrix();
		glScaled(0.4 * size, 0.8 * size, 0.5 * size);
		glutWireCube(1);
	}
	glPopMatrix();
}

void PlayerArm::Animation()
{
}

void PlayerArm::SetPosition(float x, float y, float z)
{
}
