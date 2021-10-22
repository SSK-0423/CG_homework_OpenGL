#include "PlayerLeg.h"

PlayerLeg::PlayerLeg()
{
	material.SetMaterial(param);
	material2.SetMaterial(param2);
	legTexture = new Texture("textures/jeans.ppm");
	toesTexture = new Texture("textures/kutu.ppm");
	animator = new PlayerLegAnimator(60);
	legRotateX = 0;
	firstJointRotate = 0;
	secondJointRotate = 0;
	thirdJointRotate = 0;
}

PlayerLeg::~PlayerLeg()
{
}
// ¶F‰E
void PlayerLeg::Draw(const float& x, const float& y, const float& z, bool inv, int state)
{
	glPushMatrix();
	{
		glTranslated(x * size, y * size * 1.5, z * size);
		glRotated(firstJointRotate, 1, 0, 0);
		glTranslated(0, -y * size * 0.5, z * size);
		glPushMatrix();
		{
			glPushMatrix();
			{
				glTranslated(0, -(1) * (float)size / 2, 0);
				glRotated(secondJointRotate, 1, 0, 0);
				glTranslated(0, -(1) * (float)size / 2, 0);
				glPushMatrix();
				{
					glTranslated(0, -(0.5 + 0.125) * (float)size / 2, 0.125 * (float)size / 2);
					glRotated(thirdJointRotate, 1, 0, 0);
					glTranslated(0, -(0.5 + 0.125) * (float)size / 2, 0.125 * (float)size / 2);
					material2.EnableMaterial(AMBIENT | DIFFUSE);
					glScaled(0.4 * size, 0.25 * size, 0.75 * size);
					glutSolidCube(1);	// ‘«æ
				}
				glPopMatrix();
				material.EnableMaterial(AMBIENT | DIFFUSE);
				glScaled(0.5 * size, 1 * size, 0.5 * size);
				glutSolidCube(1);	// ‚·‚Ë
			}
			glPopMatrix();
			glScaled(0.5 * size, 1 * size, 0.5 * size);
			glutSolidCube(1);	// ‚à‚à
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void PlayerLeg::Animation()
{
}

void PlayerLeg::Animation(bool inverse,int fps, int animeType)
{
	animator->Animation(legRotateX, firstJointRotate, secondJointRotate, thirdJointRotate, inverse,fps,animeType);
}

void PlayerLeg::SetPosition(float x, float y, float z)
{
}
void PlayerLeg::AddAngle(float value, int num)
{
	switch (num)
	{
	case 1:
		firstJointRotate += value;
		break;
	case 2:
		secondJointRotate += value;
		break;
	case 3:
		thirdJointRotate += value;
		break;
	default:
		break;
	}
}

void PlayerLeg::StopAnime()
{
	animator->StopAnime();
	firstJointRotate = 0;
	secondJointRotate = 0;
	thirdJointRotate = 0;
}
